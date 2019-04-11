#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QMatrix4x4>
#include <QOpenGLBuffer>

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

private:
	QOpenGLShaderProgram m_program;

private:
	Ui::GLWidget ui;
};
