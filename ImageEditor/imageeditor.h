#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <QMainWindow>
#include <QPrinter>
#include "mimage.h"

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

//! [0]
class ImageEditor : public QMainWindow
{
    Q_OBJECT

public:
    ImageEditor();

private slots:
    void open();
    void print();
    void test();

    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();

    void about();

    void lineExt();
    void channelExt();
    void gauss();
    void sharpening();
    void grayWorld();
    void median();
    void sepGauss();
    void waves();
    void glass();

private:
    void createActions();
    void createMenus();
    void updateActions();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    QLabel *imageLabel;
    QScrollArea *scrollArea;
    double scaleFactor;
    MImage *curImg;
    int minX, minY, maxX, maxY;

#ifndef QT_NO_PRINTER
    QPrinter printer;
#endif

    QAction *openAct;
    QAction *printAct;
    QAction *exitAct;
    QAction *testAct;

    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
    QAction *fitToWindowAct;

    QAction *aboutAct;
    QAction *aboutQtAct;

    QAction *lineExtAct;
    QAction *channelExtAct;
    QAction *gaussAct;
    QAction *sharpeningAct;
    QAction *grayWorldAct;
    QAction *medianAct;
    QAction *sepGaussAct;
    QAction *wavesAct;
    QAction *glassAct;

    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *effectsMenu;
    QMenu *helpMenu;
};
//! [0]

#endif
