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
    void ChangeSettings ();
    //void ChooseDifficulty();
    void QuitGame ();
    void createNewScene ();
    bool eventFilter (QObject* obj, QEvent* event);
    void drawCardOnClick ();
    void DeleteUsedCard ();
    void DeleteNPCUsedCard ();
    void CardDrawnPlayer();
    void CardDrawnNpc();
    void CardDrawnField();

private:
    QGraphicsScene* entryscene;
    QPushButton* StartingGame;
    QPushButton* Quit;
    QPushButton* Settings;
    QGraphicsView* view;
    QMediaPlayer *playlist;
    QAudioOutput* audioOutput;
    Player* P1;
    QWidget* LeftElement;
    QHBoxLayout* Player_hand;
    QHBoxLayout* NPC_hand;
    npc* AI_player;
    field Tapis;
    QLabel* Fieldlabel;
    Deckk NewDeck;
    QTimer* gameLoopTimer;
    bool isPlayer1Connected = false;
    GameLogic* loadinggamelogic;


signals:
    void drawCardSignal ();
    void handleCardClick (int cardNumber);
    void swappingturns ();
    void NpcCardHandler ();

};



#endif // UISCENE_H
