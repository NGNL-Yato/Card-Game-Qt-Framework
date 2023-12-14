#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Deck.h"


Deck::Deck() : cards(40){
    initialize();
}
void Deck::initialize(){
    cards.clear();
    for(int i = 1 ; i <= SizeOfDeck ; i++ ){
        cards.push_back(Card(i));
    }
}
void Deck::shuffle(){
    std::random_device rd;
    std::mt19937 g(rd()); //random default seed to generate random number
    std::shuffle(cards.begin() , cards.end(), g);
}

Card Deck::drawCard()
{
    if (!cards.empty())
    {
        Card drawnCards = cards.back();
        cards.pop_back();
        usedCards.push_back(drawnCards);
        return drawnCards;
    }
    else
    {
        return Card(-1);
    }
}

void Deck::displayDeck() const {
    int i = 0;
    for ( auto Start = cards.begin() ; Start != cards.end(); Start++ ){
        std::cout << "Deck card " << i << ": ";
        Start->display();
        std::cout << std::endl;
        i++;
}
}

int Deck::getSizeDeck() const {
    return SizeOfDeck;
} 

bool Deck::IsDeckEmpty() const {
    return cards.empty();
}

Deck::~Deck(){}