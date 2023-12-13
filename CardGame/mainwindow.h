#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();
private slots:
    void StartnewGame();
private:
    QLabel* player1Name;
//Calls the first player in the window
    QLabel* player2Name;
//Calls the second player in the window
    QPushButton* newGame;
//Create the new game
    QWidget* gameBoard;
//mainboard of the game
};
#endif // MAINWINDOW_H
