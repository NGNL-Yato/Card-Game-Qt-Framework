#ifndef RONDA_H
#define RONDA_H
#include <QObject>
#include <string.h>


const int SizeOfDeck = 48;  //Number Of card in the current deck
const int Not_Found = -1;

const std::string Plus_two_cards [4] = {"Cucumber_2","Gold_2","Sword_2","Table_2"};
const std::string Change_Type_cards [4] = {"Cucumber_7","Gold_7","Sword_7","Table_7"};
const std::string Skip_Turn_cards [4] = {"Cucumber_1","Gold_1","Sword_1","Table_1"};

class ronda : public QObject {
    Q_OBJECT
public:
    ronda();
    ~ronda();
private:
    bool cards_played[SizeOfDeck];
    bool Current_Turn;
    int Current_Card;
    std::string Winner;
    int Card_Left_deck;
    bool gameOver;
    std::string PlayerName;
    int Difficulty;
    int Default_Hand;
public:
    void Check_move(int CardThrown);
    void reset_Deck();
    void reset_score();
    void Next_Turn();
    void play();
    void Pass_Turn();
    void getPlayerCard(int card_d);
    void Add_Card_Hand();
    void new_game(bool startingnewgame);

signals:
    void sig_new_game();
    void sig_next_game();
    void sig_game_over();
    void sig_Current_turn();
    void sig_Add_Card_Hand();

};


#endif // RONDA_H
