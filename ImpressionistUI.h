//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_file_chooser.H>		// FLTK file chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>

#include "Impressionist.h"
#include "OriginalView.h"
#include "PaintView.h"

#include "ImpBrush.h"

class ImpressionistUI {
public:
	ImpressionistUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;

	PaintView*			m_paintView;
	OriginalView*		m_origView;

	// for brush dialog
	Fl_Window*			m_brushDialog;
	Fl_Choice*			m_BrushTypeChoice;
	Fl_Choice*			m_DirectionChoice;	//new

	Fl_Slider*			m_BrushSizeSlider;
	Fl_Button*          m_ClearCanvasButton;
	Fl_Slider*			m_LineWidthSlider;
	Fl_Slider*			m_LineAngleSlider;
	Fl_Slider*			m_AlphaSlider;

	// for color scale dailog
	Fl_Window*			m_colorDialog;

	Fl_Slider*			m_RedScaleSlider;
	Fl_Slider*			m_GreenScaleSlider;
	Fl_Slider*			m_BlueScaleSlider;

	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute

	int					getSize();
	void				setSize(int size);

	float				getAlpha();
	void				setAlpha(float alpha);

	// Attribute of line brush

	int					getLineWidth();
	void				setLineWidth(int width);

	int					getLineAngle();
	void				setLineAngle(int angle);

	int					getStrokeDirection();

	// Attribute of the color scale

	int					getRedScale();
	void				setRedScale(int reds);

	int					getGreenScale();
	void				setGreenScale(int greens);

	int					getBlueScale();
	void				setBlueScale(int blues);

private:
	ImpressionistDoc * m_pDoc;		// pointer to document to communicate with the document

									// All attributes here
	int		m_nSize;
	float	m_nAlpha;
	int		m_nLineWidth;
	int		m_nLineAngle;
	int		m_nStrokeDirection;
	int		m_nRedScale;
	int		m_nGreenScale;
	int		m_nBlueScale;

	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE + 1];
	static Fl_Menu_Item		directionControlerMenu[NUM_DIRECTION_CONTROL + 1];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);
	static void cb_directionChoice(Fl_Widget* o, void* v);	//new
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
	static void	cb_sizeSlides(Fl_Widget* o, void* v);
	static void cb_alphaSlides(Fl_Widget* o, void* v);
	static void cb_linewidthSlides(Fl_Widget*o, void *v);
	static void cb_lineangleSlides(Fl_Widget* o, void*v);
	static void cb_color_scale(Fl_Menu_* o, void* v);
	static void cb_redscaleSlides(Fl_Widget* o, void* v);
	static void cb_greenscaleSlides(Fl_Widget* o, void* v);
	static void cb_bluescaleSlides(Fl_Widget* o, void* v);

};

#endif
