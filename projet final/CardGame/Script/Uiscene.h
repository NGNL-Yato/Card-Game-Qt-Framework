#ifndef UISCENE_H
#define UISCENE_H
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QMediaPlayer>
#include <QHBoxLayout>
#include "Player.h"
#include "Npc.h"
#include "Field.h"
#include <QPointer>
#include <QtGlobal>
#include <QTimer>
#include "LogicOfgame.h"
#include <QMovie>

class uiscene : public QObject {
    Q_OBJECT
public:
    uiscene ();
    ~uiscene ();
public slots:
    void ReadingScores();
    void DeleteAllCards();
    int highScore();
    void StartnewGame ();
    void GameEnded ();
    void ChangeSettings ();
    void QuitGame ();
    void createNewScene ();
    bool eventFilter (QObject* obj, QEvent* event);
    void drawCardOnClick ();
    void DeleteUsedCard ();
    void DeleteNPCUsedCard ();
    void CardDrawnPlayer ();
    void CardDrawnNpc ();
    void CardDrawnField ();
    void ShowingButtons ();
    void HiddingButtons ();
    bool setskip ();
    bool getskip ();
    void CallingtheNpcChange ();
    void CarddropSound ();
    void CarddrawSound ();
    void ShowHelp ();
    void Difficulty ();
    void NpcCardHandler ();
    void handleCardClick ();
    void ScoreHistorySetting();
    void Home ();
    void disconnectAllSignals(); // The purpose of this function is to avoid duplication of signals : u need to clear them before reusing them
    void disconnectSettings();
    void ResumeGame();
private:
    QString GameFolderPath; //This is used to determine the relative path for all the directories that will contain pictures
    QString documentPath;
    QGraphicsScene* entryscene;
    QPushButton* StartingGame;
    QPushButton* Quit;
    QPushButton* Settings;
    QPushButton* Easy;
    QPushButton* Hard;
    QPushButton* Medium;
    QGraphicsPixmapItem* backgroundImage;
    QGraphicsPixmapItem* Difficulty_Choice;
    QPushButton* Scores_History;
    QGraphicsPixmapItem* Easy_Score_Img;
    QGraphicsPixmapItem* Medium_Score_Img;
    QGraphicsPixmapItem* Hard_Score_Img;
    QGraphicsScene* GameEndedScene;
    QPushButton* CloseGame;
    QPushButton* NextGame;
    QPushButton* Help;
    QPushButton* Before;
    QPushButton* Before_2;
    QPushButton* Exit;
    QPushButton* After;
    QPushButton* Backtomenu;
    QPushButton* Backtomenu_2;
    QPushButton* Backtomenu_3;
    QWidget* overlayWidget;
    QGraphicsPixmapItem* Tutorial_2;
    QGraphicsPixmapItem* Tutorial_1;
    QGraphicsPixmapItem* Volume_Asset;
    QPushButton* increaseVolumeButton;
    QPushButton* additionalButton1;
    QPushButton* additionalButton2;
    QPushButton* additionalButton3;
    QPushButton* additionalButton4;
    QPushButton* additionalButton5;
    QGraphicsPixmapItem* backgroundImageEntryScene;
    QGraphicsPixmapItem* First_Digit_Easy;
    QGraphicsPixmapItem* Second_Digit_Easy;
    QGraphicsPixmapItem* First_Digit_Medium;
    QGraphicsPixmapItem* Second_Digit_Medium;
    QGraphicsPixmapItem* First_Digit_Hard;
    QGraphicsPixmapItem* Second_Digit_Hard;
    QPushButton* HomeButton;
    int currentVolume;
    int volumeCounter;
    int VolumeUp;
    int PartyWinner;
    int Winning_streak;
    int score;
    int CurrentHighScore;
    QGraphicsView* view;
    QGraphicsView* newView;
    QGraphicsScene* newScene;
    QWidget* CenterElement;
    QVBoxLayout* Fieldzone;
    QVBoxLayout* Deckzone;
    QLabel* DeckLabel;
    QWidget* NPCLabel;
    QLabel* player1;
    QLabel* player2;
    QMediaPlayer *playlist;
    QAudioOutput* audioOutput;
    Player* P1;
    QWidget* LeftElement;
    QHBoxLayout* Player_hand;
    QHBoxLayout* NPC_hand;
    npc* AI_player;
    field* Tapis;
    QWidget* HandLabel;
    QLabel* Fieldlabel;
    Deckk* NewDeck;
    QTimer* gameLoopTimer;
    bool isPlayer1Connected = false;
    GameLogic* loadinggamelogic;
    QPushButton* syoufa;
    int value1;//1 for syoufa
    int value2;//2 for flouss
    int value3;//3 for tb9
    int value4;//4 for gr3
    QPushButton* flouss;
    QPushButton* tb9;
    QPushButton* gr3;
    int selectedButton = 0;
    bool Verifyingskip = false;
    bool insideHelp = false;
    int Difficulty_value;
    int Easy_Score;
    int Medium_Score;
    int Hard_Score;
    bool PartyStarted;
    QImage* Deck_Img;
    int xPos;
    int yPos;
    QImage* Field_Img;
    int MainMenu;
    QGraphicsPixmapItem* HandPanel_player;
    QGraphicsPixmapItem* HandPanel_AI_player;
    QGraphicsPixmapItem* SoundEffect_Img;
    QMovie* GIFS_Party_End;
    QLabel* GIFLabel_Party_End;
    QPushButton* Resume;
    QPushButton* Main_Menu;
    QPushButton* CardsSound;
    float SoundEffect_Volume;
    QGraphicsPixmapItem *CurrentHighScoreAsset;
    QGraphicsPixmapItem* First_Digit_Current_Score;
    QGraphicsPixmapItem* Second_Digit_Current_Score;
    QMovie* GIFS_Party_WinStreak;
    QMediaPlayer* WinSound;
    QLabel* GIFS_Party_WinStreak_Label;
    QAudioOutput* WinAudioOutput;

signals:
    void drawCardSignal ();
    void swappingturns ();
    void DisplayThechoices ();
    void ChangingDeckValue ();
    void NpcChoosingSuit ();
    void ChangingFieldSuitValue ();
    void CurrentRoundEnded ();
    void Choosing_Difficulty ();

};



#endif // UISCENE_H
