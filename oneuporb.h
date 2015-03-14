#ifndef ONEUPORB_H
#define ONEUPORB_H

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



/**@class oneUpOrb oneuporb.h "oneuporb.h"
  @brief Class for the image of the life orb

  @details This class is designed to create an image of the life orb.\n
  the orb times out on its own via a QTimer if not picked up.
 */
class oneUpOrb : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    oneUpOrb();
    ~oneUpOrb();
public slots:
    void kill();
    void makeFloat();
private:
    int floatFactor;
    int floatCount;
};



#endif // ONEUPORB_H





