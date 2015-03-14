#include "senemy.h"
#include "gamescene.h"
#include "lostlife.h"
#include "boom.h"
#include "player.h"
#include<stdlib.h>
#include <QPixmap>
#include <QDebug>
#include <qmath.h>




extern gameScene * gS;


/**This is the SEnemy constructor, it sets up the timer to start movement and another to start the shooting
 @param parent is the parent item if you wish to set one up
 */
SEnemy::SEnemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent){

    //Set the speed
    speed = 10;
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/SEnemy copy.png"));
    //SCALE THE image
    setScale(.35);




    //Set the destination point at wherever the user is
    QPointF location(gS->user->pos());
    dest = location;
    //now rotate the enemy to follow the user
    rotateToPoint(dest);

    //connect the move functionality
    QTimer * timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

    //connect the shoot functionality
    QTimer * SHtimer = new QTimer(this);

    connect(SHtimer, SIGNAL(timeout()), this, SLOT(makeBullet()));


    //bulletFreq = 1000;
    SHtimer->start(bulletFreq);






}

/**This function sets the speed of the enemy
 @param numb is the speed we want (how many pixels traveled in move function.
 */
void SEnemy::setSpeed(int numb)
{
    speed = numb;
}

/**This function sets the frequency of the enemy
 @param numb is the frequency we want
 */void SEnemy::setBFreq(int numb)
{
    bulletFreq = numb;
}

/**This function resets the speed of the enemy to original speed
 */
void SEnemy::resetSpeed()
{
    speed = 20; //10 is the default level
}

/**This function rotates the enemy toward a point
 @param p is the point it rotates to
 */
void SEnemy::rotateToPoint(QPointF p)
{
    //going to create a line from the position of the enemy to the point it wants and rotate enmey to face line
    QLineF ln(pos(), p);
    setRotation(-1 *ln.angle());
}

/**SEnemy destructor
*/
SEnemy::~SEnemy()
{

}


/**This function moves the enemy a set amount to be used with timer above
 */
void SEnemy::move()
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



            return;
        }
    }

    //set the movement motion
    //update the enemy's rotation everytime move is called
    QPointF Nlocation(gS->user->x(), gS->user->y());
    dest = Nlocation;
    rotateToPoint(dest);

    //Move enemy at current angle
    int STEP_SIZE = speed;
    double theta = rotation(); //degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y() + dy);

    //delete the enemy if the screen is closed
    if(gS->user->enemyCount == 0){
        scene()->removeItem(this);
        delete this;
        //qDebug("deleted SEnemy");
    }


}

/**This function makes the bullets for the enemy to shoot
 */
void SEnemy::makeBullet()
{
    //create a bullet
    SEBullet * bullet = new SEBullet();
    bullet->setPos(x(),y());

    //set the bullet speed
    if(gS->user->enemyCount >= gS->user->default3) bullet->Bspeed = 35;

    QLineF line(QPointF(x(),y()), dest);
    int angle = -1 * line.angle();

    bullet->setRotation(angle);


    scene()->addItem(bullet);
}

/**This is the SEBUllet constructor. It sets up the timer to travel in a direction
 */
SEBullet::SEBullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{


    //set the graphics
        setPixmap(QPixmap(":/new/prefix1/redbullet.png"));
        //SCALE THE image
        setScale(.7);

    //connect the shoot functionality
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(shoots()));
    //start the timer
    timer->start(50);






}

/**SEBullet destructor
 * */
SEBullet::~SEBullet()
{

}

/**This function moves the bullet to make a shooting motion
*/
void SEBullet::shoots()
{
    //set the movement motion
    //update the enemy's rotation everytime move is called
   // QPointF location(gS->user->x()+100, gS->user->y()+100);
    //rotateToPoint(location);

    //CHeck for collision with the user to remove the bullet
    //Create a list that holds all the QGraphicsItems that collide with this bullet
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

    //Move bullet at current angle
    int STEP_SIZE = Bspeed;
    double theta = rotation(); //degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y() + dy);

    //delete the bullet if off screen
    if (pos().x()<0 || pos().x()>800 || pos().y()<0 || pos().y()>600){
        scene()->removeItem(this);
        delete this;
        //qDebug("deleted EBullet");
    }
}

