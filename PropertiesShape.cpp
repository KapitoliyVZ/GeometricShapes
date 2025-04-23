#include <mainwindow.h>
#include "ui_mainwindow.h"

// настройка виджета параметров выбранной фигуры
void MainWindow::setWidgetPropertiesShape(Shape *selectedShape)
{
    // если выбранная фигура - круг
    if (auto *circle = dynamic_cast<CircleShape *>(selectedShape))
    {
        qDebug() << "Выбран круг.";

        ui->tabWidgetProperties->setCurrentWidget(ui->tab_circle); // открываем окно для круга
        ui->tab_circle->setEnabled(true);                          // включаем настройки для круга
        ui->tab_rectangle->setEnabled(false);                      // выключаем настройки прямоугольника
        ui->tab_triagnle->setEnabled(false);                       // выключаем настройки треугольника

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
    else if (auto *triangle = dynamic_cast<TriangleShape *>(selectedShape))
    {
        qDebug() << "Выбран треугольник.";

        ui->tabWidgetProperties->setCurrentWidget(ui->tab_triagnle); // открываем окно для треугольника
        ui->tab_triagnle->setEnabled(true);                          // включаем настройки треугольника
        ui->tab_circle->setEnabled(false);                           // выключаем настройки круга
        ui->tab_rectangle->setEnabled(false);                        // выключаем настройки прямоугольника

        QVector<QPointF> points = triangle->getPoints(); // Получаем координаты из данного треугольника

        // отображаем значение координат на кнопках
        ui->spinBox_triangle_x1->setValue(points[0].x());
        ui->spinBox_triangle_y1->setValue(points[0].y());
        ui->spinBox_triangle_x2->setValue(points[1].x());
        ui->spinBox_triangle_y2->setValue(points[1].y());
        ui->spinBox_triangle_x3->setValue(points[2].x());
        ui->spinBox_triangle_y3->setValue(points[2].y());
        // отображаем значение текущего угла вращения
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
    else if (auto *rectangle = dynamic_cast<RectangleShape *>(selectedShape))
    {
        qDebug() << "Выбран прямоугольник.";

        ui->tabWidgetProperties->setCurrentWidget(ui->tab_rectangle); // открываем окно для прямоугольника
        ui->tab_rectangle->setEnabled(true);                          // включаем настройки прямоугольника
        ui->tab_circle->setEnabled(false);                            // выключаем настройки круга
        ui->tab_triagnle->setEnabled(false);                          // выключаем настройки треугольника

        QVector<QPointF> points = rectangle->getPoints(); // Получаем координаты из данного прямоугольника

        // отображаем значение координат на кнопках
        ui->spinBox_rectangle_x1->setValue(points[0].x());
        ui->spinBox_rectangle_y1->setValue(points[0].y());
        ui->spinBox_rectangle_x2->setValue(points[1].x());
        ui->spinBox_rectangle_y2->setValue(points[1].y());
        ui->spinBox_rectangle_x3->setValue(points[2].x());
        ui->spinBox_rectangle_y3->setValue(points[2].y());
        ui->spinBox_rectangle_x4->setValue(points[3].x());
        ui->spinBox_rectangle_y4->setValue(points[3].y());

        // отображаем значение текущего угла вращения
        ui->spinBox_rectangle_rotation->setValue(rectangle->rotation());

        // отключаем две невводимые координаты
        ui->spinBox_rectangle_x2->setEnabled(false);
        ui->spinBox_rectangle_y2->setEnabled(false);
        ui->spinBox_rectangle_x4->setEnabled(false);
        ui->spinBox_rectangle_y4->setEnabled(false);

        // отключаем кнопку Apply до изменений параметров прямоугольника
        ui->pushButton_rectangle_Apply->setEnabled(false);
        // включаем кнопку Apply при любом изменении параметров прямоугольника
        connect(ui->spinBox_rectangle_x1, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableRectangleApplyButton);
        connect(ui->spinBox_rectangle_y1, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableRectangleApplyButton);
        connect(ui->spinBox_rectangle_x2, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableRectangleApplyButton);
        connect(ui->spinBox_rectangle_y2, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableRectangleApplyButton);
        connect(ui->spinBox_rectangle_x3, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableRectangleApplyButton);
        connect(ui->spinBox_rectangle_y3, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableRectangleApplyButton);
        connect(ui->spinBox_rectangle_x4, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableRectangleApplyButton);
        connect(ui->spinBox_rectangle_y4, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableRectangleApplyButton);
        connect(ui->spinBox_rectangle_rotation, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::enableRectangleApplyButton);
        // включаем кнопку Delete для прямоугольника
        ui->pushButton_rectangle_Delete->setEnabled(true);
        // динамическое изменение значений для координат 2 и 4
        connect(ui->spinBox_rectangle_x1, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateRectanglePoints);
        connect(ui->spinBox_rectangle_y1, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateRectanglePoints);
        connect(ui->spinBox_rectangle_x3, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateRectanglePoints);
        connect(ui->spinBox_rectangle_y3, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateRectanglePoints);
    }
}

//////////////////////////////////////////////////////////////////

// включить кнопку Применить для круга
void MainWindow::enableCircleApplyButton()
{
    ui->pushButton_circle_Apply->setEnabled(true);
}
// применение изменений параметров круга
void MainWindow::on_pushButton_circle_Apply_clicked()
{
    if (!selectedShape)
        return;

    auto *circle = dynamic_cast<CircleShape *>(selectedShape);
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
            return;
        // Применяем новые параметры
        if (isRadiusChanged)
            circle->setNewRadius(newRadius);

        if (isPositionChanged)
            circle->setNewCenter(QPointF(newX, newY));

        coordinate_scene->update(); // Обновляем сцену
    }
    ui->pushButton_circle_Apply->setEnabled(false); // отключаем кнопку после нажатия
}

// отмена изменений параметров круга
void MainWindow::on_pushButton_circle_Cancel_clicked()
{
    if (!selectedShape)
        return;

    auto *circle = dynamic_cast<CircleShape *>(selectedShape);
    if (circle)
    {
        // сохраняем прошлые значения
        int prevRadius = circle->getRadius();
        double prevX = circle->getCenter().x();
        double prevY = circle->getCenter().y();

        // Получаем новые значения из `QSpinBox`
        int newRadius = ui->spinBox_circle_radius->value();
        double newX = ui->spinBox_circle_XCenter->value();
        double newY = ui->spinBox_circle_YCenter->value();

        // Проверяем, изменились ли параметры
        bool isRadiusChanged = (newRadius != prevRadius);
        bool isPositionChanged = (newX != prevX || newY != prevY);

        // Если ничего не изменилось, выходим
        if (!isRadiusChanged && !isPositionChanged)
            return;

        // Если изменился радиус
        if (isRadiusChanged)

            ui->spinBox_circle_radius->setValue(prevRadius); // записываем старое значение
        
            // Если изменились координаты
        if (isPositionChanged)
        {
            // записываем старое значение
            ui->spinBox_circle_XCenter->setValue(prevX);
            ui->spinBox_circle_YCenter->setValue(prevY);
        }
        ui->pushButton_circle_Apply->setEnabled(false); // отключаем кнопку Применить после нажатия Отменить
    }
}

// Кнопка удаления круга
void MainWindow::on_pushButton_circle_Delete_clicked()
{
    if (!selectedShape)
        return; // Если фигура не выбрана, выходим

    // Проверяем, является ли выбранная фигура кругом
    auto *circle = dynamic_cast<CircleShape *>(selectedShape);
    if (!circle)
        return; // Если фигура не круг, ничего не делаем

    list_of_Shapes.removeOne(circle);     // Удаляем фигуру из списка фигур
    coordinate_scene->removeItem(circle); // Удаляем фигуру из сцены графика

    delete circle;           // Освобождаем память
    selectedShape = nullptr; // Сбрасываем выбранную фигуру

    // Удаляем соответствующий `QListWidgetItem` из `QListWidget`
    for (int i = 0; i < ui->listWidgetShapes->count(); ++i)
    {
        QListWidgetItem *item = ui->listWidgetShapes->item(i);
        if (item->text() == circle->getName())
        {
            delete ui->listWidgetShapes->takeItem(i); // Удаляем из списка
            break;
        }
    }

    ui->listWidgetShapes->clearSelection();     // Очищаем выделение в `QListWidget`
    ui->tabWidgetProperties->setEnabled(false); // Выключаем `tabWidgetProperties`

    ui->listWidgetShapes->update(); // обновляем список
    coordinate_scene->update();
}

//////////////////////////////////////////////////////////////////

// Включить кнопку Apply для треугольника
void MainWindow::enableTriangleApplyButton()
{
    ui->pushButton_triangle_Apply->setEnabled(true);
}

// Применение изменений параметров треугольника
void MainWindow::on_pushButton_triangle_Apply_clicked()
{
    if (!selectedShape)
        return;

    auto *triangle = dynamic_cast<TriangleShape *>(selectedShape);
    if (triangle)
    {
        // Сохраняем новые координаты для треугольника
        QVector<QPointF> newPoints =
            {
                QPointF(ui->spinBox_triangle_x1->value(), ui->spinBox_triangle_y1->value()),
                QPointF(ui->spinBox_triangle_x2->value(), ui->spinBox_triangle_y2->value()),
                QPointF(ui->spinBox_triangle_x3->value(), ui->spinBox_triangle_y3->value())};
        // Сохраняем новый угол вращения
        int newAngle = ui->spinBox_triangle_rotation->value();

        triangle->setNewPoints(newPoints);    // Применяем новые координаты для треугольника
        triangle->setRotationAngle(newAngle); // Применяем новый угол вращения

        coordinate_scene->update(); // Перерисовываем сцену
    }
    ui->pushButton_triangle_Apply->setEnabled(false); // отключаем кнопку после нажатия

}

// Отмена изменений параметров треугольника
void MainWindow::on_pushButton_triangle_Cancel_clicked()
{
    if (!selectedShape)
        return;

    auto *triangle = dynamic_cast<TriangleShape *>(selectedShape);
    if (triangle)
    {
        // Сохраняем предыдущие координаты для треугольника
        QVector<QPointF> prevPoints =
            {
                QPointF(triangle->getPoints()[0].x(), triangle->getPoints()[0].y()),
                QPointF(triangle->getPoints()[1].x(), triangle->getPoints()[1].y()),
                QPointF(triangle->getPoints()[2].x(), triangle->getPoints()[2].y())};
        // Сохраняем предыдущий угол вращения
        int prevAngle = triangle->getRotationAngle();

        // Сохраняем новые координаты для треугольника
        QVector<QPointF> newPoints =
            {
                QPointF(ui->spinBox_triangle_x1->value(), ui->spinBox_triangle_y1->value()), // x1, y1
                QPointF(ui->spinBox_triangle_x2->value(), ui->spinBox_triangle_y2->value()), // x2, y2
                QPointF(ui->spinBox_triangle_x3->value(), ui->spinBox_triangle_y3->value())  // x3, y3
            };

        // Сохраняем новый угол вращения
        int newAngle = ui->spinBox_triangle_rotation->value();

        if (prevPoints != newPoints)
        {
            // Если координаты изменились
            ui->spinBox_triangle_x1->setValue(prevPoints[0].x());
            ui->spinBox_triangle_y1->setValue(prevPoints[0].y());
            ui->spinBox_triangle_x2->setValue(prevPoints[1].x());
            ui->spinBox_triangle_y2->setValue(prevPoints[1].y());
            ui->spinBox_triangle_x3->setValue(prevPoints[2].x());
            ui->spinBox_triangle_y3->setValue(prevPoints[2].y());
        }

        if (prevAngle != newAngle)
        {
            // Если угол изменился
            ui->spinBox_triangle_rotation->setValue(prevAngle);
        }
        ui->pushButton_triangle_Apply->setEnabled(false); // отколючаем Применить после нажатия Отменить
    }
}

// Кнопка удаления треугольника
void MainWindow::on_pushButton_triangle_Delete_clicked()
{
    if (!selectedShape)
        return; // Если фигура не выбрана, выходим

    // Проверяем, является ли выбранная фигура кругом
    auto *triangle = dynamic_cast<TriangleShape *>(selectedShape);
    if (!triangle)
        return; // Если фигура не круг, ничего не делаем

    list_of_Shapes.removeOne(triangle);     // Удаляем фигуру из списка фигур
    coordinate_scene->removeItem(triangle); // Удаляем фигуру из сцены графика

    delete triangle;         // Освобождаем память
    selectedShape = nullptr; // Сбрасываем выбранную фигуру

    // Удаляем соответствующий `QListWidgetItem` из `QListWidget`
    for (int i = 0; i < ui->listWidgetShapes->count(); ++i)
    {
        QListWidgetItem *item = ui->listWidgetShapes->item(i);
        if (item->text() == triangle->getName())
        {
            delete ui->listWidgetShapes->takeItem(i); // Удаляем из списка
            break;
        }
    }

    ui->listWidgetShapes->clearSelection();     // Очищаем выделение в `QListWidget`
    ui->tabWidgetProperties->setEnabled(false); // Выключаем `tabWidgetProperties`

    ui->listWidgetShapes->update();
    coordinate_scene->update();
}

//////////////////////////////////////////////////////////////////

// задание и обновление координат для прямоугольника на основе измененных координат
void MainWindow::updateRectanglePoints()
{
    // Получаем текущие значения координат из `QSpinBox`
    double x1 = ui->spinBox_rectangle_x1->value();
    double y1 = ui->spinBox_rectangle_y1->value();
    double x3 = ui->spinBox_rectangle_x3->value();
    double y3 = ui->spinBox_rectangle_y3->value();

    // Вычисляем точки 2 и 4
    double x2 = x3;
    double y2 = y1;
    double x4 = x1;
    double y4 = y3;

    // Обновляем `QSpinBox`
    ui->spinBox_rectangle_x2->setValue(x2);
    ui->spinBox_rectangle_y2->setValue(y2);
    ui->spinBox_rectangle_x4->setValue(x4);
    ui->spinBox_rectangle_y4->setValue(y4);
}

// включить кнопку Apply для прямоугольника
void MainWindow::enableRectangleApplyButton()
{
    ui->pushButton_rectangle_Apply->setEnabled(true);
}

// применение изменений параметров прямоугольника
void MainWindow::on_pushButton_rectangle_Apply_clicked()
{
    if (!selectedShape)
        return;

    auto *rectangle = dynamic_cast<RectangleShape *>(selectedShape);
    if (rectangle)
    {
        // Сохраняем новые координаты для прямоугольника
        QVector<QPointF> newPoints =
            {
                QPointF(ui->spinBox_rectangle_x1->value(), ui->spinBox_rectangle_y1->value()), // x1 y1
                QPointF(ui->spinBox_rectangle_x2->value(), ui->spinBox_rectangle_y2->value()), // x2 y2
                QPointF(ui->spinBox_rectangle_x3->value(), ui->spinBox_rectangle_y3->value()), // x3 y3
                QPointF(ui->spinBox_rectangle_x4->value(), ui->spinBox_rectangle_y4->value())  // x4 y4
            };
        // Сохраняем новый угол вращения
        int newAngle = ui->spinBox_rectangle_rotation->value();

        rectangle->setNewPoints(newPoints);    // Применяем новые координаты для треугольника
        rectangle->setRotationAngle(newAngle); // Применяем новый угол вращения

        coordinate_scene->update(); // Перерисовываем сцену
        ui->tabWidgetProperties->update();
    }
    ui->pushButton_rectangle_Apply->setEnabled(true); // Отключаем кнопку после нажатия
}

// отмена изменений параметров прямоугольника
void MainWindow::on_pushButton_rectangle_Cancel_clicked()
{
    if (!selectedShape)
        return;

    auto *rectangle = dynamic_cast<RectangleShape *>(selectedShape);
    if (rectangle)
    {
        // Сохраняем предыдущие координаты для прямоугольника
        QVector<QPointF> prevPoints =
            {
                QPointF(rectangle->getPoints()[0].x(), rectangle->getPoints()[0].y()), // x1 y1
                QPointF(rectangle->getPoints()[1].x(), rectangle->getPoints()[1].y()), // x2 y2
                QPointF(rectangle->getPoints()[2].x(), rectangle->getPoints()[2].y()), // x3 y3
                QPointF(rectangle->getPoints()[3].x(), rectangle->getPoints()[3].y())  // x4 y4
            };
        // Сохраняем предыдущий угол вращения
        int prevAngle = rectangle->getRotationAngle();

        // Сохраняем новые координаты для прямоугольника
        QVector<QPointF> newPoints =
            {
                QPointF(ui->spinBox_rectangle_x1->value(), ui->spinBox_rectangle_y1->value()), // x1 y1
                QPointF(ui->spinBox_rectangle_x2->value(), ui->spinBox_rectangle_y2->value()), // x2 y2
                QPointF(ui->spinBox_rectangle_x3->value(), ui->spinBox_rectangle_y3->value()), // x3 y3
                QPointF(ui->spinBox_rectangle_x4->value(), ui->spinBox_rectangle_y4->value())  // x4 y4
            };

        // Сохраняем новый угол вращения
        int newAngle = ui->spinBox_rectangle_rotation->value();

        if (prevPoints != newPoints)
        {
            // Если координаты изменились
            ui->spinBox_rectangle_x1->setValue(prevPoints[0].x());
            ui->spinBox_rectangle_y1->setValue(prevPoints[0].y());
            ui->spinBox_rectangle_x2->setValue(prevPoints[1].x());
            ui->spinBox_rectangle_y2->setValue(prevPoints[1].y());
            ui->spinBox_rectangle_x3->setValue(prevPoints[2].x());
            ui->spinBox_rectangle_y3->setValue(prevPoints[2].y());
            ui->spinBox_rectangle_x4->setValue(prevPoints[3].x());
            ui->spinBox_rectangle_y4->setValue(prevPoints[3].y());
        }

        if (prevAngle != newAngle)
        {
            // Если угол изменился
            ui->spinBox_rectangle_rotation->setValue(prevAngle);
        }

        ui->pushButton_rectangle_Apply->setEnabled(false);
    }
}

// Кнопка удаления прямоугольника
void MainWindow::on_pushButton_rectangle_Delete_clicked()
{
    if (!selectedShape)
        return; // Если фигура не выбрана, выходим

    // Проверяем, является ли выбранная фигура кругом
    auto *rectangle = dynamic_cast<RectangleShape *>(selectedShape);
    if (!rectangle)
        return; // Если фигура не круг, ничего не делаем

    list_of_Shapes.removeOne(rectangle);     // Удаляем фигуру из списка фигур
    coordinate_scene->removeItem(rectangle); // Удаляем фигуру из сцены графика

    delete rectangle;        // Освобождаем память
    selectedShape = nullptr; // Сбрасываем выбранную фигуру

    // Удаляем соответствующий `QListWidgetItem` из `QListWidget`
    for (int i = 0; i < ui->listWidgetShapes->count(); ++i)
    {
        QListWidgetItem *item = ui->listWidgetShapes->item(i);
        if (item->text() == rectangle->getName())
        {
            delete ui->listWidgetShapes->takeItem(i); // Удаляем из списка
            break;
        }
    }

    ui->listWidgetShapes->clearSelection();     // Очищаем выделение в `QListWidget`
    ui->tabWidgetProperties->setEnabled(false); // Выключаем `tabWidgetProperties`

    ui->listWidgetShapes->update();
    coordinate_scene->update();
}
