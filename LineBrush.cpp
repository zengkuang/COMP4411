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

	if (pDoc == NULL)
	{
		printf("LineBrush::BrushMove document is NULL\n");
		return;
	}

	glLineWidth((int)Line_width);
	
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