#ifndef GHOST_H
#define GHOST_H
#include <QGraphicsRectItem>
#include <QObject>
class Ghost :public QObject ,public QGraphicsRectItem{
    Q_OBJECT
public:
    Ghost(QGraphicsRectItem *parent = nullptr);
    ~Ghost(); //F
    bool isVisible;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    void move();
};

#endif // GHOST_H
