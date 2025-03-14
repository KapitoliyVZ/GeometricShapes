#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "CoordinateSystem.h"
#include "Rectangle.h"
#include "RectangleDialog.h"
#include "Circle.h"
#include "CircleDialog.h"
#include <Triangle.h>
#include <TriangleDialog.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupScene();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// прорисовка сцены (координатной оси)
void MainWindow::setupScene()
{
    coordinate_scene = new QGraphicsScene(this);
    coordinate_scene->setBackgroundBrush(Qt::lightGray); // Устанавливаем белый фон
    ui->graphicsView->setScene(coordinate_scene);

    // GraphSettings::setupScene(scene); // Вызываем настройку графика

    GraphSettings::updateSceneSize(coordinate_scene, ui->graphicsView);
}

// прорисовка сцены (координатной оси) при изменении размеров окна пользователем
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    GraphSettings::updateSceneSize(coordinate_scene, ui->graphicsView);
}

// при прокрутке колеса мыши
void MainWindow::wheelEvent(QWheelEvent *event)
{
    const double scaleFactor = 1.05; // Коэффициент увеличения

    if (event->angleDelta().y() > 0) {
        ui->graphicsView->scale(scaleFactor, scaleFactor); // Увеличиваем
    } else {
        ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor); // Уменьшаем
    }
}

// кнопка добавления прямоугольника
void MainWindow::on_btnRectangle_clicked()
{
    RectangleDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QList<QPointF> coords = dialog.getCoordinates();

        if (coords.size() == 4) {
            RectangleShape *rect = new RectangleShape(coords);
            coordinate_scene->addItem(rect);
            list_of_Shapes.append(rect); // Сохраняем в список
        }
    }
}

// кнопка добавления круга
void MainWindow::on_btnCircle_clicked()
{
    CircleDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QPointF center = dialog.getCenter();
        double radius = dialog.getRadius();

        CircleShape *circle = new CircleShape(center, radius);
        coordinate_scene->addItem(circle);
        list_of_Shapes.append(circle); // Сохраняем в список
    }
}

// Кнопка очистки графика
void MainWindow::on_btnClearScene_clicked()
{
    for (QGraphicsItem *item : list_of_Shapes) {
        coordinate_scene->removeItem(item);
        delete item; // Освобождаем память
    }

    coordinate_scene->clear(); // Удаляем все элементы из сцены
    GraphSettings::updateSceneSize(coordinate_scene, ui->graphicsView);
}


void MainWindow::on_btnTriangle_clicked()
{
    TriangleDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QList<QPointF> coords = dialog.getCoordinates();

        if (coords.size() == 3) {
            TriangleShape *rect = new TriangleShape(coords);
            coordinate_scene->addItem(rect);
            list_of_Shapes.append(rect); // Сохраняем в список
        }
    }
}

