#ifndef LASER_H
#define LASER_H

#include <QGraphicsPolygonItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QObject>
#include <QGraphicsTextItem>

/**@class Hlaser Hlaser.h "Hlaser.h"
  @brief Class for the lasers shooting down from above

  @details This class is designed to create an image of a laser\n
  that will move down on its own.
 */
class Hlaser : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Hlaser();
    ~Hlaser();
public slots:
   void laserDown();
   void destroyMessage();


private:
   QGraphicsTextItem* message;

};

#endif // LASER_H


