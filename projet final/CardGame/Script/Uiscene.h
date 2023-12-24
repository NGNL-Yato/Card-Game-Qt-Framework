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

class uiscene : public QObject {
    Q_OBJECT
public:
    uiscene ();
    ~uiscene ();
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
    void SwitchingtoLastScene ();
    void CallingtheNpcChange ();

private:
    QGraphicsScene* entryscene;
    QPushButton* StartingGame;
    QPushButton* Quit;
    QPushButton* Settings;
    QPushButton* increaseVolumeButton;
    QPushButton* additionalButton1;
    QPushButton* additionalButton2;
    QPushButton* additionalButton3;
    QPushButton* additionalButton4;
    QPushButton* additionalButton5;
    int currentVolume;
    int volumeCounter;
    int VolumeUp;
    QGraphicsView* view;
    QGraphicsView* newView;
    QGraphicsScene* newScene;
    QMediaPlayer *playlist;
    QAudioOutput* audioOutput;
    Player* P1;
    QWidget* LeftElement;
    QHBoxLayout* Player_hand;
    QHBoxLayout* NPC_hand;
    npc* AI_player;
    field* Tapis;
    QLabel* Fieldlabel;
    Deckk NewDeck;
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

};



#endif // UISCENE_H
