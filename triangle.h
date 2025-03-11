#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "shape.h"
#include <QPolygon>

class Triangle : public Shape {
public:
    void draw(QPainter &painter, int width, int height)  override {
        QPolygon triangle;
        triangle << QPoint(width / 2, height / 2 - 30)
                 << QPoint(width / 2 - 30, height / 2 + 20)
                 << QPoint(width / 2 + 30, height / 2 + 20);
        painter.drawPolygon(triangle);
    }
};

#endif // TRIANGLE_H
