#include "CoordinateSystem.h"
#include <QPen>
#include <QFont>

// Конструктор
CoordinateSystem::CoordinateSystem(QGraphicsScene *scene, int stepSize, double unitPerPixel)
    : scene(scene),              // указатель на графическую сцену, на которой будет рисоваться координатная система
      stepSize(stepSize),        // логический шаг между делениями (в условных единицах)
      unitPerPixel(unitPerPixel) // масштаб: сколько логических единиц приходится на один пиксель
{
    if (!scene)
        return;

    // Создание осей координат (X и Y)
    axisX = scene->addLine(0, 0, 0, 0, QPen(Qt::white, 2));
    axisY = scene->addLine(0, 0, 0, 0, QPen(Qt::white, 2));
}

// Установка масштаба (логических единиц на пиксель)
void CoordinateSystem::setUnitPerPixel(double value)
{
    unitPerPixel = value;
}

// Обновление размеров сцены и координатной сетки при изменении размера окна или масштаба
void CoordinateSystem::updateSceneSize(int width, int height)
{
    if (!scene)
        return;

    // Центрируем сцену относительно (0,0)
    scene->setSceneRect(-width / 2, -height / 2, width, height);

    // Прорисовка главных осей
    axisX->setLine(-width / 2, 0, width / 2, 0);
    axisY->setLine(0, -height / 2, 0, height / 2);

    // Расчёт расстояния в пикселях между делениями
    int pixelStep = static_cast<int>(stepSize / unitPerPixel);
    if (pixelStep <= 0)
        return;

    int countX = (width / 2) / pixelStep;
    int countY = (height / 2) / pixelStep;

    // Деления и подписи по оси X
    ensureTickLabelCount(axisTicksX, axisLabelsX, 2 * countX + 1);
    int index = 0;
    for (int i = -countX; i <= countX; ++i, ++index)
    {
        int x = i * pixelStep;
        int logicalValue = i * stepSize;

        // Засечка (tick)
        axisTicksX[index]->setLine(x, -4, x, 4);
        axisTicksX[index]->show();

        // Подписи чисел засечек
        axisLabelsX[index]->setPlainText(QString::number(logicalValue));
        axisLabelsX[index]->setPos(x - 10, -5);
        axisLabelsX[index]->setTransform(QTransform().scale(1, -1));  // Инвертируем подписи

        axisLabelsX[index]->show();
    }

    // Деления и подписи по оси Y
    ensureTickLabelCount(axisTicksY, axisLabelsY, 2 * countY + 1);
    index = 0;
    for (int i = -countY; i <= countY; ++i, ++index)
    {
        int y = i * pixelStep;
        int logicalValue = i * stepSize;

        // Засечка (tick)
        axisTicksY[index]->setLine(-4, y, 4, y);
        axisTicksY[index]->show();

        // Убираем подпись "0"
        if (logicalValue == 0)
        {
            axisLabelsY[index]->setPlainText("");
            axisLabelsY[index]->hide();
            continue;
        }

        // Подписи чисел засечек
        axisLabelsY[index]->setPlainText(QString::number(logicalValue));
        axisLabelsY[index]->setPos(-25, y + 9);
        axisLabelsY[index]->setTransform(QTransform().scale(1, -1));  // Инвертируем подписи

        axisLabelsY[index]->show();
    }

}

/*
 * Обеспечивает, что векторы засечек и подписей содержат достаточно элементов,
 * при необходимости добавляет недостающие и скрывает лишние.
 */
void CoordinateSystem::ensureTickLabelCount(QVector<QGraphicsLineItem *> &ticks,
                                            QVector<QGraphicsTextItem *> &labels, int count)
{
    // Добавляем недостающие засечки
    while (ticks.size() < count)
        ticks.append(scene->addLine(0, 0, 0, 0, QPen(Qt::black)));

    // Добавляем недостающие подписи
    while (labels.size() < count)
        labels.append(scene->addText("", QFont("Arial", 6)));

    // Скрываем лишние элементы, если они есть
    for (int i = count; i < ticks.size(); ++i)
        ticks[i]->hide();
    for (int i = count; i < labels.size(); ++i)
        labels[i]->hide();
}
