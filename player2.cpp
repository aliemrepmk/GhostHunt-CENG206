#include "Player2.h"
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
<<<<<<< HEAD
#include <unordered_set>
=======
>>>>>>> 9f8895c1860b7d285b4dada89ad78fa131118c9e
extern Game *game;
Player2 :: Player2():QGraphicsPixmapItem(), AbstractPlayer(){
    setPixmap(QPixmap(":/images/area2.png"));
    setPos(400,50);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    qreal new_ax =0.5;
    qreal new_ay =0.5;
    QTransform transform;
    transform.translate(-pixmap().width() * new_ax, -pixmap().height() * new_ay);
    setTransform(transform);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player2::update);
    timer->start(10);
<<<<<<< HEAD
    visionRadius=75.00;
=======
    visionRadius=90.00;
>>>>>>> 9f8895c1860b7d285b4dada89ad78fa131118c9e
}
void Player2::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_A && x()>0) {
        setPos(x()-10, y());
<<<<<<< HEAD

    } else if (event->key() == Qt::Key_D && x()<scene()->width()) {
        setPos(x() + 10, y());

    } else if (event->key() == Qt::Key_W && y()>0 ) {
        setPos(x(), y() - 10);

    } else if (event->key() == Qt::Key_S && y()<scene()->height()) {
        setPos(x() , y()+ 10);
        ;
=======
        qDebug() << "Key A pressed";
    } else if (event->key() == Qt::Key_D && x()<scene()->width()) {
        setPos(x() + 10, y());
        qDebug() << "Key D pressed";
    } else if (event->key() == Qt::Key_W && y()>0 ) {
        setPos(x(), y() - 10);
        qDebug() << "Key W pressed";
    } else if (event->key() == Qt::Key_S && y()<scene()->height()) {
        setPos(x() , y()+ 10);
        qDebug() << "Key S pressed";
>>>>>>> 9f8895c1860b7d285b4dada89ad78fa131118c9e
    }
}
void Player2::update()
{

    // Get a list of all items colliding with the player
    QList<QGraphicsItem*> collisions = collidingItems();

<<<<<<< HEAD
    static std::unordered_set<Ghost*> visibleGhosts;

    for (auto it = visibleGhosts.begin(); it != visibleGhosts.end(); )
    {
        Ghost* ghost = *it;
        qreal dx = ghost->x() - x();
        qreal dy = ghost->y() - y();
        qreal distance = std::sqrt(dx * dx + dy * dy);

        if (distance > visionRadius)
        {
            ghost->isVisible = false;
            it = visibleGhosts.erase(it);
        }
        else
        {
            ++it;
        }
    }
    for (QGraphicsItem* item : collisions)
    {
        if (Ghost* ghost = dynamic_cast<Ghost*>(item))
        {
=======
    // Iterate over the colliding items
    for (QGraphicsItem *item : collisions) {
        if (Ghost *ghost = dynamic_cast<Ghost *>(item)) {
            // Calculate the distance between the player and the ghost
>>>>>>> 9f8895c1860b7d285b4dada89ad78fa131118c9e
            qreal dx = ghost->x() - x();
            qreal dy = ghost->y() - y();
            qreal distance = std::sqrt(dx * dx + dy * dy);

<<<<<<< HEAD
            if (distance <= visionRadius)
            {
                ghost->isVisible = true;

                // Add the visible ghost to the set
                visibleGhosts.insert(ghost);
            }

            if (distance <= 10)
            {
                game->score->increase(2);
                scene()->removeItem(ghost);
                delete ghost;
                visibleGhosts.erase(ghost);
            }
        }
    }


}
=======
            // Check if the ghost is within the vision radius
            if (distance <= visionRadius) {
                qDebug() << distance;
                // Collision with a ghost within the vision radius
                ghost->isVisible=true;
            } else{
                ghost->isVisible=false;
            }
            if(distance <= 10){
                game->score->increase(2);
                scene()->removeItem(ghost);
                delete ghost;
            }
        }
    }
}

>>>>>>> 9f8895c1860b7d285b4dada89ad78fa131118c9e
