#ifndef PLAYER_H
#define PLAYER_H

#include <QgraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QMediaPlayer>
#include <QList>
#include "Deckk.h"
#include "QVBoxLayout"
#include "Field.h"

class Player : public QObject {

    Q_OBJECT

public:
    Player();
    Player(Deckk* deckk,field* Field);
    ~Player();
    int Updatescore();
    QVBoxLayout* Drawcard();
    int getCurrentScore();
    int getSelectedCard();
    bool getWin ();
    bool setWin ();
    bool setTurn ();
    QVBoxLayout* ShowCardImg (int cardnbr);
    void DropCard();
    bool eventFilter(QObject *object, QEvent *event);
    bool installedEventFilter = false;
    int getHandCardsize ();
    QList<int> getHandElements();
    bool getTurn();
    bool VerifyCards (int card);
    int SetSelectedCard (int card);
    int GetCurrentCard();
    int GetCurrentSuit ();
    bool setGamestarted ();
    bool getGamestarted ();
    bool isEmpty ();

private:
    int compteur;
    int score;
    QList<int> CardsInHand;
    int SelectedCard;
    Deckk* deck;
    field* Field;
    QLabel* CardLabel;
    QHBoxLayout* CardBox;
    bool Turn;
    QVBoxLayout* Cardzone;
    int cardindex;
    bool Usablecard;
    int clickedcard = -1;
    bool Gamestarted = false ;
    bool Win = false ;

signals:
    void CurrentCard (int SelectedCard);
    void myturn ();

};



#endif // PLAYER_H
