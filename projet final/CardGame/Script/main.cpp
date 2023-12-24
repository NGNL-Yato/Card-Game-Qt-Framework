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
#include <QIcon>
#include <QStandardPaths>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug () << "launching the game ...";
    QString GameFolderPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    qDebug () << GameFolderPath;
    QString LogoPath = GameFolderPath + "/CardGameQt/Assets/Logo.png";
    QIcon icon(LogoPath);
    QPixmap pixmap=icon.pixmap(QSize(64,64));
    a.setWindowIcon(QIcon(pixmap));
    uiscene ui;
    return a.exec();
}
