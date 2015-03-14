#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsTextItem>

#include "enemy.h"
#include "bullet.h"
#include "senemy.h"


/**@class player player.h "player.h"
  @brief Class for the image of the player

  @details This class is designed to create an image of the player.\n
  The player is controlled by the user using the arrow keys and can shoot.
 */
class player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
friend class LEnemy;
friend class SEnemy;
friend class RBullet;
friend class UBullet;
friend class DBullet;
friend class LBullet;
friend class oneUpOrb;


    //constructor
    player(QGraphicsItem* parent=0);
    //define key press actions
    void keyPressEvent(QKeyEvent *event);
    ~player();

    void increaseCount();
    void resetCount();
    void setCount(int count);

public slots:
    void makeHLaser();
    void makeLEnemy();
    void makeSEnemy();
    void removeNWM();

    void diffEasy();
    void diffMed();
    void diffHard();


private:
    int enemyCount;
    int default1;
    int default2;
    int default3;
    int default4;
    int default5;

    QGraphicsTextItem* newWaveMessage;

};

#endif // PLAYER_H
