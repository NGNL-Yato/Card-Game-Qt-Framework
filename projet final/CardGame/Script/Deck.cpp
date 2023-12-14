#include "Deck.h"
#include <assert.h>
#include <QGroupBox>
#include "Cardplayed.h"

Deck::Deck(int deckk) {
    Currentdeck = deckk;
    for (int i=0; i<SizeOfDeck; i++)
        Card_Img[i] = nullptr;
    EmptyCard_Img = new QImage(":/CardGame/Assets/Default_Img_Card.jpg", "JPG");
    YourTurn_Img = new QImage(":/CardGame/Assets/Hovered_card.png", "PNG");
    Card_box = new QImage(":/CardGame/Assets/Card_box.png","PNG");
    BackCard_Img = new QImage(":/CardGame/Assets/BackCard.png","PNG");
    card_played = new Cardplayed(this);
}

Deck::~Deck()
{
    delete EmptyCard_Img;
    delete YourTurn_Img;
}

QImage* Deck::GetCurrentImgCard(int cardd) {
    switch (cardd) {
    case empty:     return EmptyCard_Img;
    case Hidden_card: return BackCard_Img;
    case My_Turn: return YourTurn_Img;

    default:assert((cardd >= 0) && (cardd < SizeOfDeck));
            return Card_Img[cardd];
    }
}
void Deck::set_deck() {
    Card_Img[0] = new QImage(":/CardGame/Assets/1.jpeg", "JPEG");
    Card_Img[1] = new QImage(":/CardGame/Assets/2.jpg", "JPG");
    Card_Img[2] = new QImage(":/CardGame/Assets/3.jpg", "JPG");
    Card_Img[3] = new QImage(":/CardGame/Assets/4.jpg", "JPG");
    Card_Img[4] = new QImage(":/CardGame/Assets/5.jpg", "JPG");
    Card_Img[5] = new QImage(":/CardGame/Assets/6.jpg", "JPG");
    Card_Img[6] = new QImage(":/CardGame/Assets/7.jpg", "JPG");
    Card_Img[7] = new QImage(":/CardGame/Assets/8.jpg", "JPG");
    Card_Img[8] = new QImage(":/CardGame/Assets/9.jpg", "JPG");
    Card_Img[9] = new QImage(":/CardGame/Assets/10.jpg", "JPG");
    Card_Img[10] = new QImage(":/CardGame/Assets/11.jpg", "JPG");
    Card_Img[11] = new QImage(":/CardGame/Assets/12.jpg", "JPG");
    Card_Img[12] = new QImage(":/CardGame/Assets/13.jpeg", "JPG");
    Card_Img[13] = new QImage(":/CardGame/Assets/14.jpg", "JPG");
    Card_Img[14] = new QImage(":/CardGame/Assets/15.jpg", "JPG");
    Card_Img[15] = new QImage(":/CardGame/Assets/16.jpg", "JPG");
    Card_Img[16] = new QImage(":/CardGame/Assets/17.jpg", "JPG");
    Card_Img[17] = new QImage(":/CardGame/Assets/18.jpg", "JPG");
    Card_Img[18] = new QImage(":/CardGame/Assets/19.jpg", "JPG");
    Card_Img[19] = new QImage(":/CardGame/Assets/20.jpg", "JPG");
    Card_Img[20] = new QImage(":/CardGame/Assets/21.jpg", "JPEG");
    Card_Img[21] = new QImage(":/CardGame/Assets/22.jpg", "JPG");
    Card_Img[22] = new QImage(":/CardGame/Assets/23.jpeg", "JPG");
    Card_Img[23] = new QImage(":/CardGame/Assets/24.jpg", "JPG");
    Card_Img[24] = new QImage(":/CardGame/Assets/25.jpg", "JPG");
    Card_Img[25] = new QImage(":/CardGame/Assets/26.jpg", "JPG");
    Card_Img[26] = new QImage(":/CardGame/Assets/27.jpg", "JPG");
    Card_Img[27] = new QImage(":/CardGame/Assets/28.jpg", "JPG");
    Card_Img[28] = new QImage(":/CardGame/Assets/29.jpg", "JPG");
    Card_Img[29] = new QImage(":/CardGame/Assets/30.jpg", "JPG");
    Card_Img[30] = new QImage(":/CardGame/Assets/31.jpg", "JPEG");
    Card_Img[31] = new QImage(":/CardGame/Assets/32.jpg", "JPG");
    Card_Img[32] = new QImage(":/CardGame/Assets/33.jpeg", "JPG");
    Card_Img[33] = new QImage(":/CardGame/Assets/34.jpg", "JPG");
    Card_Img[34] = new QImage(":/CardGame/Assets/35.jpg", "JPG");
    Card_Img[35] = new QImage(":/CardGame/Assets/36.jpg", "JPG");
    Card_Img[36] = new QImage(":/CardGame/Assets/37.jpg", "JPG");
    Card_Img[37] = new QImage(":/CardGame/Assets/38.jpg", "JPG");
    Card_Img[38] = new QImage(":/CardGame/Assets/39.jpg", "JPG");
    Card_Img[39] = new QImage(":/CardGame/Assets/40.jpg", "JPG");

}

void Deck::SetplayedCard(int cardd) {
    card_played->play(cardd);
}

void Deck::ResetplayedCard() {
    card_played->reset();
}

