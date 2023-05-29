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
#include <QRectF>
#include <QGraphicsTextItem>
extern Game *game;
Player :: Player():QGraphicsPixmapItem(){
    setPixmap(QPixmap(":/images/area.png"));
    setPos(400,550);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    qreal new_ax =0.5;
    qreal new_ay =0.5;
    QTransform transform;
    transform.translate(-pixmap().width() * new_ax, -pixmap().height() * new_ay);
    setTransform(transform);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::update);
    timer->start(10);
    visionRadius=90.00;
}
void Player::keyPressEvent(QKeyEvent * event)
{
    if (event -> key() == Qt::Key_Left && x() >0){
        setPos(x()-10,y());
        qDebug() << x();
    }
    else if (event -> key() == Qt::Key_Right && x() + pixmap().width() -100 < scene()->width()){
        setPos(x()+10,y());
        qDebug() << x();
    }
    else if (event -> key() == Qt::Key_Up && y() > 0){
        setPos(x(),y()-10);
        qDebug() << y();
    }
    else if (event -> key() == Qt::Key_Down && y() + pixmap().height() -100 < scene()->height()){
        setPos(x(),y()+10);
        qDebug() << y();
    }
}
void Player::update()
{

    // Get a list of all items colliding with the player
    QList<QGraphicsItem*> collisions = collidingItems();

    // Iterate over the colliding items
    for (QGraphicsItem *item : collisions) {
        if (Ghost *ghost = dynamic_cast<Ghost *>(item)) {
            // Calculate the distance between the player and the ghost
            qreal dx = ghost->x() - x();
            qreal dy = ghost->y() - y();
            qreal distance = std::sqrt(dx * dx + dy * dy);

            // Check if the ghost is within the vision radius
            if (distance <= visionRadius) {
                qDebug() << distance;
                // Collision with a ghost within the vision radius
                ghost->isVisible=true;
            }
                if(distance <= 10){
                    game->score->increase();
                    scene()->removeItem(ghost);
                    delete ghost;
                }
            }
        }
    }
