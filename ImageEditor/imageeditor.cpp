#include <QtGui>

#include "imageeditor.h"

ImageEditor::ImageEditor()
{
    curImg = NULL;
    minX = minY = maxX = maxY = 0;

    imageLabel = new QLabel;
    imageLabel->setVisible(false);
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(scrollArea);

    createActions();
    createMenus();

    setWindowTitle(tr("Image Editor"));
    resize(500, 400);
}

void ImageEditor::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                    tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty()) {
        QImage image(fileName);
        if (image.isNull()) {
            QMessageBox::information(this, tr("Image Editor"),
                                     tr("Cannot load %1.").arg(fileName));
            return;
        }
        if(curImg)
            curImg->~MImage();
        curImg = new MImage(image);

//        !!!
        minX = minY= 0;
        maxX = image.width();
        maxY = image.height();
        imageLabel->setPixmap(QPixmap::fromImage(curImg->getImage()));
        scaleFactor = 1.0;

        effectsMenu->setEnabled(true);
        fitToWindowAct->setEnabled(true);
        updateActions();
        lineExtAct->setEnabled(true);

        if (!fitToWindowAct->isChecked())
            imageLabel->adjustSize();
    }
}

void ImageEditor::print()
{
    Q_ASSERT(imageLabel->pixmap());
#ifndef QT_NO_PRINTER
//! [6] //! [7]
    QPrintDialog dialog(&printer, this);
//! [7] //! [8]
    if (dialog.exec()) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = imageLabel->pixmap()->size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(imageLabel->pixmap()->rect());
        painter.drawPixmap(0, 0, *imageLabel->pixmap());
    }
#endif
}

void ImageEditor::test()
{
    setWindowTitle(tr("test"));
}

void ImageEditor::zoomIn()
{
    scaleImage(1.25);
}

void ImageEditor::zoomOut()
{
    scaleImage(0.8);
}

void ImageEditor::normalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void ImageEditor::fitToWindow()
{
    bool fitToWindow = fitToWindowAct->isChecked();
    scrollArea->setWidgetResizable(fitToWindow);
    if (!fitToWindow) {
        normalSize();
    }
    updateActions();
}

void ImageEditor::about()
{
    QMessageBox::about(this, tr("About Image Editor"),
            tr("<p>The <b>Image Editor</b> example shows how to combine QLabel "
               "and QScrollArea to display an image. QLabel is typically used "
               "for displaying a text, but it can also display an image. "
               "QScrollArea provides a scrolling view around another widget. "
               "If the child widget exceeds the size of the frame, QScrollArea "
               "automatically provides scroll bars. </p><p>The example "
               "demonstrates how QLabel's ability to scale its contents "
               "(QLabel::scaledContents), and QScrollArea's ability to "
               "automatically resize its contents "
               "(QScrollArea::widgetResizable), can be used to implement "
               "zooming and scaling features. </p><p>In addition the example "
               "shows how to use QPainter to print an image.</p>"));
}

