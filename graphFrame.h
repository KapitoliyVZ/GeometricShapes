#ifndef GRAPHFRAME_H
#define GRAPHFRAME_H

#include <QWidget>
#include <QList>
#include "shape.h"

class GraphFrame : public QWidget {
    Q_OBJECT

public:
    explicit GraphFrame(QWidget *parent = nullptr);
    void addShape(Shape *shape);     // Устанавливаем фигуру
    void clearShapes();              // Удаляем фигуры (очистка списка)

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QList<Shape*> shapes; // Список всех нарисованных фигур

};

#endif // GRAPHFRAME_H
