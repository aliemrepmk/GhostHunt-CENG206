#include "Player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"
#include "ghost.h"
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QGraphicsTextItem>
extern Game *game;
Player :: Player(){
    setRect(0,0,100,100);
    setPos(400,500);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::update);
    timer->start(100);
}
void Player::keyPressEvent(QKeyEvent * event)
{
    if (event -> key() == Qt::Key_Left && x()>0){
        setPos(x()-10,y());
    }
    else if (event -> key() == Qt::Key_Right && x() + rect().width() < scene()->width()){
        setPos(x()+10,y());
    }
    else if (event -> key() == Qt::Key_Up && y() > 0){
        setPos(x(),y()-10);
    }
    else if (event -> key() == Qt::Key_Down && y() + rect().height() < scene()->height()){
        setPos(x(),y()+10);
    }
}
void Player::update()
{

    // Get a list of all items colliding with the player
    QList<QGraphicsItem*> collisions = collidingItems();

    // Iterate over the colliding items
    for (QGraphicsItem* item : collisions) {
        if (dynamic_cast<Ghost*>(item)) {
            // Collision with a ghost detected
            Ghost* ghost = static_cast<Ghost*>(item);

            // Increment the player's score
            game->score->increase();
            // Remove the ghost from the scene
            scene()->removeItem(ghost);
            delete ghost;
        }
    }
}
