#include "lostlife.h"


/**This is the lostLife constructor, it sets up the timer to remove it in a few seconds
 */
lostLife::lostLife()
{
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/lostAlife.png"));
    //SCALE THE image
    setScale(1.2);

//set the timer to show the boom's life span
QTimer * timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(kill())); //need to make kill

timer->start(500);




}
/**lostLife destructor
 */
lostLife::~lostLife()
{

}

/**This functions removes and deallocates the lostLife message to be used with the timer above.
 */
void lostLife::kill(){
//remove from scene
scene()->removeItem(this);
//delete
delete this;

}
