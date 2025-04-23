// Заголовочный файл для инициализации класса "Круг"

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <QPainter>

// Класс фигуры - круг
class CircleShape : public Shape
{
public:
    // Конструктор с указанием центра и радиуса
    explicit CircleShape(QPointF center, double radius, const QString &customName = "");

    void setNewRadius(double newRadius);  // Установка нового радиуса
    void setNewCenter(QPointF newCenter); // Установка нового центра
    double getRadius();                   // Получение радиуса
    QPointF getCenter();                  // Получение центра

    // Реализация метода QGraphicsItem
    QRectF boundingRect() const override;
    // Отрисовка круга
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPointF center; // Центр круга
    double radius;  // Радиус круга
};

#endif // CIRCLE_H
