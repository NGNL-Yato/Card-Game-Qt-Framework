#ifndef LOGICOFGAME_H
#define LOGICOFGAME_H
#include <QObject>
#include <QString>
#include "Deckk.h"
#include "Player.h"
#include "Npc.h"
#include "Field.h"

class GameLogic : public QObject {
    Q_OBJECT
public:
    GameLogic(Deckk& deck,Player& player1,npc& player2, field& Field);
    ~GameLogic();
    bool getWinner();
    void StartingGame ();
    int CheckingCardEffect (int card);
    int getChangingCardSuitvalue () ;
    int setChangingCardSuitvalue (int value) ;
    void testing();
    void ChangingCurrentSuit ();
    bool setinsindesuitvalue ();
    bool getinsindesuitvalue ();
    bool getClickable ();
    bool setClickable ();
    bool getPlayingtheGame ();

private:
    int givingcards ;
    field* tapis;
    Deckk* deck;
    int rank;
    Player* player1;
    npc* player2;
    bool Win;
    int changingcardtype;
    bool insidethesuitschange;
    bool Clickable;
    bool PlayingtheGame;

signals:
    void cardDrawnplayer1();
    void cardDrawnplayer2();
    void tapisdraw ();
    void startingGameFinished();
    void startPlayer1Turn();
    void player2droppingcard();
    void GoingBackToNormal ();
    void HideAllButtons ();
    void NpcChangingsuit ();

};


#endif // LOGICOFGAME_H
