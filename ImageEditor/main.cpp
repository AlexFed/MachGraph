#include <QApplication>

#include "imageeditor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ImageEditor imageEditor;
    imageEditor.show();
    return app.exec();
}
