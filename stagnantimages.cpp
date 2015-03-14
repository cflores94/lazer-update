#include "stagnantimages.h"


/**This is the player's image constructor
 */
MLimage::MLimage()
{
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/stickDude copy.png"));
    //SCALE THE image
    setScale(.5);


}
/**MLimage's destructor
 */
MLimage::~MLimage()
{
}

/**This is the sentinel's image constructor
 */
sentImage::sentImage()
{
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/sentinel.png"));
    //SCALE THE image
    setScale(.15);




}
/**sentImage's destructor
 */
sentImage::~sentImage()
{
}

/**This is the monster's image constructor
 */
monstImage::monstImage()
{
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/SEnemy copy 2.png"));
    //SCALE THE image
    setScale(.5);


}
/**monstImage's destructor
 */
monstImage::~monstImage()
{
}

/**This is the orb's image constructor
 */
orbImage::orbImage()
{
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/1UpOrb.png"));
    //SCALE THE image
    setScale(.3);



}

/**orbImage's destructor
 */
orbImage::~orbImage()
{
}

/**This is the laser's image constructor
 */
laserImage::laserImage()
{
    //set the graphics
    setPixmap(QPixmap(":/new/prefix1/laser2.png"));
    //SCALE THE image
    setScale(.5);



}
/**laserImage's destructor
 */
laserImage::~laserImage()
{
}
