#include <QObject>
#include <random>
#include "Deckk.h"
#include <QDebug>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QRandomGenerator>
#include <QStandardPaths>

Deckk::Deckk(){
    for(int i = 1;i <= 40;i++){
        Deck_cards.push_back(i);
    }
    QString GameFolderPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    DeckBackward = new QImage(GameFolderPath + "/CardGameQt/Assets/Cards/BackCard.png");
    *DeckBackward = DeckBackward->scaledToWidth(100);

}
Deckk::~Deckk(){
    Deck_cards.clear();
    if(Deck_cards.isEmpty()){
        qDebug () << "Deck mab9ach ...";
    }
}
void Deckk::shuffle(){
    std::random_device rd;
    std::mt19937 g(rd()); //random default seed to generate random number
    std::shuffle(Deck_cards.begin(), Deck_cards.end(), g);
    qDebug () << Deck_cards.size();
    QMediaPlayer* CardShuffle = new QMediaPlayer;
    QString GameFolderPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    CardShuffle->setSource(QUrl::fromLocalFile(GameFolderPath + "/CardGameQt/Assets/Audio/Shuffle.mp3"));
    QAudioOutput* CardShuffleSound = new QAudioOutput;
    int Volume = GetVolume ();
    CardShuffleSound->setVolume (Volume);
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
int Deckk::drawSpecialcard () { //Special draw method for hard difficulty
    int SpecialCardsArray[] = {1, 2, 7};
    int arraySize = sizeof(SpecialCardsArray) / sizeof(SpecialCardsArray[0]);
    int Special = SpecialCardsArray[QRandomGenerator::global()->bounded(arraySize)];
    int WantedCard= 0;
    QVector<int>::Iterator It;
    for(It = Deck_cards.begin();It != Deck_cards.end() ; It++){
        int cardrank = *It%10;
        if(cardrank == Special) {
            WantedCard = *It;
            break;
        }
    }
    if (WantedCard != 0){
        int specialCard = *It;
        Deck_cards.erase(It);
        return specialCard;
    } else {
        return this->drawcard();
    }
}
QImage* Deckk::getImgDeck () {
    return DeckBackward;
}
QVector<int> Deckk::getDeckCards(){
    return this->Deck_cards;
}
int Deckk::getDecksize (){
    return this->getDeckCards().size();
}
float Deckk::SetVolume (float Volume) {
    return Volume;
}
float Deckk::GetVolume () {
    return Volume;
}
