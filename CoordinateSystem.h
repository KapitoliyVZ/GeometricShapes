#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QVector>

class CoordinateSystem
{
public:
    explicit CoordinateSystem(QGraphicsScene *scene, int stepSize = 50, double unitPerPixel = 1.0);

    void updateSceneSize(int width, int height);
    void setUnitPerPixel(double value);

private:
    QGraphicsScene *scene;
    int stepSize;
    double unitPerPixel;

    QGraphicsLineItem *axisX;
    QGraphicsLineItem *axisY;

    QVector<QGraphicsLineItem*> axisTicksX;
    QVector<QGraphicsLineItem*> axisTicksY;
    QVector<QGraphicsTextItem*> axisLabelsX;
    QVector<QGraphicsTextItem*> axisLabelsY;

    void ensureTickLabelCount(QVector<QGraphicsLineItem*>& ticks,
                              QVector<QGraphicsTextItem*>& labels, int count);
};


#endif // COORDINATESYSTEM_H

