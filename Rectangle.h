// Заголовочный файл для инициализации класса "Круг"

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <QPolygonF>

class RectangleShape : public Shape
{
public:
    RectangleShape(const QList<QPointF> &coords);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    //QList<QPointF> points;
    QPolygonF polygon;
};

#endif // RECTANGLE_H
