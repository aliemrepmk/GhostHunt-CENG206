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
class Game :public QGraphicsView{
public:
    Game();
    QGraphicsScene *scene;
    Player *player;
    Player2 *player2;
    Score *score;
public slots:
    void onButton1Clicked();
    void onButton2Clicked();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GAME_H
