// Заголовочный файл для инициализации родительского класса Фигуры

#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>    // библиотека для графических объектов для сцены
#include <QPainter>         // библиотека для инструментов отрисовки объектов
#include <QString>


class Shape : public QGraphicsItem
{
public:
    Shape();
    //virtual ~Shape();

    virtual QRectF boundingRect() const override = 0; // Границы объекта
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0; // Отрисовка

    void setPosition(int x, int y); // Установка позиции
    void setRotationAngle(int angle); // Установка угла поворота
};

#endif // SHAPE_H
