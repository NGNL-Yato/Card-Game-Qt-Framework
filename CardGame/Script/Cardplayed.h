#ifndef CARDPLAYED_H
#define CARDPLAYED_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

#include "Cards.h"

class Cards;

class Cardplayed : public QWidget {
    Q_OBJECT
public :
    Cardplayed(Cards* ccard);
    ~Cardplayed();
private:
    Cards* deckcard;
    QVBoxLayout *layout;
    QLabel* labels[48];
    QHBoxLayout* Cucumber_box;
    QHBoxLayout* Gold_box;
    QHBoxLayout* Sword_box;
    QHBoxLayout* Table_box;

public :
    void play (int ccard);
    void add_card();
signals :
public slots :


};


#endif // CARDPLAYED_H
