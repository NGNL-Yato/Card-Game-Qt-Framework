#include "Cardplayed.h".h"

Cardplayed::Cardplayed(Cards* ccard){
    setWindowTitle(tr("Card Played"));

    setAttribute( Qt::WA_QuitOnClose, false );
    deckcard = ccard;

    Cucumber_box = new QHBoxLayout;
    Gold_box = new QHBoxLayout;
    Sword_box = new QHBoxLayout;
    Table_box = new QHBoxLayout;

    for(int i = 0 ; i < SizeOfDeck ; i++){
        labels [i] = new QLabel( this );
        labels[i]->resize(55, 100); //sizing will change later
        labels[i]->setPixmap(QPixmap::fromImage(deck->get_img_card(i)->scaledToHeight(100)));
    if( i <= 12 )
        Cucumber_box -> addWidget(labels[i]);
    if( i >= 12 && i <= 24)
        Gold_box -> addWidget(labels[i]);
    if( i >= 24 && i <= 36)
        Sword_box -> addWidget(labels[i]);
    if( i >= 36 && i <= 48)
        Table_box -> addWidget(labels[i]);
    }
    QGroupBox *grp1 = new QGroupBox;
    grp1->setLayout(Cucumber_box);

    QGroupBox *grp2 = new QGroupBox;
    grp2->setLayout(Gold_box);

    QGroupBox *grp3 = new QGroupBox;
    grp3->setLayout(Sword_box);

    QGroupBox *grp4 = new QGroupBox;
    grp4->setLayout(Table_box);

    layout = new QVBoxLayout();
    layout->addWidget(grp1);
    layout->addWidget(grp2);
    layout->addWidget(grp3);
    layout->addWidget(grp4);
    setLayout(layout);

}
Cardplayed::~Cardplayed(){
    for (int i=0; i<SizeOfDeck; i++)
    delete labels[i];

    delete Cucumber_box;
    delete Gold_box;
    delete Sword_box;
    delete Table_box;
    delete layout;
}

void Cardplayed::play(int cardd){
    if ((cardd) || (cardd >= SizeOfDeck )) return;
    labels[cardd]->setDisabled(true);
}

void Cardplayed::add_card(){

}


