#include "mainwindow.h"
#include<QDebug>

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    player1Name = new QLabel("Player 1",this);
    player2Name = new QLabel("Player 2",this);
    newGame = new QPushButton("Start new game",this);
    gameBoard = new QWidget(this);
    QWidget* mainArea = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(mainArea);
    this -> setCentralWidget(mainArea);
    layout -> addWidget(newGame);
    layout -> addWidget(player1Name);
    layout -> addWidget(gameBoard);
    layout -> addWidget(player2Name);
    /* We first added a plain widget that will be the game central area, then set a layout
for that widget (vertical alignment), then we specify that mainArea widget will be
the main window central area using main window inherited function
setCentralWidget ("this->" is the same as "mainwindow::", specifies the current class). */

    connect(newGame,&QPushButton::clicked,this,&mainwindow::StartnewGame);
    /* Method to make the button clickable and call it */

}
void mainwindow::StartnewGame(){
    {
        qDebug() << "Clicked!";
        /* qDebug() << ... is a convenient way to print debug information to the stderr
(standard error output) of the application process. It's quite similar to the
std::cerr << ... method available in the standard library, but it separates
supplied values with spaces and appends a new line at the end. */
        player1Name -> setText(tr("Alice"));
        player2Name -> setText(tr("Bob"));
        qDebug() << "I created new players";
        /* We're calling the setText method of the QLabel class. This is the setter of the
text property of QLabel.*/
    }

}

mainwindow::~mainwindow()
{

}

