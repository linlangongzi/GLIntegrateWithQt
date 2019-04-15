#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <qopenglext.h>
#include "ui_GLWidget.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT

public:
	GLWidget(QOpenGLWidget *parent = Q_NULLPTR);
	~GLWidget();

protected:
	void mousePressEvent(QMouseEvent *e) override;
	void mouseReleaseEvent(QMouseEvent *e) override;


	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int w, int h) override;

	bool checkShaderStatus(GLuint shaderID);
	bool checkProgramStatus(GLuint programID);

private:
	void initializeShaderProgram();
	void initializeGeometry();
	bool checkStatus(GLuint objectID, PFNGLGETSHADERIVPROC objectPropertyAccesserFunc, PFNGLGETSHADERINFOLOGPROC getInfoLogFunc, GLenum statusType);

private:
	QOpenGLShaderProgram m_program;
	//QOpenGLContext *m_context;
	//QOpenGLFormat * m_format;
	//QSurface *m_surface;
	QOpenGLBuffer VBO;
	QOpenGLBuffer IBO;
	struct VertexData
	{
		QVector3D position;
		QVector3D color;
		QVector2D texture;
	};
private:
	Ui::GLWidget ui;
};
