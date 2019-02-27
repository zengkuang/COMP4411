//
// ScatteredCircleBrush
//

#include<math.h>
#include<ctime>
#include<cstdlib>
#include"impressionistDoc.h"
#include"impressionistUI.h"
#include"ScatteredCircleBrush.h"

extern float frand();

ScatteredCircleBrush::ScatteredCircleBrush(ImpressionistDoc* pDoc, char* name) :ImpBrush(pDoc, name)
{}

void ScatteredCircleBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	BrushMove(source, target);
}

void ScatteredCircleBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL)
	{
		printf("ScatteredCirclePoint::BrushMove document is NLL\n");
	}

	int size = pDoc->getSize();
	double r = (double)size*0.5;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 4; i++)
	{
		int x_cor = rand() % size - size / 2;
		int y_cor = rand() % size - size / 2;
		const Point ScatteredSource(x_cor + source.x, y_cor + source.y);
		const Point ScatteredTarget(x_cor + target.x, y_cor + target.y);
		glBegin(GL_POLYGON);

			SetColor(ScatteredSource);
			for (int i = 0; i < 360; i++)
			{
				glVertex2d(ScatteredTarget.x + r * cos(2 * M_PI*i / 360), ScatteredTarget.y + r * sin(2 * M_PI*i / 360));
			}

		glEnd();
	}
}

void ScatteredCircleBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far;
}