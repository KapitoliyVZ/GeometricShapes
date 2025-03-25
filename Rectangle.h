// Заголовочный файл для инициализации класса "Прямоугольник"

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <QPolygonF>

class RectangleShape : public Shape
{
public:
    // Конструктор-1 для параметров по 4 координтам
    RectangleShape(const QList<QPointF> &coords, const QString& customName = "");

    // Конструктор-2 для параметров по начальной точке и 2 сторонам
    RectangleShape(const QPointF &startPoint, double width, double height, const QString& customName = "");

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QVector<QPointF> getPoints() const;                     // получить текущие координаты
    void setNewPoints(const QVector<QPointF>& newPoints);   // задать новые координаты прямоугольника
    void setRotationAngle(int angle);                       // задать вращение прямоугольника
    int getRotationAngle() const;                           // получить текущий угол вращения

private:
    QPolygonF polygon;
};

#endif // RECTANGLE_H
