#include "Triangle.h"

TriangleShape::TriangleShape(const QList<QPointF> &coords, const QString& customName)
    : Shape("Triangle", customName)
{
    if (coords.size() == 3) {
        polygon = QPolygonF(coords);
        setPos(0, 0);  // Устанавливаем начальную позицию
    }
}

QRectF TriangleShape::boundingRect() const
{
    return polygon.boundingRect(); // Корректно определяем границы
}

void TriangleShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
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

// получение текущих координат
QVector<QPointF> TriangleShape::getPoints() const
{
    return polygon.toVector();
}

// задать новые координаты
void TriangleShape::setNewPoints(const QVector<QPointF>& newPoints)
{
    if (newPoints.size() == 3)
    {
        polygon = QPolygonF(newPoints);  // Обновляем координаты
        update();  // Перерисовка треугольник
    }
}

// задать угол вращения
void TriangleShape::setRotationAngle(int angle)
{
    setRotation(angle);
    update();  // Перерисовка треугольника
}

// получить текущий угол вращения
int TriangleShape::getRotationAngle() const
{
    return rotation();  // Возвращаем текущий угол
}

