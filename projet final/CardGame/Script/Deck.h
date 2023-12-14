#ifndef DECK_H
#define DECK_H
#include <QGraphicsRectItem>
#include <QImage>
#include "LogicOfgame.h"

class Cardplayed;

class Deck {
public:

private:
    int Currentdeck;
    QImage* Card_Img[SizeOfDeck];
    QImage* EmptyCard_Img;
    QImage* BackCard_Img;
    QImage* YourTurn_Img;
    QImage* Card_box;
    Cardplayed* card_played;

public:
    Deck (int cardd);
    ~Deck ();
    void set_of_all_cards ();

public :
    QImage* GetCurrentImgCard (int cardd);
    void reverse_card (int cardd);
    void set_deck ();
    void DelCurrentDeck ();
    void SetplayedCard (int cardd);
    void ResetplayedCard ();
};

#endif // DECK_H
