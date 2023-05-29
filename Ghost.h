#ifndef GHOST_H
#define GHOST_H
#include <QGraphicsPixmapItem>
#include <QObject>
class Ghost :public QObject ,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ghost(QGraphicsRectItem *parent = nullptr);
    ~Ghost(); //F
    bool isVisible;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    void move();
};

#endif // GHOST_H
