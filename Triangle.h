#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <QPolygonF>

class TriangleShape : public Shape
{
public:
    TriangleShape(const QList<QPointF> &coords, const QString& customName = "");
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QVector<QPointF> getPoints() const;
    void setNewPoints(const QVector<QPointF>& newPoints);


private:
    QPolygonF polygon;

};

#endif // TRIANGLE_H
