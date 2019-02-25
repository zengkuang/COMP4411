//
// ScatteredCircleBrush
//

#ifndef SCATTEREDCIRCLEBEUSH_H
#define SCATTEREDCIRCLEBRUSH_H

#include"ImpBrush.h"

class ScatteredCircleBrush : public ImpBrush
{
public:
	ScatteredCircleBrush(ImpressionistDoc* pDoc, char* name);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	char* BrushName(void);
};


#endif /* SCATTEREDCIRCLEBRUSH_H */
