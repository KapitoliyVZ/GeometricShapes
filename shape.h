#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPolygon>
#include <QColor>

class Shape {
public:
    virtual ~Shape() {}  // Деструктор должен быть виртуальным
    virtual void draw(QPainter &painter, int width, int height) = 0; // Чисто виртуальный метод
};

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

class Rectangle : public Shape {
public:
    void draw(QPainter &painter, int width, int height)  override {
        painter.drawRect(width / 2 - 30, height / 2 - 20, 60, 40);
    }
};

class Circle : public Shape {
public:
    Circle(int r, int x, int y, QColor c);
    void draw(QPainter &painter, int width, int height) override;

private:
    int radius;
    int centerX, centerY;
    QColor color;
};

#endif // SHAPE_H
