#ifndef STAGNANTIMAGES_H
#define STAGNANTIMAGES_H

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

/**@class MLimage stagnantimages.h "stagnantimages.h"
  @brief Class for the image of the player's image

  @details This class is designed to create an image of the player to be used\n
  for the instructions page. It will not move
 */
class MLimage : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MLimage();
    ~MLimage();

};

/**@class sentImage stagnantimages.h "stagnantimages.h"
  @brief Class for the image of the sentinal enemy's image

  @details This class is designed to create an image of the sentel to be used\n
  for the instructions page. It will not move
 */
class sentImage : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    sentImage();
    ~sentImage();

};
/**@class monstImage stagnantimages.h "stagnantimages.h"
@brief Class for the image of the monster's image

@details This class is designed to create an image of the monster enemy to be used\n
for the instructions page. It will not move
*/
class monstImage : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    monstImage();
    ~monstImage();

};
/**@class laserImage stagnantimages.h "stagnantimages.h"
  @brief Class for the image of the laser's image

  @details This class is designed to create an image of the laser to be used\n
  for the instructions page. It will not move
 */
class laserImage : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    laserImage();
    ~laserImage();

};
/**@class orbImage stagnantimages.h "stagnantimages.h"
  @brief Class for the image of the life orb's image

  @details This class is designed to create an image of the life orb to be used\n
  for the instructions page. It will not move
 */
class orbImage : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    orbImage();
    ~orbImage();

};


#endif // STAGNANTIMAGES_H


