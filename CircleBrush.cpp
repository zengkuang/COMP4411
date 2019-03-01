//
// CircleBrush.cpp
//

#include<math.h>
#include"impressionistDoc.h"
#include"impressionistUI.h"
#include"CircleBrush.h"

extern float frand();

CircleBrush::CircleBrush(ImpressionistDoc* pDoc, char* name) :ImpBrush(pDoc, name)
{}

void CircleBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	BrushMove(source, target);
}

void CircleBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL)
	{
		printf("CircleBrush::BrushMove document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	GLdouble r = (double)size / 2;

	glBegin(GL_POLYGON);
		
		SetColor(source);
		for (int i = 0; i < 360; i++)
		{
			glVertex2d(target.x + r*cos(2 * M_PI*i / 360), target.y + r*sin(2 * M_PI*i / 360));
		}

	glEnd();

}

void CircleBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

void CircleBrush::Autodraw()
{

}