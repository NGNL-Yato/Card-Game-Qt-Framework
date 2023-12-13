#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating the main scene
    QGraphicsScene* MainScene = new QGraphicsScene();

    //create a scene
    QGraphicsRectItem* Cards = new QGraphicsRectItem();
    Cards ->setRect(0,0,100,100);  // setRec(pos x, pos y, height , width) height and width in px

    QGraphicsRectItem* Packet = new QGraphicsRectItem();
    Packet ->setRect(0,0,100,100);

    QGraphicsRectItem* Player = new QGraphicsRectItem();
    Player ->setRect(0,0,100,100);

    //add the item to the scene
    MainScene -> addItem(Cards);
    MainScene -> addItem(Packet);
    MainScene ->  addItem(Player);
    MainScene -> addItem(Player);

    //add a viewscene
    QGraphicsView* ActualScene = new QGraphicsView(MainScene);
    ActualScene->show();


    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "CardGame_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    mainwindow w;
    w.show();
    return a.exec();
}
