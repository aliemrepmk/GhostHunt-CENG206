#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <Player.h>
#include <QTimer>
<<<<<<< HEAD
#include "Score.h"
=======
>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c
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
