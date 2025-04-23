#ifndef SHAPEPROPERTIES_H
#define SHAPEPROPERTIES_H

#include <QWidget>
#include <QSpinBox>
#include <QPushButton>

#include "Shape.h"
#include "Circle.h"

// Класс для отображения параметров фигуры
class ShapeProperties : public QWidget
{
    Q_OBJECT

public:
    explicit ShapeProperties(QWidget *parent = nullptr);
    void setShape(Shape *shape); // Обновляем виджет при выборе фигуры

signals:
    void shapeUpdated(); // Сигнал: фигура изменилась
    void shapeDeleted(); // Сигнал: фигура удалена

private slots:
    void onRadiusChanged(int newRadius); // Изменение радиуса круга

private:
    Shape *currentShape = nullptr;        // Выбранная фигура
    CircleShape *currentCircle = nullptr; // Если выбрана окружность
};

#endif // SHAPEPROPERTIES_H
