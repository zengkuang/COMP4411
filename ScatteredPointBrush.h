//
// ScatteredPintBrush.h
//

#ifndef SCATTEREDPOINTBURSH_H
#define SCATTEREDPOINTBURSH_H

#include"ImpBrush.h"

class ScatteredPointBrush : public ImpBrush
{
public:
	ScatteredPointBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	void Autodraw();
	char* BrushName(void);
};

#endif /*SCATTEREDPOINTBURSH_H*/