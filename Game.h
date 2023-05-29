#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <Player.h>
#include <QTimer>
#include "Score.h"
class Game :public QGraphicsView{
public:
    Game();
    QGraphicsScene *scene;
    Player *player;
    Score *score;
public slots:
    void onButton1Clicked();
    void onButton2Clicked();
};

#endif // GAME_H
