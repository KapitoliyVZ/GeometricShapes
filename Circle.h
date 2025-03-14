// Заголовочный файл для инициализации класса "Круг"

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <QPainter>

class CircleShape : public Shape
{
public:
    // Конструктор с указанием центра и радиуса
    explicit CircleShape(QPointF center, double radius, const QString& customName = "");

    // Реализация метода QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPointF center;
    double radius;
};


#endif // CIRCLE_H
