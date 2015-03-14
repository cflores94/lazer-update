#include "bullet.h"
#include "enemy.h"
#include "senemy.h"
#include "laser.h"
#include "boom.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QFont>

#include <QDebug>

extern gameScene * gS;

//This number is the number of kills needed to recieve an extra life
int oneUpReq = 10;

/**This is the RBullet constructor, it sets up the timer to start movement
 @param parent is the parent item if you wish to set one up
 */
RBullet::RBullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
        //set the graphics
        setPixmap(QPixmap(":/new/prefix1/playerBulletH.png"));
        //SCALE THE image
        setScale(.3);

    //connect the shoot functionality
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));

    timer->start(50);




}

/**RBullet destructor
 * */
RBullet::~RBullet()
{

}
/**This function moves the bullet to the right a set amount. Function to be used on the above timer
 */
void RBullet::moveRight()
{
    //CHeck for collision with an enemy to remove both
    //Create a list that holds all the QGraphicsItems that collide with this bullet
    QList<QGraphicsItem *> collidingList = collidingItems();

    //function collidingItems() returns a list with all pointers pointing at objects colliding with the calling object
    //now traverse the list to find out if it is an enemy
    for(int i=0, n = collidingList.size(); i<n; ++i){
        //type id checks for the type of object for given object
        if(typeid(*(collidingList[i])) == typeid(LEnemy) ||
                typeid(*(collidingList[i])) == typeid(SEnemy) ){


            //show the explosion
            boom * explosion = new boom;
            explosion->setPos(collidingList[i]->x(), collidingList[i]->y() );
            scene()->addItem(explosion);

            //remove both bullet and enemy
            scene()->removeItem(collidingList[i]);
            scene()->removeItem(this);
            //now deallocate their memory
            delete collidingList[i];
            delete this;

            //Add one to the score
            gS->increaseScore();


            //now increase the player enemycount
            gS->user->increaseCount();

            //now check if the user merits an extra life
            if(gS->user->enemyCount % oneUpReq == 0) gS->giveOneUpOrb();


            qDebug()<<"did it";

            return;
        }
    }


    setX(x()+15);
    if (pos().x()>800){
        scene()->removeItem(this);

        delete this;
    }
}

/**This is the LBullet constructor, it sets up the timer to start movement
 @param parent is the parent item if you wish to set one up
 */LBullet::LBullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
        //set the graphics
        setPixmap(QPixmap(":/new/prefix1/playerBulletH.png"));
        //SCALE THE image
        setScale(.3);


    //connect the shoot functionality
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));

    timer->start(50);



}

LBullet::~LBullet()
{

}


/**This function moves the bullet to the left a set amount. Function to be used on the above timer
 */
void LBullet::moveLeft()
{
    //CHeck for collision with an enemy to remove both
    //Create a list that holds all the QGraphicsItems that collide with this bullet
    QList<QGraphicsItem *> collidingList = collidingItems();

    //function collidingItems() returns a list with all pointers pointing at objects colliding with the calling object
    //now traverse the list to find out if it is an enemy
    for(int i=0, n = collidingList.size(); i<n; ++i){
        //type id checks for the type of object for given object
        if(typeid(*(collidingList[i])) == typeid(LEnemy) ||
                typeid(*(collidingList[i])) == typeid(SEnemy)){
            //show the explosion
            boom * explosion = new boom;
            explosion->setPos(collidingList[i]->x(), collidingList[i]->y() );
            scene()->addItem(explosion);

            //remove both bullet and enemy
            scene()->removeItem(collidingList[i]);
            scene()->removeItem(this);
            //now deallocate their memory
            delete collidingList[i];
            delete this;

            //Add one to the score
            gS->increaseScore();

            //now increase the player enemycount
            gS->user->increaseCount();

            //now check if the user merits an extra life
            if(gS->user->enemyCount % oneUpReq == 0) gS->giveOneUpOrb();

           // qDebug()<<"did it";

            return;
        }
    }


    setX(x()-15);
    if (pos().x()<0){
        scene()->removeItem(this);
        delete this;
    }
}

