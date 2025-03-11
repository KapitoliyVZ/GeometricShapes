#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
    void draw(QPainter &painter, int width, int height)  override {
        painter.drawRect(width / 2 - 30, height / 2 - 20, 60, 40);
    }
};

#endif // RECTANGLE_H
