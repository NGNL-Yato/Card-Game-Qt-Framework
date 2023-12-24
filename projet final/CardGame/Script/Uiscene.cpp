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
    Winning_streak = 0;
    PartyWinner = false;
    Tutorial_1 = new QGraphicsPixmapItem;
    Tutorial_2 = new QGraphicsPixmapItem;
    Before = new QPushButton;
    After = new QPushButton;
    Exit = new QPushButton;
    overlayWidget = new QWidget;
    entryscene = new QGraphicsScene();
    entryscene->setSceneRect(0, 0, 1280, 717);/* Gave this size instead of 720 to not have the scrolling on the mouse */
    view = new QGraphicsView(entryscene);
    view->setFixedSize(1280, 720); //Choosed to fix the size of the screen for test purposes
    QPixmap SceneBackground_Img("CardGameQt/Assets/BackGround/Backgroundui.png");
    QGraphicsPixmapItem* backgroundImage = new QGraphicsPixmapItem(SceneBackground_Img);
    entryscene->addItem(backgroundImage);
    StartingGame = new QPushButton;
    StartingGame->setIcon(QIcon("../Assets/Buttons/START.png"));
    StartingGame->setIconSize(QSize(500, 500));
    StartingGame->setFixedSize(500, 150);
    StartingGame->setStyleSheet("background-color: transparent;");
    StartingGame->move(385, 175);

    Settings = new QPushButton;
    Settings->setIcon(QIcon("./Assets/Buttons/SETTINGS.png"));
    Settings->setIconSize(QSize(500, 500));
    Settings->setFixedSize(500, 150);
    Settings->setStyleSheet("background-color: transparent;");
    Settings->move(385, 300);

    Quit = new QPushButton;
    Quit->setIcon(QIcon("../Assets/Buttons/QUIT.png"));
    Quit->setIconSize(QSize(500, 500));
    Quit->setFixedSize(500, 150);
    Quit->setStyleSheet("background-color: transparent;");
    Quit->move(385, 425);

    Help = new QPushButton;
    Help->setIcon(QIcon("../Assets/Buttons/HELP.png"));
    Help->setIconSize(QSize(100, 100));
    Help->setFixedSize(100, 100);
    Help->setStyleSheet("background-color: transparent;");
    Help->move(1130, 15);

    entryscene->addWidget(overlayWidget);
    entryscene->addWidget(Help);
    entryscene->addWidget(StartingGame);
    entryscene->addWidget(Quit);
    entryscene->addWidget(Settings);
    entryscene->addItem (Tutorial_1);
    entryscene->addItem (Tutorial_2);
    entryscene->addWidget (After);
    entryscene->addWidget (Before);
    entryscene->addWidget (Exit);

    overlayWidget->hide();
    Exit->hide ();
    Before->hide ();
    After->hide ();
    Tutorial_1->hide ();
    Tutorial_2->hide ();

    connect(StartingGame, &QPushButton::clicked, this, &uiscene::StartnewGame);
    connect(Quit, &QPushButton::clicked, this, &uiscene::QuitGame);
    connect(Settings, &QPushButton::clicked, this,[=]{
        if (!insideHelp){
            ChangeSettings();
        } else {
            qDebug () << " You're inside the help ";
        }
    });
    connect(Help,&QPushButton::clicked, this ,[=]{
        ShowHelp();
    });

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    playlist = new QMediaPlayer;
    playlist->setSource(QUrl::fromLocalFile("../Assets/Audio/GameMusic1.m4a"));
    //Credit : https://www.youtube.com/watch?v=yuvjuL--gnQ (We were here guitar cover)
    playlist->setLoops(QMediaPlayer::Infinite);
    audioOutput = new QAudioOutput;
    audioOutput->setVolume(0.6);
    playlist->setAudioOutput(audioOutput);
    playlist->play();

    view->show();
}
uiscene::~uiscene() {}
void uiscene::StartnewGame() {
    if (!insideHelp){
      view->close();
      createNewScene();
    } else {
        qDebug () << " You're inside the help ";
    }
}
void uiscene::createNewScene() {
    newScene = new QGraphicsScene();
    newScene->setSceneRect(0, 0, 1280, 717);/* Gave this size instead of 720 to not have the scrolling on the mouse */
    newView = new QGraphicsView(newScene);
    newView->setFixedSize(1280, 720);
    qDebug()<<"I load the new game";
    QPixmap background("../Assets/BackGround/BCK.jpg");
    QGraphicsPixmapItem* Backgroundimg = new QGraphicsPixmapItem(background);
    QPixmap pimg("../Assets/P1.png");
    QLabel * player1 = new QLabel;
    player1->setPixmap(pimg.scaled(100,100));
    int xPos = 100;
    int yPos = 550;
    player1->move(xPos, yPos);

    Help = new QPushButton;
    Help->setIcon(QIcon("../Assets/Buttons/HELP.png"));
    Help->setIconSize(QSize(100, 100));
    Help->setFixedSize(100, 100);
    Help->setStyleSheet("background-color: transparent;");
    Help->move(1130, 15);

    overlayWidget = new QWidget;//Background
    Tutorial_1 = new QGraphicsPixmapItem;
    Tutorial_2 = new QGraphicsPixmapItem;
    Before = new QPushButton;
    After = new QPushButton;
    Exit = new QPushButton;

    syoufa = new QPushButton;
    flouss = new QPushButton;
    tb9 = new QPushButton;
    gr3 = new QPushButton;

    syoufa->setIcon(QIcon("../Assets/Buttons/sword.png"));
    syoufa->move(400,470);
    syoufa->setIconSize(QSize(45, 45));
    syoufa->setFixedSize(45, 45);
    syoufa->setStyleSheet("background-color: transparent;");
    syoufa->setProperty("3",value3);

    flouss->setIcon(QIcon("../Assets/Buttons/gold.png"));
    flouss->move(350,470);
    flouss->setIconSize(QSize(50, 50));
    flouss->setFixedSize(50, 50);
    flouss->setStyleSheet("background-color: transparent;");
    flouss->setProperty("2",value2);

    tb9->setIcon(QIcon("../Assets/Buttons/drum.png"));
    tb9->move(400,420);
    tb9->setIconSize(QSize(45, 45));
    tb9->setFixedSize(45, 45);
    tb9->setStyleSheet("background-color: transparent;");
    tb9->setProperty("4",value4);

    gr3->setIcon(QIcon("../Assets/Buttons/pumpkin.png"));
    gr3->move(350,420);
    gr3->setIconSize(QSize(50, 50));
    gr3->setFixedSize(50, 50);
    gr3->setStyleSheet("background-color: transparent;");
    gr3->setProperty("1",value1);

    newScene->addItem(Backgroundimg);

    Tapis = new field(NewDeck);

    NewDeck = new Deckk;
    qDebug () << " Deck now have : "<< NewDeck->getDeckCards();
    NewDeck->getImgDeck();
    QImage* Deck_Img = NewDeck->getImgDeck();
    qDebug()<<Deck_Img;

    AI_player = new npc(NewDeck,Tapis);

    NPC_hand = new QHBoxLayout;

    QWidget* NPCLabel = new QWidget;
    NPCLabel->setLayout(NPC_hand);
    NPCLabel->setFixedWidth(700);
    NPCLabel->setFixedHeight(170);
    xPos = (newScene->width() - NPCLabel->width()) / 2;
    yPos = 0;
    NPCLabel->move(xPos, yPos);
    NPCLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0.25); border-radius: 15px;");

    P1 = new Player(NewDeck,Tapis);

    Player_hand = new QHBoxLayout;
    QWidget* HandLabel = new QWidget;
    HandLabel->setLayout(Player_hand);
    HandLabel->setFixedWidth(650);
    HandLabel->setFixedHeight(170);
    xPos = (newScene->width() - HandLabel->width()) / 2;
    yPos = (newScene->height() - HandLabel->height());
    HandLabel->move(xPos, yPos);
    HandLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0.25); border-radius: 15px;");
    qDebug() << HandLabel->size();

    connect(this, &uiscene::drawCardSignal, this, &uiscene::drawCardOnClick);
    connect(P1, &Player::CurrentCard, this, &uiscene::handleCardClick);

    QLabel* DeckLabel = new QLabel;
    DeckLabel->setFixedSize(Deck_Img->width(), Deck_Img->height());
    DeckLabel->setPixmap(QPixmap::fromImage(*Deck_Img));
    DeckLabel->setStyleSheet("background-color: transparent");

    QVBoxLayout* Deckzone = new QVBoxLayout;
    Deckzone->addWidget(DeckLabel);

    LeftElement = new QWidget;
    LeftElement->setLayout(Deckzone);
    xPos = newScene->width() - (Deck_Img->width()*2.5);
    yPos = (newScene->height() - Deck_Img->height()) / 2 - 50;
    LeftElement->move(xPos, yPos);
    LeftElement->setStyleSheet("background-color: rgba(255, 255, 255, 0.25); border-radius: 15;");

    LeftElement->installEventFilter(this);

    QImage* EmptyField_img = Tapis->getImgField();
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
    CenterElement->setStyleSheet("border-radius: 15px;background-color: rgba(255, 255, 255, 0.25);");

    loadinggamelogic = new GameLogic(*NewDeck,*P1,*AI_player,*Tapis);

    connect(loadinggamelogic, &GameLogic::cardDrawnplayer1, this, &uiscene::CardDrawnPlayer);
    connect(loadinggamelogic, &GameLogic::cardDrawnplayer2, this, &uiscene::CardDrawnNpc);
    connect(loadinggamelogic, &GameLogic::tapisdraw,this, &uiscene::CardDrawnField);
        NewDeck->shuffle();
        QTimer::singleShot(1000, this, [&]() {
            loadinggamelogic->StartingGame();
    });
    connect(Help,&QPushButton::clicked, this ,[=]{
        ShowHelp();
    });
    connect (this,&uiscene::swappingturns,loadinggamelogic, &GameLogic::startPlayer1Turn);
    connect (loadinggamelogic, &GameLogic::player2droppingcard,this, &uiscene::NpcCardHandler);

    newScene->addWidget(flouss);
    newScene->addWidget(gr3);
    newScene->addWidget(tb9);
    newScene->addWidget(syoufa);

    flouss->hide();
    gr3->hide();
    tb9->hide();
    syoufa->hide();

    connect(flouss, &QPushButton::clicked, this, [=] {
        gr3->hide();
        tb9->hide();
        syoufa->hide();
        loadinggamelogic->setChangingCardSuitvalue(1);
        qDebug () << "Im checking the value rn : "<< loadinggamelogic->getChangingCardSuitvalue();
        P1->setTurn();
        qDebug () << " Rak 7akm  daba flouss";
        emit ChangingDeckValue ();
    });
    connect(gr3, &QPushButton::clicked, this, [=] {
        flouss->hide();
        tb9->hide();
        syoufa->hide();
        loadinggamelogic->setChangingCardSuitvalue(0);
        qDebug () << " Rak 7akm  daba gr3";
        qDebug () << "Im checking the value rn : "<< loadinggamelogic->getChangingCardSuitvalue();
        P1->setTurn();
        emit ChangingDeckValue ();
    });
    connect(tb9, &QPushButton::clicked, this, [=] {
        gr3->hide();
        flouss->hide();
        syoufa->hide();
        loadinggamelogic->setChangingCardSuitvalue(3);
        qDebug () << "Im checking the value rn : "<< loadinggamelogic->getChangingCardSuitvalue();
        qDebug () << " Rak 7akm  daba tb9";
        P1->setTurn();
        emit ChangingDeckValue ();
    });
    connect(syoufa, &QPushButton::clicked, this, [=] {
        gr3->hide();
        tb9->hide();
        flouss->hide();
        loadinggamelogic->setChangingCardSuitvalue(2);
        qDebug () << "Im checking the value rn : "<< loadinggamelogic->getChangingCardSuitvalue();
        qDebug () << " Rak 7akm  daba syoufa";
        P1->setTurn();
        emit ChangingDeckValue ();
    });
    
    connect (this,&uiscene::NpcChoosingSuit,this,&uiscene::CallingtheNpcChange);
    connect (loadinggamelogic,&GameLogic::NpcChangingsuit,this,&uiscene::CallingtheNpcChange);
    connect (loadinggamelogic,&GameLogic::HideAllButtons,this,&uiscene::HiddingButtons);
    connect (this, &uiscene::ChangingDeckValue,loadinggamelogic, &GameLogic::ChangingCurrentSuit);
    connect (this, &uiscene::DisplayThechoices,this,&uiscene::ShowingButtons);
    connect (loadinggamelogic, &GameLogic::GoingBackToNormal,loadinggamelogic,&GameLogic::startPlayer1Turn);
    connect (this, &uiscene::CurrentRoundEnded,this, &uiscene::SwitchingtoLastScene);

    newScene->addWidget(overlayWidget);
    newScene->addWidget(NPCLabel);
    newScene->addWidget(player1);
    newScene->addWidget(HandLabel);
    newScene->addWidget(LeftElement);
    newScene->addWidget(CenterElement);
    newScene->addWidget(Help);
    newScene->addItem (Tutorial_1);
    newScene->addItem (Tutorial_2);
    newScene->addWidget (After);
    newScene->addWidget (Before);
    newScene->addWidget (Exit);

    overlayWidget->hide();
    Help->show ();
    Exit->hide ();
    Before->hide ();
    After->hide ();
    Tutorial_1->hide ();
    Tutorial_2->hide ();

    newView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    newView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    newView->show();

}
void uiscene::CallingtheNpcChange () {
    HiddingButtons();
    selectedButton = AI_player->Choosingthenewsuit();
    qDebug () << "(NPC) I'm changing the card suit. ";
    if (selectedButton == 0){
        gr3->show();
    } else if (selectedButton == 1){
        flouss->show();
    } else if (selectedButton == 2){
        syoufa->show();
    } else if (selectedButton == 3){
        tb9->show();
    } else {
        qDebug() << "Recheck if here inside buttons if there is a problem.";
    }
    loadinggamelogic->setChangingCardSuitvalue(selectedButton);
    qDebug () << "Checking Current Value if working properly :" << loadinggamelogic->getChangingCardSuitvalue();
    P1->SetSelectedCard(-1);
    P1->setTurn();
    emit ChangingDeckValue ();
}
void uiscene::SwitchingtoLastScene () {
    qDebug () << "I will switch the scene.";
    newScene->clear ();
    GameEnded ();
}
void uiscene::GameEnded () {
    qDebug () << "Entering the new scene...";
    GameEndedScene = new QGraphicsScene;
    GameEndedScene->setSceneRect(0, 0, 1280, 717);

    CloseGame = new QPushButton;
    CloseGame->setIcon(QIcon("../Assets/Buttons/QUIT.png"));
    CloseGame->setIconSize(QSize(500, 500));
    CloseGame->setFixedSize(500, 150);
    CloseGame->setStyleSheet("background-color: transparent;");
    CloseGame->move(385, 300);

    NextGame = new QPushButton;
    if (PartyWinner){
        NextGame->setIcon(QIcon("../Assets/Buttons/RESTART.png"));
    } else {
        NextGame->setIcon(QIcon("../Assets/Buttons/TRYAGAIN.png"));
    }
    NextGame->setIconSize(QSize(500, 500));
    NextGame->setFixedSize(500, 150);
    NextGame->setStyleSheet("background-color: transparent;");
    NextGame->move(385, 350);

    Quit = new QPushButton;
    Quit->setIcon(QIcon("../Assets/Buttons/QUIT.png"));
    Quit->setIconSize(QSize(500, 500));
    Quit->setFixedSize(500, 150);
    Quit->setStyleSheet("background-color: transparent;");
    Quit->move(385, 550);

    QPixmap SceneBackground_Img("../Assets/BackGround/Backgroundui.png");
    QGraphicsPixmapItem* backgroundImage = new QGraphicsPixmapItem(SceneBackground_Img);

    GameEndedScene->addItem (backgroundImage);
    GameEndedScene->addWidget(NextGame);
    GameEndedScene->addWidget(Quit);
    newView->setScene(GameEndedScene);

    connect (Quit, &QPushButton::clicked, this,&uiscene::QuitGame);
    connect(NextGame, &QPushButton::clicked, this, [=] {
        newView->close ();
        createNewScene ();
        qDebug () << "Trying again ...";
    });
    connect(Quit, &QPushButton::clicked, this, &uiscene::QuitGame);
}
void uiscene::CardDrawnField() {
    this->CarddrawSound ();
    qDebug () << " i give card to the field";
    Tapis->DrawCard(NewDeck);
    QImage* tempImg = Tapis->ShowCardImg();
    Fieldlabel->setFixedSize(tempImg->width(), tempImg->height());
    Fieldlabel->setPixmap(QPixmap::fromImage(*tempImg));
    P1->setTurn();
}
void uiscene::ShowingButtons () {
    flouss->show();
    gr3->show();
    tb9->show();
    syoufa->show();
    qDebug () << "i will proceed to change the card suit ...";
    loadinggamelogic->setinsindesuitvalue();
    qDebug () << "I change Inside suit value "<< loadinggamelogic->getinsindesuitvalue();
}
void uiscene::HiddingButtons (){
    flouss->hide();
    gr3->hide();
    tb9->hide();
    syoufa->hide();
    qDebug () << "i will proceed to change the visibility of the buttons ...";
    loadinggamelogic->setinsindesuitvalue();
    qDebug () << "I change Inside suit value "<< loadinggamelogic->getinsindesuitvalue();
}
void uiscene::CardDrawnPlayer() {
    this->CarddrawSound ();
    qDebug () << " i give cards to myself ";
    QVBoxLayout* temp = P1->Drawcard();
    Player_hand->addLayout(temp);
    qDebug() << Player_hand;
}
void uiscene::CardDrawnNpc() {
    qDebug () << " i give cards to npc ";
    qDebug () << NewDeck->getDeckCards();
    this->CarddrawSound ();
    QVBoxLayout* temp = AI_player->Drawcard();
    NPC_hand->addLayout(temp);
    qDebug() << Player_hand;
    if (AI_player->getSelectedCard()%10 == 1){
        qDebug () <<" (NPC) I played a 1 and now i took a card from the deck. ";
    } else if (AI_player->getSelectedCard()%10 == 2){
        qDebug () <<" (NPC) I played a 2 and now i took a card from the deck. ";
        if (loadinggamelogic->getinsindesuitvalue()){ //To make sure that the buttons dissapeared after showing them
            loadinggamelogic->getinsindesuitvalue();
        } else {
            emit swappingturns();
        }
    } else if (!Tapis->EmptyField() && Tapis->getCurrentCard()%10 == 7){
        qDebug () <<" (NPC) I pass my turn with 7 on the field. ";
        emit ChangingFieldSuitValue ();
    } else {
        qDebug () <<" (NPC) I passed my turn . ";
    }
}
void uiscene::ChangeSettings(){
    qDebug()<<"I will change settings";
    Quit->hide();
    Settings->hide();
    StartingGame->hide();

    increaseVolumeButton = new QPushButton;
    increaseVolumeButton->move(380, 350);
    increaseVolumeButton->setIcon(QIcon("../Assets/Buttons/Button_Volume.png"));
    increaseVolumeButton->setIconSize(QSize(130, 130));
    increaseVolumeButton->setFixedSize(130, 130);
    increaseVolumeButton->setStyleSheet("background-color: transparent;");

    additionalButton1 = new QPushButton;
    additionalButton1->move(540, 295);
    additionalButton1->setIcon(QIcon("../Assets/Buttons/Volume_Choice.png"));
    additionalButton1->setIconSize(QSize(54, 200));
    additionalButton1->setFixedSize(54, 200);
    additionalButton1->setStyleSheet("background-color: transparent;");

    additionalButton2 = new QPushButton;
    additionalButton2->move(610, 295);
    additionalButton2->setIcon(QIcon("../Assets/Buttons/Volume_Choice.png"));
    additionalButton2->setIconSize(QSize(54, 200));
    additionalButton2->setFixedSize(54, 200);
    additionalButton2->setStyleSheet("background-color: transparent;");

    additionalButton3 = new QPushButton;
    additionalButton3->move(670, 295);
    additionalButton3->setIcon(QIcon("../Assets/Buttons/Volume_Choice.png"));
    additionalButton3->setIconSize(QSize(54, 200));
    additionalButton3->setFixedSize(54, 200);
    additionalButton3->setStyleSheet("background-color: transparent;");

    additionalButton4 = new QPushButton;
    additionalButton4->move(730, 295);
    additionalButton4->setIcon(QIcon("../Assets/Buttons/Volume_Choice.png"));
    additionalButton4->setIconSize(QSize(54, 200));
    additionalButton4->setFixedSize(54, 200);
    additionalButton4->setStyleSheet("background-color: transparent;");

    additionalButton5 = new QPushButton;
    additionalButton5->move(790, 295);
    additionalButton5->setIcon(QIcon("../Assets/Buttons/Volume_Choice.png"));
    additionalButton5->setIconSize(QSize(54, 200));
    additionalButton5->setFixedSize(54, 200);
    additionalButton5->setStyleSheet("background-color: transparent;");

    additionalButton1->hide ();// all buttons hidden by default
    additionalButton2->hide ();
    additionalButton3->hide ();
    additionalButton4->hide ();
    additionalButton5->hide ();

    double volume = audioOutput->volume();
    qDebug () <<"Current Volume ...  "<<volume ;
    if (volume > 0.0 && volume <= 0.21) {
        additionalButton1->show();
    } else if (volume > 0.21 && volume <= 0.41) {
        additionalButton1->show();
        additionalButton2->show();
    } else if (volume > 0.41 && volume <= 0.61) {
        additionalButton1->show();
        additionalButton2->show();
        additionalButton3->show();
    } else if (volume > 0.61 && volume <= 0.81) {
        additionalButton1->show();
        additionalButton2->show();
        additionalButton3->show();
        additionalButton4->show();
    } else if (volume > 0.81 && volume <= 1.0) {
        additionalButton1->show();
        additionalButton2->show();
        additionalButton3->show();
        additionalButton4->show();
        additionalButton5->show();
    } else {
        qDebug() << " Volume is ";
    }

    currentVolume = audioOutput->volume() * 10;
    connect(increaseVolumeButton, &QPushButton::clicked, this, [=]() {
        qDebug() << "Increasing the volume ..";
        double newVolume = qMin(audioOutput->volume() + 0.2, 1.0); // Increase by 20% (0.2 out of 1.0)
        if (audioOutput->volume() >= 0.0 && audioOutput->volume() <= 0.2) {
            additionalButton1->show();
            audioOutput->setVolume(newVolume);
            qDebug() << "Increased .. 1";
        } else if (audioOutput->volume() > 0.2 && audioOutput->volume() <= 0.4) {
            additionalButton2->show();
            audioOutput->setVolume(newVolume);
            qDebug() << "Increased .. 2";
        } else if (audioOutput->volume() > 0.4 && audioOutput->volume() <= 0.6) {
            additionalButton3->show();
            audioOutput->setVolume(newVolume);
            qDebug() << "Increased .. 3";
        } else if (audioOutput->volume() > 0.6 && audioOutput->volume() <= 0.8) {
            additionalButton4->show();
            audioOutput->setVolume(newVolume);
            qDebug() << "Increased .. 4";
        } else if (audioOutput->volume() > 0.8 && audioOutput->volume() <= 10.0) {
            additionalButton5->show();
            audioOutput->setVolume(newVolume);
            qDebug() << "Increased .. 5";
        } else {
            qDebug() << " [ERROR] Can't change volume?";
        }
    });

    connect(additionalButton1, &QPushButton::clicked, this, [=]() {
        qDebug() << "Decreasing the volume ..";
        audioOutput->setVolume(0.0);
        additionalButton1->hide();
        additionalButton2->hide();
        additionalButton3->hide();
        additionalButton4->hide();
        additionalButton5->hide();
    });
    connect(additionalButton2, &QPushButton::clicked, this, [=]() {
        qDebug() << "Decreasing the volume ..";
        audioOutput->setVolume(0.2);
        additionalButton2->hide();
        additionalButton3->hide();
        additionalButton4->hide();
        additionalButton5->hide();
    });
    connect(additionalButton3, &QPushButton::clicked, this, [=]() {
        qDebug() << "Decreasing the volume ..";
        audioOutput->setVolume(0.4);
        additionalButton3->hide();
        additionalButton4->hide();
        additionalButton5->hide();
    });
    connect(additionalButton4, &QPushButton::clicked, this, [=]() {
        qDebug() << "Decreasing the volume ..";
        audioOutput->setVolume(0.8);
        additionalButton4->hide();
        additionalButton5->hide();
    });
    connect(additionalButton5, &QPushButton::clicked, this, [=]() {
        qDebug() << "Decreasing the volume ..";
        audioOutput->setVolume(0.8);
        additionalButton5->hide();
    });

    QPushButton* Backtomenu = new QPushButton;
    Backtomenu->setIcon(QIcon("../Assets/Buttons/BEFORE.png"));
    Backtomenu->move(0,0);
    Backtomenu->setIconSize(QSize(200, 200));
    Backtomenu->setFixedSize(200, 200);
    Backtomenu->setStyleSheet("background-color: transparent;");

    entryscene->addWidget(Backtomenu);
    entryscene->addWidget(increaseVolumeButton);
    entryscene->addWidget(additionalButton1);
    entryscene->addWidget(additionalButton2);
    entryscene->addWidget(additionalButton3);
    entryscene->addWidget(additionalButton4);
    entryscene->addWidget(additionalButton5);

    connect(Backtomenu,&QPushButton::clicked,this,[=](){
        qDebug()<<"Im gonna go back";
        Backtomenu->hide();
        increaseVolumeButton->hide();
        additionalButton1->hide ();
        additionalButton2->hide ();
        additionalButton3->hide ();
        additionalButton4->hide ();
        additionalButton5->hide ();
        Quit->show();
        Settings->show();
        StartingGame->show();
    });

}
void uiscene::QuitGame() {
    if (!insideHelp){
       view->close();
    } else {
        qDebug () << " You're inside the help ";
    }
}
void uiscene::drawCardOnClick() {
    Tapis->RefillEmptyDeck();
    qDebug () << "i m checking card suit " << loadinggamelogic->getinsindesuitvalue();
    if (!NewDeck->isEmpty() && P1->getGamestarted() == true && !insideHelp){
        if (P1->getTurn()){
            qDebug() << "I'm gonna draw a card";
            QVBoxLayout* temp =P1->Drawcard();
            this->CarddrawSound ();
            Player_hand->addLayout(temp);
            qDebug() << Player_hand;
            P1->setTurn();
            if (loadinggamelogic->getinsindesuitvalue()){
                qDebug () << "I'm calling the 7 function to recheck the bots card.";
                emit ChangingDeckValue();
            } else {
                emit swappingturns();
            }
        }
    } else {
        qDebug () <<"Deck Empty, stop trolling and use a card please.";
    }
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
void uiscene::handleCardClick() {
    qDebug () << "Current card in hand : "<< P1->GetCurrentCard();
    qDebug () << "Selected card in hand : "<< P1->getSelectedCard();
    int cardsuitcheck = (P1->getSelectedCard()-1) /10;
    int cardrankcheck = P1->getSelectedCard() %10;
    qDebug() << "inside the field is the suit :"<< Tapis->getcardsuit();
    qDebug() << "inside the field is the card number :"<< Tapis->getcardrank();
    qDebug () <<  "logic of game ..."<< loadinggamelogic->getinsindesuitvalue() ;
    if(loadinggamelogic->getinsindesuitvalue() == false && !insideHelp){
        if (cardsuitcheck ==Tapis->getcardsuit() || cardrankcheck == Tapis->getcardrank()){
            qDebug () << " U can put a card ...";
            emit loadinggamelogic->startPlayer1Turn();
            DeleteUsedCard ();
            this->CarddropSound();
            P1->DropCard();
            QImage* tempImg = Tapis->ShowCardImg();
            Fieldlabel->setFixedSize(tempImg->width(), tempImg->height());
            Fieldlabel->setPixmap(QPixmap::fromImage(*tempImg));
            qDebug() << "rak yallah 7titi daba nit "<< P1->getSelectedCard();
            if (P1->isEmpty()){
                PartyWinner = true;
                P1->setWin();
                emit CurrentRoundEnded ();
            } else if (AI_player->isEmpty()){
                Winning_streak = 0;
                emit  CurrentRoundEnded();
            } else {
                if ((P1->getSelectedCard()%10) == 7){
                    qDebug () << " rak 7at 7 check again";
                    P1->SetSelectedCard(-1);
                    emit DisplayThechoices();
                } else if (P1->getSelectedCard()%10 == 2){
                    qDebug () << "rak yallah 3titih ihz 2, mazal atl3b";
                } else if(P1->getSelectedCard()%10 == 1){
                    qDebug () << "rak yallah 3titih ihz 1, mazal atl3b";
                } else {
                    P1->setTurn ();
                    P1->SetSelectedCard(-1);
                    emit swappingturns();
                }
            }
        }
    } else if (loadinggamelogic->getinsindesuitvalue() == true && !insideHelp) {
        if (loadinggamelogic->getChangingCardSuitvalue() == cardsuitcheck || cardrankcheck == 7){
            emit ChangingDeckValue ();
            qDebug () << " I'm handling the 7 card Logic right now...";
            DeleteUsedCard ();
            P1->DropCard();
            this->CarddropSound();
            QImage* tempImg = Tapis->ShowCardImg();
            Fieldlabel->setFixedSize(tempImg->width(), tempImg->height());
            Fieldlabel->setPixmap(QPixmap::fromImage(*tempImg));
            HiddingButtons();
            qDebug() << "rak yallah 7titi daba nit "<< P1->getSelectedCard();
            if (P1->isEmpty()){
                PartyWinner = true;
                P1->setWin();
                emit CurrentRoundEnded ();
            } else if ((P1->getSelectedCard()%10) == 7){
                qDebug () << " rak 7at 7 check again";
                P1->SetSelectedCard(-1);
                emit DisplayThechoices ();
            } else if (P1->getSelectedCard()%10 == 2){
                qDebug () << "rak yallah 3titih ihz 2, mazal atl3b";
            } else if(P1->getSelectedCard()%10 == 1){
                qDebug () << "rak yallah 3titih ihz 1, mazal atl3b";
            } else {
                P1->setTurn ();
                P1->SetSelectedCard(-1);
                emit swappingturns();
            }
        }
    } else {
        qDebug() << " u cant put this card here";
    }
}
void uiscene::DeleteUsedCard() {
   // qDebug() << "------------------------------------";
    //qDebug() << "I Selected the card : " << P1->getSelectedCard();
   // qDebug() << "------------------------------------";
   // qDebug() << "Number of cards in hand : " << P1->getHandCardsize();

    int selectedIndex = P1->getHandElements().indexOf(P1->GetCurrentCard());
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
                            P1->SetSelectedCard(P1->getSelectedCard());
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
    qDebug () << " Deleting played card rn...";
    DeleteNPCUsedCard();
    AI_player->DropCard();
    this->CarddropSound();
    QImage* tempImg = Tapis->ShowCardImg();
    Fieldlabel->setFixedSize(tempImg->width(), tempImg->height());
    Fieldlabel->setPixmap(QPixmap::fromImage(*tempImg));
    qDebug () << "i Deleted the Current Card";
    if (AI_player->isEmpty()){
        Winning_streak = 0;
        emit CurrentRoundEnded ();
    } else if ((AI_player->getSelectedCard()%10) == 7){
        qDebug () << " (NPC) rak 7at 7 check again";
    } else if (AI_player->getSelectedCard()%10 == 2){
        qDebug () << " (NPC)rak yallah 3titih ihz 2, mazal atl3b" << AI_player->getSelectedCard();
        emit swappingturns ();
    } else if(AI_player->getSelectedCard()%10 == 1){
        qDebug () << " (NPC)rak yallah 3titih ihz 1, mazal atl3b" << AI_player->getSelectedCard();
        emit swappingturns();
    } else {
        qDebug() << "Player is gonna play in theory ";
        P1->setTurn ();
        P1->SetSelectedCard(-1);
        emit swappingturns();
    }
}
bool uiscene::getskip () {
    return Verifyingskip;
}
bool uiscene::setskip () {
    return Verifyingskip = !Verifyingskip;
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
        qDebug() << "(NPC)Card doesn't exist anymore";
    }
}
void uiscene::CarddropSound (){
    QMediaPlayer* CarddropAudio = new QMediaPlayer;
    CarddropAudio->setSource(QUrl::fromLocalFile("../Assets/Audio/Crarddrop.m4a"));
    QAudioOutput* CardShuffleSound = new QAudioOutput;
    CardShuffleSound->setVolume (0.6);
    CarddropAudio->setAudioOutput(CardShuffleSound);
    CarddropAudio->play();
};
void uiscene::CarddrawSound () {
    QMediaPlayer* CarddawAudio = new QMediaPlayer;
    CarddawAudio->setSource(QUrl::fromLocalFile("../Assets/Audio/FlippingCard.mp3"));
    QAudioOutput* CardShuffleSound = new QAudioOutput;
    CardShuffleSound->setVolume (0.6);
    CarddawAudio->setAudioOutput(CardShuffleSound);
    CarddawAudio->play();
}
void uiscene::ShowHelp (){
    Help->hide ();
    insideHelp = true;
    qDebug () << "I enter the tutorial ..." << insideHelp;
    Tutorial_1->setPixmap(QPixmap("../Assets/BackGround/TUTORIAL1.png"));
    Tutorial_2->setPixmap(QPixmap("../Assets/BackGround/TUTORIAL2.png"));

    After->setIcon(QIcon("../Assets/Buttons/AFTER.png"));
    After->setIconSize(QSize(100, 100));
    After->setFixedSize(100, 100);
    After->setStyleSheet("background-color: transparent;");
    After->move(1100, 600);

    Before->setIcon(QIcon("../Assets/Buttons/BEFORE.png"));
    Before->setIconSize(QSize(100, 100));
    Before->setFixedSize(100, 100);
    Before->setStyleSheet("background-color: transparent;");
    Before->move(1100, 600);

    Exit->setIcon(QIcon("../Assets/Buttons/EXIT.png"));
    Exit->setIconSize(QSize(100, 100));
    Exit->setFixedSize(100, 100);
    Exit->setStyleSheet("background-color: transparent;");
    Exit->move(1130, 15);

    overlayWidget->setGeometry(0, 0, 1280, 717);
    overlayWidget->setStyleSheet("background-color: rgba(80, 68, 71, 0.75);");

    overlayWidget->show();
    Tutorial_1->show();
    After->show();
    Exit->show();

    connect (Exit ,&QPushButton::clicked ,this ,[=]{
        Tutorial_1->hide();
        Tutorial_2->hide();
        After->hide();
        Before->hide();
        Exit->hide();
        Help->show();
        overlayWidget->hide();
        insideHelp = false;
        qDebug () << "I exit the tutorial ..." << insideHelp;
    });
    connect (Before ,&QPushButton::clicked ,this ,[=]{
        Tutorial_2->hide();
        Before->hide();
        Tutorial_1->show();
        After->show();
        Exit->show();
    });
    connect (After ,&QPushButton::clicked ,this ,[=]{
        Tutorial_1->hide();
        After->hide();
        Tutorial_2->show();
        Before->show();
        Exit->show();
    });
}
