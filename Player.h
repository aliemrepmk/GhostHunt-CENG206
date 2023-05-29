#ifndef PLAYER_H
#define PLAYER_H
<<<<<<< HEAD
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsTextItem>
class Player :public QObject ,public QGraphicsPixmapItem{
=======
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsTextItem>
#include "Score.h"
class Player :public QObject ,public QGraphicsRectItem{
>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event)override;
    void update();
<<<<<<< HEAD
    int visionRadius;
=======
>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c
};

#endif // PLAYER_H
