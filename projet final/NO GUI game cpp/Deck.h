#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
public:
    Deck(); // Constructor
    ~Deck(); // Destructor

    void initialize(); // Initialize the deck with cards
    void shuffle(); // Shuffle the deck
    Card drawCard(); // Draw a card from the deck
    void displayDeck() const ; // Display all cards in the deck
    int getSizeDeck() const ; //Display the current size of the deck
    bool IsDeckEmpty() const ; //Verify if the deck is empty(will be used to store the usedcards and transfer them to the deck again)

private:
    std::vector<Card> cards;
    std::vector<Card> usedCards; 
    int SizeOfDeck = 40;
};

#endif // DECK_H
