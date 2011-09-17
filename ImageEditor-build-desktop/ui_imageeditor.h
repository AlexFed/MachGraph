/********************************************************************************
** Form generated from reading UI file 'imageeditor.ui'
**
** Created: Sat Sep 17 14:44:34 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEEDITOR_H
#define UI_IMAGEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageEditor
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageEditor)
    {
        if (ImageEditor->objectName().isEmpty())
            ImageEditor->setObjectName(QString::fromUtf8("ImageEditor"));
        ImageEditor->resize(400, 300);
        menuBar = new QMenuBar(ImageEditor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ImageEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageEditor);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ImageEditor->addToolBar(mainToolBar);
        centralWidget = new QWidget(ImageEditor);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ImageEditor->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ImageEditor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImageEditor->setStatusBar(statusBar);

        retranslateUi(ImageEditor);

        QMetaObject::connectSlotsByName(ImageEditor);
    } // setupUi

    void retranslateUi(QMainWindow *ImageEditor)
    {
        ImageEditor->setWindowTitle(QApplication::translate("ImageEditor", "ImageEditor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageEditor: public Ui_ImageEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEEDITOR_H
