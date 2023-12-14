#ifndef CARDPLAYED_H
#define CARDPLAYED_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include "Deck.h"

class Deck;

class Cardplayed : public QWidget {
    Q_OBJECT
public :
    Cardplayed(Deck* cardd);
    ~Cardplayed();
private:
    Deck* deckcard;
    QVBoxLayout *layout;
    QLabel* labels[40];
    QHBoxLayout* Cucumber_box;
    QHBoxLayout* Gold_box;
    QHBoxLayout* Sword_box;
    QHBoxLayout* Table_box;

public :
    void play (int cardd);
    void add_card();
    void reset();

signals :
public slots :


};


#endif // CARDPLAYED_H
