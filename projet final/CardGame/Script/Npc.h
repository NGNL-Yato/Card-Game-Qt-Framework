#ifndef NPC_H
#define NPC_H

#include <QgraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QMediaPlayer>
#include <QVector>
#include "Deckk.h"
#include "QVBoxLayout"
#include "Field.h"

class npc {

public:
    npc();
    npc(Deckk* deckk,field* Field, int difficulty);
    ~npc();
    int Updatescore(bool Win);
    QVBoxLayout* Drawcard();
    int getCurrentScore();
    int getSelectedCard();
    bool setTurn();
    void DropCard ();
    int getHandCardsize ();
    QVBoxLayout* ShowCardImg ();
    bool getTurn ();
    bool VerifyCards ();
    bool VerifyCards (int cardd);
    int PlayingCard();
    int Choosingthenewsuit ();
    QList<int> getHandCards ();
    bool isEmpty ();
    int CheckingAllCards();
private:
    int score;
    QList<int> CardsInHand;
    int SelectedCard;
    Deckk* deck;
    QLabel* CardLabel;
    QHBoxLayout* CardBox;
    bool Turn;
    field* Field;
    int indexofCardtoplay;
    int HigherCardSuitsnbr;
    int Difficulty_Tier;
};


#endif // NPC_H
