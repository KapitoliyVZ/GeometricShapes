#include "Shape.h"

// Инициализация счётчика
int Shape::shapeCounter = 0;

// Конструктор
Shape::Shape(const QString& type, const QString& customName)
    : id(QUuid::createUuid())
{
    // Если имя передано пользователем, используем его
    if (!customName.isEmpty())
    {
        name = customName;
    }
    else
    {
        // Генерация имени автоматически
        ++shapeCounter;
        name = QString("%1_%2").arg(type).arg(shapeCounter);
    }

    // Включаем флаги для выделения
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
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
void Shape::setName(const QString& newName)
{
    if (!newName.isEmpty())
    {
        name = newName;
    }
}
