#include "player.h"
#include "bullet.h"
#include "laser.h"
#include "enemy.h"
#include "boom.h"
#include "senemy.h"

#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>


/**This is the player constructor, it sets up image and the positioning
 */
player::player(QGraphicsItem *parent)
{
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/stickDude copy.png"));

    //SCALE THE PLAYER
    setScale(.3);

    //Starting Spot
    setPos(0,540);

    //set enemy count to 0
    enemyCount = 0;
    //set the difficulty count level defaults
    default1 = 10;
    default2 = 25;
    default3 = 35;
    default4 = 40;
    default5 = 60;


}

/**This function sets up all the key events to move the player and to shoot bullets
 */
void player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Right){
        if(pos().x()<720)
        setX(x()+40);
    }
    else if(event->key() == Qt::Key_Left){
        if(pos().x()>0)
                setX(x()-40);
    }
    else if(event->key() == Qt::Key_Down){
        if(pos().y()<540)
        setY(y()+40);
    }
    else if(event->key() == Qt::Key_Up){
        if(pos().y()>0)
            setY(y()-40);
    }

    else if(event->key() == Qt::Key_D){
        //create a bullet
        RBullet * rbullet = new RBullet();
        rbullet->setPos(x(),y());
        scene()->addItem(rbullet);

    }

    else if(event->key() == Qt::Key_A){
        //create a bullet
        LBullet * bullet = new LBullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

    }
    else if(event->key() == Qt::Key_W){
        //create a bullet
        UBullet * bullet = new UBullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

    }
    else if(event->key() == Qt::Key_S){
        //create a bullet
        DBullet * bullet = new DBullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

    }
    else if(event->key() == Qt::Key_Space){
        boom * explosion = new boom;
        explosion->setPos(x(),y());
        scene()->addItem(explosion);

    }

}

/**Player destructor
 */
player::~player()
{
}

/**this function increases the enemy count to be used when an enemy is \n
 * killed in order to use later to increase enemy behavior
 */
void player::increaseCount()
{
    ++enemyCount;
}

/**this function resets the enemy count for when a new game is started
 * */
void player::resetCount()
{
    enemyCount = 0;
}
/**This functions sets the count to any int. This is used when skipping to harder parts of the game
 * @param count is the count we desire to input
 * */
void player::setCount(int count)
{
    enemyCount = count;
}

/**This function creates lasers to be shot down
 */
void player::makeHLaser()
{
    //create the laser beam
    if(isVisible()){

    Hlaser * Hlazer = new Hlaser();
    scene()->addItem(Hlazer);
    }
}

/**This function creates enemies during certain conditions
 */
void player::makeLEnemy()
{
    if(isVisible()){

        if(enemyCount < default1 || (enemyCount>default4 && enemyCount< default5)){

            //create the Enemy
            LEnemy * enemy = new LEnemy();
            scene()->addItem(enemy);
        }

        else if((enemyCount>= default1 && enemyCount< default2) ||
                enemyCount>default5){

            //create the Enemy
            LEnemy * enemy = new LEnemy();
            enemy->setSpeed(20);
            scene()->addItem(enemy);
        }





    }
}

/**This function creates SEnemys during certain conditions
 */
void player::makeSEnemy()
{
    if(isVisible()){

        if((enemyCount>=default2 && enemyCount<default3) || (enemyCount>=default4 && enemyCount<default5)){
            int slowSpeed = 7;
           //Set Random Position
           int random_number = rand() % 800;
           //to make sure its randomly either coming from top or bottom
           if(random_number <= 200){
               SEnemy * enemy1 = new SEnemy();
               enemy1->setSpeed(slowSpeed);
               scene()->addItem(enemy1);
               enemy1->setPos( random_number, -50);
           }

           else if(random_number > 200 && random_number <= 400){
               SEnemy * enemy1 = new SEnemy();
               enemy1->setSpeed(slowSpeed);
               scene()->addItem(enemy1);
               enemy1->setPos(random_number, 650);
           }

           else if(random_number > 400 && random_number <= 600){
               SEnemy * enemy1 = new SEnemy();
               enemy1->setSpeed(slowSpeed);
               scene()->addItem(enemy1);
               enemy1->setPos( random_number, -50);

            }

           else if(random_number > 600 && random_number <= 800){
               SEnemy * enemy1 = new SEnemy();
               enemy1->setSpeed(slowSpeed);
               scene()->addItem(enemy1);
               enemy1->setPos(random_number, 650);

           }
        }
        else if((enemyCount>=default3 && enemyCount<default4) || enemyCount>=default5){
            int fastSpeed = 12;
           //Set Random Position
           int random_number = rand() % 800;
           //to make sure its randomly either coming from top or bottom
           if(random_number <= 200){
               SEnemy * enemy1 = new SEnemy();
               enemy1->setSpeed(fastSpeed);
               enemy1->setBFreq(300);
               scene()->addItem(enemy1);
               enemy1->setPos( random_number, -50);
           }

           else if(random_number > 200 && random_number <= 400){
               SEnemy * enemy1 = new SEnemy();
               enemy1->setSpeed(fastSpeed);
               enemy1->setBFreq(300);
               scene()->addItem(enemy1);
               enemy1->setPos(random_number, 650);
           }

           else if(random_number > 400 && random_number <= 600){
               SEnemy * enemy1 = new SEnemy();
               enemy1->setSpeed(fastSpeed);
               enemy1->setBFreq(300);
               scene()->addItem(enemy1);
               enemy1->setPos( random_number, -50);

            }

           else if(random_number > 600 && random_number <= 800){
               SEnemy * enemy1 = new SEnemy();
               enemy1->setSpeed(fastSpeed);
               enemy1->setBFreq(300);
               scene()->addItem(enemy1);
               enemy1->setPos(random_number, 650);

           }
        }
    }
}
//removes a message (not used)
void player::removeNWM()
{
    newWaveMessage->scene()->removeItem(newWaveMessage);
}

/**THis functions rests the enemy count to start from the beginning
 */
void player::diffEasy()
{
    resetCount();
    //qDebug()<<"did easy";

}
/**This functions sets the enemy count to default3 to skip to the middle of the game
 */
void player::diffMed()
{
    setCount(default3);
   // qDebug()<<"did med";

}
/**This functions sets the enemy count to default5 to skip to the hard part of the game
 */

void player::diffHard()
{
    setCount(default5);
   // qDebug()<<"did hard";

}
