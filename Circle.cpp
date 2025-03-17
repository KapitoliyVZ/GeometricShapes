#include "Circle.h"
#include "qstyle.h"

CircleShape::CircleShape(QPointF center, double radius, const QString& customName)
    : Shape("Circle", customName), center(center), radius(radius)
{
    setPos(center);
}

QRectF CircleShape::boundingRect() const
{
    return QRectF(-radius, -radius, radius * 2, radius * 2);
}

void CircleShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    // qDebug() << "Рисуется круг: " << getName() << ", выделена: " << isSelected();

    // Если фигура выделена
    if (isSelected())
    {
        painter->setPen(Qt::red); // цвет контура - красный
    }
    else
    {
        painter->setPen(Qt::black); // цвет контура - черный
    }

    // painter->setBrush(Qt::red); // цвет заливки
    painter->drawEllipse(boundingRect()); // прорисовка фигуры (эллипс)
}
