#include "Circle.h"

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

    qDebug() << "Рисуется круг: " << getName() << ", выделена: " << isSelected() << ", радиус:" << CircleShape::getRadius();

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

// задать новый радиус круга
void CircleShape::setNewRadius(double newRadius)
{
    qDebug() << "новый радиус: "<<newRadius;
    if (newRadius <= 0) return; // Проверка на корректный радиус

    radius = newRadius; // Обновляем радиус
    update();           // Перерисовываем круг
}

// получить значение радиуса круга
double CircleShape::getRadius()
{
    return radius;
}

// задать новый центр круга
void CircleShape::setNewCenter(QPointF newCenter)
{
    qDebug() << "Центр изменен: (" << newCenter.x() << "," << newCenter.y() << ")";

    center = newCenter; // Обновляем центр
    setPos(newCenter);  // Меняем позицию в QGraphicsScene
    update();
}

// получить значение центра круга
QPointF CircleShape::getCenter()
{
    return center;
}

