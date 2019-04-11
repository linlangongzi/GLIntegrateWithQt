/********************************************************************************
** Form generated from reading UI file 'GLWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLWIDGET_H
#define UI_GLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GLWidget
{
public:

    void setupUi(QWidget *GLWidget)
    {
        if (GLWidget->objectName().isEmpty())
            GLWidget->setObjectName(QString::fromUtf8("GLWidget"));
        GLWidget->resize(400, 300);

        retranslateUi(GLWidget);

        QMetaObject::connectSlotsByName(GLWidget);
    } // setupUi

    void retranslateUi(QWidget *GLWidget)
    {
        GLWidget->setWindowTitle(QApplication::translate("GLWidget", "GLWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GLWidget: public Ui_GLWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLWIDGET_H
