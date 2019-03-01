#ifndef LineBrush_h
#define LineBrush_h

#include "ImpBrush.h"

class LineBrush : public ImpBrush
{
public:
	LineBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	void Autodraw();
	char* BrushName(void);
};

#endif /*LineBrush_h*/