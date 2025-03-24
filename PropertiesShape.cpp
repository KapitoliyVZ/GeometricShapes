#include <mainwindow.h>
#include "ui_mainwindow.h"

void MainWindow::setWidgetPropertiesShape(Shape* selectedShape)
{
    // если выбранная фигура - круг
    if (auto* circle = dynamic_cast<CircleShape*>(selectedShape))
    {
        qDebug() << "Выбран круг.";

        ui->tabWidgetProperties->setCurrentWidget(ui->tab_circle); // открываем окно для круга
        ui->tab_rectangle->setEnabled(false);   // выключаем настройки прямоугольника
        ui->tab_triagnle->setEnabled(false);    // выключаем настройки треугольника

        ui->spinBox_circle_radius->setValue(circle->getRadius());      // показываем значение радиуса круга
        ui->spinBox_circle_XCenter->setValue(circle->getCenter().x()); // показываем значение центра-X круга
        ui->spinBox_circle_YCenter->setValue(circle->getCenter().y()); // показываем значение центра-Y круга
    }
    // если выбранная фигура - треугольник
    else if (auto* triangle = dynamic_cast<TriangleShape*>(selectedShape))
    {
        qDebug() << "Выбран треугольник.";

        ui->tabWidgetProperties->setCurrentWidget(ui->tab_triagnle); // открываем окно для треугольника
        ui->tab_circle->setEnabled(false);      // выключаем настройки круга
        ui->tab_rectangle->setEnabled(false);   // выключаем настройки прямоугольника

        QVector<QPointF> points = triangle->getPoints();  // Получаем координаты

        ui->spinBox_triangle_x1->setValue(points[0].x());
        ui->spinBox_triangle_y1->setValue(points[0].y());
        ui->spinBox_triangle_x2->setValue(points[1].x());
        ui->spinBox_triangle_y2->setValue(points[1].y());
        ui->spinBox_triangle_x3->setValue(points[2].x());
        ui->spinBox_triangle_y3->setValue(points[2].y());

    }
    // если выбранная фигура - прямоугольник
    else if(auto* rectangle = dynamic_cast<RectangleShape*>(selectedShape))
    {
        ui->tab_circle->setEnabled(false);      // выключаем настройки круга
        ui->tab_triagnle->setEnabled(false);    // выключаем настройки треугольника
    }

}

void MainWindow::onRadiusChanged(int newRadius)
{
    // qDebug() << "Новое значение spinBox_radius: " << newRadius;
}

// применение изменений параметров круга
void MainWindow::onApplyCircleChangesClicked()
{
    MainWindow::selectedShape;

    if (!selectedShape) return;

    auto* circle = dynamic_cast<CircleShape*>(selectedShape);
    if (circle)
    {
        // Получаем новые значения из `QSpinBox`
        int newRadius = ui->spinBox_circle_radius->value();
        double newX = ui->spinBox_circle_XCenter->value();
        double newY = ui->spinBox_circle_YCenter->value();

        // Проверяем, изменились ли параметры
        bool isRadiusChanged = (newRadius != circle->getRadius());
        bool isPositionChanged = (newX != circle->getCenter().x() || newY != circle->getCenter().y());

        // Если ничего не изменилось, выходим
        if (!isRadiusChanged && !isPositionChanged)
        {
            qDebug() << "Никакие параметры не изменились.";
            return;
        }
        // Применяем новые параметры
        if (isRadiusChanged)
        {
            circle->setNewRadius(newRadius);
            qDebug() << "новый радиус принят: " << newRadius;
        }

        if (isPositionChanged)
        {
            circle->setNewCenter(QPointF(newX, newY));
            qDebug() << "новый центр принят: (" << newX << "," << newY << ")";
        }

        coordinate_scene->update(); // Обновляем сцену
    }
}

// применение изменений параметров треугольника
void MainWindow::onApplyTriangleChangesClicked()
{
    MainWindow::selectedShape;

    if (!selectedShape) return;


    auto* triangle = dynamic_cast<TriangleShape*>(selectedShape);
    if (triangle)
    {
        QVector<QPointF> newPoints =
        {
            QPointF(ui->spinBox_triangle_x1->value(), ui->spinBox_triangle_y1->value()),
            QPointF(ui->spinBox_triangle_x2->value(), ui->spinBox_triangle_y2->value()),
            QPointF(ui->spinBox_triangle_x3->value(), ui->spinBox_triangle_y3->value())
        };

        triangle->setNewPoints(newPoints);
        coordinate_scene->update();  // Перерисовываем сцену
    }

}
