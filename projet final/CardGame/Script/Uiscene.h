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
    void DeleteAllCards();
public slots:
    void StartnewGame ();
    void GameEnded ();
    void ChangeSettings ();
    //void ChooseDifficulty();
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
    //void SwitchingtoLastScene ();
    void CallingtheNpcChange ();
    void CarddropSound ();
    void CarddrawSound ();
    void ShowHelp ();
    void Difficulty ();

private:
    QGraphicsScene* entryscene;
    QPushButton* StartingGame;
    QPushButton* Quit;
    QPushButton* Settings;
    QPushButton* Easy;
    QPushButton* Hard;
    QPushButton* Medium;
    QGraphicsPixmapItem* backgroundImage;
    QGraphicsPixmapItem* Difficulty_Choice;
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
    int currentVolume;
    int volumeCounter;
    int VolumeUp;
    int PartyWinner;
    int Winning_streak;
    QGraphicsView* view;
    QGraphicsView* newView;
    QGraphicsScene* newScene;
    QWidget* CenterElement;
    QVBoxLayout* Fieldzone;
    QVBoxLayout* Deckzone;
    QLabel* DeckLabel;
    QWidget* NPCLabel;
    QLabel * player1;
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
    bool PartyStarted;
    QImage* Deck_Img;
    int xPos;
    int yPos;
    QImage* Field_Img;
    int MainMenu;
    QGraphicsPixmapItem* HandPanel_player;
    QGraphicsPixmapItem* HandPanel_AI_player;
    QMovie* GIFS_Party_End;
    QLabel* GIFLabel_Party_End;


signals:
    void drawCardSignal ();
    void handleCardClick ();
    void swappingturns ();
    void NpcCardHandler ();
    void DisplayThechoices ();
    void ChangingDeckValue ();
    void NpcChoosingSuit ();
    void ChangingFieldSuitValue ();
    void CurrentRoundEnded ();
    void Choosing_Difficulty ();

};



#endif // UISCENE_H
