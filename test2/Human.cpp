#include "Human.h"
Human::Human(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent){
    // Set the size and color of the human
    setRect(0,0,20,20);
    setBrush(Qt :: green);

    // Create a timer that will move the human periodically
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Human::moveRandomly);
    timer->start(500); // Move the human every 1 second
}
void Human::moveRandomly()
{
    // Generate a random direction to move in
    qreal dx = QRandomGenerator::global()->bounded(-10, 10);
    qreal dy = QRandomGenerator::global()->bounded(-10, 10);

    // Move the human by the random amount
    setPos(x() + dx, y() + dy);
}
