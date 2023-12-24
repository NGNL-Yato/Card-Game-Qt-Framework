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
    insidethesuitschange = false;
    Win = true;
    changingcardtype = -5;
}
GameLogic::~GameLogic () {}
void GameLogic::testing () {
    emit startPlayer1Turn();
}
void GameLogic::startPlayer1Turn() {
    qDebug () << " I'm  verifying your card ...";
    qDebug () << player1->getHandElements();
    qDebug () << player2->getHandCards();
    if(!player1->isEmpty() && !player2->isEmpty()){
        if(player1->getTurn()){
            if (player1->GetCurrentCard() != -1){
                int selectedcard = player1->GetCurrentCard() %10;
                qDebug()<<" i m checking card value "<< selectedcard;
                if (selectedcard == 1){
                    qDebug() << "u should again";
                } else if (selectedcard == 2){
                    qDebug()<<" your gonna take 2 ";
                    QTimer::singleShot(300, this, [&]() {
                        emit cardDrawnplayer2 ();
                        QTimer::singleShot(300, this, [=]() {
                        emit cardDrawnplayer2 ();
                        });
                    });
                } else if (selectedcard == 7) {
                    qDebug () << " u can choose the suit ";
                    setChangingCardSuitvalue(player1->GetCurrentSuit());
                    qDebug () << getChangingCardSuitvalue();
                }

            } else {
                qDebug() << " u didnt chose a card yet ";
            }
        } else {
            if(player2->VerifyCards()){
                qDebug()<< " (NPC) im gonna drop a card ";
                int selectedcard2 = player2->getSelectedCard() %10;
                qDebug()<<" (NPC) i m checking card value "<< selectedcard2;
                if (selectedcard2 == 1){
                    QTimer::singleShot(300, this, [&]() {
                    qDebug() << " (NPC) u will play again";
                    emit player2droppingcard();
                    });
                } else if (selectedcard2 == 2){
                    qDebug()<<" (NPC) your gonna take 2";
                    QTimer::singleShot(300, this, [&]() {
                        emit cardDrawnplayer1 ();
                        QTimer::singleShot(300, this, [=]() {
                        emit cardDrawnplayer1 ();
                        });
                        emit player2droppingcard();
                    });
                } else if (selectedcard2 == 7) {
                    QTimer::singleShot(300, this, [&]() {
                    emit player2droppingcard();
                    });
                    qDebug () << " (NPC) u can choose the suit ";
                    //player1->setTurn ();
                    emit NpcChangingsuit();
                } else {
                    QTimer::singleShot(300, this, [&]() {
                        emit player2droppingcard();
                    });
                }
            } else {
            player1->setTurn();
            QTimer::singleShot(300, this, [&]() {
            emit cardDrawnplayer2();
            });
            }
        }
    } else {
        qDebug () <<" Salat carta mn idik .";
    }
}
void GameLogic::ChangingCurrentSuit () {
    qDebug () << " Starting the value check for new suit ...";
    qDebug () << "Current should be  : "<< getChangingCardSuitvalue();
    if (!player1->isEmpty()){
        if(player1->getTurn()){
            if (player1->GetCurrentCard () != -1){
                if(player1->GetCurrentSuit() == getChangingCardSuitvalue()){
                    qDebug () << "Valid Card.";
                    player1->setTurn ();
                    emit HideAllButtons ();
                    emit GoingBackToNormal ();
                }
            } else {
                qDebug () << "You don't have a card yet.";
            }
        } else if (player2->VerifyCards (getChangingCardSuitvalue())) {
            qDebug () << "(NPC) Valid card, game will continue";
            if (player2->getSelectedCard()%10 == 7){
                QTimer::singleShot(300, this, [&]() {
                emit player2droppingcard ();
                emit NpcChangingsuit ();
                });
            } else if (player2->getSelectedCard()%10 == 2){
                QTimer::singleShot(300, this, [&]() {
                    emit cardDrawnplayer1 ();
                    QTimer::singleShot(300, this, [=]() {
                        emit cardDrawnplayer1 ();
                    });
                    emit player2droppingcard();
                });
            } else if (player2->getSelectedCard()%10 == 1){
                QTimer::singleShot(300, this, [&]() {
                    qDebug() << " (NPC) u will play again";
                    emit player2droppingcard();
                });
            } else {
                qDebug () << "(NPC) I dont have any special card.";
               emit HideAllButtons ();
                QTimer::singleShot(300, this, [&]() {
               emit player2droppingcard ();
               emit GoingBackToNormal ();
               });
            }
        } else {
            qDebug () << "Player 2 will take a card from the deck .";
            player1->setTurn ();
            QTimer::singleShot(300, this, [&]() {
            emit cardDrawnplayer2 ();
                QTimer::singleShot(300, this, [=]() {
                    emit cardDrawnplayer2 ();
                });
            });
            emit GoingBackToNormal ();
        }
    } else {
        qDebug () <<" Salat carta mn idik .";
    }
}
int GameLogic::getChangingCardSuitvalue () {
    return changingcardtype;
}
int GameLogic::setChangingCardSuitvalue (int value) {
    changingcardtype = value;
    return changingcardtype;
}
void GameLogic::StartingGame () {
    qDebug () << " im gonna give cards rn ";
    qDebug () <<" Deck contains : " << deck->getDeckCards().size();
    givingcards = 0;
    QTimer::singleShot(300, this, [=]() {
    while (givingcards < 4) {
        QEventLoop loop;
        QTimer::singleShot(300 * givingcards, this, [&]() {
            emit cardDrawnplayer1();
            qDebug () << " --------------------------------------";
            qDebug () <<" Deck contains : " << deck->getDeckCards().size();
            loop.quit();
        });
        loop.exec();
        QTimer::singleShot(300 * (givingcards + 1), this, [&]() {
            qDebug () << " --------------------------------------";
            emit cardDrawnplayer2();
            qDebug () <<" Deck contains : " << deck->getDeckCards().size();
            loop.quit();
        });
       loop.exec();
       ++givingcards;
    }
    QTimer::singleShot(300, this, [&]() {
    emit tapisdraw ();
    });
    player1->setGamestarted();
    qDebug () <<" Deck contains : " << deck->getDeckCards().size();
    });

}
void GameLogic::startTesting() {
    qDebug () << "up up starting the game logic here ";
    testing ();
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
bool GameLogic::setinsindesuitvalue (){
    return insidethesuitschange = !insidethesuitschange;
}
bool GameLogic::getinsindesuitvalue () {
    return insidethesuitschange;
}

