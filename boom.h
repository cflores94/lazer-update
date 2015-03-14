#ifndef BOOM_H
#define BOOM_H

#include <QGraphicsPolygonItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QObject>


#include "gamescene.h"

/**@class boom boom.h "boom.h"
  @brief Class for the image of an explosion

  @details This class is designed to create an image of an explosion\n
  that will last a limited amount of time thanks to the timer attached\n
  to each image.
 */
class boom : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    boom();
    ~boom();
public slots:
    void kill();
};

#endif // BOOM_H



