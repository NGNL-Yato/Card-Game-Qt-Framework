#include "Field.h"
#include <QString>
#include "Deckk.h"
#include <QVector>
#include <qDebug>
#include <QStandardPaths>
field::field (Deckk& deck) : FieldDeck(& deck){
    QString GameFolderPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    FieldCurrentImage = new QImage(GameFolderPath + "/Gamefolder/CardGameQt/Assets/Cards/Empty_card.png");
    *FieldCurrentImage = FieldCurrentImage->scaledToWidth(100);
    qDebug() << FieldCards;
}
QImage* field::getImgField() {
    return FieldCurrentImage;
}
field::~field () {
    delete FieldCurrentImage;
    FieldCurrentImage = nullptr;
    /*for (auto It = FieldCards->begin (); It != FieldCards->end (); ++It){
        delete It;
    }*/
    if (FieldCards->isEmpty()){
        qDebug () << "Rah mss7t koulchi ...";
    }
    FieldCards->clear();
}
int field::getCurrentCard(){
    return *FieldCards->begin();
}
QImage* field::ShowCardImg () {
    if(!EmptyField() && FieldCurrentImage != nullptr){
        int CurrentCard = getCurrentCard();
        QString GameFolderPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        const QString CurrentcardImg = QString (GameFolderPath + "/Gamefolder/CardGameQt/Assets/Cards/%1.jpg").arg(CurrentCard);
        //qDebug () << " I show the image inside the field ";
        FieldCurrentImage = new QImage(CurrentcardImg);
        *FieldCurrentImage = FieldCurrentImage->scaledToWidth(100);
        //qDebug() << " i Change the card image ";
        return FieldCurrentImage;
    } else {
        return nullptr;
    }
}
QVector<int> field::getFieldcards () {
    return *FieldCards;
}
void field::RefillEmptyDeck(Deckk& deck){
    if( deck.getDecksize() < 3)
    {
        qDebug () << "Refilling the deck ... ";
        auto start = std::next(FieldCards->begin());
        do{
            int temp = *start;
            deck.PushBack(temp);
            start = FieldCards->erase(start);
        }while( start != FieldCards->end());
        qDebug () <<"Temp deck : " << deck.getDeckCards();
        deck.shuffle();
    }  else {
        qDebug()<<"Current Deck is not empty yet.";
    }
}
bool field::EmptyField () {
    return FieldCards->empty();
}
void field::TakeCard (int cardnumber) {
    if(!FieldCards->contains(cardnumber) ){
        qDebug() << "------------------------------------";
        //qDebug () << "Im pushing cards inside the field";
        FieldCards->push_front(cardnumber);
        qDebug ()<<"Field contains : "<< *FieldCards;
    } else {
        qDebug () << "Value already pushed inside on the Field";
    }
}
int field::getcardsuit (){
    int currentcardsuit = getCurrentCard();
    qDebug () << getCurrentCard();
    if(currentcardsuit >= 1 && currentcardsuit <= 10){
        return 0;
    } else if(currentcardsuit >= 11 && currentcardsuit <= 20){
        return 1;
    } else if(currentcardsuit >= 21 && currentcardsuit <= 30){
        return 2;
    } else if(currentcardsuit >= 31 && currentcardsuit <= 40){
        return 3;
    } else {
        qDebug () << "Tbuggat hna ";
        return -1;
    }
};
int field::getcardrank () {
    int currentcardrank = getCurrentCard() % 10;
    return currentcardrank;
};
int field::DrawCard (Deckk& deck) {
    int cardnumber = deck.drawcard();
    int forbiddencards[12] = {1, 2, 7, 11, 12, 17, 21, 22, 27, 31, 32, 37};
    while (true) {
        bool isForbidden = false;
        for (int i = 0; i < 12; i++) {
            if (cardnumber == forbiddencards[i]) {
                isForbidden = true;
                qDebug() << "Forbidden card drawn: " << forbiddencards[i];
                break;
            }
        }
        if (isForbidden) {
            cardnumber = deck.drawcard();
        } else {
            FieldCards->push_back(cardnumber);
            qDebug() << "The Field contains : " << cardnumber;
            return cardnumber;
        }
    }
    qDebug () << "Something is wrong go back to the field to check the error.";
    return -1;
}
