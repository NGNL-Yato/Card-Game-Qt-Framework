#include"Cards.h"
#include <assert.h>
#include <QGroupBox>

Cards::Cards(int deckk) : Cardplayed(deckk){

    for (int i=0; i<SizeOfDeck; i++)
        Card_Img[SizeOfDeck] = nullptr;

    EmptyCard_Img = new QImage(":/CardGame/Assets/Default_Img_Card.jpg", "JPG");
    YourTurn_Img = new QImage(":/CardGame/Assets/Hovered_card.png", "PNG");
    Card_box = new QImage(":/CardGame/Assets/Card_box.png","PNG");
    BackCard_Img = new QImage(":/CardGame/Assets/BackCard.png","PNG");

}

