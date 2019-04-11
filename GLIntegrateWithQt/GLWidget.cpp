#include "GLWidget.h"

GLWidget::GLWidget(QOpenGLWidget *parent)
	: QOpenGLWidget(parent)
{
	ui.setupUi(this);
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLWidget::resizeGL(int w, int h)
{
}

void GLWidget::mousePressEvent(QMouseEvent * e)
{
}

void GLWidget::mouseReleaseEvent(QMouseEvent * e)
{
}
