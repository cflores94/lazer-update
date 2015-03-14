#include "laser.h"
#include "player.h"
#include "gamescene.h"
#include "lostlife.h"
#include <QPixmap>
#include <stdlib.h>

#include <QDebug>

extern gameScene * gS;

/**This is the Hlaser constructor, it sets up the timer to start movement
 @param parent is the parent item if you wish to set one up
 */
Hlaser::Hlaser()
{
    //Set Random Position
    int random_number = rand() % 700;
    setPos(random_number, 0);
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/laser2.png"));
    //SCALE THE image
    setScale(.5);

    //connect the shoot functionality
    QTimer * timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(laserDown()));

    timer->start(50);



}

/**Hlaser destructor
 */
Hlaser::~Hlaser()
{
}

/**This function moves the laser a certain amount down one time. It is used witht the timer above to keep moving down the game. Checks for collision with player;
 */
void Hlaser::laserDown()
{
    //CHeck for collision with an enemy to remove both
    //Create a list that holds all the QGraphicsItems that collide with this bullet
    QList<QGraphicsItem *> collidingList = collidingItems();

    //function collidingItems() returns a list with all pointers pointing at objects colliding with the calling object
    //now traverse the list to find out if it is the player
    for(int i=0, n = collidingList.size(); i<n; ++i){
        //type id checks for the type of object for given object
        if(typeid(*(collidingList[i])) == typeid(player)){


            scene()->removeItem(this);
            //now deallocate the memory
            delete this;

            //Subtract one life
            gS->decreaseLives();



            return;
        }
    }
    int laserSpeed = 25;
    setY(y()+laserSpeed);
    if (pos().y()>600){
        scene()->removeItem(this);
        delete this;
    }
}


void Hlaser::destroyMessage()
{
    //this->scene()->removeItem(message);
    //scene()->removeItem(message);
}



