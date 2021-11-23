#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsPixmapItem item(QPixmap("c:/1.jpg"));
    scene.addItem(&item);
    view.resize( 160, 90 );*/

    Widget view;
    view.show();

    return a.exec();
}
