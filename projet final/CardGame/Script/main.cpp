#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QWidget>
#include <QMainWindow>
#include "Uiscene.h"
#include <QObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uiscene ui;
    return a.exec();
}
