#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>

class Shape {
public:
    virtual ~Shape() {}  // Деструктор должен быть виртуальным
    virtual void draw(QPainter &painter, int width, int height) = 0; // Чисто виртуальный метод
};

#endif // SHAPE_H
