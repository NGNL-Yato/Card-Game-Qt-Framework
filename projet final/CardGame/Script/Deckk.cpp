#include <QObject>
#include <random>
#include "Deckk.h"
#include <QDebug>
#include <QAudioOutput>
#include <QMediaPlayer>

Deckk::Deckk(){
    for(int i = 1;i <= 40;i++){
        Deck_cards.push_back(i);
    }
    DeckBackward = new QImage("../Assets/BackCard.png");
    *DeckBackward = DeckBackward->scaledToWidth(100);

}
Deckk::~Deckk(){}
void Deckk::shuffle(){
    std::random_device rd;
    std::mt19937 g(rd()); //random default seed to generate random number
    std::shuffle(Deck_cards.begin(), Deck_cards.end(), g);
    //qDebug () << Deck_cards;
    QMediaPlayer* CardShuffle = new QMediaPlayer;
    CardShuffle->setSource(QUrl::fromLocalFile("../Assets/Shuffle.mp3"));
    QAudioOutput* CardShuffleSound = new QAudioOutput;
    CardShuffleSound->setVolume (0.6);
    CardShuffle->setAudioOutput(CardShuffleSound);
    CardShuffle->play();
}
bool Deckk::isEmpty(){
    //qDebug()<<"im empty " << Deck_cards.empty();
    return Deck_cards.empty();
}
void Deckk::PushBack(int value){
    Deck_cards.push_back(value);
}
int Deckk::drawcard(){
        //qDebug()<<" i have inside the list "<<Deck_cards;
        return Deck_cards.takeLast();
}
QImage* Deckk::getImgDeck () {
    return DeckBackward;
}
QVector<int> Deckk::getDeckCards(){
    return Deck_cards;
}
