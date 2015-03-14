#include "gamescene.h"
#include "bullet.h"
#include "laser.h"
#include "enemy.h"
#include "senemy.h"
#include "youlost.h"
#include "lostlife.h"
#include "oneup.h"
#include "oneuporb.h"
#include <QRadialGradient>
#include <QFont>
#include <QGraphicsTextItem>
#include <QColor>
#include <QBrush>
#include <QImage>

#include <QDebug>

/**This is the gameScene constructor, it sets up all the objects needed to play the game;
 */
gameScene::gameScene(){

    //welcome = new QLabel("HELLO");
    //welcome->setAlignment(Qt::AlignCenter);

    //Create the scene
    scene = new QGraphicsScene(this);
    //scene->setBackgroundBrush(Qt::black);
    //set background to the image
    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/backg.jpg")));

    //Set the scene
    setScene(scene);

    //Create the elements
    //First the player
    user = new player();
    user->setFlag(QGraphicsItem::ItemIsFocusable);
    user->setFocus();
    //set his enemy count to 0
    //user->resetCount();

    //Create Vertical Lasers
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), user,SLOT(makeHLaser()));
    //this timer decides frequency of lasers made
    timer->start(1500);

    //Create Horizontal Enemies for the first wave
    //while(user->enemyCount != 2){
    Etimer = new QTimer();
    QObject::connect(Etimer, SIGNAL(timeout()), user,SLOT(makeLEnemy()));
    //this timer decides frequency of enemies made
    Etimer->start(1000);

    //Now the second type of enemies
    SEtimer = new QTimer();
    QObject::connect(SEtimer, SIGNAL(timeout()), user,SLOT(makeSEnemy()));
    //this timer decides frequency of enemies made
    SEtimer->start(2300);

    //Add the elements to the scene
    scene->addItem(user);
    scene->addWidget(welcome);

    view = new QGraphicsView(scene);
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);


    setFixedSize(800,600);

    //add text For lives and score
    //set the font
    QFont font;
        font.setBold(true);
        font.setPointSize(30);
    //create the text items
    lives = new QGraphicsTextItem("Lives: ");
    score = new QGraphicsTextItem("Score: ");

    //Set the score and lives
    intLife = 10;
    intScore = 0;
    livesNum = new QGraphicsTextItem(QString::number(intLife));
    scoreNum = new QGraphicsTextItem(QString::number(intScore));

    //assign the color and font
    QColor gText("lightgray");
    lives->setDefaultTextColor(gText);
    lives->setFont(font);
    livesNum->setDefaultTextColor(gText);
    livesNum->setFont(font);
    score->setDefaultTextColor(gText);
    score->setFont(font);
    scoreNum->setDefaultTextColor(gText);
    scoreNum->setFont(font);

    //add to the scene
    scene->addItem(lives);
    scene->addItem(livesNum);
    scene->addItem(score);
    scene->addItem(scoreNum);

    //position livesNum
    livesNum->setX(100);

    //position score and score num
    score->setX(630);
    scoreNum->setX(730);


    //set the background
    //background * backDrop = new background;
    //scene->addItem(backDrop);



    this->setWindowTitle("laZer");
}

/**gameScene destructor
 */
gameScene::~gameScene()
{

}

/**This function increases the score by one. To be used in the bullet and enemy collisions.
 */
void gameScene::increaseScore()
{
    QColor gText("lightgray");
    QFont font;
        font.setBold(true);
        font.setPointSize(30);

    intScore += 1;
    scene->removeItem(scoreNum);
    delete scoreNum;

    scoreNum = new QGraphicsTextItem(QString::number(intScore));
    scoreNum->setDefaultTextColor(gText);
    scoreNum->setFont(font);

    scene->addItem(scoreNum);

    scoreNum->setX(730);

}

/**This function resets the score for when the game finishes and the next game will start with a score of 0;
 */
void gameScene::resetScore()
{
    QColor gText("lightgray");
    QFont font;
        font.setBold(true);
        font.setPointSize(30);

    holdScore = intScore;
    intScore = 0;
    scene->removeItem(scoreNum);
    delete scoreNum;

    scoreNum = new QGraphicsTextItem(QString::number(intScore));
    scoreNum->setDefaultTextColor(gText);
    scoreNum->setFont(font);

    scene->addItem(scoreNum);

    scoreNum->setX(730);

}

