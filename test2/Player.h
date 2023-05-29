#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsTextItem>
#include "Score.h"
class Player :public QObject ,public QGraphicsRectItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event)override;
    void update();
};

#endif // PLAYER_H
