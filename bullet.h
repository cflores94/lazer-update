#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPolygonItem>
#include <QObject>

#include "gamescene.h"


/**@class RBullet RBullet.h "bullet.h"
  @brief Class for the image of a bullet

  @details This class is designed to create an image of a bullet\n
  that will move to the right on its own.
 */
class RBullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    RBullet(QGraphicsItem * parent = 0);
    ~RBullet();
public slots:
   void moveRight();


private:
    QGraphicsPolygonItem * Polybull;

};

/**@class LBullet LBullet.h "bullet.h"
  @brief Class for the image of a bullet

  @details This class is designed to create an image of a bullet\n
  that will move to the left on its own.
 */
class LBullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    LBullet(QGraphicsItem * parent = 0);
    ~LBullet();
public slots:
   void moveLeft();


private:
    QGraphicsPolygonItem * Polybull;

};

/**@class Ubullet UBullet.h "bullet.h"
  @brief Class for the image of a bullet

  @details This class is designed to create an image of a bullet\n
  that will move up on its own.
 */
class UBullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    UBullet(QGraphicsItem * parent = 0);
    ~UBullet();
public slots:
   void moveUp();


private:
    QGraphicsPolygonItem * Polybull;

};

/**@class DBullet DBullet.h "bullet.h"
  @brief Class for the image of a bullet

  @details This class is designed to create an image of a bullet\n
  that will move down on its own.
 */
class DBullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    DBullet(QGraphicsItem * parent = 0);
    ~DBullet();
public slots:
   void moveDown();



};


#endif // BULLET_H
