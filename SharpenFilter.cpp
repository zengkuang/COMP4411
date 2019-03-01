//
// SharpenFilter.cpp
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "SharpenFilter.h"
#include <cstdlib>

extern float frand();

SharpenFilter::SharpenFilter(ImpressionistDoc* pDoc, char* name) : ImpBrush(pDoc, name)
{}

void SharpenFilter::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	glPointSize((float)size);

	BrushMove(source, target);
}

void SharpenFilter::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* pUI = pDoc->m_pUI;

	if (pDoc == NULL)
	{
		printf("SharoenFilter::BrushMove document is NULL\n");
		return;
	}

	printf("draw");
	glBegin(GL_POINTS);

		SetColor(source);
		glVertex2d(target.x, target.y);

	glEnd();
}

void SharpenFilter::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}
