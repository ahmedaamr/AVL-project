#include "widget.h"
#include <QApplication>
#include"AVL.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
     AVL y;
     QGraphicsScene scene;
     QGraphicsView view(&scene);

     view.setRenderHints(QPainter::SmoothPixmapTransform);

     y.init(&scene, &view);
    Widget w(y);
    w.show();

    return a.exec();
}
