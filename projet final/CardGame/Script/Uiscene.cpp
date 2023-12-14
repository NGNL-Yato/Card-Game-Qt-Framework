#include "Uiscene.h"
#include <QGraphicsView>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include "Field.h"
#include "Deckk.h"
#include <QSlider>
#include <QAudioOutput>
#include "Player.h"
#include <QGraphicsRectItem>
#include <QEvent>
#include <QMouseEvent>
#include <LogicOfgame.h>
#include <QObject>

uiscene::uiscene() {
    entryscene = new QGraphicsScene();
    entryscene->setSceneRect(0, 0, 1280, 720);
    view = new QGraphicsView(entryscene);
    view->setFixedSize(1280, 720);
    QPixmap SceneBackground_Img("C:/Users/Setup game/Desktop/projet final/CardGame/Assets/Backgroundui.png");
    QGraphicsPixmapItem* backgroundImage = new QGraphicsPixmapItem(SceneBackground_Img);
    entryscene->addItem(backgroundImage);
    StartingGame = new QPushButton();
    StartingGame->setIcon(QIcon("C:/Users/Setup game/Desktop/projet final/CardGame/Assets/START.png"));
    StartingGame->setIconSize(QSize(500, 500));
    StartingGame->setFixedSize(500, 150);
    StartingGame->setStyleSheet("background-color: transparent;");
    StartingGame->move(385, 175);

    Settings = new QPushButton();
    Settings->setIcon(QIcon("C:/Users/Setup game/Desktop/projet final/CardGame/Assets/SETTINGS.png"));
    Settings->setIconSize(QSize(500, 500));
    Settings->setFixedSize(500, 150);
    Settings->setStyleSheet("background-color: transparent;");
    Settings->move(385, 300);

    Quit = new QPushButton();
    Quit->setIcon(QIcon("C:/Users/Setup game/Desktop/projet final/CardGame/Assets/QUIT.png"));
    Quit->setIconSize(QSize(500, 500));
    Quit->setFixedSize(500, 150);
    Quit->setStyleSheet("background-color: transparent;");
    Quit->move(385, 425);

    entryscene->addWidget(StartingGame);
    entryscene->addWidget(Quit);
    entryscene->addWidget(Settings);

    connect(StartingGame, &QPushButton::clicked, this, &uiscene::StartnewGame);
    connect(Quit, &QPushButton::clicked, this, &uiscene::QuitGame);
    connect(Settings, &QPushButton::clicked, this,&uiscene::ChangeSettings);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    playlist = new QMediaPlayer;
    playlist->setSource(QUrl::fromLocalFile("C:/Users/Setup game/Desktop/projet final/CardGame/Assets/audio2.m4a"));
    playlist->setLoops(QMediaPlayer::Infinite);
    QAudioOutput* audioOutput = new QAudioOutput;
    playlist->setAudioOutput(audioOutput);
    playlist->play();

    view->show();
}

uiscene::~uiscene() {}

void uiscene::StartnewGame() {
    view->close();
    createNewScene();
}


