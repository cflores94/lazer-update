#include "oneuporb.h"
#include "oneup.h"

extern gameScene * gS;

/**This is the oneUpOrb constructor, it sets up the timer to start bobbing movement and to remove it in case it isn't picked up
 */
oneUpOrb::oneUpOrb()
{
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/1UpOrb.png"));
    //SCALE THE image
    setScale(.12);

    //set position
    //Set Random Position
    int random_number = rand() % 540;
    setPos( random_number, random_number);

    //set the timer to make the orb float up and down
    floatFactor = 1;
    floatCount = 0;
    QTimer * fTimer = new QTimer(this);
    connect(fTimer, SIGNAL(timeout()), this, SLOT(makeFloat()));
    fTimer->start(140);

//set the timer to show the orb's life span
QTimer * timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(kill())); //need to make kill

timer->start(4000);






}

/**OneUpOrb destructor
 */
oneUpOrb::~oneUpOrb()
{

}

/**This functions removes the orb from the screen and deallocates memory
 */
void oneUpOrb::kill(){
//remove from scene
scene()->removeItem(this);
//delete
delete this;

}

/**This function makes the orb bob up and down. It moves the orb in the y direction, switching direction after several calls.
 */
void oneUpOrb::makeFloat()
{
    setY(y()+(floatFactor*10));
    ++floatCount;
    if(floatCount > 3){
        floatFactor *= -1;
        floatCount = 0;
    }

        //CHeck for collision with the user (which means collection of the orb)
            //Create a list that holds all the QGraphicsItems that collide with this orb
            QList<QGraphicsItem *> collidingList = collidingItems();

            //function collidingItems() returns a list with all pointers pointing at objects colliding with the calling object
            //now traverse the list to find out if it is an enemy
            for(int i=0, n = collidingList.size(); i<n; ++i){
                //type id checks for the type of object for given object
                if(typeid(*(collidingList[i])) == typeid(player)){

                  //one up the lives if is visible (not if already collided and hidden meanwhile it gets deleted
                    if(isVisible()){
                        gS->addOneLife();

                    }

                    //remove the orb, it is deleted later with the time out in the orb class
                    hide();

                    //qDebug()<<"did it";

                    return;
                }
            }
//delete if the game ends
            if(gS->user->enemyCount == 0){
                scene()->removeItem(this);
                delete this;
                //qDebug("deleted orb");
            }

}
