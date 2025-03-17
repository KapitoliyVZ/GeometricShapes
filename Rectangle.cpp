#include "Rectangle.h"

RectangleShape::RectangleShape(const QList<QPointF> &coords, const QString& customName)
    : Shape("Rectangle", customName)
{
    if (coords.size() == 4) {
        polygon = QPolygonF(coords);
        setPos(0, 0);  // Устанавливаем начальную позицию
    }
}

QRectF RectangleShape::boundingRect() const
{
    return polygon.boundingRect(); // Корректно определяем границы
}

void RectangleShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (polygon.isEmpty()) return;

    // Если фигура выделена
    if (isSelected())
    {
        painter->setPen(Qt::red); // цвет контура - красный
    }
    else
    {
        painter->setPen(Qt::black); // цвет контура - черный
    }

    // painter->setBrush(Qt::blue); // цвет заливки
    painter->drawPolygon(polygon);  // прорисовка фигуры
}
