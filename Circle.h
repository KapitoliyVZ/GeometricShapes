// Заголовочный файл для инициализации класса "Круг"

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class CircleShape : public Shape
{
public:
    CircleShape(QPointF center, double radius);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPointF center;
    double radius;
};


#endif // CIRCLE_H
