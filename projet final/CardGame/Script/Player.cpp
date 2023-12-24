#include "Player.h"
#include <QFile>
#include <QEvent>
#include <QMouseEvent>

Player::Player(){}
Player::Player (Deckk* deckk, field* Fieldd) : deck(deckk), Field (Fieldd) {
    score = 0;
    Turn = false;
    SelectedCard = -1;
}

Player::~Player () {};

bool Player::setTurn () {
    if(Turn){
        Turn = false;
        qDebug() << " tpassa tour dialk ";
        return Turn;
    } else {
        Turn =true;
        qDebug() << " tour dialk ";
        emit myturn ();
        return Turn;
    }
}

int Player::getCurrentScore () {
    return score;
}

bool Player::getWin () {
    return Win;
}
bool Player::setWin () {
    return Win = !Win;
}
int Player::Updatescore () {
    if(Win){
        qDebug() << "Rb7ti ";
        return score++;
    } else {
        return -1;
    }
}

QVBoxLayout* Player::ShowCardImg (int cardnumber) {
    SelectedCard = cardnumber;
    QString CurrentcardImg = QString("C:/Users/Setup game/Desktop/projet final/CardGame/Assets/%1.jpg").arg(cardnumber);
    QFile file(CurrentcardImg);
    if (!file.exists()) {
        qDebug() << "File not found: " << CurrentcardImg;
    }
    QImage* CardImg = new QImage(CurrentcardImg);
    if (CardImg->isNull()) {
        qDebug() << "Failed to load image: " << CurrentcardImg;
        delete CardImg; // Delete the image if loading failed
        return nullptr; // Return nullptr or handle the error appropriately
    }
    CardLabel = new QLabel;
    CardLabel->setPixmap(QPixmap::fromImage(CardImg->scaledToHeight(140)));
    CardLabel->setFixedSize(110, 170);
    CardLabel->setProperty("cardNumber", cardnumber);
    Cardzone = new QVBoxLayout;
    Cardzone->addWidget(CardLabel);
    CardLabel->installEventFilter(this);
    return Cardzone;
}

QVBoxLayout* Player::Drawcard () {
    int cardnumber = deck->drawcard();
    qDebug()<<"--------------------------------------------------------------------";
    qDebug()<<"i have in hand  :"<<CardsInHand;
    if (!deck->isEmpty()){
        qDebug()<<"i have picked :"<<cardnumber;
        CardsInHand.push_back(cardnumber);
        QVBoxLayout* card = ShowCardImg(cardnumber);
        return card;
    }
    return nullptr;
}

int Player::getSelectedCard () {
    if (clickedcard != -1){
        return clickedcard;
    } else {
        qDebug() << "Rah carta 3ndha -1, go back to player cpp to check error";
        return 0;
    }
}

int Player::GetCurrentCard(){
    return clickedcard;
}
int Player::SetSelectedCard(int card){
    clickedcard=card;
    return clickedcard;
}

int Player::getHandCardsize () {
    return CardsInHand.size();
}
QList<int> Player::getHandElements() {
    return CardsInHand;
}
void Player::DropCard () {
    int Cardindex = CardsInHand.indexOf(SelectedCard);
    //qDebug() << " I will drop the card : "<<SelectedCard;
    //qDebug () <<"The size of card before deleting is :"<< CardsInHand.size();
    if (getSelectedCard()) {
        //qDebug () <<"The card index is :"<< Cardindex;
        CardsInHand.remove(Cardindex);
        Field->TakeCard(SelectedCard);
        SelectedCard = -1;
        qDebug() << " I still have " << CardsInHand.size() << " cards in my hand";
    } else {
        qDebug() << "My hand is empty now , I have no cards";
    }
    if(CardsInHand.length() == 0){
        qDebug () << " u won";
    } else {
        qDebug () << "mazal marb7ti, kml tr7";
    }
}

bool Player::VerifyCards (int card){
    if(CardsInHand.indexOf(card)!=0){
        qDebug () << "i have this card";
        return true;
    } else {
        qDebug () << "i dont have this card";
        return false;
    }
}

bool Player::getTurn () {
    return Turn;
}

bool Player::eventFilter(QObject* object, QEvent* event) {
    if (getTurn() && getGamestarted()){
        if (event->type() == QEvent::MouseButtonPress) {
            //qDebug() << "I clicked inside the card";
            if (object->inherits("QLabel")) {
                QLabel* label = qobject_cast<QLabel*>(object);
                if (label) {
                    SelectedCard = label->property("cardNumber").toInt();
                    qDebug() << "Card clicked: " << SelectedCard;
                    SetSelectedCard(SelectedCard);
                    emit CurrentCard(SelectedCard);
                    return true;
                }
            }
        }
        return QObject::eventFilter(object, event);
    } else {
        //qDebug () << "hada rah machi tour dialk daba sir ghyrha";
        return false;
    }
}

int Player::GetCurrentSuit (){
    if ((SelectedCard-1)/10 == 0){
        return 0;
    } else if ((SelectedCard-1)/10 == 1){
        return 1;
    } else if ((SelectedCard-1)/10 == 2){
        return 2;
    } else if ((SelectedCard-1)/10 == 3){
        return 3;
    } else {
        return -1;
    }
}



bool Player::setGamestarted () {
        return Gamestarted = !Gamestarted;
}

bool Player::getGamestarted () {
    return Gamestarted;
}
bool Player::isEmpty (){
    if (CardsInHand.empty()){
        return true;
    } else {
        return false;
    }
}
