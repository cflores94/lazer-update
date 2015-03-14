#include "instruction.h"
#include "bullet.h"
#include "laser.h"
#include "enemy.h"
#include "senemy.h"
#include "youlost.h"
#include "lostlife.h"
#include "oneup.h"
#include "oneuporb.h"
#include <QRadialGradient>
#include <QFont>
#include <QGraphicsTextItem>
#include <QColor>
#include <QBrush>
#include <QImage>

#include <QDebug>

/**This is the instruction page constructor, it sets up all the images and text
 */
instruction::instruction(){



    //Create the scene
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::black);


    setScene(scene);


    Welcome = new QGraphicsTextItem("Welcome to Lazer!");
    Intro = new QGraphicsTextItem("It is the year 2215 and the world is now a post-apocalyptic wasteland.\n"
                                    "Major Lazer is one of the few remaining survivors in this world, and he\n"
                                    "is left alone to battle the evils that ended the world we all knew.\n ");
    instructionsHeader = new QGraphicsTextItem("Instructions: ");
    instructions = new QGraphicsTextItem("move: directional arrow keys\n"
                                         "shoot left:    a\n"
                                         "shoot down: s\n"
                                         "shoot right:  d\n"
                                         "shoot up:     w\n");
    gameItemHeader = new QGraphicsTextItem("Game Items/Character Key:");
    MLHeader = new QGraphicsTextItem("Major Lazer:");
    SentHeader = new QGraphicsTextItem("Sentinel Enemy:");
    MonstHeader = new QGraphicsTextItem("Monster Enemy:");
    LaserHeader = new QGraphicsTextItem("Laser Beam:");
    OrbHeader = new QGraphicsTextItem("Orb:");
    MLdes = new QGraphicsTextItem("The Major is an ex renegade Jamaican\n"
                                  "commando with laser arms who was a\n"
                                  "Zombie War veteran and vampire-\n"
                                  "fighting CIA operative. He is one of the\n"
                                  "few who survived the apocalypse and\n"
                                  "is fighting to regain the Earth he once\n"
                                  "knew and loved. ");
    SentDes = new QGraphicsTextItem("moves from right to left. Beware of\n"
                                    "occaisional change of speed");
    MonstDes = new QGraphicsTextItem("This enemy is more intelligent. He\n"
                                     "follows the Major around wherever he\n"
                                     "goes and can even shoot back at the\n"
                                     "Major.");
    LaserDes = new QGraphicsTextItem("Due to the Earth's atmosphere's\n"
                                     "current state, laser beams periodically\n"
                                     "rain down from above, another reason\n"
                                     "why most of the Earth's population has\n"
                                     "diminished. These will hurt the Major\n"
                                     "upon contact. ");
    OrbDes = new QGraphicsTextItem("Whenever the Major kills enough\n"
                                   "enemies, this orb appears in the\n"
                                   "vicinity. Stay attentive, because Major\n"
                                   "Lazer only has a finite amount of time\n"
                                   "to retrieve the orb and gain an extra\n"
                                   "life before it disappears. ");
    conclusion = new QGraphicsTextItem("The creatures seem to come in waves. They may be slow and \n"
                                       "predictable at first, but if you kill enough of them they learn from \n"
                                       "your behavior and become more challenging. Try to stay alive as long\n"
                                       "as you can and DON'T TOUCH THE LASERS!\n"
                                       "(exit this window when ready to play)\n");



    //set the font
    QFont font;
        font.setBold(true);
        font.setPointSize(15);
    QFont Bigfont;
        Bigfont.setBold(true);
        Bigfont.setUnderline(true);
        Bigfont.setPointSize(24);
    QFont Ufont;
        Ufont.setBold(true);
        Ufont.setUnderline(true);
        Ufont.setPointSize(15);

    //assign the color and font
    QColor gText("lightgray");
    Welcome->setDefaultTextColor(gText);
    Welcome->setFont(Bigfont);

    Intro->setDefaultTextColor(gText);
    Intro->setFont(font);

    instructionsHeader->setDefaultTextColor(gText);
    instructionsHeader->setFont(Ufont);

    instructions->setDefaultTextColor(gText);
    instructions->setFont(font);

    gameItemHeader->setDefaultTextColor(gText);
    gameItemHeader->setFont(Ufont);

    MLHeader->setDefaultTextColor(gText);
    MLHeader->setFont(font);

    SentHeader->setDefaultTextColor(gText);
    SentHeader->setFont(font);

    MonstHeader->setDefaultTextColor(gText);
    MonstHeader->setFont(font);

    OrbHeader->setDefaultTextColor(gText);
    OrbHeader->setFont(font);

    LaserHeader->setDefaultTextColor(gText);
    LaserHeader->setFont(font);

    MLdes->setDefaultTextColor(gText);
    MLdes->setFont(font);

    SentDes->setDefaultTextColor(gText);
    SentDes->setFont(font);

    MonstDes->setDefaultTextColor(gText);
    MonstDes->setFont(font);

    OrbDes->setDefaultTextColor(gText);
    OrbDes->setFont(font);

    LaserDes->setDefaultTextColor(gText);
    LaserDes->setFont(font);

    conclusion->setDefaultTextColor(gText);
    conclusion->setFont(font);

    //add to the scene
    scene->addItem(Welcome);
    scene->addItem(Intro);
    scene->addItem(instructionsHeader);
    scene->addItem(instructions);
    scene->addItem(gameItemHeader);

    scene->addItem(MLHeader);
    scene->addItem(SentHeader);
    scene->addItem(MonstHeader);
    scene->addItem(OrbHeader);
    scene->addItem(LaserHeader);
    scene->addItem(MLdes);
    scene->addItem(SentDes);
    scene->addItem(MonstDes);
    scene->addItem(OrbDes);
    scene->addItem(LaserDes);
    scene->addItem(conclusion);

    //position the text
    Intro->setY(40);
    instructionsHeader->setY(105);
    instructions->setY(125);
    gameItemHeader->setY(222);
    MLHeader->setY(242);
    MLdes->setPos(250, 252);
    SentHeader->setY(420);
    SentDes->setPos(250, 430);
    MonstHeader->setY(600);
    MonstDes->setPos(250, 610);
    OrbHeader->setY(778);
    OrbDes->setPos(250, 788);
    LaserHeader->setY(956);
    LaserDes->setPos(250, 966);
    conclusion->setY(1134);


    //now add the pictures
    playerPic = new MLimage;
    playerPic->setPos(50,300);
    scene->addItem(playerPic);

    sentinelPic = new sentImage;
    sentinelPic->setPos(20,480);
    scene->addItem(sentinelPic);

    SenemyPic = new monstImage;
    SenemyPic->setPos(40,640);
    scene->addItem(SenemyPic);

    orbPic = new orbImage;
    orbPic->setPos(70, 825);
    scene->addItem(orbPic);

    laserPic = new laserImage;
    laserPic->setPos(100, 1000);
    scene->addItem(laserPic);


    setFixedWidth(700);






    this->setWindowTitle("laZer Instructions");
}

/**instruction destructor
 */
instruction::~instruction()
{

}
