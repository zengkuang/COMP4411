//
// BlurFilter.cpp
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "BlurFilter.h"

extern float frand();

BlurFilter::BlurFilter(ImpressionistDoc* pDoc, char* name) : ImpBrush(pDoc, name)
{}

void BlurFilter::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* pUI = pDoc->m_pUI;

	BrushMove(source, target);
}

void BlurFilter::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* pIU = pDoc->m_pUI;

	if (pDoc == NULL)
	{
		printf("BlurFilter::BrushMove document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	glPointSize((float)size);

	glBegin(GL_POINTS);

		SetColor(source);
		glVertex2d(target.x, target.y);

	glEnd();
}

void BlurFilter::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}
