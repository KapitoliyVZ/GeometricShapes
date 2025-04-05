#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <QPolygonF>

class TriangleShape : public Shape
{
public:
    TriangleShape(const QList<QPointF> &coords, const QString &customName = "");
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QVector<QPointF> getPoints() const;                   // получить текущие координаты треугольника
    void setNewPoints(const QVector<QPointF> &newPoints); // задать новые координаты треугольника
    void setRotationAngle(int angle);                     // задать вращение треугольника
    int getRotationAngle() const;                         // получить текущий угол вращения

private:
    QPolygonF polygon;
};

#endif // TRIANGLE_H
