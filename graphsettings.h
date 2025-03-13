#ifndef GRAPHSETTINGS_H
#define GRAPHSETTINGS_H

#include <QGraphicsView>
#include <QGraphicsScene>
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

#endif // GRAPHSETTINGS_H
