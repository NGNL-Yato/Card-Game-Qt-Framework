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
void GameLogic::startPlayer1Turn() {
    qDebug () << " I'm  verifying your card ... Normal Logic";
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
                    this->Clickable = true;
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
                    QTimer::singleShot(1000, this, [&]() {
                    qDebug() << " (NPC) u will play again";
                    emit player2droppingcard();
                    });
                } else if (selectedcard2 == 2){
                    qDebug()<<" (NPC) your gonna take 2";
                    QTimer::singleShot(1000, this, [&]() {
                        emit cardDrawnplayer1 ();
                        QTimer::singleShot(1000, this, [=]() {
                        emit cardDrawnplayer1 ();
                        });
                        emit player2droppingcard();
                    });
                } else if (selectedcard2 == 7) {
                    QTimer::singleShot(1000, this, [&]() {
                    emit player2droppingcard();
                    });
                    qDebug () << " (NPC) u can choose the suit ";
                    emit NpcChangingsuit();
                } else {
                    QTimer::singleShot(1000, this, [&]() {
                        emit player2droppingcard();
                    });
                }
            } else {
                player1->setTurn();
                QTimer::singleShot(1000, this, [=]() {
                    emit cardDrawnplayer2();
                });
            }
        }
    } else {
        qDebug () <<" Salat carta mn idik .";
    }
}
void GameLogic::ChangingCurrentSuit () {
    this->Clickable = false ;
    qDebug () << " Starting the value check for new suit ...";
    qDebug () << "Current should be  : "<< getChangingCardSuitvalue();
    tapis->RefillEmptyDeck(*deck);
    if (!player1->isEmpty()){
        if(player1->getTurn()){
            if (player1->GetCurrentCard () != -1){
                if((player1->GetCurrentSuit() == getChangingCardSuitvalue())||(player1->GetCurrentCard()%10 == 7)){
                    qDebug () << "Valid Card.";
                    emit HideAllButtons ();
                    emit GoingBackToNormal ();
                }
            } else {
                qDebug () << "You don't have a card yet.";
            }
        } else if (player2->VerifyCards (getChangingCardSuitvalue())) {
            qDebug () << "(NPC) Valid card, game will continue";
            emit HideAllButtons ();
            if (player2->getSelectedCard()%10 == 7){
                QTimer::singleShot(300, this, [&]() {
                    emit player2droppingcard ();
                    QTimer::singleShot(300, this, [&]() {
                        emit NpcChangingsuit ();
                    });
                });

            } else if (player2->getSelectedCard()%10 == 2){
                if(!player2->isEmpty()){
                    QTimer::singleShot(300, this, [&]() {
                        emit cardDrawnplayer1 ();
                    });
                    QTimer::singleShot(300, this, [=]() {
                        emit cardDrawnplayer1 ();
                    });
                    QTimer::singleShot(300, this, [=]() {
                        emit player2droppingcard();
                    });
                }
            } else if (player2->getSelectedCard()%10 == 1){
                QTimer::singleShot(300, this, [&]() {
                    qDebug() << " (NPC) u will play again";
                    emit player2droppingcard();
                });
            } else {
                qDebug () << "(NPC) I dont have any special card.";
                QTimer::singleShot(300, this, [&]() {
               emit player2droppingcard ();
               emit GoingBackToNormal ();
               });
            }
        } else {
            qDebug () << "Player 2 will take a card from the deck (No card og this type).";
            QTimer::singleShot(300, this, [&]() {
            emit cardDrawnplayer2 ();
            });
            player1->setTurn ();
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
    this->PlayingtheGame = false;
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
        this->PlayingtheGame = true;
        player1->setGamestarted();
        qDebug () <<" Deck contains : " << deck->getDeckCards().size();
    });
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
bool GameLogic::getClickable (){
    return this->Clickable;
}
bool GameLogic::setClickable (){
    return Clickable = !Clickable;
}
bool GameLogic::getPlayingtheGame () {
    return this->PlayingtheGame;
}

int GameLogic::getPlayer2Difficulty (int var) {
    return var;
}
