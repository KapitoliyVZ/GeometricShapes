#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QVector>

class CoordinateSystem // Класс отвечает за отображение координатной сетки на заданной сцене.
{
public:
    explicit CoordinateSystem(QGraphicsScene *scene, int stepSize = 50, double unitPerPixel = 1.0);

    void updateSceneSize(int width, int height); // Обновляет размеры сцены и перерисовывает координатную систему
    void setUnitPerPixel(double value);          // Устанавливает масштаб в логических единицах на пиксель

private:
    QGraphicsScene *const scene; // Указатель на сцену (не изменяется после инициализации)
    int stepSize;                // Логический шаг между делениями
    double unitPerPixel;         // Масштаб (логических единиц на пиксель)

    QGraphicsLineItem *axisX = nullptr; // Главная ось X
    QGraphicsLineItem *axisY = nullptr; // Главная ось Y

    QVector<QGraphicsLineItem *> axisTicksX; // Деления по оси X
    QVector<QGraphicsLineItem *> axisTicksY; // Деления по оси Y

    QVector<QGraphicsTextItem *> axisLabelsX; // Подписи по оси X
    QVector<QGraphicsTextItem *> axisLabelsY; // Подписи по оси Y

    QGraphicsTextItem *axisLabelX = nullptr; // Подпись названия оси X
    QGraphicsTextItem *axisLabelY = nullptr; // Подпись названия оси Y

    /*
     * Гарантирует, что количество засечек и подписей соответствует требуемому количеству.
     * Лишние скрываются, недостающие — добавляются.
     */
    void ensureTickLabelCount(QVector<QGraphicsLineItem *> &ticks,
                              QVector<QGraphicsTextItem *> &labels,
                              int count);

};

#endif // COORDINATESYSTEM_H