void uiscene::createNewScene() {
    QGraphicsScene* newScene = new QGraphicsScene();
    newScene->setSceneRect(0, 0, 1280, 720);
    QGraphicsView* newView = new QGraphicsView(newScene);
    newView->setFixedSize(1280, 720);
    qDebug()<<"I load the new game";
    QPixmap background("C:/Users/Setup game/Desktop/projet final/CardGame/Assets/BCK.jpg");
    QGraphicsPixmapItem* Backgroundimg = new QGraphicsPixmapItem(background);
    QPixmap pimg("C:/Users/Setup game/Desktop/projet final/CardGame/Assets/P1.png");
    QLabel * player1 = new QLabel;
    player1->setPixmap(pimg.scaled(100,100));
    int xPos = 100;
    int yPos = 550;
    player1->move(xPos, yPos);

    newScene->addItem(Backgroundimg);

    NewDeck.shuffle();
    NewDeck.getImgDeck();
    QImage* Deck_Img = NewDeck.getImgDeck();
    qDebug()<<Deck_Img;

    AI_player = new npc(&NewDeck,&Tapis);

    NPC_hand = new QHBoxLayout;

    QWidget* NPCLabel = new QWidget;
    NPCLabel->setLayout(NPC_hand);
    NPCLabel->setFixedWidth(700);
    NPCLabel->setFixedHeight(170);
    xPos = (newScene->width() - NPCLabel->width()) / 2;
    yPos = 0;
    NPCLabel->move(xPos, yPos);

    P1 = new Player(&NewDeck,&Tapis);


    Player_hand = new QHBoxLayout;
    QWidget* HandLabel = new QWidget;
    HandLabel->setLayout(Player_hand);
    HandLabel->setFixedWidth(650);
    HandLabel->setFixedHeight(170);
    xPos = (newScene->width() - HandLabel->width()) / 2;
    yPos = (newScene->height() - HandLabel->height());
    HandLabel->move(xPos, yPos);
    qDebug() << HandLabel->size();

    qDebug() << " i am here "<<P1->getTurn();

    connect(this, &uiscene::drawCardSignal, this, &uiscene::drawCardOnClick);
    connect(P1, &Player::CurrentCard, this, &uiscene::handleCardClick);

    QLabel* DeckLabel = new QLabel;
    DeckLabel->setFixedSize(Deck_Img->width(), Deck_Img->height());
    DeckLabel->setPixmap(QPixmap::fromImage(*Deck_Img));

    QVBoxLayout* Deckzone = new QVBoxLayout;
    Deckzone->addWidget(DeckLabel);

    LeftElement = new QWidget;
    LeftElement->setLayout(Deckzone);
    xPos = newScene->width() - (Deck_Img->width()*2.5);
    yPos = (newScene->height() - Deck_Img->height()) / 2 - 50;
    LeftElement->move(xPos, yPos);

    LeftElement->installEventFilter(this);

    QImage* EmptyField_img = Tapis.getImgField();
    qDebug()<<*EmptyField_img;

    Fieldlabel = new QLabel;
    Fieldlabel->setFixedSize(EmptyField_img->width(), EmptyField_img->height());
    Fieldlabel->setPixmap(QPixmap::fromImage(*EmptyField_img));

    QVBoxLayout* Fieldzone = new QVBoxLayout;
    Fieldzone->addWidget(Fieldlabel);

    QWidget* CenterElement = new QWidget;
    CenterElement->setLayout(Fieldzone);
    xPos = (newScene->width() - Fieldlabel->width()) / 2;
    yPos = (newScene->height() - Fieldlabel->height()) / 2;
    CenterElement->move(xPos, yPos);

    loadinggamelogic = new GameLogic(NewDeck,*P1,*AI_player,Tapis);

    connect(loadinggamelogic, &GameLogic::cardDrawnplayer1, this, &uiscene::CardDrawnPlayer);
    connect(loadinggamelogic, &GameLogic::cardDrawnplayer2, this, &uiscene::CardDrawnNpc);
    connect(loadinggamelogic, &GameLogic::tapisdraw,this, &uiscene::CardDrawnField);
    loadinggamelogic->StartingGame();
    connect(loadinggamelogic, &GameLogic::startingGameFinished, loadinggamelogic, &GameLogic::startTesting); // its here only to start the testing function after the cards are given

    connect (this,&uiscene::swappingturns,loadinggamelogic, &GameLogic::startPlayer1Turn);
    connect (loadinggamelogic, &GameLogic::player2droppingcard,this, &uiscene::NpcCardHandler);

    newScene->addWidget(NPCLabel);
    newScene->addWidget(player1);
    newScene->addWidget(HandLabel);
    newScene->addWidget(LeftElement);
    newScene->addWidget(CenterElement);
    newView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    newView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    newView->show();
}

