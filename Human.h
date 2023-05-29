#ifndef HUMAN_H
#define HUMAN_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QBrush>
#include <QRandomGenerator>
class Human : public QObject , public QGraphicsRectItem{
    Q_OBJECT
public :
    Human(QGraphicsItem *parent = nullptr);
public slots :
    void moveRandomly();
};

#endif // HUMAN_H
