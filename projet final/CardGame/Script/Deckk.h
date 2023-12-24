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
    float Volume;

public:
    Deckk();
    ~Deckk();
public slots:

    int drawSpecialcard();
    bool isEmpty();
    void shuffle();
    void Refill();
    int drawcard();
    QVector<int> getDeckCards();
    QImage* getImgDeck();
    void PushBack(int value);
    int getDecksize ();
    float SetVolume(float Volume);
    float GetVolume();
};

#endif // DECKK_H
