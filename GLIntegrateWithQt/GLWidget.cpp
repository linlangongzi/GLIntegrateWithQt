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
	if (!m_program.create())
	{
		close();
	}
	if (!m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/MainWindow/Resources/vertexShader.vs"))
	{
		close();
	}
	if (!m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/MainWindow/Resources/fragmentShader.fs"))
	{
		close();
	}
	if (!m_program.link())
	{
		close();
	}
	if (!m_program.bind())
	{
		close();
	}
	//if (checkProgramStatus( m_program.programId()))
	//{
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	//}

}
void GLWidget::initializeGeometry()
{
	VertexData vertex[] = {
		//     ---- 位置 ----       ---- 颜色 ----                 --- 纹理坐标 -
		{QVector3D(0.5f,  0.5f, 0.0f), QVector3D(1.0f, 0.0f, 0.0f), QVector2D(1.0f, 1.0f)}, // 右上
		{QVector3D(0.5f, -0.5f, 0.0f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(1.0f, 0.0f)},  // 右下
		{QVector3D(-0.5f, -0.5f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 0.0f)}, // 左下
		{QVector3D(-0.5f,  0.5f, 0.0f), QVector3D(1.0f, 1.0f, 0.0f), QVector2D(0.0f, 1.0f)}, // 左上
	};
	VBO.create();
	IBO.create();
	VBo.bind();
	VBO.allocate(vertex, 4 * sizeof(VertexData));
}
void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	initializeShaderProgram();
	initializeGeometry();
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	VBO.bind();
	IBO.bind();
	m_program.enableAttributeArray("VBO");
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
		(PFNGLGETSHADERIVPROC)context()->getProcAddress("glGetShaderiv"), 
		(PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog"),
		GL_COMPILE_STATUS);
}

bool GLWidget::checkProgramStatus(GLuint programID)
{
	return checkStatus(programID,
		(PFNGLGETSHADERIVPROC) context()->getProcAddress("glGetProgramiv"), 
		(PFNGLGETSHADERINFOLOGPROC) wglGetProcAddress("glGetProgramInfoLog"), 
		GL_COMPILE_STATUS);
}
