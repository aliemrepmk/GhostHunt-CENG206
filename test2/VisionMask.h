#ifndef VISIONMASK_H
#define VISIONMASK_H
#include <QGraphicsItem>
class VisionMask: public QGraphicsItem{
public:
    VisionMask(qreal radius , QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter , const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    qreal m_radius;
};
#endif // VISIONMASK_H
