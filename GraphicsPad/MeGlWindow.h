#ifndef ME_GL_WINDOW
#define ME_GL_WINDOW
#include <QtOpenGL\qglwidget>

class MeGlWindow : public QGLWidget
{
protected:
	void initializeGL();
	void paintGL();
	//void keyPressEvent(QKeyEvent*);
	void newFrame();
public:
};

#endif