/**This is the UBullet constructor, it sets up the timer to start movement
 @param parent is the parent item if you wish to set one up
 */
UBullet::UBullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
        //set the graphics
        setPixmap(QPixmap(":/new/prefix1/playerBulletV.png"));
        //SCALE THE image
        setScale(.3);

    //connect the shoot functionality
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));

    timer->start(50);



}

UBullet::~UBullet()
{

}
/**This function moves the bullet up a set amount. Function to be used on the above timer
 */
void UBullet::moveUp()
{
    //CHeck for collision with an enemy to remove both
    //Create a list that holds all the QGraphicsItems that collide with this bullet
    QList<QGraphicsItem *> collidingList = collidingItems();

    //function collidingItems() returns a list with all pointers pointing at objects colliding with the calling object
    //now traverse the list to find out if it is an enemy
    for(int i=0, n = collidingList.size(); i<n; ++i){
        //type id checks for the type of object for given object
        if(typeid(*(collidingList[i])) == typeid(LEnemy) ||
                typeid(*(collidingList[i])) == typeid(SEnemy)){
            //show the explosion
            boom * explosion = new boom;
            explosion->setPos(collidingList[i]->x(), collidingList[i]->y() );
            scene()->addItem(explosion);

            //remove both bullet and enemy
            scene()->removeItem(collidingList[i]);
            scene()->removeItem(this);
            //now deallocate their memory
            delete collidingList[i];
            delete this;

            //Add one to the score
            gS->increaseScore();

            //now increase the player enemycount
            gS->user->increaseCount();

            //now check if the user merits an extra life
            if(gS->user->enemyCount % oneUpReq == 0) gS->giveOneUpOrb();

           // qDebug()<<"did it";

            return;
        }
    }


    setY(y()-15);
    if (pos().y()<0){
        scene()->removeItem(this);

        delete this;
     }
}

/**This is the DBullet constructor, it sets up the timer to start movement
 @param parent is the parent item if you wish to set one up
 */
DBullet::DBullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //Set Random Position
        int random_number = rand() % 500;
        setPos( 600, random_number);
        //set the graphics
        setPixmap(QPixmap(":/new/prefix1/playerBulletV.png"));
        //SCALE THE image
        setScale(.3);

    //connect the shoot functionality
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));

    timer->start(50);


}

DBullet::~DBullet()
{

}

/**This function moves the bullet down a set amount. Function to be used on the above timer
 */
void DBullet::moveDown()
{
    //CHeck for collision with an enemy to remove both
    //Create a list that holds all the QGraphicsItems that collide with this bullet
    QList<QGraphicsItem *> collidingList = collidingItems();

    //function collidingItems() returns a list with all pointers pointing at objects colliding with the calling object
    //now traverse the list to find out if it is an enemy
    for(int i=0, n = collidingList.size(); i<n; ++i){
        //type id checks for the type of object for given object
        if(typeid(*(collidingList[i])) == typeid(LEnemy) ||
                typeid(*(collidingList[i])) == typeid(SEnemy)){
            //show the explosion
            boom * explosion = new boom;
            explosion->setPos(collidingList[i]->x(), collidingList[i]->y() );
            scene()->addItem(explosion);

            //remove both bullet and enemy
            scene()->removeItem(collidingList[i]);
            scene()->removeItem(this);
            //now deallocate their memory
            delete collidingList[i];
            delete this;

            //Add one to the score
            gS->increaseScore();

            //now increase the player enemycount
            gS->user->increaseCount();

            //now check if the user merits an extra life
            if(gS->user->enemyCount % oneUpReq == 0) gS->giveOneUpOrb();

            //qDebug()<<"did it";

            return;
        }
    }



    setY(y()+15);
    if (pos().y()>600){
        scene()->removeItem(this);
        delete this;
    }
}
