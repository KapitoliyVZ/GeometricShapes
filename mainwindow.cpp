#include <QVBoxLayout>
#include <QWheelEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsLineItem>

#include "graphsettings.h"
#include "rectangle.h"
#include "rectangledialog.h"
#include "circle.h"
#include "circledialog.h"


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
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

   // GraphSettings::setupScene(scene); // Вызываем настройку графика

    GraphSettings::updateSceneSize(scene, ui->graphicsView);
}

// при изменении размеров окна пользователем
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    GraphSettings::updateSceneSize(scene, ui->graphicsView);
}

// при прокрутке колеса мыши
void MainWindow::wheelEvent(QWheelEvent *event)
{
    // const double scaleFactor = 1.05; // Коэффициент увеличения

    // if (event->angleDelta().y() > 0) {
    //     ui->graphicsView->scale(scaleFactor, scaleFactor); // Увеличиваем
    // } else {
    //     ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor); // Уменьшаем
    // }
}

void MainWindow::on_btnRectangle_clicked()
{
    RectangleDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QList<QPointF> coords = dialog.getCoordinates();

        if (coords.size() == 4) {
            RectangleShape *rect = new RectangleShape(coords);
            scene->addItem(rect);
            shapes.append(rect); // Сохраняем в список
        }
    }
}


void MainWindow::on_btnCircle_clicked()
{
    CircleDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QPointF center = dialog.getCenter();
        double radius = dialog.getRadius();

        CircleShape *circle = new CircleShape(center, radius);
        scene->addItem(circle);
        shapes.append(circle); // Сохраняем в список
    }
}

// Кнопка очистки графика
void MainWindow::on_btnClearScene_clicked()
{
    for (QGraphicsItem *item : shapes) {
        scene->removeItem(item);
        delete item; // Освобождаем память
    }

    scene->clear(); // Удаляем все элементы из сцены
    GraphSettings::updateSceneSize(scene, ui->graphicsView);
}

