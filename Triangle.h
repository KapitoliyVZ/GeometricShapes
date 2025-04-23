#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <QPolygonF>

// Класс TriangleShape наследуется от класса Shape и представляет собой треугольник
class TriangleShape : public Shape
{
public:
    TriangleShape(const QList<QPointF> &coords, const QString &customName = ""); // конструктор 
    QRectF boundingRect() const override; // определение границ
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override; // отрисовка

    QVector<QPointF> getPoints() const;                   // получить текущие координаты треугольника
    void setNewPoints(const QVector<QPointF> &newPoints); // задать новые координаты треугольника
    void setRotationAngle(int angle);                     // задать вращение треугольника
    int getRotationAngle() const;                         // получить текущий угол вращения

private:
    QPolygonF polygon; // координаты треугольника
};

#endif // TRIANGLE_H
