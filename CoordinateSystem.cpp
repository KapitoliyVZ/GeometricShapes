#include "CoordinateSystem.h"
#include <QPen>
#include <QFont>

CoordinateSystem::CoordinateSystem(QGraphicsScene *scene, int stepSize, double unitPerPixel)
    : scene(scene), stepSize(stepSize), unitPerPixel(unitPerPixel)
{
    if (!scene) return;

    axisX = scene->addLine(0, 0, 0, 0, QPen(Qt::white, 2));
    axisY = scene->addLine(0, 0, 0, 0, QPen(Qt::white, 2));
}

void CoordinateSystem::setUnitPerPixel(double value)
{
    unitPerPixel = value;
}

void CoordinateSystem::updateSceneSize(int width, int height)
{
    if (!scene) return;

    scene->setSceneRect(-width / 2, -height / 2, width, height);

    axisX->setLine(-width / 2, 0, width / 2, 0);
    axisY->setLine(0, -height / 2, 0, height / 2);

    int pixelStep = static_cast<int>(stepSize / unitPerPixel);
    if (pixelStep <= 0) return;

    int countX = (width / 2) / pixelStep;
    int countY = (height / 2) / pixelStep;

    ensureTickLabelCount(axisTicksX, axisLabelsX, 2 * countX + 1);
    int index = 0;
    for (int i = -countX; i <= countX; ++i, ++index)
    {
        int x = i * pixelStep;
        int logicalValue = i * stepSize;

        axisTicksX[index]->setLine(x, -4, x, 4);
        axisTicksX[index]->show();

        axisLabelsX[index]->setPlainText(QString::number(logicalValue));
        axisLabelsX[index]->setPos(x - 10, 6);
        axisLabelsX[index]->show();
    }

    ensureTickLabelCount(axisTicksY, axisLabelsY, 2 * countY + 1);
    index = 0;
    for (int i = -countY; i <= countY; ++i, ++index)
    {
        int y = i * pixelStep;
        int logicalValue = -i * stepSize;

        axisTicksY[index]->setLine(-4, y, 4, y);
        axisTicksY[index]->show();

        axisLabelsY[index]->setPlainText(QString::number(logicalValue));
        axisLabelsY[index]->setPos(6, y - 8);
        axisLabelsY[index]->show();
    }

}

void CoordinateSystem::ensureTickLabelCount(QVector<QGraphicsLineItem*>& ticks,
                                            QVector<QGraphicsTextItem*>& labels, int count)
{
    while (ticks.size() < count)
        ticks.append(scene->addLine(0, 0, 0, 0, QPen(Qt::black)));

    while (labels.size() < count)
        labels.append(scene->addText("", QFont("Arial", 6)));

    for (int i = count; i < ticks.size(); ++i) ticks[i]->hide();
    for (int i = count; i < labels.size(); ++i) labels[i]->hide();
}
