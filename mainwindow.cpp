#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include "CoordinateSystem.h"
#include "Rectangle.h"
#include "RectangleDialog.h"
#include "Circle.h"
#include "CircleDialog.h"
#include <Triangle.h>
#include <TriangleDialog.h>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupScene();

    // Включаем режим выбора фигур на сцене (на координатной сетке)
    coordinate_scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    coordinate_scene->setSelectionArea(QPainterPath());

    ui->tabWidgetProperties->setEnabled(false);// выключаем таблицу настроек до выбора нарисованной фигуры
    // ui->tabWidgetProperties->setEnabled(selectedShape != nullptr);

    // Нажатие на фигуру на графике
    connect(ui->graphicsView->scene(), &QGraphicsScene::selectionChanged, this, &MainWindow::onSceneSelectShape);

    // реакция на нажатие на пустую область для снятия выделения фигуры
    connect(ui->graphicsView->scene(), &QGraphicsScene::selectionChanged, this, &MainWindow::onSelectionChanged);
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
    // QMainWindow::resizeEvent(event);
    // GraphSettings::updateSceneSize(coordinate_scene, ui->graphicsView);
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

        // Проверяем уникальность имени
        if (!isShapeNameUnique(name))
        {
            QMessageBox::warning(this, "Ошибка", "Фигура с таким именем уже существует!");
            return;
        }
        // Построение по 4 координатам
        if (dialog.isCoordMode())
        {
            if (coords.size() == 4) {
                RectangleShape *rectangle = new RectangleShape(coords, name);
                coordinate_scene->addItem(rectangle);
                list_of_Shapes.append(rectangle);   // Сохраняем в список
                updateShapeList();                  // Обновляем виджет с именами
            }
        }
        // Построение по стартовой точке и размерам
        else if (dialog.isSizeMode())
        {
            QPointF startPoint = dialog.getStartPoint();
            double width = dialog.getWidth();
            double height = dialog.getHeight();

            RectangleShape *rectangle = new RectangleShape(startPoint, width, height, name);
            coordinate_scene->addItem(rectangle);
            list_of_Shapes.append(rectangle);   // Сохраняем в список
            updateShapeList();                  // Обновляем виджет с именами
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

        // Проверяем уникальность имени
        if (!isShapeNameUnique(name))
        {
            QMessageBox::warning(this, "Ошибка", "Фигура с таким именем уже существует!");
            return;
        }

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

        // Проверяем уникальность имени
        if (!isShapeNameUnique(name))
        {
            QMessageBox::warning(this, "Ошибка", "Фигура с таким именем уже существует!");
            return;
        }

        if (coords.size() == 3) {
            TriangleShape *triangle = new TriangleShape(coords, name);
            coordinate_scene->addItem(triangle);
            list_of_Shapes.append(triangle); // Сохраняем в список
            updateShapeList(); // Обновляем виджет с именами
        }
    }
}

// проверка наличия введенного имени
bool MainWindow::isShapeNameUnique(const QString& name)
{
    for (auto* item : list_of_Shapes)
    {
        auto* shape = dynamic_cast<Shape*>(item);
        if (shape && shape->getName() == name)
        {
            return false;  // Данное имя имеется
        }
    }
    return true;  // Имя уникальное
}


// Кнопка очистки графика
void MainWindow::on_btnClearScene_clicked()
{
    qDebug() << "Удаляем все фигуры...";

    // Удаляем все фигуры со сцены
    for (auto* item : list_of_Shapes)
    {
        coordinate_scene->removeItem(item);  // Удаляем из `QGraphicsScene`
        delete item;                         // Освобождаем память
    }

    // Очищаем список фигур
    list_of_Shapes.clear();

    // Очищаем `QListWidget`
    ui->listWidgetShapes->clear();

    // Обновляем сцену
    coordinate_scene->update();

    selectedShape = nullptr; // Сбрасываем выбор фигуры
    ui->tabWidgetProperties->setEnabled(selectedShape != nullptr); // Выключаем tabWidgetProperties

    qDebug() << "Все фигуры удалены!";
}

// Обновление виджета списка (listWidgetShapes)
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

// Выбор фигуры в виджете списка (listWidgetShapes)
void MainWindow::on_listWidgetShapes_itemClicked(QListWidgetItem *item)
{
    if (!item) return;  // Защита от null

    QString shapeName = item->text();   // Получаем имя фигуры из QListWidget
    selectedShape = nullptr;            // Выбранная фигура

    qDebug() << "Выбрана фигура из списка: " << shapeName;

    // Проходим по списку всех фигур
    for (auto* item : list_of_Shapes)
    {
        // Приводим (item) QGraphicsItem к классу Shape
        auto* shape = dynamic_cast<Shape*>(item);

        // Ищем фигуру в списке
        if (shape && shape->getName() == shapeName)
        {
            qDebug() << "Фигура найдена в списке!";

            selectedShape = shape;                   // Назначаем найденную фигуру выбранной
            selectedShape->setSelected(true);        // Ставим флаг выделения
        }
        else
        {
            shape->setSelected(false); // Снимаем выделение с остальных фигур
        }
        shape->update(); // Перерисовываем фигуру
    }

    ui->tabWidgetProperties->setEnabled(true);  // Включаем tabWidgetProperties
    coordinate_scene->update();                 // Обновляем сцену
    setWidgetPropertiesShape(selectedShape);    // настраиваем отображение виджета с парамметрами выбранной фигуры

}

// Выбор фигуры на сцене графика (QGraphicsScene)
void MainWindow::onSceneSelectShape()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();

    if (selectedItems.isEmpty())
    {
        deselectShape(); // Снятие выделения всех фигур
        return;
    }

    // Получаем первую выбранную фигуру
    Shape* shape = dynamic_cast<Shape*>(selectedItems.first());

    if (!shape) return;

    selectedShape = shape;

    // Выбираем её в `QListWidget`
    for (int i = 0; i < ui->listWidgetShapes->count(); ++i)
    {
        QListWidgetItem* item = ui->listWidgetShapes->item(i);
        if (item->text() == selectedShape->getName())
        {
            item->setSelected(true);
            break;
        }
    }

    ui->tabWidgetProperties->setEnabled(true);  // Включаем tabWidgetProperties
    coordinate_scene->update();                 // Обновляем сцену
    setWidgetPropertiesShape(selectedShape);    // настраиваем отображение виджета с парамметрами выбранной фигуры

}


// Сброс выделения фигур
void MainWindow::deselectShape()
{
    if (selectedShape)
    {
        selectedShape->setSelected(false);  // Убираем выделение
        selectedShape = nullptr;            // Обнуляем указатель
        ui->tabWidgetProperties->setEnabled(selectedShape != nullptr);  // Выключаем tabWidgetProperties
        ui->listWidgetShapes->clearSelection();                         // Снимаем выделение в списке
    }
}

//
void MainWindow::onSelectionChanged()
{
    // Если нет выбранных объектов
    if (ui->graphicsView->scene()->selectedItems().isEmpty())
    {
        deselectShape(); // Сбрасываем выделение
    }
}




