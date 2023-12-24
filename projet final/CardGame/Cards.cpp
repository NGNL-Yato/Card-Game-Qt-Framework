#include"Cards.h"

Cards::Cards(int deck):Current_Card(deck){

    for (int SizeOfDeck=0; i<SizeOfDeck; SizeOfDeck++)
        Card_Img[SizeOfDeck] = nullptr;

    img_empty_card = new QImage("", "PNG");
    img_your_turn = new QImage("", "PNG");


    default: set_standard_deck();

}
