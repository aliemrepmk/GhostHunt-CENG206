#include "VisionMask.h"
#include <QPainter>
VisionMask::VisionMask(qreal radius , QGraphicsItem *parent):QGraphicsItem(parent),m_radius(radius){
    setOpacity(0.5);
}
QRectF VisionMask :: boundingRect()const{
    return QRectF(-m_radius,-m_radius,2 * m_radius, 2*m_radius);
}
void VisionMask::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setBrush(Qt::black);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(boundingRect());
}
