#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include "Ghost.h"
#include <QLabel>
#include <QImage>
#include <QMovie>
#include <QStyle>
#include <QApplication>
Game::Game(){
    main_scene = new QGraphicsScene(this);
    main_scene ->setSceneRect(0,0,800,600);
    main_scene ->setBackgroundBrush(Qt::lightGray);
    QMovie* movie = new QMovie(":/images/initialGround.gif");
    if (movie->isValid()) {
        QGraphicsProxyWidget* proxy = main_scene->addWidget(new QLabel());
        proxy->setPos(0, 0);
        proxy->show();
        QLabel* label = qobject_cast<QLabel*>(proxy->widget());
        if (label) {
            label->setMovie(movie);
            movie->start();
        }
    }



    setScene(main_scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    //Start Game
    QPushButton* button1 = new QPushButton("Start The Game");
    button1->setFixedSize(150,50);

    button1->setStyleSheet("background-color: brown; color: white;");
    QGraphicsProxyWidget* proxy1 = main_scene->addWidget(button1);
    proxy1->setPos(50, 150);
    connect(button1, &QPushButton::clicked, this, &Game::onButton1Clicked);

    //About
    QPushButton* button2 = new QPushButton("Learn About");
    button2->setFixedSize(150,50);
    button2->setStyleSheet("background-color: brown; color: white;");
    QGraphicsProxyWidget* proxy2 = main_scene->addWidget(button2);
    proxy2->setPos(50, 300);
    connect(button2, &QPushButton::clicked, this, &Game::onButton2Clicked);
    setWindowTitle("Epic Ghost Hunt");
    setWindowIcon(QIcon(":/images/icon.png"));
    show();
}

void Game::onButton1Clicked()
{
    setBackgroundBrush(QBrush(QImage(":/images/ground.jpg")));
    //Start the Game
    inside_game = new QGraphicsScene();   //Explicit heap dynamic variable
    setScene(inside_game);
    inside_game->setSceneRect(0,0,800,600);
    inside_game ->setBackgroundBrush(Qt::white);
    player = new Player();    //Explicit heap dynamic variable
    player2 = new Player2();  //Explicit heap dynamic variable
    inside_game->addItem(player);
    inside_game->addItem(player2);
    score = new Score();  //Explicit heap dynamic variable
    inside_game->addItem(score);
    for (int i = 0; i < 11; i++) {//11 ghost
        Ghost* ghost = new Ghost();
        inside_game->addItem(ghost);
    }

}
void Game::onButton2Clicked()
{
    // Create the about_scene
    setBackgroundBrush(QBrush(QImage(":/images/ground2.png")));
    about_scene = new QGraphicsScene();
    setScene(about_scene);
    about_scene->setSceneRect(0, 0, 800, 600);
    about_scene->setBackgroundBrush(Qt::white);

    // Create labels
    QGraphicsTextItem* label1 = new QGraphicsTextItem("About This Game");
    label1->setPos(300, 50);
    label1->setFont(QFont("Arial", 24));
    about_scene->addItem(label1);

    QGraphicsTextItem* label2 = new QGraphicsTextItem("-------------------------------------------");
    label2->setPos(275, 100);
    label2->setFont(QFont("Arial", 16));
    about_scene->addItem(label2);

    QGraphicsTextItem* label3 = new QGraphicsTextItem("Contributors:                    How To Play:");
    label3->setPos(175, 150);
    label3->setFont(QFont("Arial", 20));
    about_scene->addItem(label3);

    QGraphicsTextItem* label4 = new QGraphicsTextItem("->Ali Emre PAMUK           ->Press 'Start The Game'.\n"
                                                      "->Eren ALYÖRÜK             ->First player plays with 'WASD',\n"
                                                      "->Faruk KAPLAN                 second players play with d-pad."
                                                      "\n->Mert ALTEKİN                ->The first player who eat 6 ghosts"
                                                      "\n->Şeyma SARCAN               wins.");
    label4->setPos(125, 200);
    label4->setFont(QFont("Arial", 18));
    about_scene->addItem(label4);

    // Create the back button
    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedSize(100, 30);
    backButton->setStyleSheet("background-color: black; color: white;");
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
