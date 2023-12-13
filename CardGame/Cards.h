#ifndef CARDS_H
#define CARDS_H
#include <QGraphicsRectItem>
#include <QImage>


class Cards: public QGraphicsRectItem{
private:
    QImage* Card_Img[SizeOfDeck];
    QImage* EmptyCard_Img;
    QImage* BackCard_Img;
    QImage* YourTurn_Img;

public:
    Cards(int Card);
    ~Cards();
}

#endif // CARDS_H
