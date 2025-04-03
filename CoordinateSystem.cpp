#include "CoordinateSystem.h"

// Конструктор: создаём оси и деления только 1 раз
GraphSettings::GraphSettings(QGraphicsScene *scene, int step): scene(scene), stepSize(step)
{
    if (!scene) return;

    // Создаём оси
    axisX = scene->addLine(0, 0, 0, 0, QPen(Qt::white, 2)); // Ось X
    axisY = scene->addLine(0, 0, 0, 0, QPen(Qt::white, 2)); // Ось Y

    // Создаём деления на осях
    for (int i = -10; i <= 10; i++) // Предполагаем 10 делений в каждую сторону
    {
        QGraphicsLineItem *tickX = scene->addLine(0, 0, 0, 0, QPen(Qt::black));
        QGraphicsLineItem *tickY = scene->addLine(0, 0, 0, 0, QPen(Qt::black));
        axisTicksX.append(tickX);
        axisTicksY.append(tickY);

        QGraphicsTextItem *labelX = scene->addText(QString::number(i * step), QFont("Arial", 6));
        QGraphicsTextItem *labelY = scene->addText(QString::number(i * step), QFont("Arial", 6));
        axisLabelsX.append(labelX);
        axisLabelsY.append(labelY);
    }
}

// Функция обновления размера и отрисовки
void GraphSettings::updateSceneSize(int width, int height)
{
    if (!scene) return;

    scene->setSceneRect(-width / 2, -height / 2, width, height);

    // Обновляем оси
    axisX->setLine(-width / 2, 0, width / 2, 0);
    axisY->setLine(0, -height / 2, 0, height / 2);

    // Обновляем деления и подписи
    int index = 0;
    for (int x = -width / 2; x <= width / 2; x += stepSize)
    {
        if (index >= axisTicksX.size()) break;
        axisTicksX[index]->setLine(x, -2, x, 2);
        axisLabelsX[index]->setPos(x - 10, 5);
        axisLabelsX[index]->setPlainText(QString::number(x));
        index++;
    }

    index = 0;
    for (int y = -height / 2; y <= height / 2; y += stepSize)
    {
        if (index >= axisTicksY.size()) break;
        axisTicksY[index]->setLine(-2, y, 2, y);
        axisLabelsY[index]->setPos(5, y - 10);
        axisLabelsY[index]->setPlainText(QString::number(y));
        index++;
    }
}



