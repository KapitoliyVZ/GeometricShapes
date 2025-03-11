#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <QColor>

class Circle : public Shape {
public:
    Circle(int r, int x, int y, QColor c);
    void draw(QPainter &painter, int width, int height) override;

private:
    int radius;
    int centerX, centerY;
    QColor color;
};

#endif // CIRCLE_H