void ImageEditor::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcut(tr("Ctrl+P"));
    printAct->setEnabled(false);
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    testAct = new QAction(tr("&Test"), this);
    testAct->setShortcut(tr("Ctrl+T"));
    connect(testAct, SIGNAL(triggered()), this, SLOT(test()));

    zoomInAct = new QAction(tr("Zoom &In (25%)"), this);
    zoomInAct->setShortcut(tr("Ctrl++"));
    zoomInAct->setEnabled(false);
    connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn()));

    zoomOutAct = new QAction(tr("Zoom &Out (25%)"), this);
    zoomOutAct->setShortcut(tr("Ctrl+-"));
    zoomOutAct->setEnabled(false);
    connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut()));

    normalSizeAct = new QAction(tr("&Normal Size"), this);
    normalSizeAct->setShortcut(tr("Ctrl+S"));
    normalSizeAct->setEnabled(false);
    connect(normalSizeAct, SIGNAL(triggered()), this, SLOT(normalSize()));

    fitToWindowAct = new QAction(tr("&Fit to Window"), this);
    fitToWindowAct->setEnabled(false);
    fitToWindowAct->setCheckable(true);
    fitToWindowAct->setShortcut(tr("Ctrl+F"));
    connect(fitToWindowAct, SIGNAL(triggered()), this, SLOT(fitToWindow()));

    lineExtAct = new QAction(tr("Линейное растяжение гистограммы яркости"), this);
    connect(lineExtAct, SIGNAL(triggered()), this, SLOT(lineExt()));

    channelExtAct = new QAction(tr("Поканальное растяжение гистограммы"), this);
    connect(channelExtAct, SIGNAL(triggered()), this, SLOT(chanelExt()));

    gaussAct = new QAction(tr("Фильтр Гаусса"), this);
    connect(gaussAct, SIGNAL(triggered()), this, SLOT(gauss()));

    sharpeningAct = new QAction(tr("Повышение резкости"), this);
    connect(sharpeningAct, SIGNAL(triggered()), this, SLOT(sharpening()));

    grayWorldAct = new QAction(tr("Серый Мир"), this);
    connect(grayWorldAct, SIGNAL(triggered()), this, SLOT(grayWorld()));

    medianAct = new QAction(tr("Медианная фильтрация"), this);
    connect(medianAct, SIGNAL(triggered()), this, SLOT(median()));

    sepGaussAct = new QAction(tr("Сепарабельный фильтр Гаусса"), this);
    connect(sepGaussAct, SIGNAL(triggered()), this, SLOT(sepGauss()));

    wavesAct = new QAction(tr("Волны"), this);
    connect(wavesAct, SIGNAL(triggered()), this, SLOT(waves()));

    glassAct = new QAction(tr("Стекло"), this);
    connect(glassAct, SIGNAL(triggered()), this, SLOT(glass()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void ImageEditor::createMenus()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    fileMenu->addSeparator();
    fileMenu->addAction(testAct);

    viewMenu = new QMenu(tr("&View"), this);
    viewMenu->addAction(zoomInAct);
    viewMenu->addAction(zoomOutAct);
    viewMenu->addAction(normalSizeAct);
    viewMenu->addSeparator();
    viewMenu->addAction(fitToWindowAct);

    effectsMenu = new QMenu(tr("&Effects"), this);
    effectsMenu->addAction(lineExtAct);
    effectsMenu->addAction(channelExtAct);
    effectsMenu->addSeparator();
    effectsMenu->addAction(gaussAct);
    effectsMenu->addAction(sharpeningAct);
    effectsMenu->addAction(sepGaussAct);
    effectsMenu->addSeparator();
    effectsMenu->addAction(grayWorldAct);
    effectsMenu->addAction(medianAct);
    effectsMenu->addSeparator();
    effectsMenu->addAction(wavesAct);
    effectsMenu->addAction(glassAct);
    effectsMenu->setEnabled(false);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(viewMenu);
    menuBar()->addMenu(effectsMenu);
    menuBar()->addMenu(helpMenu);
}

void ImageEditor::updateActions()
{
    zoomInAct->setEnabled(!fitToWindowAct->isChecked());
    zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
    normalSizeAct->setEnabled(!fitToWindowAct->isChecked());
}

void ImageEditor::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor < 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void ImageEditor::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

///

void ImageEditor::lineExt()
{
    curImg->lineExt(minX, minY, maxX, maxY);
    imageLabel->setPixmap(QPixmap::fromImage(curImg->getImage()));
}

void ImageEditor::channelExt()
{
    curImg->channelExt(minX, minY, maxX, maxY);
    imageLabel->setPixmap(QPixmap::fromImage(curImg->getImage()));
}

void ImageEditor::gauss()
{
    curImg->gauss(minX, minY, maxX, maxY);
    imageLabel->setPixmap(QPixmap::fromImage(curImg->getImage()));
}

void ImageEditor::sharpening()
{
    curImg->sharpening(minX, minY, maxX, maxY);
    imageLabel->setPixmap(QPixmap::fromImage(curImg->getImage()));
}

void ImageEditor::grayWorld()
{
    curImg->grayWorld(minX, minY, maxX, maxY);
    imageLabel->setPixmap(QPixmap::fromImage(curImg->getImage()));
}

void ImageEditor::median()
{
    curImg->median(minX, minY, maxX, maxY);
    imageLabel->setPixmap(QPixmap::fromImage(curImg->getImage()));
}

void ImageEditor::sepGauss()
{
    curImg->sepGauss(minX, minY, maxX, maxY);
    imageLabel->setPixmap(QPixmap::fromImage(curImg->getImage()));
}

void ImageEditor::waves()
{
    curImg->waves(minX, minY, maxX, maxY);
    imageLabel->setPixmap(QPixmap::fromImage(curImg->getImage()));
}

void ImageEditor::glass()
{
    curImg->glass(minX, minY, maxX, maxY);
    imageLabel->setPixmap(QPixmap::fromImage(curImg->getImage()));
}
