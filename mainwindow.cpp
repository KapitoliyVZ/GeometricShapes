#include <QVBoxLayout>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsLineItem>

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
    // Создаём сцену и привязываем к QGraphicsView
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // Устанавливаем границы области рисования
    int width = 400, height = 400;
    scene->setSceneRect(-width/2, -height/2, width, height);

    // Рисуем координатные оси
    QPen axisPen(Qt::black);
    axisPen.setWidth(2);

    scene->addLine(-width/2, 0, width/2, 0, axisPen); // Ось X
    scene->addLine(0, -height/2, 0, height/2, axisPen); // Ось Y

    // Рисуем деления и подписываем координаты
    int step = 50; // Шаг координатной сетки

    QFont font("Arial", 8);
    for (int x = -width/2; x <= width/2; x += step) {
        if (x == 0) continue; // Пропускаем центр
        scene->addLine(x, -5, x, 5, axisPen); // Засечки на оси X

        QGraphicsTextItem *text = scene->addText(QString::number(x), font);
        text->setPos(x - 10, 5); // Смещаем текст для выравнивания
    }

    for (int y = -height/2; y <= height/2; y += step) {
        if (y == 0) continue; // Пропускаем центр
        scene->addLine(-5, y, 5, y, axisPen); // Засечки на оси Y

        QGraphicsTextItem *text = scene->addText(QString::number(y), font);
        text->setPos(5, y - 10); // Смещаем текст для выравнивания
    }
}



void MainWindow::on_btnRectangle_clicked()
{
    // RectangleShape *rect = new RectangleShape(50, 30);
    // scene->addItem(rect);
    // rect->setPosition(0, 0); // Устанавливаем в центр координат

    RectangleDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QList<QPointF> coords = dialog.getCoordinates();

        if (coords.size() == 4) {
            RectangleShape *rect = new RectangleShape(coords);
            scene->addItem(rect);
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
    }
}

