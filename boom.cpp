#include "boom.h"

/**This is the default boom constructor, it sets up the timer to destroy it
 */
boom::boom()
{
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/boom.png"));
    //SCALE THE image
    setScale(.4);

//set the timer to show the boom's life span
QTimer * timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(kill())); //need to make kill

timer->start(250);

}
/**This is the destructor
  */
boom::~boom()
{

}
/**This function removes the boom object form the scene and deallocates its memory when the timer times out.
 */
void boom::kill(){
//remove from scene
scene()->removeItem(this);
//delete
delete this;

}

