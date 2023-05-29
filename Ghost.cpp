#include "ghost.h"
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
Ghost::Ghost(QGraphicsRectItem *parent):QGraphicsRectItem(parent){
    // Set the ghost's initial position and size
    setPos(QRandomGenerator::global()->bounded(0, 500), QRandomGenerator::global()->bounded(0, 500));
    setRect(0, 0, 20, 20);
    // Create a timer to update the ghost's position every 100 ms
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ghost::move);
    timer->start(100);
}

QRectF Ghost::boundingRect() const
{
    return rect();
}

void Ghost::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Paint the ghost as a yellow square
    painter->setBrush(Qt::yellow);
    painter->drawRect(rect());
}

void Ghost::move()
{
    // Move the ghost in a random direction
    qreal dx = QRandomGenerator::global()->bounded(-10, 11);
    qreal dy = QRandomGenerator::global()->bounded(-10, 11);
    setPos(pos() + QPointF(dx, dy));

}
