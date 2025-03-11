#include "rectangle.h"

RectangleShape::RectangleShape(const QList<QPointF> &coords)
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

    // painter->setBrush(Qt::blue); // цвет заливки
    painter->setPen(Qt::white);     // цвет контура
    painter->drawPolygon(polygon);  // прорисовка фигуры
}
