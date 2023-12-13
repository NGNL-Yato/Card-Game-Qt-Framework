// Card.h
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
public:
    Card(); // Default constructor
    Card(int cardd); // Parameterized constructor
    ~Card(); // Destructor

    int getRank() const;
    std::string getSuit() const;
    void display() const;
    bool isFlipped() const;
    void flip();
    

private:
    int card;
    int rank;
    std::string suit;
    bool flipped;
};

#endif // CARD_H