#include "Rectangle.h"

// Конструктор-1 с четырьмя координатами
RectangleShape::RectangleShape(const QList<QPointF> &coords, const QString& customName)
    : Shape("Rectangle", customName)
{
    if (coords.size() == 4) {
        polygon = QPolygonF(coords);
        setPos(0, 0);  // Устанавливаем начальную позицию
    }
}

// Конструктор-2 с начальной точкой и размерами
RectangleShape::RectangleShape(const QPointF& startPoint, double width, double height, const QString& customName)
    : Shape("Rectangle", customName)
{
    polygon = QRectF(startPoint.x(), startPoint.y(), width, height);  // Прямоугольник по начальной точке и размерам
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

// получение текущих координат
QVector<QPointF> RectangleShape::getPoints() const
{
    return polygon.toVector();
}

// задать новые координаты
void RectangleShape::setNewPoints(const QVector<QPointF>& newPoints)
{
    if (newPoints.size() == 4)
    {
        polygon = QPolygonF(newPoints);  // Обновляем координаты
        update();  // Перерисовка треугольник
    }
}

// задать угол вращения
void RectangleShape::setRotationAngle(int angle)
{
    setRotation(angle);
    update();  // Перерисовка треугольника
}

// получить текущий угол вращения
int RectangleShape::getRotationAngle() const
{
    return rotation();  // Возвращаем текущий угол
}

