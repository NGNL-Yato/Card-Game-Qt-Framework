#include <QObject>
#include <random>
#include "Deckk.h"
#include <QDebug>

Deckk::Deckk(){
    for(int i = 1;i < 40;i++){
        Deck_cards.push_back(i);
    }
    DeckBackward = new QImage("C:/Users/Setup game/Desktop/projet final/CardGame/Assets/BackCard.png");
    *DeckBackward = DeckBackward->scaledToWidth(100);

}

Deckk::~Deckk(){}
void Deckk::shuffle(){
    std::random_device rd;
    std::mt19937 g(rd()); //random default seed to generate random number
    std::shuffle(Deck_cards.begin(), Deck_cards.end(), g);
    //qDebug () << Deck_cards;
}
bool Deckk::isEmpty(){
    //qDebug()<<"im empty " << Deck_cards.empty();
    return Deck_cards.empty();
}

void Deckk::PushBack(int value){
    Deck_cards.push_back(value);
}

int Deckk::drawcard(){
    if(!isEmpty()){
        //qDebug()<<" i have inside the list "<<Deck_cards;
        return Deck_cards.takeLast();
    } else {
        return -1;
    }
}
QImage* Deckk::getImgDeck () {
    return DeckBackward;
}


