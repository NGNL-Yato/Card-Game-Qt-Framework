#ifndef Field_H
#define Field_H

#include <QObject>
#include <QVector>
#include "Deckk.h"
#include <QImage>
#include <QVBoxLayout>
#include <QString>

class field {
private:
    QVector<int> FieldCards[40];
    QVector<int> OldCards;
    Deckk* FieldDeck;
    QImage* FieldCurrentImage;

public:
    field(Deckk* deck);
    ~field();

public slots:
    int getCurrentCard();
    QImage* ShowCardImg();
    void RefillEmptyDeck();
    bool EmptyField();
    QImage* getImgField();
    void TakeCard (int cardnumber) ;
    int DrawCard (Deckk* deck);
    int getcardsuit();
    int getcardrank();
    QVector<int> getFieldcards ();
};

#endif //FIELD_H
