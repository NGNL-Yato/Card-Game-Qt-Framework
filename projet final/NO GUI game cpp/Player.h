#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include "Deck.h"
#include <set>
#include <string>

class Player{
    public:
    Player (const std::string Name);
    ~Player ();
    void PlayerWinRound ();
    bool IsHandEmpty ();
    bool getTurn ();
    void AddCard();
    void DiscardFromHand();
    void RemoveCardFromHand(const Card& cardToRemove);
    void SwitchTurn();

    private:
    int score;      /*Number of parties won*/
    std::vector<Card> HandCards;
    std::string UserName;
    bool Turn;
    Deck *PlayerDeck;

};


#endif