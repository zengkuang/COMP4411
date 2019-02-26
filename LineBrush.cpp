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
	int Stroke_direction = pDoc->m_pCurrentStrokeDirection;


	if (pDoc == NULL)
	{
		printf("LineBrush::BrushMove document is NULL\n");
		return;
	}

	glLineWidth((int)Line_width);

	switch (Stroke_direction) {
		case SLIDER_RIGHT_MOUSE:
			
			break;
		case GRADIENT:
			int* grad = Gradient(source);
			Line_angle = atan2(grad[0], grad[1]);
			break;
		case BRUSH_DIRECTION:
			Line_angle = atan2((pDoc->pointer_history[0]->x - pDoc->pointer_history[1]->x), (pDoc->pointer_history[0]->y - pDoc->pointer_history[1]->y));
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