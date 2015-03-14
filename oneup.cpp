#include "oneup.h"

/**This is the oneUP constructor, it sets up the timer to remove the item after a few seconds
 */
oneUp::oneUp()
{
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/1Up.png"));
    //SCALE THE image
    setScale(1.2);

//set the timer to show the message's life span
QTimer * timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(kill()));

timer->start(400);






}
/**OneUp destructor
 * */
oneUp::~oneUp()
{

}
/**This functions removes the one up message from the screen and deallocates memory
 */
void oneUp::kill(){
//remove from scene
scene()->removeItem(this);
//delete
delete this;

}
