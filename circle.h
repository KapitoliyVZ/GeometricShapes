#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

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
