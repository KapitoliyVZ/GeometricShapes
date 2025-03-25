#include <mainwindow.h>
#include "ui_mainwindow.h"

void MainWindow::setWidgetPropertiesShape(Shape* selectedShape)
{
    // если выбранная фигура - круг
    if (auto* circle = dynamic_cast<CircleShape*>(selectedShape))
    {
        qDebug() << "Выбран круг.";

        ui->tabWidgetProperties->setCurrentWidget(ui->tab_circle);  // открываем окно для круга
        ui->tab_circle->setEnabled(true);                           // включаем настройки для круга
        ui->tab_rectangle->setEnabled(false);                       // выключаем настройки прямоугольника
        ui->tab_triagnle->setEnabled(false);                        // выключаем настройки треугольника

        ui->spinBox_circle_radius->setValue(circle->getRadius());      // отображаем значение радиуса круга
        ui->spinBox_circle_XCenter->setValue(circle->getCenter().x()); // отображаем значение центра-X круга
        ui->spinBox_circle_YCenter->setValue(circle->getCenter().y()); // отображаем значение центра-Y круга

        // отключаем кнопку Apply до изменений параметров круга
        ui->pushButton_circle_Apply->setEnabled(false);
        // включаем кнопку Apply при изменении параметров круга
        connect(ui->spinBox_circle_XCenter, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableCircleApplyButton);
        connect(ui->spinBox_circle_YCenter, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableCircleApplyButton);
        connect(ui->spinBox_circle_radius, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableCircleApplyButton);
        // включаем кнопку Delete для круга
        ui->pushButton_circle_Delete->setEnabled(true);

    }
    // если выбранная фигура - треугольник
    else if (auto* triangle = dynamic_cast<TriangleShape*>(selectedShape))
    {
        qDebug() << "Выбран треугольник.";

        ui->tabWidgetProperties->setCurrentWidget(ui->tab_triagnle); // открываем окно для треугольника
        ui->tab_triagnle->setEnabled(true);                          // выключаем настройки треугольника
        ui->tab_circle->setEnabled(false);                           // выключаем настройки круга
        ui->tab_rectangle->setEnabled(false);                        // выключаем настройки прямоугольника

        QVector<QPointF> points = triangle->getPoints();  // Получаем координаты из данного треугольника

        // отображаем значение координат на кнопках
        ui->spinBox_triangle_x1->setValue(points[0].x());
        ui->spinBox_triangle_y1->setValue(points[0].y());
        ui->spinBox_triangle_x2->setValue(points[1].x());
        ui->spinBox_triangle_y2->setValue(points[1].y());
        ui->spinBox_triangle_x3->setValue(points[2].x());
        ui->spinBox_triangle_y3->setValue(points[2].y());
        //отображаем значение текущего угла вращения
        ui->spinBox_triangle_rotation->setValue(triangle->rotation());

        // отключаем кнопку Apply до изменений параметров треугольника
        ui->pushButton_triangle_Apply->setEnabled(false);
        // включаем кнопку Apply при изменении параметров треугольника
        connect(ui->spinBox_triangle_x1, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableTriangleApplyButton);
        connect(ui->spinBox_triangle_y1, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableTriangleApplyButton);
        connect(ui->spinBox_triangle_x2, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableTriangleApplyButton);
        connect(ui->spinBox_triangle_y2, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableTriangleApplyButton);
        connect(ui->spinBox_triangle_x3, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableTriangleApplyButton);
        connect(ui->spinBox_triangle_y3, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableTriangleApplyButton);
        connect(ui->spinBox_triangle_rotation, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableTriangleApplyButton);
        // включаем кнопку Delete для круга
        ui->pushButton_triangle_Delete->setEnabled(true);

    }
    // если выбранная фигура - прямоугольник
    else if(auto* rectangle = dynamic_cast<RectangleShape*>(selectedShape))
    {
        ui->tab_circle->setEnabled(false);      // выключаем настройки круга
        ui->tab_triagnle->setEnabled(false);    // выключаем настройки треугольника
    }
}

