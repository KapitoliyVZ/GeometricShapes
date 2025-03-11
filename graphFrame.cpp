#include "graphFrame.h"
#include <QPainter>

GraphFrame::GraphFrame(QWidget *parent) : QWidget(parent) {}


void GraphFrame::addShape(Shape *shape) {
    shapes.append(shape);   // Добавляем новую фигуру в список
    update();               // Перерисовываем
}

void GraphFrame::clearShapes() {
    qDeleteAll(shapes); // Освобождаем память
    shapes.clear();     // Очищаем список
    update();           // Перерисовываем окно
}

void GraphFrame::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    int centerX = width() / 2;  // начало оси X
    int centerY = height() / 2; // начало оси Y

    // Рисуем координатные оси
    painter.setPen(Qt::black);                          // задаем цвет: черный
    painter.drawLine(centerX, 0, centerX, height());    // Ось Y
    painter.drawLine(0, centerY, width(), centerY);     // Ось X

    // Подписываем оси
    painter.drawText(centerX + 5, 15, "Y");             // Верх оси Y
    painter.drawText(width() - 20, centerY - 5, "X");   // Правый конец оси X

    // Рисуем координаты через каждые 50 пикселей
    for (int i = -centerX; i <= centerX; i += 50) {
        int xPos = centerX + i;
        if (xPos > 0 && xPos < width()) {
            painter.drawText(xPos, centerY + 15, QString::number(i / 50)); // Ось X
            painter.drawLine(xPos, centerY - 3, xPos, centerY + 3);
        }
    }

    for (int i = -centerY; i <= centerY; i += 50) {
        int yPos = centerY - i;
        if (yPos > 0 && yPos < height()) {
            painter.drawText(centerX + 5, yPos, QString::number(i / 50)); // Ось Y
            painter.drawLine(centerX - 3, yPos, centerX + 3, yPos);
        }
    }

    // Рисуем все фигуры из списка
    painter.setPen(Qt::red);
    for (Shape *shape : shapes) {
        shape->draw(painter, width(), height());
    }

}
