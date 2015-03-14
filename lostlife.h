#ifndef LOSTLIFE_H
#define LOSTLIFE_H

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



/**@class lostLife lostlife.h "lostlife.h"
  @brief Class for the image that indicates a life lost

  @details This class is designed to create an image of the life lost message.\n
  the message times out on its own via a QTimer.
 */
class lostLife : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    lostLife();
    ~lostLife();
public slots:
    void kill();
};



#endif // LOSTLIFE_H





