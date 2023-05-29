#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include "Ghost.h"
#include <QLabel>
#include <QImage>
Game::Game(){
    main_scene = new QGraphicsScene(this);
    main_scene ->setSceneRect(0,0,800,600);
    main_scene ->setBackgroundBrush(Qt::lightGray);
    setBackgroundBrush(QBrush(QImage(":/images/ground.jpg")));


    setScene(main_scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    //Start Game
    QPushButton* button1 = new QPushButton("Start The Game");
    button1->setFixedSize(200,50);
    QGraphicsProxyWidget* proxy1 = main_scene->addWidget(button1);
    proxy1->setPos(50, 150);
    connect(button1, &QPushButton::clicked, this, &Game::onButton1Clicked);

    //About
    QPushButton* button2 = new QPushButton("Learn About");
    button2->setFixedSize(200,50);
    QGraphicsProxyWidget* proxy2 = main_scene->addWidget(button2);
    proxy2->setPos(50, 350);
    connect(button2, &QPushButton::clicked, this, &Game::onButton2Clicked);
    setWindowTitle("Epic Ghost Hunt");
    setWindowIcon(QIcon(":/images/icon.png"));
    show();
}

void Game::onButton1Clicked()
{



    //Start the Game
    inside_game = new QGraphicsScene();
    setScene(inside_game);
    inside_game->setSceneRect(0,0,800,600);
    inside_game ->setBackgroundBrush(Qt::white);
    player = new Player();
    player2 = new Player2();
    inside_game->addItem(player);
    inside_game->addItem(player2);
    score = new Score();
    inside_game->addItem(score);
    for (int i = 0; i < 11; i++) {//11 ghost
        Ghost* ghost = new Ghost();
        inside_game->addItem(ghost);
    }

}
void Game::onButton2Clicked()
{
    // Create the about_scene
    about_scene = new QGraphicsScene();
    setScene(about_scene);
    about_scene->setSceneRect(0, 0, 800, 600);
    about_scene->setBackgroundBrush(Qt::white);

    // Create labels
    QGraphicsTextItem* label1 = new QGraphicsTextItem("About This Game");
    label1->setPos(50, 50);
    label1->setFont(QFont("Arial", 24));
    about_scene->addItem(label1);

    QGraphicsTextItem* label2 = new QGraphicsTextItem("This is a game about...");
    label2->setPos(50, 100);
    label2->setFont(QFont("Arial", 16));
    about_scene->addItem(label2);

    // Create the back button
    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedSize(100, 30);
    QGraphicsProxyWidget* backButtonProxy = about_scene->addWidget(backButton);
    backButtonProxy->setPos(50, 500);
    connect(backButton, &QPushButton::clicked, this, &Game::returnToMainMenu);

    show();
}

void Game::keyPressEvent(QKeyEvent* event) {
    // Handle key events
    if (player) {
        player->keyPressEvent(event);
    }
    if (player2) {
        player2->keyPressEvent(event);
    }
}
void Game::returnToMainMenu()
{
    // Delete the about_scene
    QGraphicsScene currentScene = scene();
    setScene(nullptr);

    // Switch back to the main menu scene
    setScene(main_scene);
}
