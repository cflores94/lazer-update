#ifndef YOULOST_H
#define YOULOST_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
//#include <random>
//#include <chrono>
#include <QTimer>
#include <QPushButton>
#include <iostream>
#include <QRadioButton>
#include <QButtonGroup>

#include "gamescene.h"
#include "mainwindow.h"

class gameScene;
class MainWindow;


/**@class youLost youlost.h "youlost.h"
  @brief Class for the creation of the window that pops up when you lose

  @details This class is designed to create the screen that pops up when you lose
 */
class youLost : public QWidget
{
    Q_OBJECT
public:
    explicit youLost(QWidget *parent = 0);
    ~youLost();

private:
    QLabel* youLose;
    QLabel* playAgain;
    QLabel* yourScore;

    QPushButton* yes;
    QPushButton* no;

    QVBoxLayout* finalLayout;

    QWidget* central;

    gameScene * game;
    MainWindow * window;


};

#endif // YOULOST_H
