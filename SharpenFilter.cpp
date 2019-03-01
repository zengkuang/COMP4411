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

	
	glBegin(GL_POINTS);
		
		SetColor(source);
		glVertex2d(target.x, target.y);

	glEnd();
}

void SharpenFilter::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

void SharpenFilter::Autodraw()
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* pUI = pDoc->m_pUI;

	int spacing = pDoc->getSpacing();
	bool Rand = pDoc->getRandSpacing();

	srand((unsigned)time(NULL));

	for (int i = 0; i < pDoc->m_nWidth; i += spacing)
	{
		for (int j = 0; j < pDoc->m_nHeight; j += spacing)
		{
			if (Rand)
			{
				int rand_size = rand() % 40 + 1;
				glPointSize((float)rand_size);
			}
			else
			{
				glPointSize((float)pDoc->getSize());
			}
			Point current_source;
			Point current_target;
			current_source.x = i;
			current_target.x = i;
			current_source.y = j;
			current_target.y = j;

			printf("reach point");
			BrushMove(current_source, current_target);
		}
	}
}