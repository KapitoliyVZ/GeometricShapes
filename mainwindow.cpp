#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "CoordinateSystem.h"
#include "Rectangle.h"
#include "RectangleDialog.h"
#include "Circle.h"
#include "CircleDialog.h"
#include <Triangle.h>
#include <TriangleDialog.h>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupScene();

    // Включаем режим выбора фигур на сцене
    coordinate_scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    coordinate_scene->setSelectionArea(QPainterPath());

    // Подключаем сигнал клика по элементу списка
    //connect(ui->listWidgetShapes, &QListWidget::itemClicked, this, &MainWindow::on_listWidgetShapes_itemClicked);
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
        QString name = dialog.getRectangleName();

        if (coords.size() == 4) {
            RectangleShape *rectangle = new RectangleShape(coords, name);
            coordinate_scene->addItem(rectangle);
            list_of_Shapes.append(rectangle); // Сохраняем в список
            updateShapeList(); // Обновляем виджет с именами
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
        QString name = dialog.getCircleName();

        CircleShape *circle = new CircleShape(center, radius, name);
        coordinate_scene->addItem(circle);
        list_of_Shapes.append(circle); // Сохраняем в список
        updateShapeList(); // Обновляем виджет с именами
    }
}
// кнопка добавления треугольника
void MainWindow::on_btnTriangle_clicked()
{
    TriangleDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QList<QPointF> coords = dialog.getCoordinates();
        QString name = dialog.getTriangleName();

        if (coords.size() == 3) {
            TriangleShape *triangle = new TriangleShape(coords, name);
            coordinate_scene->addItem(triangle);
            list_of_Shapes.append(triangle); // Сохраняем в список
            updateShapeList(); // Обновляем виджет с именами
        }
    }
}

// Кнопка очистки графика
void MainWindow::on_btnClearScene_clicked()
{
    // for (QGraphicsItem *item : list_of_Shapes) {
    //     coordinate_scene->removeItem(item);
    //     delete item; // Освобождаем память
    // }
    // updateShapeList(); // Обновляем виджет с именами
    // coordinate_scene->clear(); // Удаляем все элементы из сцены
    // GraphSettings::updateSceneSize(coordinate_scene, ui->graphicsView);
}

// обновление списка фигур
void MainWindow::updateShapeList()
{
    // Очищаем виджет перед обновлением
    ui->listWidgetShapes->clear();

    // Проходим по всем фигурам в списке
    for (auto* item : list_of_Shapes)
    {
        // Приводим QGraphicsItem к классу Shape
        auto* shape = dynamic_cast<Shape*>(item);
        if (shape)
        {
            // Добавляем имя в QListWidget
            ui->listWidgetShapes->addItem(shape->getName());
        }
    }
}

// выделение фигуры
void MainWindow::on_listWidgetShapes_itemClicked(QListWidgetItem *item)
{
    if (!item) return;  // Защита от null

    // Получаем имя фигуры из QListWidget
    QString shapeName = item->text();
    qDebug() << "Выбрана фигура: " << shapeName;

    // Проходим по списку всех фигур
    for (auto* item : list_of_Shapes)
    {
        // Приводим QGraphicsItem к классу Shape
        auto* shape = dynamic_cast<Shape*>(item);
        // Ищем фигуру в списке
        if (shape && shape->getName() == shapeName)
        {
            qDebug() << "Фигура найдена в списке! Выделяем...";
            // Выделяем фигуру
            shape->setSelected(true); // Ставим флаг выделения
        }
        else
        {
            // Снимаем выделение с остальных фигур
            shape->setSelected(false);
        }
        shape->update(); // Перерисовываем фигуру
    }

    // Обновляем сцену
    if (coordinate_scene)
    {
        coordinate_scene->update();
    }
    else
    {
        qDebug() << "⚠ Ошибка: coordinate_scene == nullptr!";
    }
}

