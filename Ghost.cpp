#include "ghost.h"
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
Ghost::Ghost(QGraphicsRectItem *parent):QGraphicsRectItem(parent){
    // Set the ghost's initial position and size
    setPos(QRandomGenerator::global()->bounded(0, 500), QRandomGenerator::global()->bounded(0, 500));
<<<<<<< HEAD
    setRect(-5,-5,20,20);
=======
    setRect(0, 0, 20, 20);
>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c
    // Create a timer to update the ghost's position every 100 ms
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ghost::move);
    timer->start(100);
<<<<<<< HEAD
    isVisible=false;
=======
>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c
}

QRectF Ghost::boundingRect() const
{
    return rect();
}

void Ghost::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
<<<<<<< HEAD
        // Set the transparency level
    if(isVisible){
        painter->setOpacity(0.5); // Adjust the value to change the transparency

        painter->setBrush(QColor(255, 255, 0)); // Yellow color with transparency
        painter->drawRect(rect());
    }
=======
    // Paint the ghost as a yellow square
    painter->setBrush(Qt::yellow);
    painter->drawRect(rect());
>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c
}

void Ghost::move()
{
<<<<<<< HEAD

=======
>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c
    // Move the ghost in a random direction
    qreal dx = QRandomGenerator::global()->bounded(-10, 11);
    qreal dy = QRandomGenerator::global()->bounded(-10, 11);
    setPos(pos() + QPointF(dx, dy));

}
