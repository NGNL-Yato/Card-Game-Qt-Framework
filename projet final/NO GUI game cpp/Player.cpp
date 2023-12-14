#include <vector>
#include "Player.h"
#include <string>
#include <iostream>

Player::Player(std::string Name) : UserName(Name), PlayerDeck(deck){
    score = 0;
    Turn = false;
    
}
Player::~Player(){};

bool Player::getTurn(){
    return Turn;
}

bool Player::IsHandEmpty(){
    return HandCards.empty();
}

void Player::PlayerWinRound(){
    if(IsHandEmpty()){
        score++;
    }
}

void Player::AddCard(){
    if (!PlayerDeck->IsDeckEmpty()) {
        Card drawnCard = PlayerDeck->drawCard();
        HandCards.push_back(drawnCard);
    }
}

void Player::RemoveCardFromHand(const Card& cardToRemove) {
    if (!IsHandEmpty()) {
        auto it = std::find(HandCards.begin(), HandCards.end(), cardToRemove);        
        cardToRemove.(it);
    }
}

void Player::SwitchTurn(){
    Turn = !Turn;
}