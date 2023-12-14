#include "LogicOfgame.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QTimer>
#include <QEventLoop>
#include <QEvent>
#include <QObject>
#include <QThread>

GameLogic::GameLogic (Deckk& deckk,Player& p1,npc& p2, field& Field) {
    deck = &deckk;
    tapis = &Field;
    player1 = &p1;
    player2 = &p2;
    qDebug () << "logic created ";
};

GameLogic::~GameLogic () {};

void GameLogic::testing () {
    emit startPlayer1Turn();
}


void GameLogic::startPlayer1Turn() {
    qDebug() << "------------------------------------";
    qDebug () << player1->GetCurrentCard();
    qDebug() << "player turn"<<player1->getTurn();
    qDebug() << "bot turn"<<player2->getTurn();
    qDebug() << "------------------------------------";
    if(player1->getTurn()){
        if (player1->GetCurrentCard() != -1){
            int selectedcard = player1->getSelectedCard() %10;
            qDebug()<<" i m checking card value "<< selectedcard;
            if (selectedcard == 1){
                qDebug() << "u should again";
                player1->setTurn();
            } else if (selectedcard == 2){
                qDebug()<<" your gonna take 2 ";
                QTimer::singleShot(300, this, [&]() {
                    emit cardDrawnplayer2 ();
                    emit cardDrawnplayer2 ();
                });
                player1->setTurn();
                player2->setTurn();
            } else if (selectedcard == 7) {
                qDebug () << " u can choose the suit ";
            }

        } else {
            qDebug() << " u didnt chose a card yet ";
        }
    } else {
        if(player2->VerifyCards()){
            qDebug()<< " im gonna drop a card ";
            int selectedcard2 = player2->getSelectedCard() %10;
            qDebug()<<" i m checking card value "<< selectedcard2;
            if (selectedcard2 == 1){
                qDebug() << "u should again";
                emit player2droppingcard();
                player2->setTurn();
            } else if (selectedcard2 == 2){
                qDebug()<<" your gonna take 2 ";
                emit player2droppingcard();
                QTimer::singleShot(300, this, [&]() {
                    emit cardDrawnplayer1 ();
                    emit cardDrawnplayer1 ();
                });
                player1->setTurn();
                player2->setTurn();
            } else if (selectedcard2 == 7) {
                emit player2droppingcard();
                qDebug () << " u can choose the suit ";
            }
        } else {
        player1->setTurn();
        player2->setTurn();
        emit cardDrawnplayer2();
        }
    }
}
void GameLogic::StartingGame () {
    qDebug () << " im gonna give cards rn ";
    givingcards = 0;
    QTimer::singleShot(300, this, [=]() {
    while (givingcards < 4) {
        QEventLoop loop;
        QTimer::singleShot(300 * givingcards, this, [&]() {
            emit cardDrawnplayer1();
            qDebug () << " --------------------------------------";
            loop.quit();
        });
        loop.exec();
        QTimer::singleShot(300 * (givingcards + 1), this, [&]() {
            qDebug () << " --------------------------------------";
            emit cardDrawnplayer2();
            loop.quit();
        });
       loop.exec();
       ++givingcards;
    }
    emit tapisdraw ();
    emit startingGameFinished();
    });

}
void GameLogic::startTesting() {
    qDebug () << "up up starting the game logic here ";
    testing();
}
int GameLogic::CheckingCardEffect (int card){
    if (card == 1){
        qDebug () << "I'm skipping ur turn.";
        return 1;
    } else if (card == 2){
        qDebug () << " Hz 2.";
        return 2;
    } else if (card == 7){
        qDebug () << "Chnou 7akm";
        return 7;
    }   else return 0;
}