/**This function decreases the player's lives by one. To be used upon player and enemy or laser collisions
 */
void gameScene::decreaseLives()
{
//we dont want the lives to lower when we are not playing
 if(isVisible()){


    QColor gText("lightgray");
    QFont font;
        font.setBold(true);
        font.setPointSize(30);

        --intLife;



    if(intLife == 0){
        /*intLife = 2;


        scene->removeItem(livesNum);
        delete livesNum;

        livesNum = new QGraphicsTextItem(QString::number(intLife));
        livesNum->setDefaultTextColor(gText);
        livesNum->setFont(font);

        scene->addItem(livesNum);

        livesNum->setX(100);
        */

        resetLives();
        resetScore();

        this->close();
        youLost * lose = new youLost;
        lose->show();



        return;
    }

    else{
//    --intLife;

    scene->removeItem(livesNum);
    delete livesNum;

    livesNum = new QGraphicsTextItem(QString::number(intLife));
    livesNum->setDefaultTextColor(gText);
    livesNum->setFont(font);

    scene->addItem(livesNum);

    livesNum->setX(100);

    //show loss of life message
    lostLife * message = new lostLife;
    message->setPos(150,250);
    scene->addItem(message);


    }
 }
 else if(!(isVisible())) { //qDebug("skipping");
     return;
 }
}

/**This function resets the lives to 0 for the new game;
 */
void gameScene::resetLives()
{
    QColor gText("lightgray");
    QFont font;
        font.setBold(true);
        font.setPointSize(30);


    //Reset the lives to 0 and re-add the text to the scene in order to "refresh" the value
    intLife = 10;
    scene->removeItem(livesNum);
    delete livesNum;

    livesNum = new QGraphicsTextItem(QString::number(intLife));
    livesNum->setDefaultTextColor(gText);
    livesNum->setFont(font);

    scene->addItem(livesNum);

    livesNum->setX(100);

    //Reset the enemy count for the player
    user->resetCount();

}

/**This function adds a life orb to the scene. To be used when 10 kills are made;
 */
void gameScene::giveOneUpOrb()
{
    //show the orb
    oneUpOrb * orb = new oneUpOrb;
    scene->addItem(orb);

    //set up the text to edit the lives
    QColor gText("lightgray");
    QFont font;
        font.setBold(true);
        font.setPointSize(30);
        //CHeck for collision with the user (which means collection of the orb)
            //Create a list that holds all the QGraphicsItems that collide with this orb
            QList<QGraphicsItem *> collidingList = orb->collidingItems();

            //function collidingItems() returns a list with all pointers pointing at objects colliding with the calling object
            //now traverse the list to find out if it is an enemy
            for(int i=0, n = collidingList.size(); i<n; ++i){
                //type id checks for the type of object for given object
                if(typeid(*(collidingList[i])) == typeid(player)){
                    //show oneUp message
                    oneUp * message = new oneUp;
                    message->setPos(150,250);
                    scene->addItem(message);

                    //remove the orb, it is deleted later with the time out in the orb class
                    orb->hide();

                    //since there was a collision, now we give an extra life
                    ++intLife;

                    scene->removeItem(livesNum);
                    delete livesNum;

                    livesNum = new QGraphicsTextItem(QString::number(intLife));
                    livesNum->setDefaultTextColor(gText);
                    livesNum->setFont(font);

                    scene->addItem(livesNum);

                    livesNum->setX(100);

                    //qDebug()<<"did it";

                    return;
                }
            }




}

/**This function adds a life. To be used when the one up orb is picked up.
 */
void gameScene::addOneLife()
{
    //set up the text to edit the lives
    QColor gText("lightgray");
    QFont font;
        font.setBold(true);
        font.setPointSize(30);

    //since there was a collision, now we give an extra life
    ++intLife;

    scene->removeItem(livesNum);
    delete livesNum;

    livesNum = new QGraphicsTextItem(QString::number(intLife));
    livesNum->setDefaultTextColor(gText);
    livesNum->setFont(font);

    scene->addItem(livesNum);

    livesNum->setX(100);

    //show oneUp message
    oneUp * message = new oneUp;
    message->setPos(150,250);
    scene->addItem(message);
}


