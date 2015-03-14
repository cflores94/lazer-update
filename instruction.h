#ifndef INSTRUCTION_H
#define INSTRUCTION_H

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
#include "stagnantimages.h"

class RBullet;
class LBullet;
class DBullet;
class UBullet;
class Hlaser;
class player;


/**@class instruction instruction.h "instruction.h"
  @brief Class for the creation of a view that explains the game

  @details This class is designed to create a window to explain the game.\n
  It derives from QGraphicsView so it is acting as a QGraphicsView object with modified\n
  objects in it.
 */
class instruction : public QGraphicsView
{

public:
    instruction();
    ~instruction();




private:

    QGraphicsScene* scene;

    QGraphicsView* view;

    //text
    QGraphicsTextItem * Welcome;
    QGraphicsTextItem * Intro;
    QGraphicsTextItem * instructionsHeader;
    QGraphicsTextItem * instructions;
    QGraphicsTextItem * gameItemHeader;
    QGraphicsTextItem * MLHeader;
    QGraphicsTextItem * SentHeader;
    QGraphicsTextItem * MonstHeader;
    QGraphicsTextItem * LaserHeader;
    QGraphicsTextItem * OrbHeader;
    QGraphicsTextItem * MLdes;
    QGraphicsTextItem * SentDes;
    QGraphicsTextItem * MonstDes;
    QGraphicsTextItem * LaserDes;
    QGraphicsTextItem * OrbDes;

    QGraphicsTextItem * conclusion;

    MLimage * playerPic;
    sentImage * sentinelPic;
    orbImage * orbPic;
    monstImage * SenemyPic;
    laserImage * laserPic;

};

#endif // INSTRUCTION_H
