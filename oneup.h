#ifndef ONEUP_H
#define ONEUP_H

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



/**@class oneUp oneup.h "oneup.h"
  @brief Class for the image that indicates a life gained

  @details This class is designed to create an image of the life gained message.\n
  the message times out on its own via a QTimer.
 */
class oneUp : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    oneUp();
    ~oneUp();
public slots:
    void kill();
};



#endif // ONEUP_H





