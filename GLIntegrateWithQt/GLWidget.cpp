#include "GLWidget.h"
#include <iostream>
#include <QDebug>

GLWidget::GLWidget(QOpenGLWidget *parent)
	: QOpenGLWidget(parent)
{
	ui.setupUi(this);
	//m_surface = new QSurface();
	//m_context = new QOpenGLContext();
	//m_context->makeCurrent();
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeShaderProgram()
{
	m_program.create();
	if (checkProgramStatus( m_program.programId()))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	}

}
bool GLWidget::checkStatus(GLuint objectID, PFNGLGETSHADERIVPROC objectPropertyAccesserFunc, PFNGLGETSHADERINFOLOGPROC getInfoLogFunc, GLenum statusType)
{
	GLint status;
	objectPropertyAccesserFunc(objectID, statusType, &status);
	if (status != GL_TRUE)
	{
		GLint infoLength;
		objectPropertyAccesserFunc(objectID, GL_INFO_LOG_LENGTH, &infoLength);
		GLchar* logBuffer = new GLchar(infoLength);
		
		GLsizei bufferSize;
		getInfoLogFunc(objectID, infoLength, &bufferSize, logBuffer);
		std::cout << logBuffer;
		delete logBuffer;
		return false;
	}
	return true;
}

bool GLWidget::checkShaderStatus(GLuint shaderID)
{
	return checkStatus(shaderID, /*(PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv")*/
		(PFNGLGETSHADERIVPROC)context()->getProcAddress("glGetShaderiv"), (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog"), GL_COMPILE_STATUS);
}
bool GLWidget::checkProgramStatus(GLuint programID)
{
	return checkStatus(programID, (PFNGLGETSHADERIVPROC) context()->getProcAddress("glGetProgramiv"), (PFNGLGETSHADERINFOLOGPROC) wglGetProcAddress("glGetProgramInfoLog"), GL_COMPILE_STATUS);
}
void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	initializeShaderProgram();
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
