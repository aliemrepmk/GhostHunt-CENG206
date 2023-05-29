#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include "Ghost.h"
#include <QLabel>
<<<<<<< HEAD
#include <QImage>
=======
>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c
Game::Game(){
    scene = new QGraphicsScene();
    scene ->setSceneRect(0,0,800,600);
    scene ->setBackgroundBrush(Qt::lightGray);
<<<<<<< HEAD
    setBackgroundBrush(QBrush(QImage(":/images/ground.jpg")));
=======

>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    //Start Game
    QPushButton* button1 = new QPushButton("Start The Game");
    button1->setFixedSize(200,50);
    QGraphicsProxyWidget* proxy1 = scene->addWidget(button1);
    proxy1->setPos(50, 150);
    connect(button1, &QPushButton::clicked, this, &Game::onButton1Clicked);

    //About
    QPushButton* button2 = new QPushButton("Learn About");
    button2->setFixedSize(200,50);
    QGraphicsProxyWidget* proxy2 = scene->addWidget(button2);
    proxy2->setPos(50, 350);
    connect(button2, &QPushButton::clicked, this, &Game::onButton2Clicked);

    show();
}
void Game::onButton1Clicked()
{



    //Start the Game
    QGraphicsScene  *inside_game = new QGraphicsScene();
    setScene(inside_game);
    inside_game->setSceneRect(0,0,800,600);
    inside_game ->setBackgroundBrush(Qt::white);
    player = new Player();
    inside_game->addItem(player);
    score = new Score();
    inside_game->addItem(score);
    for (int i = 0; i < 10; i++) {
        Ghost* ghost = new Ghost();
        inside_game->addItem(ghost);
    }

}
void Game::onButton2Clicked()
{

    //About
}
