//
// SharpenFilter.h
//

#ifndef SHARPENFILTER_H
#define SHARPENFILTER_H

#include "ImpBrush.h"

class SharpenFilter : public ImpBrush
{
public:
	SharpenFilter(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	void Autodraw();
	char* BrushName(void);

};


#endif /* SHARPENFILTER_H */
