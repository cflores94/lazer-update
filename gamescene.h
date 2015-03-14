#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QWidget>
#include <QString>
#include <QPixmap>

#include "player.h"
#include "laser.h"
#include "bullet.h"
#include "enemy.h"
#include "senemy.h"
#include "oneuporb.h"
#include "mainwindow.h"
#include "youlost.h"

class RBullet;
class LBullet;
class DBullet;
class UBullet;
class Hlaser;
class player;
class youLost;


/**@class gameScene gamescene.h "gamescene.h"
  @brief Class for the creation of the gamescene

  @details This class is designed to create the stage where the game is played.\n
  It derives from QGraphicsView so it is acting as a QGraphicsView object with modified\n
  objects in it.
 */
class gameScene : public QGraphicsView
{
   // Q_OBJECT

    friend class RBullet;
    friend class LBullet;
    friend class UBullet;
    friend class DBullet;
    friend class Hlaser;
    friend class LEnemy;
    friend class SEnemy;
    friend class SEBullet;
    friend class oneUpOrb;
    friend class MainWindow;
    friend class youLost;



public:
    gameScene();
    ~gameScene();

    void increaseScore();
    void resetScore();
    void decreaseLives();
    void resetLives();
    void giveOneUpOrb();
    void addOneLife();

private:
    QLabel* welcome;

    QGraphicsScene* scene;

    QGraphicsView* view;

    QGraphicsRectItem* rect;

    player* user;

    //text
    QGraphicsTextItem * lives;
    QGraphicsTextItem * score;

    QGraphicsTextItem * livesNum;
    int intLife;

    QGraphicsTextItem * scoreNum;
    int intScore;

    int holdScore;

    //timers for the enemies
    QTimer * Etimer;
    QTimer * SEtimer;




};

#endif // GAMESCENE_H
