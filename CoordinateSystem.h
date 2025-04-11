#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QVector>

/*
 * Класс CoordinateSystem отвечает за отображение координатной сетки на заданной сцене.
 * Он включает в себя прорисовку осей, делений и текстовых меток.
 * Масштаб отображения настраивается через stepSize (логический шаг) и unitPerPixel (масштаб логических единиц на пиксель).
 */
class CoordinateSystem
{
public:
    explicit CoordinateSystem(QGraphicsScene *scene, int stepSize = 50, double unitPerPixel = 1.0);

    /*
     * Обновляет размеры сцены и перерисовывает координатную систему
     * @param width   ширина вьюпорта
     * @param height  высота вьюпорта
     */
    void updateSceneSize(int width, int height);

    /*
     * Устанавливает масштаб в логических единицах на пиксель
     */
    void setUnitPerPixel(double value);

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

    QGraphicsTextItem* axisLabelX = nullptr; // Подпись X
    QGraphicsTextItem* axisLabelY = nullptr; // Подпись Y


    /*
     * Гарантирует, что количество засечек и подписей соответствует требуемому количеству.
     * Лишние скрываются, недостающие — добавляются.
     */
    void ensureTickLabelCount(QVector<QGraphicsLineItem *> &ticks,
                              QVector<QGraphicsTextItem *> &labels,
                              int count);
};

#endif // COORDINATESYSTEM_H
