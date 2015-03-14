#include "mainwindow.h"
#include "gamescene.h"

#include <QStyle>
#include <QFont>

/**This is the MainWindow constructor, it sets up all the elements needed in that initial window
 @param parent is the parent item if you wish to set one up
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    this->setWindowTitle("laZer");


    //Labels for the game title and speed levels title
    lazer = new QLabel ("laZer");
    lazer->setAlignment(Qt::AlignCenter);

    difficulty = new QLabel ("Difficulty");
    //enemies = new QLabel ("Speed of Enemies");


    //Push button to start the game
    go = new QPushButton("GO!");
    seeInstr = new QPushButton("Instructions");

    //RadioButtons for the difficulty
    easy = new QRadioButton ("Easy");
    medium = new QRadioButton ("Medium");
    hard = new QRadioButton ("Hard");


    //Layout to make the speeds line up
    diffs = new QVBoxLayout;
    diffs->addWidget(difficulty);
    diffs->addWidget(easy);
    diffs->addWidget(medium);
    diffs->addWidget(hard);
    diffs->setAlignment(Qt::AlignCenter);



    //Piece together the title and the go button
    finalLayout = new QVBoxLayout;
    finalLayout->addWidget(lazer);
    finalLayout->addWidget(go);
    finalLayout->addLayout(diffs);
    finalLayout->addWidget(seeInstr);

    central = new QWidget;
    central->setLayout(finalLayout);

    central->setFixedHeight(300);
    central->setFixedWidth(400);

    this->setCentralWidget(central);

    setFixedSize(500,400);




}

/**MainWindow destructor
 */
MainWindow::~MainWindow()
{
    //delete ui;
}

/**This function sets the gamescene by connecting the pushbuttons and the radio buttons to correspond to game play
 @param game_scene is the games scene that will be added
 */
void MainWindow::setGameScene(gameScene *game_scene)
{
    gScene = game_scene;
   // QLabel* test = new QLabel("TESTING");

    QObject::connect(go, SIGNAL(clicked()), gScene, SLOT(show()));

    //QObject::connect(go, SIGNAL(clicked()), this, SLOT(close()));

    QObject::connect(easy, SIGNAL(clicked()), gScene->user, SLOT(diffEasy()));
    QObject::connect(medium, SIGNAL(clicked()), gScene->user, SLOT(diffMed()));
    QObject::connect(hard, SIGNAL(clicked()), gScene->user, SLOT(diffHard()));


}

/**This function sets the instruction screen that is opened with the push button "instructions"
*/
void MainWindow::setInstructions(instruction *inst_scene){
    instScene = inst_scene;
    QObject::connect(seeInstr, SIGNAL(clicked()), instScene, SLOT(show()));

}
