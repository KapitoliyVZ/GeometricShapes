#include "CoordinateSystem.h"

// функция настройки отображения графика scene в QGraphicView
void GraphSettings::setupScene(QGraphicsScene *scene, int width, int height)
{
    if (!scene) return;

    scene->clear(); // Очищаем сцену перед настройкой
    //width = 800, height = 800; // Увеличиваем вдвое
    scene->setSceneRect(-width/2, -height/2, width, height);

    // Рисуем координатные оси
    QPen axisPen(Qt::black);
    axisPen.setWidth(2);

    scene->addLine(-width/2, 0, width/2, 0, axisPen); // Ось X
    scene->addLine(0, -height/2, 0, height/2, axisPen); // Ось Y

    // Рисуем деления и подписываем координаты
    int step = 50;
    QFont font("Arial", 6);

    for (int x = -width/2; x <= width/2; x += step)
    {
        if (x == 0) continue;
        scene->addLine(x, -2, x, 2, axisPen); // размеры засечек на оси x

        QGraphicsTextItem *text = scene->addText(QString::number(x), font); // значения делений
        text->setPos(x - 10, 5);
    }

    for (int y = -height/2; y <= height/2; y += step)
    {
        if (y == 0) continue;
        scene->addLine(-2, y, 2, y, axisPen); // размеры засечек на оси y

        QGraphicsTextItem *text = scene->addText(QString::number(y), font); // значения делений
        text->setPos(5, y - 10);
    }
}

void GraphSettings::updateSceneSize(QGraphicsScene *scene, QGraphicsView *view)
{
    if (!scene || !view) return;

    QRectF viewRect = view->rect();
    int width = viewRect.width();
    int height = viewRect.height();

    scene->setSceneRect(-width / 2, -height / 2, width, height);
    setupScene(scene, width, height);
}
