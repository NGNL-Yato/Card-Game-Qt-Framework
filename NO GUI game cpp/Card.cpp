// Card.cpp
#include "Card.h"
#include <iostream>

Card::Card() : card(-1), flipped(true) {
    rank; // Default rank value
    suit = "Empty"; // Default suit value for a flipped card
}

Card::Card(int card_) : card(card_),flipped(false){ 
    
    if (card > 0 && card <= 10) {
        rank = card;
        suit = "Syoufa";
    } else if (card > 10 && card <= 20) {
        rank = card - 10;
        suit = "Jbn";
    } else if (card > 20 && card <= 30) {
        rank = card - 20;
        suit = "Gr3";
    } else if (card > 30 && card <= 40) {
        rank = card - 30;
        suit = "Dhb";
    } else {
        std::cerr << "Invalid card number: " << card << std::endl;
        rank = 0;
        suit = "Unknown";
    }  
}

Card::~Card() {
    // Destructor
}

int Card::getRank() const {
    return rank;
}

std::string Card::getSuit() const {
    return suit;
}

void Card::display() const {
    if (flipped) {
        std::cout << "Flipped Card" << std::endl;
    } else {
        std::cout << rank << " of " << suit << std::endl;
    }
}

bool Card::isFlipped() const {
    return flipped;
}

void Card::flip() {
    flipped = true;
}