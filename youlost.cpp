#include "youlost.h"

extern gameScene * gS;
extern MainWindow * w;


/**youLost's constructor. Sets up the buttons and labels to indicate you\n
     lost and prompt for a return to main menu or to play
 */
youLost::youLost(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("laZer");


    youLose = new QLabel("You Lost!");
    youLose->setAlignment(Qt::AlignCenter);

    QString tmp = QString::number(gS->holdScore);
    yourScore = new QLabel("Your Score: " + tmp);//gS->holdScore);
    yourScore->setAlignment(Qt::AlignCenter);


    playAgain = new QLabel("Play Again?");
    playAgain->setAlignment(Qt::AlignCenter);

    yes = new QPushButton("Yes");
    no = new QPushButton("No");


    finalLayout = new QVBoxLayout;
    finalLayout->addWidget(youLose);
    finalLayout->addWidget(yourScore);
    finalLayout->addWidget(playAgain);
    finalLayout->addWidget(yes);
    finalLayout->addWidget(no);

    this->setLayout(finalLayout);
    this->setFixedHeight(200);
    this->setFixedWidth(300);

    //set gamescene for the play again button
    game = gS;
    QObject::connect(yes, SIGNAL(clicked()), game, SLOT(show()));
    QObject::connect(yes, SIGNAL(clicked()), this, SLOT(close()));


    //set mainwindow for the no button
    window = w;
    QObject::connect(no, SIGNAL(clicked()), window, SLOT(show()));
    QObject::connect(no, SIGNAL(clicked()), this, SLOT(close()));





}

/**youLost's destructor
 * */
youLost::~youLost()
{

}

