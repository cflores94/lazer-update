/**@mainpage Lazer Code
   @author Carlos Flores
   @date March 13, 2015
   @version 1.0
   @brief This is the the mainwidow for my game. All the components are added here.

*/
#include <QApplication>


#include "mainwindow.h"
#include "gamescene.h"
#include "youlost.h"
#include "instruction.h"
//#include "gameboard.h"

gameScene * gS;
MainWindow* w;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    w = new MainWindow;

    gS = new gameScene;

    instruction * inst = new instruction;


    w->setGameScene(gS);
    w->setInstructions(inst);
    w->show();




    return a.exec();
}
