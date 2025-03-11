#include "circle.h"
#include <QPainter>

Circle::Circle(int r, int x, int y, QColor c)
    : radius(r), centerX(x), centerY(y), color(c) {}

void Circle::draw(QPainter &painter, int width, int height) {
    painter.setPen(color);
    // painter.setBrush(color);

    int x = width / 2 + centerX - radius;
    int y = height / 2 - centerY - radius;

    // painter.drawEllipse(x, y, radius * 2, radius * 2);
    painter.drawEllipse(width / 2 - 25, height / 2 - 25, 50, 50);
}
