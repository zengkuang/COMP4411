//
// BlurFilter.h
//

#ifndef BLURFILTER_H
#define BLURFILTER_H

#include "ImpBrush.h"

class BlurFilter : public ImpBrush
{
public:
	BlurFilter(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point targert);
	void Autodraw();
	char* BrushName(void);
};

#endif /* BLURFILTER_H */
