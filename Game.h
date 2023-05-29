#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <Player.h>
#include <player2.h>
#include <QTimer>
#include "Score.h"
#include <QKeyEvent>
#include <QMovie>
#include <QApplication>
class Game :public QGraphicsView{
public:
    Game();
    QGraphicsScene *main_scene;
    QGraphicsScene *inside_game;
    Player *player;
    Player2 *player2;
    Score *score;
    void resetGame();
    QGraphicsScene *about_scene;
public slots:
    void onButton1Clicked();
    void onButton2Clicked();
    void returnToMainMenu();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GAME_H
