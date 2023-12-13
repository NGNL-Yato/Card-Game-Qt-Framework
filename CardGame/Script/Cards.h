#ifndef CARDS_H
#define CARDS_H
#include <QGraphicsRectItem>
#include <QImage>
#include "Ronda.h"
#include "Cardplayed.h"


class Cards: public QGraphicsRectItem{
public:

private:
    QImage* Card_Img[SizeOfDeck];
    QImage* EmptyCard_Img;
    QImage* BackCard_Img;
    QImage* YourTurn_Img;
    QImage* Card_box;

public:
    Cards(int Card);
    ~Cards();
    void set_of_all_cards();

public :
    QImage* get_img_card(int card );
    void reverse_card(int card);
    void set_deck();

};

#endif // CARDS_H
