//
// ScatteredPointBrush.cpp
//

#include<ctime>
#include<cstdlib>
#include"impressionistDoc.h"
#include"impressionistUI.h"
#include"ScatteredPointBrush.h"

extern float frand();

ScatteredPointBrush::ScatteredPointBrush(ImpressionistDoc* pDoc, char* name) :ImpBrush(pDoc, name)
{}

void ScatteredPointBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	BrushMove(source, target);
}

void ScatteredPointBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL)
	{
		Printf("ScatteredPointBrush::BrushMove document is NULL\n");
	}

	int size = pDoc->getSize();
	glPointSize(1.0);

	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		int x_cor = rand() % size - size / 2;
		int y_cor = rand() % size - size / 2;
		const Point ScatteredSource(x_cor + source.x, y_cor + source.y);
		const Point ScatteredTarget(x_cor + target.x, y_cor + target.y);
		glBegin(GL_POINTS);
			
			SetColor(ScatteredSource);
			glVertex2d(ScatteredTarget.x, ScatteredTarget.y);

		glEnd();
	}
}

void ScatteredPointBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

