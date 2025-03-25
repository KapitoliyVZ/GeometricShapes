#include "Triangle.h"

TriangleShape::TriangleShape(const QList<QPointF> &coords)
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

    // painter->setBrush(Qt::blue); // цвет заливки
    painter->setPen(Qt::white);     // цвет контура
    painter->drawPolygon(polygon);  // прорисовка фигуры
}
<<<<<<< Updated upstream
=======

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
        update();  // Перерисовка треугольника
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

>>>>>>> Stashed changes
