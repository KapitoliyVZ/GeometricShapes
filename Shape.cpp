#include "Shape.h"
#include <QGraphicsSceneMouseEvent>


// Конструктор
Shape::Shape(const QString &type, const QString &customName)
{
    name = customName; // Имя фигуры
    // Включаем флаги для выделения
    setFlags(QGraphicsItem::ItemIsSelectable);
}

// Геттер имени
QString Shape::getName() const
{
    return name;
}

// Сеттер имени (для возможности изменения имени позже)
void Shape::setName(const QString &newName)
{
    if (!newName.isEmpty())
    {
        name = newName;
    }
}

// Изменение курсова при наведении на фигуру
void Shape::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(QCursor(Qt::PointingHandCursor)); // Курсор "рука"
    QGraphicsItem::hoverEnterEvent(event);
}

// Вернуть курсор прежним
void Shape::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    unsetCursor(); // Сброс курсора
    QGraphicsItem::hoverLeaveEvent(event);
}
