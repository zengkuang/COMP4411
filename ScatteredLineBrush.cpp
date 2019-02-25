//
// ScatteredLineBrush.cpp
//

#include<math.h>
#include<ctime>
#include<cstdlib>
#include"impressionistDoc.h"
#include"impressionistUI.h"
#include"ScatteredLineBrush.h"

extern float frand();

ScatteredLineBrush::ScatteredLineBrush(ImpressionistDoc* pDoc, char* name) :ImpBrush(pDoc, name)
{}

void ScatteredLineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	BrushMove(source, target);
}

void ScatteredLineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL)
	{
		printf("ScatteredLineBrush::BrushMove document is NULL\n");
	}

	int size = pDoc->getSize();
	int width = pDoc->getLineWidth();
	int angle = pDoc->getLineAngle();
	glLineWidth(width);

	srand((unsigned)time(NULL));

	for (int i = 0; i < 4; i++)
	{
		int x_cor = rand() % size - size / 2;
		int y_cor = rand() % size - size / 2;
		const Point ScatteredSource(source.x + x_cor, source.y + y_cor);
		const Point ScatteredTarget(target.x + x_cor, target.y + y_cor);

		glBegin(GL_LINES);

			SetColor(ScatteredSource);
			glVertex2d(ScatteredTarget.x - cos(angle*M_PI / 180)*size / 2, ScatteredTarget.y - sin(angle*M_PI / 180)*size / 2);
			glVertex2d(ScatteredTarget.x + cos(angle*M_PI / 180)*size / 2, ScatteredTarget.y + sin(angle*M_PI / 180)*size / 2)

		glEnd();
	}
}

void ScatteredLineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}