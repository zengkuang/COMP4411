//
// LineBrush.cpp
//

#include<iostream>
#include<math.h>
#include"impressionistDoc.h"
#include"impressionistUI.h"
#include"LineBrush.h"

using namespace std;

extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name):ImpBrush(pDoc,name)
{}

void LineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	BrushMove(source, target);
}

void LineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	int Line_width = pDoc->getLineWidth();
	int Line_angle = pDoc->getLineAngle();
	int Stroke_direction = pDoc->getStrokeDirectionType();


	if (pDoc == NULL)
	{
		printf("LineBrush::BrushMove document is NULL\n");
		return;
	}

	glLineWidth((float)Line_width);
	float* grad = Gradient(source);
	//printf("%d\n", Stroke_direction);
	//printf("%f\t%f\n", grad[0], grad[1]);
	switch (Stroke_direction) {
		case SLIDER_RIGHT_MOUSE:
			
			break;
		case GRADIENT:
			//printf("gradient\n");
			grad = Gradient(source);
			Line_angle = atan2(-grad[1], grad[0])*180/M_PI;
			//printf("%d\n", Line_angle);
			break;
		case BRUSH_DIRECTION:
			Line_angle = atan2((pDoc->pointer_history[0]->y - pDoc->pointer_history[1]->y), (pDoc->pointer_history[0]->x - pDoc->pointer_history[1]->x))*180/M_PI;
			break;
	}


	glBegin(GL_LINES);

		SetColor(source);
		glVertex2d(target.x - size * cos(Line_angle*M_PI / 180) / 2, target.y - size * sin(Line_angle*M_PI / 180) / 2);
		glVertex2d(target.x + size * cos(Line_angle*M_PI / 180) / 2, target.y + size * sin(Line_angle*M_PI / 180) / 2);

	glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}
