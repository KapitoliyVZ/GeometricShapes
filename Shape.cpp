#include "Shape.h"

Shape::Shape()
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

void Shape::setPosition(int x, int y)
{
    setPos(x, y);
}

void Shape::setRotationAngle(int angle)
{
    setRotation(angle);
}
