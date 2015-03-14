#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

#include "instruction.h"

//forward declarations of classes to be used later
class gameScene;
class instruction;

/**@class MainWindow mainwindow.h "mainwindow.h"
  @brief Class for the creation of the mainwindow, the first one that pops up

  @details This class is designed to create the first screen that prompts the user to play
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void setGameScene(gameScene* game_scene);

    void setInstructions(instruction *inst_scene);
private:
    gameScene* gScene;
    instruction * instScene;

    QLabel* lazer;
    QLabel* difficulty;
    QLabel* instructions;
    QLabel* instTitle;

    QPushButton* go;
    QPushButton * seeInstr;

    QRadioButton* easy;
    QRadioButton* medium;
    QRadioButton* hard;


    QVBoxLayout* diffs;
    QHBoxLayout* LtwoCol;
    QVBoxLayout* finalLayout;

    QWidget* central;

};

#endif // MAINWINDOW_H
