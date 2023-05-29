#include "ghost.h"
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <QGraphicsScene>

Ghost::Ghost(QGraphicsRectItem *parent):QGraphicsRectItem(parent){
    // Set the ghost's initial position and size
    setPos(QRandomGenerator::global()->bounded(0, 500), QRandomGenerator::global()->bounded(0, 500));
    setRect(-5,-5,20,20);
    // Create a timer to update the ghost's position every 100 ms
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ghost::move);
    timer->start(100);
    isVisible=false;
}

Ghost::~Ghost(){ //F
    if (scene() != nullptr) {
        scene()->removeItem(this);
    }
}

QRectF Ghost::boundingRect() const
{
    return rect();
}

void Ghost::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Set the transparency level
    if(isVisible){
        painter->setOpacity(0.5); // Adjust the value to change the transparency

        painter->setBrush(QColor(255, 255, 0)); // Yellow color with transparency
        painter->drawRect(rect());
    }
}

void Ghost::move()
{

    // Move the ghost in a random direction
    qreal dx = QRandomGenerator::global()->bounded(-10, 11);
    qreal dy = QRandomGenerator::global()->bounded(-10, 11);
    // Calculate the new position
    QPointF newPos = pos() + QPointF(dx, dy);

    // Check if the new position is within the scene boundaries
    if (scene() && scene()->sceneRect().contains(newPos))
    {
        // Set the new position if it's within the scene

        setPos(newPos);
    } else{
        move();
    }

}