void uiscene::CardDrawnField() {
    qDebug () << " i give card to the field";
    Tapis.DrawCard(&NewDeck);
    QImage* tempImg = Tapis.ShowCardImg();
    Fieldlabel->setFixedSize(tempImg->width(), tempImg->height());
    Fieldlabel->setPixmap(QPixmap::fromImage(*tempImg));
    P1->setTurn();
}

void uiscene::CardDrawnPlayer() {
    Tapis.RefillEmptyDeck(&NewDeck);
    qDebug () << " i give cards to myself ";
    QVBoxLayout* temp = P1->Drawcard();
    Player_hand->addLayout(temp);
    qDebug() << Player_hand;
}

void uiscene::CardDrawnNpc() {
    Tapis.RefillEmptyDeck(&NewDeck);
    qDebug () << " i give cards to npc ";
    QVBoxLayout* temp = AI_player->Drawcard();
    NPC_hand->addLayout(temp);
    qDebug() << Player_hand;
}

void uiscene::ChangeSettings(){
    qDebug()<<"I will change settings";
    Quit->hide();
    Settings->hide();
    StartingGame->hide();
    QSlider* volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0,10);
    volumeSlider->setValue(10);
    volumeSlider->move(385, 300);

    QPushButton* Backtomenu = new QPushButton();
    Backtomenu->setIcon(QIcon("C:/Users/Setup game/Desktop/projet final/CardGame/Assets/BEFORE.png"));
    Backtomenu->move(0,0);
    Backtomenu->setIconSize(QSize(200, 200));
    Backtomenu->setFixedSize(200, 200);
    Backtomenu->setStyleSheet("background-color: transparent;");
    entryscene->addWidget(volumeSlider);
    qDebug() << "Before connecting signal";
    if (volumeSlider) {
        connect(volumeSlider, &QSlider::valueChanged, this, [=](int volume) {
            qDebug() << "Volume changed:" << volume;
            audioOutput->setVolume(volume);
        });
    }
    qDebug() << "After connecting signal";

    entryscene->addWidget(Backtomenu);
    connect(Backtomenu,&QPushButton::clicked,this,[=](){
        qDebug()<<"Im gonna go back";
        Backtomenu->hide();
        volumeSlider->hide();
        Quit->show();
        Settings->show();
        StartingGame->show();
    });

}
void uiscene::QuitGame() {
    view->close();
}
void uiscene::drawCardOnClick() {
    qDebug() << "I'm gonna draw a card";
    QVBoxLayout* temp =P1->Drawcard();
    Player_hand->addLayout(temp);
    qDebug() << Player_hand;
    P1->setTurn();
    AI_player->setTurn();
    emit swappingturns();
}

bool uiscene::eventFilter(QObject* obj, QEvent* event) {
    if (obj == LeftElement) {
        if (event->type() == QEvent::MouseButtonPress) {
            qDebug () << "Clicked on the deck to draw card";
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                qDebug () << "Clicked with left button";
                emit drawCardSignal();
                return true;
            }
        }
    }
    return QObject::eventFilter(obj, event);
}

void uiscene::handleCardClick(int cardNumber) {
    Tapis.RefillEmptyDeck(&NewDeck);
    int cardsuitcheck = (P1->getSelectedCard()-1) /10;
    int cardrankcheck = P1->getSelectedCard() %10;
    qDebug() << "inside the field is the suit :"<< Tapis.getcardsuit();
    qDebug() << "inside the field is the card number :"<< Tapis.getcardsuit();

    if(cardsuitcheck ==Tapis.getcardsuit() || cardrankcheck == Tapis.getcardrank()){
        emit loadinggamelogic->startPlayer1Turn();
        DeleteUsedCard ();
        Tapis.TakeCard(cardNumber);
        P1->DropCard();
        QImage* tempImg = Tapis.ShowCardImg();
        Fieldlabel->setFixedSize(tempImg->width(), tempImg->height());
        Fieldlabel->setPixmap(QPixmap::fromImage(*tempImg));
        AI_player->setTurn();
        P1->setTurn();
        emit swappingturns();
    } else {
        qDebug() << " u cant put this card here";
    }
}

