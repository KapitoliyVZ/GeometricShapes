#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include <QGraphicsView>    // виджет для отображения <QGraphicsScene>
#include <QGraphicsScene>   // библиотека для графической сцены с графическими объектами <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QFont>

class GraphSettings
{
public:
    // функция настройки отображения графика scene в QGraphicView
    static void setupScene(QGraphicsScene *scene, int width, int height);

    // функция настройки размеров графика scene в QGraphicView
    static void updateSceneSize(QGraphicsScene *scene, QGraphicsView *view);
};

#endif // COORDINATESYSTEM_H
