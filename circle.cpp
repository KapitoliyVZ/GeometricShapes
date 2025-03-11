#include "circle.h"

CircleShape::CircleShape(QPointF center, double radius)
    : center(center), radius(radius)
{
    setPos(center);
}

QRectF CircleShape::boundingRect() const
{
    return QRectF(-radius, -radius, radius * 2, radius * 2);
}

void CircleShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::red); // цвет заливки
    painter->setPen(Qt::black); // цвет контура
    painter->drawEllipse(boundingRect()); // прорисовка фигуры (эллипс)
}
