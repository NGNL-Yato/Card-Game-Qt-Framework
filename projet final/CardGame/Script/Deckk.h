#ifndef DECKK_H
#define DECKK_H
#include <QObject>
#include <QVector>
#include <QImage>

class Deckk {
private:
    QVector<int> Deck_cards;
    bool Empty;
    QImage* DeckBackward;

public:
    Deckk();
    ~Deckk();
public slots:

    bool isEmpty();
    void shuffle();
    void Refill();
    int drawcard();
    QVector<int> getDeckCards();
    QImage* getImgDeck();
    void PushBack(int value);

};

#endif // DECKK_H
