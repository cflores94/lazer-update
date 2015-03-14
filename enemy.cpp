#include "enemy.h"
#include "gamescene.h"
#include "lostlife.h"
#include "boom.h"
#include<stdlib.h>
#include <QPixmap>
#include <QDebug>


extern gameScene * gS;

/**This is the LEnemey constructor, it sets up the timer to start movement
 @param parent is the parent item if you wish to set one up
 */
LEnemy::LEnemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent){

    //Set the speed
    speed = 10;
    //Set Random Position
    int random_number = rand() % 540;
    setPos( 800, random_number);
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/sentinel.png"));
    //SCALE THE image
    setScale(.1);

    //connect the move functionality
    QTimer * timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));

    timer->start(50);





}

/**This function sets the speed of the Lenemys
 @param numb is the speed we want to set. the speed is relative to how many pixels it moves upon each movement call
 */
void LEnemy::setSpeed(int numb)
{
    speed = numb;
}

/**This function resets the speed of the Lenemys to the original value, 10;
 */
void LEnemy::resetSpeed()
{
    speed = 10; //10 is the default level
}

/**Lenemy destructor;
 */
LEnemy::~LEnemy()
{

}


/**This function moves the enemy's to the left a certain amount. Used above with the timer.
 */
void LEnemy::moveLeft()
{

    //CHeck for collision with an enemy to remove both
    //Create a list that holds all the QGraphicsItems that collide with this enemy
    QList<QGraphicsItem *> collidingList = collidingItems();

    //function collidingItems() returns a list with all pointers pointing at objects colliding with the calling object
    //now traverse the list to find out if it is the player
    for(int i=0, n = collidingList.size(); i<n; ++i){
        //type id checks for the type of object for given object
        if(typeid(*(collidingList[i])) == typeid(player)){
            //remove just laser for now
            //scene()->removeItem(collidingList[i]);
            scene()->removeItem(this);
            //now deallocate their memory
            //delete collidingList[i];
            delete this;

            //Subtract one life
            gS->decreaseLives();






            //qDebug()<<"did it";

            return;
        }
    }

//edit the speed here to make enemy faster
    setX(x()-speed);
    if (pos().x()<-100){
        scene()->removeItem(this);
//        qDebug()<<"sentinal gone";
        delete this;
        }
}

