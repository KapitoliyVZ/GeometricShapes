#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QPen>
#include <QFont>
#include <QVector>

class GraphSettings
{
public:
    explicit GraphSettings(QGraphicsScene *scene, int stepSize = 50); // Конструктор

    void updateSceneSize(int width, int height); // Функция обновления размеров сцены

private:
    QGraphicsScene *scene;  // Указатель на сцену
    int stepSize;           // Размер шага делений

    QGraphicsLineItem *axisX; // Линия оси X
    QGraphicsLineItem *axisY; // Линия оси Y

    QVector<QGraphicsLineItem*> axisTicksX; // Засечки на оси X
    QVector<QGraphicsLineItem*> axisTicksY; // Засечки на оси Y

    QVector<QGraphicsTextItem*> axisLabelsX; // Подписи на оси X
    QVector<QGraphicsTextItem*> axisLabelsY; // Подписи на оси Y
};

#endif // COORDINATESYSTEM_H

