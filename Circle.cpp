#include "Circle.h"

// Конструктор с указанием центра и радиуса
CircleShape::CircleShape(QPointF center, double radius, const QString &customName)
    : Shape("Circle", customName), center(center), radius(radius)
{
    setPos(center);
    setAcceptHoverEvents(true); // для изменения курсора при наведении
}

// Функция определяет границы объекта
QRectF CircleShape::boundingRect() const
{
    //
    return QRectF(-radius, -radius, radius * 2, radius * 2);
}

// Функция отрисовки круга
void CircleShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Если фигура выделена
    if (isSelected())
        painter->setPen(Qt::red); // цвет контура - красный
    else
        painter->setPen(Qt::gray); // цвет контура - черный

    painter->drawEllipse(boundingRect()); // прорисовка фигуры (эллипс)
}

// Задать новый радиус круга
void CircleShape::setNewRadius(double newRadius)
{
    if (newRadius <= 0)
        return; // Проверка на корректный радиус

    radius = newRadius; // Обновляем радиус
    update();           // Перерисовываем круг
}

// Получить значение радиуса круга
double CircleShape::getRadius()
{
    return radius;
}

// Задать новый центр круга
void CircleShape::setNewCenter(QPointF newCenter)
{
    center = newCenter; // Задаем новый центр
    setPos(newCenter);  // Меняем позицию в QGraphicsScene
    update();
}

// получить значение центра круга
QPointF CircleShape::getCenter()
{
    return center;
}
