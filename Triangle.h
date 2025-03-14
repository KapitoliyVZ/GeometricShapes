#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <QPolygonF>

class TriangleShape : public Shape
{
public:
    TriangleShape(const QList<QPointF> &coords);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    //QList<QPointF> points;
    QPolygonF polygon;

};

#endif // TRIANGLE_H