void uiscene::DeleteUsedCard() {
   // qDebug() << "------------------------------------";
    //qDebug() << "I Selected the card : " << P1->getSelectedCard();
   // qDebug() << "------------------------------------";
   // qDebug() << "Number of cards in hand : " << P1->getHandCardsize();

    int selectedIndex = P1->getHandElements().indexOf(P1->getSelectedCard());
    if (selectedIndex != -1) {
        QLayoutItem* item = Player_hand->itemAt(selectedIndex);
        if (item && item->layout()) {
            QVBoxLayout* cardLayout = qobject_cast<QVBoxLayout*>(item->layout());
            if (cardLayout) {
               // qDebug() << "Child is a QVBoxLayout";
                for (int loop = 0; loop < cardLayout->count(); ++loop) {
                    QLayoutItem* innerItem = cardLayout->itemAt(loop);
                    if (innerItem && innerItem->widget()) {
                        QObject* cardObject = innerItem->widget();

                        if (cardObject->inherits("QLabel")) {
                            QLabel* cardLabel = qobject_cast<QLabel*>(cardObject);
                          //  int cardNumber = cardLabel->property("cardNumber").toInt();
                          //  qDebug() << "Im printing : " << cardNumber;
                            cardLabel->clear();
                            cardLayout->removeWidget(cardLabel);
                            cardLabel->deleteLater();
                            P1->SetSelectedCard(-1);
                          //  qDebug() << "Deleted the element";
                        }
                    }
                }
            }
            Player_hand->removeItem(item);
            delete cardLayout;
        }
    } else {
        qDebug() << "Card doesn't exist anymore";
    }
}

void uiscene::NpcCardHandler(){
    qDebug () << " Deleting played card rn";
    DeleteNPCUsedCard();
    Tapis.TakeCard(AI_player->getSelectedCard());
    AI_player->DropCard();
    QImage* tempImg = Tapis.ShowCardImg();
    Fieldlabel->setFixedSize(tempImg->width(), tempImg->height());
    Fieldlabel->setPixmap(QPixmap::fromImage(*tempImg));
    AI_player->setTurn();
    P1->setTurn();
    emit swappingturns ();
}


void uiscene::DeleteNPCUsedCard() {
int selectedIndex = AI_player->getHandCards().indexOf(AI_player->PlayingCard());
    if (selectedIndex != -1) {
        QLayoutItem* item = NPC_hand->itemAt(selectedIndex);
        if (item && item->layout()) {
            QVBoxLayout* cardLayout = qobject_cast<QVBoxLayout*>(item->layout());
            if (cardLayout) {
                 qDebug() << "Child is a QVBoxLayout";
                for (int loop = 0; loop < cardLayout->count(); ++loop) {
                    QLayoutItem* innerItem = cardLayout->itemAt(loop);
                    if (innerItem && innerItem->widget()) {
                        QObject* cardObject = innerItem->widget();

                        if (cardObject->inherits("QLabel")) {
                            QLabel* cardLabel = qobject_cast<QLabel*>(cardObject);
                            //  int cardNumber = cardLabel->property("cardNumber").toInt();
                            //  qDebug() << "Im printing : " << cardNumber;
                            cardLabel->clear();
                            cardLayout->removeWidget(cardLabel);
                            cardLabel->deleteLater();
                            //  qDebug() << "Deleted the element";
                        }
                    }
                }
            }
            NPC_hand->removeItem(item);
            delete cardLayout;
        }
    } else {
        qDebug() << "Card doesn't exist anymore";
    }
}
