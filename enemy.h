#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPolygonItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QObject>

#include "player.h"

/**@class LEnemy LEnemy.h "enemy.h"
  @brief Class for the image of an enemy

  @details This class is designed to create an image of an eneymy\n
  that will move to the left on its own.
 */
class LEnemy : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    LEnemy(QGraphicsItem * parent=0);

    //change the speed of the enemies
    void setSpeed(int numb);
    void resetSpeed();

    ~LEnemy();
public slots:
   void moveLeft();


private:
   int speed;

};


#endif // ENEMY_H
