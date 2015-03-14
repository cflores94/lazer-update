#ifndef SENEMY_H
#define SENEMY_H

#include <QGraphicsPolygonItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QObject>
#include <QPointF>
#include <QList>

#include "player.h"

/**@class SEnemy senemy.h "senemy.h"
  @brief Class for the image of the enemy that follow the player.

  @details This class is designed to create an image of the Senemy.\n
  The enemy moves on its own with a QTimer attached to a move function that\n
  follow the player.
 */
class SEBullet;

class SEnemy : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
friend class SEBullet;
public:
    SEnemy(QGraphicsItem * parent=0);

    //change the speed of the enemies
    void setSpeed(int numb);
    void setBFreq(int numb);

    void resetSpeed();

    void rotateToPoint(QPointF p);

    ~SEnemy();
public slots:
   void move();
   void makeBullet();


private:
   int speed;
   int bulletFreq = 800;
   QList<QPointF> points;
   QPointF dest;
   int point_index;


};

/**@class SEBullet senemy.h "senemy.h"
@brief Class for the image of a bullet

@details This class is designed to create an image of a bullet\n
that will move straight along the angle at which it was fired.
*/
class SEBullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    friend class SEnemy;
public:
    SEBullet(QGraphicsItem * parent = 0);
    ~SEBullet();
public slots:
   void shoots();


private:
    int Bspeed = 20;


};



#endif // SENEMY_H
