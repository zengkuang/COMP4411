//
// ImpBrush.cpp
//
// The implementation of virtual brush. All the other brushes inherit from it.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ImpBrush.h"

// Static class member initializations
int			ImpBrush::c_nBrushCount = 0;
ImpBrush**	ImpBrush::c_pBrushes = NULL;

ImpBrush::ImpBrush(ImpressionistDoc*	pDoc,
	char*				name) :
	m_pDoc(pDoc),
	m_pBrushName(name)
{
}

//---------------------------------------------------
// Return m_pDoc, which connects the UI and brushes
//---------------------------------------------------
ImpressionistDoc* ImpBrush::GetDocument(void)
{
	return m_pDoc;
}

//---------------------------------------------------
// Return the name of the current brush
//---------------------------------------------------
char* ImpBrush::BrushName(void)
{
	return m_pBrushName;
}

//----------------------------------------------------
// Set the color to paint with to the color at source,
// which is the coord at the original window to sample 
// the color from
//----------------------------------------------------
void ImpBrush::SetColor(const Point source)
{
	ImpressionistDoc* pDoc = GetDocument();


	GLubyte color[3];
	float Alpha = pDoc->getAlpha();
	int nAlpha = Alpha * 255;
	
	int RedScale = pDoc->getRedScale();
	int GreenScale = pDoc->getGreenScale();
	int BlueScale = pDoc->getBlueScale();

	memcpy(color, pDoc->GetOriginalPixel(source), 3);

	color[0] = color[0] * RedScale / 255;
	color[1] = color[1] * GreenScale / 255;
	color[2] = color[2] * BlueScale / 255;

	glColor4ub(color[0],color[1],color[2],nAlpha);

}

float* ImpBrush::Gradient(const Point source)
{
	ImpressionistDoc* pDoc = GetDocument();

	GLubyte color1[3];
	GLubyte color2[3];
	GLubyte color3[3];
	GLubyte color4[3];
	GLubyte color5[3];
	GLubyte color6[3];
	GLubyte color7[3];
	GLubyte color8[3];
	GLubyte color9[3];

	memcpy(color1, pDoc->GetOriginalPixel(source.x - 1, source.y - 1), 3);
	memcpy(color2, pDoc->GetOriginalPixel(source.x - 1, source.y), 3);
	memcpy(color3, pDoc->GetOriginalPixel(source.x - 1, source.y + 1), 3);
	memcpy(color4, pDoc->GetOriginalPixel(source.x, source.y - 1), 3);
	memcpy(color5, pDoc->GetOriginalPixel(source.x, source.y), 3);
	memcpy(color6, pDoc->GetOriginalPixel(source.x, source.y + 1), 3);
	memcpy(color7, pDoc->GetOriginalPixel(source.x + 1, source.y - 1), 3);
	memcpy(color8, pDoc->GetOriginalPixel(source.x + 1, source.y), 3);
	memcpy(color9, pDoc->GetOriginalPixel(source.x + 1, source.y + 1), 3);

	float grayscale1 = color1[0] * 0.2989 + color1[1] * 0.5870 + color1[2] * 0.1440;
	float grayscale2 = color2[0] * 0.2989 + color2[1] * 0.5870 + color2[2] * 0.1440;
	float grayscale3 = color3[0] * 0.2989 + color3[1] * 0.5870 + color3[2] * 0.1440;
	float grayscale4 = color4[0] * 0.2989 + color4[1] * 0.5870 + color4[2] * 0.1440;
	float grayscale5 = color5[0] * 0.2989 + color5[1] * 0.5870 + color5[2] * 0.1440;
	float grayscale6 = color6[0] * 0.2989 + color6[1] * 0.5870 + color6[2] * 0.1440;
	float grayscale7 = color7[0] * 0.2989 + color7[1] * 0.5870 + color7[2] * 0.1440;
	float grayscale8 = color8[0] * 0.2989 + color8[1] * 0.5870 + color8[2] * 0.1440;
	float grayscale9 = color9[0] * 0.2989 + color9[1] * 0.5870 + color9[2] * 0.1440;

	float gradient_x = grayscale1 * (-1) + grayscale2 * (-2) + grayscale3 * (-1) + grayscale7 * 1 + grayscale8 * 2 + grayscale9 * 1;
	float gradient_y = grayscale1 * 1 + grayscale4 * 2 + grayscale7 * 1 + grayscale3 * (-1) + grayscale6 * (-2) + grayscale9 * (-1);

	float* current_gradient = new float[2];
	current_gradient[0] = gradient_x;
	current_gradient[1] = gradient_y;

	return current_gradient;
}