// включить кнопку Apply для круга
void MainWindow::enableCircleApplyButton()
{
    ui->pushButton_circle_Apply->setEnabled(true);
}

// применение изменений параметров круга
void MainWindow::on_pushButton_circle_Apply_clicked()
{
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

// Кнопка удаления круга
void MainWindow::on_pushButton_circle_Delete_clicked()
{
    if (!selectedShape) return;  // Если фигура не выбрана, выходим

    // Проверяем, является ли выбранная фигура кругом
    auto* circle = dynamic_cast<CircleShape*>(selectedShape);
    if (!circle) return;  // Если фигура не круг, ничего не делаем

    list_of_Shapes.removeOne(circle);       // Удаляем фигуру из списка фигур
    coordinate_scene->removeItem(circle);   // Удаляем фигуру из сцены графика

    delete circle;              // Освобождаем память
    selectedShape = nullptr;    // Сбрасываем выбранную фигуру

    // Удаляем соответствующий `QListWidgetItem` из `QListWidget`
    for (int i = 0; i < ui->listWidgetShapes->count(); ++i)
    {
        QListWidgetItem* item = ui->listWidgetShapes->item(i);
        if (item->text() == circle->getName())
        {
            delete ui->listWidgetShapes->takeItem(i);  // Удаляем из списка
            break;
        }
    }

    ui->listWidgetShapes->clearSelection();      // Очищаем выделение в `QListWidget`
    ui->tabWidgetProperties->setEnabled(false); // Выключаем `tabWidgetProperties`

    ui->listWidgetShapes->update();
    coordinate_scene->update();
}

// включить кнопку Apply для треугольника
void MainWindow::enableTriangleApplyButton()
{
    ui->pushButton_triangle_Apply->setEnabled(true);
}

// применение изменений параметров треугольника
void MainWindow::on_pushButton_triangle_Apply_clicked()
{
    // MainWindow::selectedShape;

    if (!selectedShape) return;

    auto* triangle = dynamic_cast<TriangleShape*>(selectedShape);
    if (triangle)
    {
        // Сохраняем новые координаты для треугольника
        QVector<QPointF> newPoints =
            {
                QPointF(ui->spinBox_triangle_x1->value(), ui->spinBox_triangle_y1->value()),
                QPointF(ui->spinBox_triangle_x2->value(), ui->spinBox_triangle_y2->value()),
                QPointF(ui->spinBox_triangle_x3->value(), ui->spinBox_triangle_y3->value())
            };
        // Сохраняем новый угол вращения
        int newAngle = ui->spinBox_triangle_rotation->value();

        triangle->setNewPoints(newPoints);      // Применяем новые координаты для треугольника
        triangle->setRotationAngle(newAngle);   // Применяем новый угол вращения

        coordinate_scene->update(); // Перерисовываем сцену
    }

}

// Кнопка удаления треугольника
void MainWindow::on_pushButton_triangle_Delete_clicked()
{
    if (!selectedShape) return;  // Если фигура не выбрана, выходим

    // Проверяем, является ли выбранная фигура кругом
    auto* triangle = dynamic_cast<TriangleShape*>(selectedShape);
    if (!triangle) return;  // Если фигура не круг, ничего не делаем

    list_of_Shapes.removeOne(triangle);       // Удаляем фигуру из списка фигур
    coordinate_scene->removeItem(triangle);   // Удаляем фигуру из сцены графика

    delete triangle;              // Освобождаем память
    selectedShape = nullptr;    // Сбрасываем выбранную фигуру

    // Удаляем соответствующий `QListWidgetItem` из `QListWidget`
    for (int i = 0; i < ui->listWidgetShapes->count(); ++i)
    {
        QListWidgetItem* item = ui->listWidgetShapes->item(i);
        if (item->text() == triangle->getName())
        {
            delete ui->listWidgetShapes->takeItem(i);  // Удаляем из списка
            break;
        }
    }

    ui->listWidgetShapes->clearSelection();      // Очищаем выделение в `QListWidget`
    ui->tabWidgetProperties->setEnabled(false); // Выключаем `tabWidgetProperties`

    ui->listWidgetShapes->update();
    coordinate_scene->update();
}
