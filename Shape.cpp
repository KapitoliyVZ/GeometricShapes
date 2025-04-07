#include "Shape.h"
#include <QGraphicsSceneMouseEvent>


// Конструктор
Shape::Shape(const QString &type, const QString &customName) : id(QUuid::createUuid())
{

    name = customName;
    // Включаем флаги для выделения
    setFlags(QGraphicsItem::ItemIsSelectable);
}

// Геттер имени
QString Shape::getName() const
{
    return name;
}

// Геттер ID
QUuid Shape::getId() const
{
    return id;
}

// Сеттер имени (для возможности изменения имени позже)
void Shape::setName(const QString &newName)
{
    if (!newName.isEmpty())
    {
        name = newName;
    }
}
