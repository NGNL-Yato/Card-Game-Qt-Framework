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
#include <QRandomGenerator>
#include <QMovie>
#include <QCoreApplication>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QCoreApplication>

uiscene::uiscene() { //HEAVITAS FONT USED FOR ALL THE PICTURES
    /* All Buttons have been constructed here in the uiscene constructor to avoid duplication and pointer problems.
     * Since QT manages the pointers, there is no need for us to free them when we finish.
     */
    SoundEffect_Volume = 0.6;
    Difficulty_value = 0;
    Winning_streak = 0;
    this->ReadingScores();
    PartyWinner = false;
    PartyStarted = false;
    Tutorial_1 = new QGraphicsPixmapItem;
    Tutorial_2 = new QGraphicsPixmapItem;
    Volume_Asset = new QGraphicsPixmapItem;
    Before = new QPushButton;
    Before_2 = new QPushButton;
    After = new QPushButton;
    Exit = new QPushButton;
    Difficulty_Choice = new QGraphicsPixmapItem;
    overlayWidget = new QWidget;
    entryscene = new QGraphicsScene;
    NextGame = new QPushButton;
    Quit = new QPushButton;
    CloseGame = new QPushButton;
    CenterElement = new QWidget;
    Fieldzone = new QVBoxLayout;
    Fieldlabel = new QLabel;
    LeftElement = new QWidget;
    Deckzone = new QVBoxLayout;
    DeckLabel = new QLabel;
    HandLabel = new QWidget;
    Player_hand = new QHBoxLayout;
    NPCLabel = new QWidget;
    NPC_hand = new QHBoxLayout;
    player1 = new QLabel;
    player2 = new QLabel;
    syoufa = new QPushButton;
    flouss = new QPushButton;
    tb9 = new QPushButton;
    gr3 = new QPushButton;
    HandPanel_AI_player = new QGraphicsPixmapItem;
    HandPanel_player = new QGraphicsPixmapItem;
    GIFLabel_Party_End = new QLabel;
    Scores_History = new QPushButton;
    Easy_Score_Img = new QGraphicsPixmapItem;
    Medium_Score_Img = new QGraphicsPixmapItem;
    Hard_Score_Img = new QGraphicsPixmapItem;
    HomeButton = new QPushButton;
    First_Digit_Easy = new QGraphicsPixmapItem;
    Second_Digit_Easy = new QGraphicsPixmapItem;
    First_Digit_Medium = new QGraphicsPixmapItem;
    Second_Digit_Medium = new QGraphicsPixmapItem;
    First_Digit_Hard = new QGraphicsPixmapItem;
    Second_Digit_Hard = new QGraphicsPixmapItem;
    CurrentHighScoreAsset = new QGraphicsPixmapItem;
    First_Digit_Current_Score = new QGraphicsPixmapItem;
    Second_Digit_Current_Score = new QGraphicsPixmapItem;
    Resume = new QPushButton;
    Main_Menu = new QPushButton;
    SoundEffect_Img = new QGraphicsPixmapItem;
    view = new QGraphicsView(entryscene);

    entryscene->setSceneRect(0, 0, 1280, 717);/* Gave this size instead of 720 to not have the scrolling on the mouse */
    view->setFixedSize(1280, 720); //Choosed to fix the size of the screen for test purposes
    QString GameFolderPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString relativePath = GameFolderPath + "/Gamefolder/CardGameQt/Assets/BackGround/Backgroundui.png";
    QPixmap SceneBackground_Img(relativePath);
    qDebug () << "Apk path is here :"<< relativePath ;
    backgroundImage = new QGraphicsPixmapItem(SceneBackground_Img);
    entryscene->addItem(backgroundImage);

    StartingGame = new QPushButton;
    StartingGame->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/START.png"));
    StartingGame->setIconSize(QSize(500, 500));
    StartingGame->setFixedSize(500, 150);
    StartingGame->setStyleSheet("background-color: transparent;");
    StartingGame->move(385, 175);

    Settings = new QPushButton;
    Settings->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/SETTINGS.png"));
    Settings->setIconSize(QSize(500, 500));
    Settings->setFixedSize(500, 150);
    Settings->setStyleSheet("background-color: transparent;");
    Settings->move(385, 300);

    Backtomenu = new QPushButton;
    Backtomenu->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/BEFORE.png"));
    Backtomenu->move(0,0);
    Backtomenu->setIconSize(QSize(200, 200));
    Backtomenu->setFixedSize(200, 200);
    Backtomenu->setStyleSheet("background-color: transparent;");

    Backtomenu_2 = new QPushButton;
    Backtomenu_2->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/BEFORE.png"));
    Backtomenu_2->move(0,0);
    Backtomenu_2->setIconSize(QSize(200, 200));
    Backtomenu_2->setFixedSize(200, 200);
    Backtomenu_2->setStyleSheet("background-color: transparent;");

    HomeButton->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/HOME.png"));
    HomeButton->move(10,10);
    HomeButton->setIconSize(QSize(60, 60));
    HomeButton->setFixedSize(60, 60);
    HomeButton->setStyleSheet("background-color: transparent;");

    Backtomenu_3 = new QPushButton;
    Backtomenu_3->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/BEFORE.png"));
    Backtomenu_3->move(0,0);
    Backtomenu_3->setIconSize(QSize(200, 200));
    Backtomenu_3->setFixedSize(200, 200);
    Backtomenu_3->setStyleSheet("background-color: transparent;");

    Quit = new QPushButton;
    Quit->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/QUIT.png"));
    Quit->setIconSize(QSize(500, 500));
    Quit->setFixedSize(500, 150);
    Quit->setStyleSheet("background-color: transparent;");
    Quit->move(385, 425);

    Scores_History->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/SCORES.png"));
    Scores_History->setIconSize(QSize(350, 350));
    Scores_History->setFixedSize(400, 120);
    Scores_History->setStyleSheet("background-color: transparent;");
    Scores_History->move(400, 450);

    Help = new QPushButton;
    Help->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/HELP.png"));
    Help->setIconSize(QSize(60, 60));
    Help->setFixedSize(60, 60);
    Help->setStyleSheet("background-color: transparent;");
    Help->move(1200, 10);

    Easy = new QPushButton;
    Easy->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/EASY.png"));
    Easy->setIconSize(QSize(500, 500));
    Easy->setFixedSize(380, 115);
    Easy->setStyleSheet("background-color: transparent;");
    Easy->move(450, 220);

    Medium = new QPushButton;
    Medium->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/NORMAL.png"));
    Medium->setIconSize(QSize(500, 500));
    Medium->setFixedSize(380, 115);
    Medium->setStyleSheet("background-color: transparent;");
    Medium->move(450, 340);

    Hard = new QPushButton;
    Hard->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/HARD.png"));
    Hard->setIconSize(QSize(500, 500));
    Hard->setFixedSize(380, 115);
    Hard->setStyleSheet("background-color: transparent;");//set the bgcolor on black to verify the hitbox
    Hard->move(450, 460);

    Resume->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/RESUME.png"));
    Resume->setIconSize(QSize(500, 500));
    Resume->setFixedSize(500, 150);
    Resume->setStyleSheet("background-color: transparent;");
    Resume->move(400, 225);

    Main_Menu->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/MAINMENU.png"));
    Main_Menu->setIconSize(QSize(500, 500));
    Main_Menu->setFixedSize(500, 150);
    Main_Menu->setStyleSheet("background-color: transparent;");
    Main_Menu->move(400,375);

    Difficulty_Choice->setPixmap(QPixmap(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/DIFFICULTY.png"));
    Difficulty_Choice->moveBy(323,-100);

    increaseVolumeButton = new QPushButton;
    increaseVolumeButton->move(380, 275);
    increaseVolumeButton->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/Button_Volume.png"));
    increaseVolumeButton->setIconSize(QSize(130, 130));
    increaseVolumeButton->setFixedSize(130, 130);
    increaseVolumeButton->setStyleSheet("background-color: transparent;");

    CardsSound = new QPushButton;
    CardsSound->move(1080, 220);
    CardsSound->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/CARDSOUNDON.png"));
    CardsSound->setIconSize(QSize(100, 100));
    CardsSound->setFixedSize(100, 100);
    CardsSound->setStyleSheet("background-color: transparent;");

    additionalButton1 = new QPushButton;
    additionalButton1->move(540, 240);
    additionalButton1->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/Volume_Choice.png"));
    additionalButton1->setIconSize(QSize(54, 200));
    additionalButton1->setFixedSize(54, 200);
    additionalButton1->setStyleSheet("background-color: transparent;");

    additionalButton2 = new QPushButton;
    additionalButton2->move(610, 240);
    additionalButton2->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/Volume_Choice.png"));
    additionalButton2->setIconSize(QSize(54, 200));
    additionalButton2->setFixedSize(54, 200);
    additionalButton2->setStyleSheet("background-color: transparent;");

    additionalButton3 = new QPushButton;
    additionalButton3->move(670, 240);
    additionalButton3->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/Volume_Choice.png"));
    additionalButton3->setIconSize(QSize(54, 200));
    additionalButton3->setFixedSize(54, 200);
    additionalButton3->setStyleSheet("background-color: transparent;");

    additionalButton4 = new QPushButton;
    additionalButton4->move(730, 240);
    additionalButton4->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/Volume_Choice.png"));
    additionalButton4->setIconSize(QSize(54, 200));
    additionalButton4->setFixedSize(54, 200);
    additionalButton4->setStyleSheet("background-color: transparent;");

    additionalButton5 = new QPushButton;
    additionalButton5->move(790, 240);
    additionalButton5->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/Volume_Choice.png"));
    additionalButton5->setIconSize(QSize(54, 200));
    additionalButton5->setFixedSize(54, 200);
    additionalButton5->setStyleSheet("background-color: transparent;");

    syoufa->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/sword.png"));
    syoufa->move(300,440);
    syoufa->setIconSize(QSize(45, 45));
    syoufa->setFixedSize(45, 45);
    syoufa->setStyleSheet("background-color: transparent;");
    syoufa->setProperty("3",value3);

    flouss->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/gold.png"));
    flouss->move(250,440);
    flouss->setIconSize(QSize(50, 50));
    flouss->setFixedSize(50, 50);
    flouss->setStyleSheet("background-color: transparent;");
    flouss->setProperty("2",value2);

    tb9->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/drum.png"));
    tb9->move(300,390);
    tb9->setIconSize(QSize(45, 45));
    tb9->setFixedSize(45, 45);
    tb9->setStyleSheet("background-color: transparent;");
    tb9->setProperty("4",value4);

    Volume_Asset->setPixmap(QPixmap(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/VOLUME.png").scaled(QSize(400, 120)));
    Volume_Asset->setPos(425,100);

    gr3->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/pumpkin.png"));
    gr3->move(250,390);
    gr3->setIconSize(QSize(50, 50));
    gr3->setFixedSize(50, 50);
    gr3->setStyleSheet("background-color: transparent;");
    gr3->setProperty("1",value1);

    player1->setPixmap(QPixmap(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Player.png").scaled(150,150));
    player1->setStyleSheet("background-color: transparent;");
    QPixmap Cardzone(GameFolderPath +"/Gamefolder/CardGameQt/Assets/BackGround/WoodPanel.png");

    Easy_Score_Img->setPixmap(QPixmap(GameFolderPath+"/Gamefolder/CardGameQt/Assets/Buttons/EASYSCORE.png").scaled(QSize(500, 150)));
    Medium_Score_Img->setPixmap(QPixmap(GameFolderPath+"/Gamefolder/CardGameQt/Assets/Buttons/NORMALSCORE.png").scaledToHeight(150));
    Hard_Score_Img->setPixmap(QPixmap(GameFolderPath+"/Gamefolder/CardGameQt/Assets/Buttons/HARDSCORE.png").scaled(QSize(500, 150)));
    SoundEffect_Img->setPixmap(QPixmap(GameFolderPath+"/Gamefolder/CardGameQt/Assets/BackGround/SoundEffectImg.png").scaled(QSize(250, 200)));
    CurrentHighScoreAsset->setPixmap(QPixmap(GameFolderPath+"/Gamefolder/CardGameQt/Assets/BackGround/winstrike.png").scaled(QSize(271, 323)));
    CurrentHighScoreAsset->setPos(100,0);

    overlayWidget->setGeometry(0, 0, 1280, 720);
    overlayWidget->setStyleSheet("background-color: rgba(111, 67, 42, 0.75);");

    Easy_Score_Img->moveBy(425, 100);
    Medium_Score_Img->moveBy(375, 250);
    Hard_Score_Img->moveBy(425, 400);

    HandPanel_player->setPixmap(QPixmap(Cardzone).scaled(750,200));
    HandPanel_player->moveBy(265,502);

    HandPanel_AI_player->setPixmap(QPixmap(Cardzone).scaled(750,200));
    HandPanel_AI_player->moveBy(265,18);

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

    additionalButton1->hide ();// all buttons hidden by default
    additionalButton2->hide ();
    additionalButton3->hide ();
    additionalButton4->hide ();
    additionalButton5->hide ();

    Backtomenu_2->hide ();
    NextGame->hide();

    entryscene->addWidget(NextGame);
    entryscene->addWidget(Quit);
    entryscene->addWidget(Help);
    entryscene->addWidget(StartingGame);
    entryscene->addWidget(Quit);
    entryscene->addWidget(Settings);
    entryscene->addWidget(Easy);
    entryscene->addWidget(Hard);
    entryscene->addWidget(Medium);
    entryscene->addItem(Difficulty_Choice);
    entryscene->addWidget(Backtomenu);
    entryscene->addWidget(Backtomenu_2);
    entryscene->addWidget(Backtomenu_3);
    entryscene->addItem (Volume_Asset);
    entryscene->addWidget(increaseVolumeButton);
    entryscene->addWidget(additionalButton1);
    entryscene->addWidget(additionalButton2);
    entryscene->addWidget(additionalButton3);
    entryscene->addWidget(additionalButton4);
    entryscene->addWidget(additionalButton5);
    entryscene->addItem(HandPanel_AI_player);
    entryscene->addItem(HandPanel_player);
    entryscene->addWidget(NPCLabel);
    entryscene->addWidget(player1);
    entryscene ->addWidget(player2);
    entryscene->addWidget(HandLabel);
    entryscene->addWidget(LeftElement);
    entryscene->addWidget(CenterElement);
    entryscene->addWidget(CloseGame);
    entryscene->addWidget(flouss);
    entryscene->addWidget(gr3);
    entryscene->addWidget(tb9);
    entryscene->addWidget(syoufa);
    Deckzone->addWidget(DeckLabel);
    Fieldzone->addWidget(Fieldlabel);
    entryscene->addWidget(HomeButton);
    entryscene->addWidget(Scores_History);
    entryscene->addItem(Easy_Score_Img);
    entryscene->addItem(Medium_Score_Img);
    entryscene->addItem(Hard_Score_Img);
    entryscene->addItem(First_Digit_Easy);
    entryscene->addItem(Second_Digit_Easy);
    entryscene->addItem(First_Digit_Medium);
    entryscene->addItem(Second_Digit_Medium);
    entryscene->addItem(First_Digit_Hard);
    entryscene->addItem(Second_Digit_Hard);
    entryscene->addWidget(overlayWidget);
    entryscene->addItem(CurrentHighScoreAsset);
    entryscene->addItem(First_Digit_Current_Score);
    entryscene->addItem(Second_Digit_Current_Score);
    entryscene->addItem (Tutorial_1);
    entryscene->addItem (Tutorial_2);
    entryscene->addWidget (After);
    entryscene->addWidget (Before);
    entryscene->addWidget (Exit);
    entryscene->addWidget(GIFLabel_Party_End);
    entryscene->addWidget(Main_Menu);
    entryscene->addWidget(Resume);
    entryscene ->addWidget(CardsSound);
    entryscene ->addItem (SoundEffect_Img);

    CurrentHighScoreAsset->hide();
    flouss->hide();
    gr3->hide();
    tb9->hide();
    syoufa->hide();
    CardsSound->hide ();
    Volume_Asset->hide();
    Backtomenu->hide();
    increaseVolumeButton->hide();
    additionalButton1->hide ();
    additionalButton2->hide ();
    additionalButton3->hide ();
    additionalButton4->hide ();
    additionalButton5->hide ();
    SoundEffect_Img->hide();
    GIFLabel_Party_End-> hide ();
    player2->hide ();
    overlayWidget->hide();
    Exit->hide ();
    Before->hide ();
    After->hide ();
    Tutorial_1->hide ();
    Tutorial_2->hide ();
    Easy-> hide ();
    Medium-> hide ();
    Hard-> hide ();
    Difficulty_Choice->hide();
    CloseGame->hide ();
    Easy_Score_Img->hide ();
    Medium_Score_Img->hide ();
    Hard_Score_Img->hide ();
    Scores_History->hide ();
    CenterElement->hide();
    Main_Menu->hide();
    Fieldlabel->hide();
    LeftElement->hide();
    Resume->hide();
    DeckLabel->hide();
    HandLabel->hide();
    NPCLabel->hide();
    player1->hide();
    HandPanel_AI_player->hide ();
    HandPanel_player->hide ();
    Backtomenu_3->hide ();
    HomeButton->hide ();

    connect(StartingGame, &QPushButton::clicked, this,&uiscene::Difficulty);
    connect (Easy, &QPushButton::clicked, this,[=]{
        if (!insideHelp){
            Difficulty_value = 1;
            StartnewGame ();
        } else {
            qDebug () << " You're inside the help ";
        }
    });
    connect (Medium, &QPushButton::clicked, this,[=]{
        if (!insideHelp){
            Difficulty_value = 2;
            StartnewGame ();
        } else {
            qDebug () << " You're inside the help ";
        }
    });
    connect (Hard, &QPushButton::clicked, this,[=]{
        if (!insideHelp){
            Difficulty_value = 3;
            StartnewGame ();
        } else {
            qDebug () << " You're inside the help ";
        }
    });
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
    playlist->setSource(QUrl::fromLocalFile(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Audio/GameMusic1.m4a"));
    //Credit : https://www.youtube.com/watch?v=yuvjuL--gnQ (We were here guitar cover)
    playlist->setLoops(QMediaPlayer::Infinite);
    audioOutput = new QAudioOutput;
    audioOutput->setVolume(0.6);
    playlist->setAudioOutput(audioOutput);
    playlist->play();

    view->show();
}
uiscene::~uiscene() {}
void uiscene::ResumeGame () {
    this->insideHelp = true; // to avoid creating a new variable just to stop the player from missing with the cards while the game is on
    overlayWidget->show();
    Main_Menu->show ();
    Resume->show ();
    connect (Resume,&QPushButton::clicked, this , [=]{
        overlayWidget->hide ();
        Main_Menu->hide ();
        Resume->hide ();
        this ->insideHelp = false;
    });
    connect (Main_Menu,&QPushButton::clicked,this , [=]{
        overlayWidget->hide ();
        Main_Menu->hide ();
        Resume->hide ();
        this->Home();
    });
}
void uiscene::ScoreHistorySetting() {
    this->disconnectSettings();
    qDebug()<<"I will see the Score history ...";
    this->ReadingScores();

    QString numberFolderPath = GameFolderPath + "/Gamefolder/CardGameQt/Assets/Numbers/";

    QString firstDigitEasyPath = numberFolderPath + QString::number(Easy_Score/10) + ".png";
    qDebug () << firstDigitEasyPath;
    First_Digit_Easy->setPixmap(QPixmap(firstDigitEasyPath).scaledToHeight(55));
    First_Digit_Easy->setPos(725, 138);

    QString secondDigitEasyPath = numberFolderPath + QString::number(Easy_Score%10) + ".png";
    qDebug () << secondDigitEasyPath;
    Second_Digit_Easy->setPixmap(QPixmap(secondDigitEasyPath).scaledToHeight(55));
    Second_Digit_Easy->setPos(770, 138);

    QString firstDigitMediumPath = numberFolderPath + QString::number(Medium_Score/10) + ".png";
    qDebug () << firstDigitMediumPath;
    First_Digit_Medium->setPixmap(QPixmap(firstDigitMediumPath).scaledToHeight(55));
    First_Digit_Medium->setPos(775, 290);

    QString secondDigitMediumPath = numberFolderPath + QString::number(Medium_Score%10) + ".png";
    qDebug () << secondDigitMediumPath;
    Second_Digit_Medium->setPixmap(QPixmap(secondDigitMediumPath).scaledToHeight(55));
    Second_Digit_Medium->setPos(820, 290);

    QString firstDigitHardPath = numberFolderPath + QString::number(Hard_Score/10) + ".png";
    qDebug () << firstDigitHardPath;
    First_Digit_Hard->setPixmap(QPixmap(firstDigitHardPath).scaledToHeight(55));
    First_Digit_Hard->setPos(725, 440);

    QString secondDigitHardPath = numberFolderPath + QString::number(Hard_Score%10) + ".png";
    qDebug () << secondDigitHardPath;
    Second_Digit_Hard->setPixmap(QPixmap(secondDigitHardPath).scaledToHeight(55));
    Second_Digit_Hard->setPos(770, 440);

    First_Digit_Easy-> show();
    Second_Digit_Easy-> show ();
    First_Digit_Medium-> show ();
    Second_Digit_Medium-> show ();
    First_Digit_Hard-> show ();
    Second_Digit_Hard-> show ();

    Backtomenu_3->show ();
    Volume_Asset->hide ();
    increaseVolumeButton->hide ();
    Easy_Score_Img->show ();
    Medium_Score_Img->show ();
    Hard_Score_Img->show ();
    connect(Backtomenu_3,&QPushButton::clicked,this,[=]{
        Backtomenu_3->hide ();
        Easy_Score_Img->hide ();
        Medium_Score_Img->hide ();
        Hard_Score_Img->hide ();
        this->ChangeSettings();
        First_Digit_Easy-> hide ();
        Second_Digit_Easy-> hide ();
        First_Digit_Medium-> hide ();
        Second_Digit_Medium-> hide ();
        First_Digit_Hard-> hide ();
        Second_Digit_Hard-> hide ();
    });
}
void uiscene::StartnewGame() {
    if (!insideHelp){
        Difficulty_Choice->hide();
        Easy->hide();
        Medium->hide();
        Hard->hide();
        Backtomenu_2->hide();
        //view->close();
        Settings->hide ();
        HomeButton->show();
        createNewScene();
    } else {
        qDebug () << " You're inside the help ";
    }
}
void uiscene::createNewScene() {
    this->PartyStarted = true ; /* Bool to show that the game started */
    CenterElement->show();
    Fieldlabel->show();
    LeftElement->show();
    DeckLabel->show();
    HandLabel->show();
    NPCLabel->show();
    player1->show();
    HandPanel_AI_player->show ();
    HandPanel_player->show ();

    qDebug()<<"I load the new game";

    int xPos = 100;
    int yPos = 550;
    player1->move(xPos, yPos);

    QString Backgroundpath = (GameFolderPath + "/Gamefolder/CardGameQt/Assets/BackGround/BCK%1.png").arg(this->Difficulty_value);
    backgroundImage->setPixmap(QPixmap(Backgroundpath));

    QString player2Imgpath = (GameFolderPath + "/Gamefolder/CardGameQt/Assets/BackGround/DiffImg%1.png").arg(this->Difficulty_value);
    player2->setPixmap(QPixmap(player2Imgpath).scaled(150,150));
    player2->setStyleSheet("background-color: transparent;");
    player2->move(100,50);

    NewDeck = new Deckk;

    Tapis = new field(*NewDeck);

    qDebug () << " Deck now have : "<< NewDeck->getDeckCards();

    AI_player = new npc(NewDeck,Tapis,Difficulty_value);

    NPCLabel->setLayout(NPC_hand);
    NPCLabel->setFixedWidth(700);
    NPCLabel->setFixedHeight(170);
    xPos = (entryscene->width() - NPCLabel->width()) / 2;
    yPos = 20;
    NPCLabel->move(xPos, yPos);
    NPCLabel->setStyleSheet("background-color: transparent;");

    P1 = new Player(NewDeck,Tapis);

    HandLabel->setLayout(Player_hand);
    HandLabel->setFixedWidth(680);
    HandLabel->setFixedHeight(170);
    xPos = (entryscene->width() - HandLabel->width()) / 2;
    yPos = (entryscene->height() - HandLabel->height()-35);
    HandLabel->move(xPos, yPos);
    HandLabel->setStyleSheet("background-color: transparent;");
    qDebug() << HandLabel->size();

    Deck_Img = NewDeck->getImgDeck();
    DeckLabel->setPixmap(QPixmap(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Cards/BackCard.png").scaled (100, 162));
    DeckLabel->setGeometry(363, 124, 100, 162);
    DeckLabel->setFixedSize(100, 162);
    DeckLabel->setStyleSheet("background-color: transparent");

    LeftElement->setLayout(Deckzone);
    LeftElement->setFixedSize(120, 190);
    xPos = entryscene->width() - (Deck_Img->width()*2.5);
    yPos = (entryscene->height() - Deck_Img->height()) / 2 ;
    LeftElement->move(xPos, yPos);
    LeftElement->setStyleSheet("background-color: transparent;");
    qDebug () << "Passed the check 5";

    LeftElement->installEventFilter(this);

    Field_Img = Tapis->getImgField();

    Fieldlabel->setPixmap(QPixmap::fromImage(*Field_Img));
    Fieldlabel->setFixedSize(Field_Img->width(), Field_Img->height());
    Fieldlabel->setStyleSheet("background-color: transparent;");


    qDebug () << "Passed the check 6";

    CenterElement->setLayout(Fieldzone);
    CenterElement->setFixedSize(Fieldlabel->width()+20, Fieldlabel->height()+20);
    CenterElement->move(((entryscene->width() - Fieldlabel->width() -20) / 2), ((entryscene->height() - Fieldlabel->height()-20) / 2));
    CenterElement->setStyleSheet("background-color: transparent;");

    loadinggamelogic = new GameLogic(*NewDeck,*P1,*AI_player,*Tapis);

    NewDeck->shuffle();
    QTimer::singleShot(1000, this, [&]() {
        loadinggamelogic->StartingGame();
    });

    connect (this,&uiscene::swappingturns,loadinggamelogic, &GameLogic::startPlayer1Turn);
    connect (loadinggamelogic, &GameLogic::player2droppingcard,this, &uiscene::NpcCardHandler);
    connect(this, &uiscene::drawCardSignal, this, &uiscene::drawCardOnClick);
    connect(P1, &Player::CurrentCard, this, &uiscene::handleCardClick);
    connect(loadinggamelogic, &GameLogic::cardDrawnplayer1, this, &uiscene::CardDrawnPlayer);
    connect(loadinggamelogic, &GameLogic::cardDrawnplayer2, this, &uiscene::CardDrawnNpc);
    connect(loadinggamelogic, &GameLogic::tapisdraw,this, &uiscene::CardDrawnField);
    connect(flouss, &QPushButton::clicked, this, [=] {
        if (loadinggamelogic->getClickable()){
            gr3->hide();
            tb9->hide();
            syoufa->hide();
            loadinggamelogic->setChangingCardSuitvalue(1);
            qDebug () << "Im checking the value rn : "<< loadinggamelogic->getChangingCardSuitvalue();
            P1->setTurn();
            qDebug () << " Rak 7akm  daba flouss";
            emit ChangingDeckValue ();
        } else {
            qDebug() << "Machi nta li 7titi 7";
        }
    });
    connect(gr3, &QPushButton::clicked, this, [=] {
        if (loadinggamelogic->getClickable()){
            flouss->hide();
            tb9->hide();
            syoufa->hide();
            loadinggamelogic->setChangingCardSuitvalue(0);
            qDebug () << " Rak 7akm  daba gr3";
            qDebug () << "Im checking the value rn : "<< loadinggamelogic->getChangingCardSuitvalue();
            P1->setTurn();
            emit ChangingDeckValue ();
        } else {
            qDebug() << "Machi nta li 7titi 7";
        }
    });
    connect(tb9, &QPushButton::clicked, this, [=] {
        if (loadinggamelogic->getClickable()){
            gr3->hide();
            flouss->hide();
            syoufa->hide();
            loadinggamelogic->setChangingCardSuitvalue(3);
            qDebug () << "Im checking the value rn : "<< loadinggamelogic->getChangingCardSuitvalue();
            qDebug () << " Rak 7akm  daba tb9";
            P1->setTurn();
            emit ChangingDeckValue ();
        } else {
            qDebug() << "Machi nta li 7titi 7";
        }
    });
    connect(syoufa, &QPushButton::clicked, this, [=] {
        if (loadinggamelogic->getClickable()){
            gr3->hide();
            tb9->hide();
            flouss->hide();
            loadinggamelogic->setChangingCardSuitvalue(2);
            qDebug () << "Im checking the value rn : "<< loadinggamelogic->getChangingCardSuitvalue();
            qDebug () << " Rak 7akm  daba syoufa";
            P1->setTurn();
            emit ChangingDeckValue ();
        } else {
            qDebug() << "Machi nta li 7titi 7";
        }
    });
    connect(HomeButton,&QPushButton::clicked,this,[=]{
        if (loadinggamelogic->getPlayingtheGame()) { // to disable the button when the game starts to avoid any problem.
            this->ResumeGame ();
        }
    });
    connect (this,&uiscene::NpcChoosingSuit,this,&uiscene::CallingtheNpcChange);
    connect (loadinggamelogic,&GameLogic::NpcChangingsuit,this,&uiscene::CallingtheNpcChange);
    connect (loadinggamelogic,&GameLogic::HideAllButtons,this,&uiscene::HiddingButtons);
    connect (this, &uiscene::ChangingDeckValue,loadinggamelogic, &GameLogic::ChangingCurrentSuit);
    connect (this, &uiscene::DisplayThechoices,this,&uiscene::ShowingButtons);
    connect (loadinggamelogic, &GameLogic::GoingBackToNormal,loadinggamelogic,&GameLogic::startPlayer1Turn);
    connect (this, &uiscene::CurrentRoundEnded,this, [=]{
        qDebug () << "I will switch the scene.";
        this->HiddingButtons();
        this->DeleteAllCards();
        delete P1;
        P1 = nullptr;
        delete AI_player;
        AI_player = nullptr;
        delete Tapis;
        Tapis = nullptr;
        delete NewDeck;
        NewDeck = nullptr;
        NPCLabel->hide();
        player1->hide();
        player2->hide ();
        HandLabel->hide();
        LeftElement->hide();
        CenterElement->hide();
        HandPanel_AI_player-> hide ();
        HandPanel_player-> hide ();
        GameEnded ();

    });

    player2->show ();
    overlayWidget->hide();
    Exit->hide ();
    Before->hide ();
    After->hide ();
    Tutorial_1->hide ();
    Tutorial_2->hide ();
}
void uiscene::disconnectAllSignals() {
    // Disconnect all signals used for the Game scene
    disconnect(this, &uiscene::swappingturns, loadinggamelogic, &GameLogic::startPlayer1Turn);
    disconnect(loadinggamelogic, &GameLogic::player2droppingcard, this, &uiscene::NpcCardHandler);
    disconnect(this, &uiscene::drawCardSignal, this, &uiscene::drawCardOnClick);
    disconnect(P1, &Player::CurrentCard, this, &uiscene::handleCardClick);
    disconnect(loadinggamelogic, &GameLogic::cardDrawnplayer1, this, &uiscene::CardDrawnPlayer);
    disconnect(loadinggamelogic, &GameLogic::cardDrawnplayer2, this, &uiscene::CardDrawnNpc);
    disconnect(loadinggamelogic, &GameLogic::tapisdraw, this, &uiscene::CardDrawnField);
    disconnect(flouss, &QPushButton::clicked, this, nullptr);
    disconnect(gr3, &QPushButton::clicked, this, nullptr);
    disconnect(tb9, &QPushButton::clicked, this, nullptr);
    disconnect(syoufa, &QPushButton::clicked, this, nullptr);
    disconnect(Resume,&QPushButton::clicked,this , nullptr);
    disconnect (Main_Menu,&QPushButton::clicked,this , nullptr);
    disconnect (NextGame, &QPushButton::clicked, this,nullptr);
    disconnect (this, &uiscene::CurrentRoundEnded,this, nullptr);
    disconnect (this,&uiscene::NpcChoosingSuit,this,&uiscene::CallingtheNpcChange);
    disconnect (loadinggamelogic,&GameLogic::NpcChangingsuit,this,&uiscene::CallingtheNpcChange);
    disconnect (loadinggamelogic,&GameLogic::HideAllButtons,this,&uiscene::HiddingButtons);
    disconnect (this, &uiscene::ChangingDeckValue,loadinggamelogic, &GameLogic::ChangingCurrentSuit);
    disconnect (this, &uiscene::DisplayThechoices,this,&uiscene::ShowingButtons);
    disconnect (loadinggamelogic, &GameLogic::GoingBackToNormal,loadinggamelogic,&GameLogic::startPlayer1Turn);
}
void uiscene::CallingtheNpcChange () {
    if (loadinggamelogic->getChangingCardSuitvalue()){
        HiddingButtons();
    } else {
        qDebug () << " No need to change any value ";
    }
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
void uiscene::Home () {
    if (this->PartyStarted){
        qDebug () << "I will go back to the first menu ...";
        this->HiddingButtons();
        this ->insideHelp = false;
        this ->DeleteAllCards();
        delete P1;
        P1 = nullptr;
        delete AI_player;
        AI_player = nullptr;
        delete Tapis;
        Tapis = nullptr;
        delete NewDeck;
        NewDeck = nullptr;
        NPCLabel->hide();
        player1->hide();
        player2->hide ();
        HandLabel->hide();
        LeftElement->hide();
        CenterElement->hide();
        HandPanel_AI_player-> hide ();
        HandPanel_player-> hide ();
        this->disconnectAllSignals();
    } else {
        CloseGame->hide ();
        NextGame->hide ();
    }
    HomeButton->hide ();
    backgroundImage->setPixmap(QPixmap(GameFolderPath +"/Gamefolder/CardGameQt/Assets/BackGround/Backgroundui.png"));
    Quit->show();
    Help->show();
    Settings->show();
    StartingGame->show();
}
void uiscene::GameEnded () {
    this->highScore();
    CurrentHighScoreAsset->show();
    PartyStarted = false ; /*Bool that shows that the game ended */
    backgroundImage->setPixmap(QPixmap(GameFolderPath +"/Gamefolder/CardGameQt/Assets/BackGround/Backgroundui.png"));
    Help-> hide ();
    CloseGame->show();
    NextGame->show();
    HomeButton->hide ();


    qDebug () << "Entering the new scene...";

    int Currenthighscore = this-> Winning_streak; // its the current score

    QString numberFolderPath = GameFolderPath + "/Gamefolder/CardGameQt/Assets/Numbers/";

    QString CurrentScoreDigit_1_Path = numberFolderPath + QString::number(Currenthighscore/10) + ".png";
    qDebug () << CurrentScoreDigit_1_Path;
    First_Digit_Current_Score->setPixmap(QPixmap(CurrentScoreDigit_1_Path).scaledToHeight(50));
    First_Digit_Current_Score->setPos(188 , 250);

    QString CurrentScoreDigit_2_Path = numberFolderPath + QString::number(Currenthighscore%10) + ".png";
    qDebug () << CurrentScoreDigit_2_Path;
    Second_Digit_Current_Score->setPixmap(QPixmap(CurrentScoreDigit_2_Path).scaledToHeight(50));
    Second_Digit_Current_Score->setPos(232, 250);

    GIFS_Party_WinStreak = new QMovie;
    WinSound = new QMediaPlayer;
    GIFS_Party_WinStreak_Label = new QLabel;
    WinAudioOutput = new QAudioOutput;
    QString NewHighScoreAudioPath ;
    GIFS_Party_End = new QMovie;
    GIFS_Party_WinStreak_Label->hide ();
    entryscene ->addWidget(GIFS_Party_WinStreak_Label);
    qDebug () << "First : "<< Winning_streak<< "Second : "<<Currenthighscore;
    if (this->Winning_streak != 0){
        if (this->Winning_streak == Currenthighscore) {
            GIFS_Party_WinStreak->setFileName(QString(GameFolderPath +"/Gamefolder/CardGameQt/Assets/GameEndedGif/NewScore.gif"));
            GIFS_Party_WinStreak->setScaledSize(QSize(60, 60));
            GIFS_Party_WinStreak->setBackgroundColor(QColor(0, 0, 0, 0));
            GIFS_Party_WinStreak->start();
            GIFS_Party_WinStreak->loopCount();
            GIFS_Party_WinStreak_Label->setAttribute(Qt::WA_TranslucentBackground, true); // transparency
            GIFS_Party_WinStreak_Label->setMovie(GIFS_Party_WinStreak);
            GIFS_Party_WinStreak_Label->move(341, 217 );
            GIFS_Party_WinStreak_Label->setFixedHeight(60);
            GIFS_Party_WinStreak_Label->setFixedWidth(60);
            GIFS_Party_WinStreak_Label->show();
            if (this ->Difficulty_value == 3) {
                NewHighScoreAudioPath = GameFolderPath + "/Gamefolder/CardGameQt/Assets/Audio/NewHighScore2.mp3";
            } else {
                NewHighScoreAudioPath = GameFolderPath + "/Gamefolder/CardGameQt/Assets/Audio/NewHighScore1.mp3";
            }
        } else {
            NewHighScoreAudioPath = GameFolderPath + "/Gamefolder/CardGameQt/Assets/Audio/Win1Game.mp3";
        }
        qDebug () << NewHighScoreAudioPath;
        WinSound->setSource(QUrl::fromLocalFile(QString(NewHighScoreAudioPath)));
        WinAudioOutput->setVolume(this->SoundEffect_Volume);  // Adjust the volume as needed
        WinSound->setAudioOutput(WinAudioOutput);
        WinSound->play();
    }

    QString result = PartyWinner ? "win" : "lose";
    int RandomGif_nbr = QRandomGenerator::global()->bounded(1, 4);
    QString EndGameGIF = QString(GameFolderPath + "/Gamefolder/CardGameQt/Assets/GameEndedGif/%1%2.gif").arg(result).arg(RandomGif_nbr);

    GIFS_Party_End->setFileName(EndGameGIF);
    GIFS_Party_End->setScaledSize(QSize(300, 150));
    GIFS_Party_End->start();
    GIFS_Party_End->loopCount();

    GIFLabel_Party_End->setMovie(GIFS_Party_End);
    GIFLabel_Party_End->move(500, 100);
    GIFLabel_Party_End->setFixedHeight(150);
    GIFLabel_Party_End->setFixedWidth(300);
    GIFLabel_Party_End->show();


    CloseGame->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/QUIT.png"));
    CloseGame->setIconSize(QSize(500, 500));
    CloseGame->setFixedSize(500, 150);
    CloseGame->setStyleSheet("background-color: transparent;");
    CloseGame->move(385, 530);

    Main_Menu->move(385, 400);

    Main_Menu->show();
    First_Digit_Current_Score->show();
    Second_Digit_Current_Score->show();

    if (PartyWinner){
        NextGame->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/RESTART.png"));
        NextGame->move(415, 250);
    } else {
        NextGame->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/TRYAGAIN.png"));
        NextGame->move(400, 250);
    }
    NextGame->setIconSize(QSize(500, 500));
    NextGame->setFixedSize(500, 150);
    NextGame->setStyleSheet("background-color: transparent;");

    GIFLabel_Party_End-> show ();
    qDebug () << "Waiting for your new decision ...";
    connect (CloseGame, &QPushButton::clicked, this,&uiscene::QuitGame);

    connect(NextGame, &QPushButton::clicked, this, [=] {
        if (GIFS_Party_WinStreak) {
            delete GIFS_Party_WinStreak;
            GIFS_Party_WinStreak = nullptr;
            delete GIFS_Party_WinStreak_Label;
            GIFS_Party_WinStreak_Label =nullptr;
            delete WinSound;
            WinSound = nullptr;
        } else if (WinAudioOutput) {
            delete WinAudioOutput;
            WinAudioOutput = nullptr;
        }
        delete GIFS_Party_End;
        this->PartyWinner = false;
        GIFS_Party_End = nullptr;
        this->disconnectAllSignals();
        NextGame->hide();
        CloseGame->hide();
        CurrentHighScoreAsset->hide();
        First_Digit_Current_Score->hide();
        Second_Digit_Current_Score->hide();
        GIFLabel_Party_End->hide();
        Help->show();
        HomeButton->show();
        createNewScene ();
        Main_Menu->move(400,375);
        Main_Menu->hide();
        qDebug () << "Playing again ...";
    });
    connect (Main_Menu,&QPushButton::clicked,this , [=]{
        delete GIFS_Party_End;
        GIFS_Party_End = nullptr;
        this->disconnectAllSignals();
        NextGame->hide();
        CloseGame->hide();
        CurrentHighScoreAsset->hide();
        First_Digit_Current_Score->hide();
        Second_Digit_Current_Score->hide();
        GIFLabel_Party_End->hide();
        Main_Menu->hide ();
        this->Home();
    });
}
void uiscene::CardDrawnField() {
    this->CarddrawSound ();
    qDebug () << " i give card to the field";
    Tapis->DrawCard(*NewDeck);
    Field_Img = Tapis->ShowCardImg();
    //Fieldlabel->setFixedSize(tempImg->width(), tempImg->height());
    Fieldlabel->setPixmap(QPixmap::fromImage(*Field_Img));
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
    //qDebug () << NewDeck->getDeckCards();
    this->CarddrawSound ();
    QVBoxLayout* temp = AI_player->Drawcard();
    NPC_hand->addLayout(temp);
    if(loadinggamelogic->getPlayingtheGame()){
        if (!Tapis->EmptyField() && Tapis->getCurrentCard()%10 == 7) {
            qDebug () <<" (NPC) I pass my turn with 7 on the field. ";
            emit ChangingDeckValue ();
        } else if (!Tapis->EmptyField() && Tapis->getCurrentCard()%10 == 2) {
            qDebug () <<" (NPC) 3ad 3tani nhz 2";
        } else {
            qDebug () <<" (NPC) I passed my turn . ";
            emit swappingturns();
        }
    } else {
        qDebug () << "I'm still giving cards . ";
    }
}
void uiscene::ChangeSettings(){
    qDebug()<<"I will change settings";
    this->disconnectSettings();
    Help->hide();
    Backtomenu->show ();
    SoundEffect_Img->show();
    Volume_Asset->show ();
    Scores_History->show ();
    increaseVolumeButton->show();
    CardsSound->show ();
    Quit->hide();
    Settings->hide();
    StartingGame->hide();

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

    SoundEffect_Img ->setPos(1000,0);
    currentVolume = audioOutput->volume() * 10;

    connect(CardsSound,&QPushButton::clicked, this, [=]() {
        qDebug () << "Changing Volume sound effects ...";
        if(SoundEffect_Volume == 0.0){
            this->SoundEffect_Volume = 0.6;
            CardsSound->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/CARDSOUNDON.png"));
        } else {
            this->SoundEffect_Volume  = 0.0;
            CardsSound->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/CARDSOUNDOFF.png"));

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
    connect(Scores_History,&QPushButton::clicked,this,[=]{
        Volume_Asset->hide();
        Backtomenu->hide();
        CardsSound->hide ();
        SoundEffect_Img->hide();
        increaseVolumeButton->hide();
        additionalButton1->hide ();
        additionalButton2->hide ();
        additionalButton3->hide ();
        additionalButton4->hide ();
        additionalButton5->hide ();
        Scores_History->hide ();
        ScoreHistorySetting();
    });
    connect(Backtomenu,&QPushButton::clicked,this,[=](){
        qDebug()<<"Im gonna go back";
        Volume_Asset->hide();
        Backtomenu->hide();
        SoundEffect_Img->hide();
        CardsSound->hide ();
        increaseVolumeButton->hide();
        additionalButton1->hide ();
        additionalButton2->hide ();
        additionalButton3->hide ();
        additionalButton4->hide ();
        additionalButton5->hide ();
        Scores_History->hide ();
        Quit->show();
        Help->show();
        Settings->show();
        StartingGame->show();
    });
}
void uiscene::disconnectSettings () {
    disconnect(additionalButton5, &QPushButton::clicked, this,nullptr);
    disconnect(additionalButton4, &QPushButton::clicked, this,nullptr);
    disconnect(additionalButton3, &QPushButton::clicked, this,nullptr);
    disconnect(additionalButton2, &QPushButton::clicked, this,nullptr);
    disconnect(additionalButton1, &QPushButton::clicked, this,nullptr);
    disconnect(Backtomenu,&QPushButton::clicked,this,nullptr);
    disconnect(Scores_History,&QPushButton::clicked,this,nullptr);
    disconnect(CardsSound,&QPushButton::clicked, this,nullptr);
}
void uiscene::Difficulty () {
    qDebug()<<"I will choose the difficulty ...";

    Quit->hide();
    Settings->hide();
    StartingGame->hide();

    Backtomenu_2->show();
    Easy->show();
    Medium->show();
    Hard->show();
    Difficulty_Choice->show();

    connect (Backtomenu_2,&QPushButton::clicked,this ,[=]{
        Quit->show();
        Settings->show();
        StartingGame->show();

        Backtomenu_2->hide();
        Easy->hide();
        Medium->hide();
        Hard->hide();
        Difficulty_Choice->hide();
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
    Tapis->RefillEmptyDeck(*NewDeck);
    qDebug () << "i m checking card suit " << loadinggamelogic->getinsindesuitvalue();
    qDebug () << NewDeck->getDeckCards().size();
    if (P1->getGamestarted() == true && !insideHelp){
        if (P1->getTurn()){
            qDebug() << "";
            QVBoxLayout* temp =P1->Drawcard();
            this->CarddrawSound ();
            Player_hand->addLayout(temp);
            qDebug() << Player_hand;
            P1->setTurn();
            if (Tapis->getCurrentCard()%10 == 7){
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
    qDebug () <<  "logic of game ..."<< loadinggamelogic->getinsindesuitvalue() ; // INSIDE THE 7 LOGIC OR NOT
    if (P1->getTurn()){
    if(loadinggamelogic->getinsindesuitvalue() == false && !insideHelp){
        if (cardsuitcheck ==Tapis->getcardsuit() || cardrankcheck == Tapis->getcardrank()){
            emit swappingturns();
            qDebug () << " U can put a card ...";
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
                this->Winning_streak++;
                emit CurrentRoundEnded ();
            } else if (AI_player->isEmpty()){
                this->PartyWinner = false;
                Winning_streak = 0;
                emit  CurrentRoundEnded();
            } else {
                if ((P1->getSelectedCard()%10) == 7){
                    if ( loadinggamelogic->getClickable() == false){
                        loadinggamelogic->setClickable();
                    } else {
                        qDebug () << "Working fine ... ";
                    }
                    P1->SetSelectedCard(-1);
                    emit DisplayThechoices();
                } else if (P1->getSelectedCard()%10 == 2){
                    qDebug () << "rak yallah 3titih ihz 2, mazal atl3b";
                } else if(P1->getSelectedCard()%10 == 1){
                    qDebug () << "rak yallah 3titih ihz 1, mazal atl3b";
                } else {
                    P1->setTurn ();
                    P1->SetSelectedCard(-1);
                    qDebug () << "I crashed rn";
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
            loadinggamelogic->setinsindesuitvalue();
            if (P1->isEmpty()){
                PartyWinner = true;
                P1->setWin();
                this->Winning_streak++;
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
    } else {
        qDebug () <<"Not ur turn ..";
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
void uiscene::DeleteAllCards() { /* Clearing all cards similarly to the delete cards of player and npc */
    qDebug() << " I'm gonna delete the cards ...";
    // I dont call the condition to check if the game ended or not since the player can restart the game at any moment
    if (P1->getHandCardsize() > 0){
        while (P1->getHandCardsize() > 0){
            qDebug () << P1->getHandCardsize();
            int selectedIndex = P1->getHandElements().indexOf(P1->GetFirstCard());
            if (selectedIndex != -1) {
                QLayoutItem* item = Player_hand->itemAt(selectedIndex);
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
                                    qDebug() << "Deleted the element";
                                }
                            }
                        }
                    }
                    Player_hand->removeItem(item);
                    delete cardLayout;
                }
            } else {
                qDebug() << "No card in hand ser, Everything has been deleted successfully";
            }
        }
    } else {
        qDebug ()<< "No cards in hand ..";
    }
    if (!AI_player->isEmpty()){
        qDebug () << AI_player->getHandCards();
        qDebug () << AI_player->getHandCardsize();
        while (AI_player->getHandCardsize() > 0) {
            qDebug () <<"(NPC) I have in hands : "<< AI_player->getHandCardsize();
            int selectedIndex = AI_player->getHandCards().indexOf(AI_player->getFirstCard());
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
                                    qDebug() << "Deleted the element";
                                }
                            }
                        }
                    }
                    NPC_hand->removeItem(item);
                    delete cardLayout;
                }
            } else {
                qDebug() << "(NPC)No card in hand ser, Everything has been deleted successfully";
            }
        }
    } else {
        qDebug ()<< "No cards in hand ..";
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
        this->PartyWinner = false;
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
    CarddropAudio->setSource(QUrl::fromLocalFile(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Audio/Crarddrop.m4a"));
    QAudioOutput* CardShuffleSound = new QAudioOutput;
    CardShuffleSound->setVolume (SoundEffect_Volume);
    CarddropAudio->setAudioOutput(CardShuffleSound);
    CarddropAudio->play();
};
void uiscene::CarddrawSound () {
    QMediaPlayer* CarddawAudio = new QMediaPlayer;
    CarddawAudio->setSource(QUrl::fromLocalFile(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Audio/FlippingCard.mp3"));
    QAudioOutput* CardShuffleSound = new QAudioOutput;
    CardShuffleSound->setVolume (SoundEffect_Volume);
    CarddawAudio->setAudioOutput(CardShuffleSound);
    CarddawAudio->play();
}
void uiscene::ShowHelp (){
    Backtomenu_2->hide();
    Help->hide ();
    insideHelp = true;
    qDebug () << "I enter the tutorial ..." << insideHelp;
    Tutorial_1->setPixmap(QPixmap(GameFolderPath +"/Gamefolder/CardGameQt/Assets/BackGround/TUTORIAL1.png"));
    Tutorial_2->setPixmap(QPixmap(GameFolderPath +"/Gamefolder/CardGameQt/Assets/BackGround/TUTORIAL2.png"));

    After->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/AFTER.png"));
    After->setIconSize(QSize(100, 100));
    After->setFixedSize(100, 100);
    After->setStyleSheet("background-color: transparent;");
    After->move(1100, 600);

    Before->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/BEFORE.png"));
    Before->setIconSize(QSize(100, 100));
    Before->setFixedSize(100, 100);
    Before->setStyleSheet("background-color: transparent;");
    Before->move(1100, 600);

    Exit->setIcon(QIcon(GameFolderPath +"/Gamefolder/CardGameQt/Assets/Buttons/EXIT.png"));
    Exit->setIconSize(QSize(60, 60));
    Exit->setFixedSize(60, 60);
    Exit->setStyleSheet("background-color: transparent;");
    Exit->move(1200, 10);

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
        if(Settings->isHidden() && this->PartyStarted == false){ // since the button needs to appear when the game starts, PartyStarted condition has been added
            Backtomenu_2->show ();
        }
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
int uiscene::highScore()
{
    documentPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString cardGameFolder = documentPath + "/Gamefolder/CardGameQt"; // folder that will be created inside the document folder
    QString filePath = cardGameFolder + "/CardGameData.txt"; // text file where we will store our high score data
    QDir cardGameDir(cardGameFolder); // to check if the folder exists or not
    if (!cardGameDir.exists()) {
        if (cardGameDir.mkpath(".")) {
            qDebug() << "CardGameQt folder created successfully.";
        } else {
            qDebug() << "[Error] Couldn't create CardGameQt folder.";
        }
    } else {
        qDebug() << "CardGameQt folder already exists.";
    }
    QFile file(filePath);
    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << "Highscore-Easy:0\n";
            stream << "Highscore-Medium:0\n";
            stream << "Highscore-Hard:0\n";
            file.close();
            qDebug() << "CardGameData.txt created successfully.";
        } else {
            qDebug() << "[Error] Failed to create CardGameData.txt.";
        }
    } else if (file.exists()) {
        QList<int> highScores;
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) { // Use ReadWrite to preserve existing content
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList parts = line.split(':');
                if (parts.size() == 2) {
                    highScores.append(parts[1].toInt());
                }
            }
            file.close(); // Close the file after reading

            CurrentHighScore = highScores.value(this->Difficulty_value - 1, 0); // Get the existing high score for the current difficulty
            if (Winning_streak > CurrentHighScore) {
                highScores[this->Difficulty_value - 1] = Winning_streak; // Update the high score if the current score is higher
                qDebug() << "New high score for the Difficulty Level " << this->Difficulty_value << " is : " << this->Winning_streak;
            } else {
                qDebug() << "Current Highscore is the same ...";
            }

            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                for (int i = 0; i < highScores.size(); ++i) {
                    out << "Highscore-" << (i + 1) << ":" << highScores[i] << "\n";
                }
                file.close();
                qDebug() << "High scores updated and saved.";
            } else {
                qDebug() << "[Error] Failed to open CardGameData.txt for writing.";
            }
        } else {
            qDebug() << "[Error] Failed to open CardGameData.txt for reading and writing.";
        }
    } else {
        qDebug() << "[Error] File does not exist. Please create it first.";
    }
    return CurrentHighScore;
}
void uiscene::ReadingScores () {
    documentPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString cardGameFolder = documentPath + "/Gamefolder/CardGameQt"; // folder that will be created inside the document folder
    QString filePath = cardGameFolder + "/CardGameData.txt"; // text file where we will store our high score data
    QDir cardGameDir(cardGameFolder); // to check if the folder exists or not
    if (!cardGameDir.exists()) {
        if (cardGameDir.mkpath(".")) {
            qDebug() << "CardGameQt folder created successfully.";
        } else {
            qDebug() << "[Error] Couldn't create CardGameQt folder.";
        }
    } else {
        qDebug() << "CardGameQt folder already exists.";
    }
    QFile file(filePath);
    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << "Highscore-1:0\n";
            stream << "Highscore-2:0\n";
            stream << "Highscore-3:0\n";
            file.close();
            qDebug() << "CardGameData.txt created successfully.";
        } else {
            qDebug() << "[Error] Failed to create CardGameData.txt.";
        }
    } else if(file.exists()){
        qDebug()<<"I'm checking the file ..";
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList parts = line.split(':');
                qDebug () << "size is : "<< parts.size();
                if (parts.size() == 2) {
                    QString difficulty = parts[0].trimmed();
                    int score = parts[1].toInt();
                    qDebug () << " Score is :"<<score<<" and Difficulty is : "<<difficulty;
                    if (difficulty == "Highscore-1") {
                        qDebug() << "Easy Score: " << score;
                        this->Easy_Score = score;
                    } else if (difficulty == "Highscore-2") {
                        qDebug() << "Medium Score: " << score;
                        this->Medium_Score = score;
                    } else if (difficulty == "Highscore-3") {
                        qDebug() << "Hard Score: " << score;
                        this->Hard_Score = score;
                    }
                }
            }
            file.close();
            qDebug() << "Scores read successfully.";
        } else {
            qDebug() << "[Error] Failed to open CardGameData.txt for reading.";
        }
    } else {
        qDebug () << "[Error] Couldn't read the file.";
    }
}
