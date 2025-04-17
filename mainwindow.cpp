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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this); // инициализация интерфейса

    setWindowTitle("Редактор фигур");               // Название окна
    setWindowIcon(QIcon("D:/YandexDisk/Qt/GeometricShapes/Title-picture2.png"));   // Иконка окна (из ресурсов)
    //setWindowIcon(QIcon(":/icons/app_icon.png"));   // Иконка окна (из ресурсов)

    setupScene(); // прорисовка сцены (координатной оси)

    // Включаем режим выбора фигур на сцене (на координатной сетке)
    coordinate_scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    coordinate_scene->setSelectionArea(QPainterPath());

    ui->tabWidgetProperties->setEnabled(false); // выключаем таблицу настроек до выбора нарисованной фигуры

    // Нажатие на фигуру на графике
    connect(ui->graphicsView->scene(), &QGraphicsScene::selectionChanged, this, &MainWindow::onSceneSelectShape);

    // реакция на нажатие на пустую область для снятия выделения фигуры
    connect(ui->graphicsView->scene(), &QGraphicsScene::selectionChanged, this, &MainWindow::onSelectionChanged);
}
// деструктор классам
MainWindow::~MainWindow()
{
    delete ui;
}

// прорисовка сцены (координатной оси)
void MainWindow::setupScene()
{
    // Создание сцены и привязка к graphicsView
    coordinate_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(coordinate_scene);                 // Устанавливаем сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);      // Включаем сглаживание
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag); // Включаем режим перетаскивания сцены

    // Инвертируем ось Y — положительное направление вверх
    ui->graphicsView->setTransform(QTransform().scale(1, -1));

    // Инициализация системы координат с параметрами шага и масштабом
    coordinateSystem = new CoordinateSystem(coordinate_scene, 50, 1.0);

    // Первичная настройка размера сцены на основе размеров виджета
    const int viewWidth = ui->graphicsView->width();
    const int viewHeight = ui->graphicsView->height();
    coordinateSystem->updateSceneSize(viewWidth, viewHeight);
}

// прорисовка сцены (координатной оси) при изменении размеров окна пользователем
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    coordinateSystem->updateSceneSize(ui->graphicsView->width(), ui->graphicsView->height()); // обновляем размеры сцены
}

// при прокрутке колеса мыши
void MainWindow::wheelEvent(QWheelEvent *event)
{
    const double scaleFactor = 1.05; // коэффициент прокрутки
    const double minScale = 1.0;     // коэффициент отдаления
    const double maxScale = 1.5;     // коэффициент приближения

    // Получаем текущий масштаб (по X достаточно, т.к. X=Y)
    double currentScale = ui->graphicsView->transform().m11();

    // Устанавливаем новый масштаб в зависимости от направления прокрутки
    if (event->angleDelta().y() > 0 && currentScale < maxScale) // прокрутка вверх
        ui->graphicsView->setTransform(ui->graphicsView->transform() * QTransform::fromScale(scaleFactor, scaleFactor));
    else if (event->angleDelta().y() < 0 && currentScale > minScale) // прокрутка вниз
        ui->graphicsView->setTransform(ui->graphicsView->transform() * QTransform::fromScale(1.0 / scaleFactor, 1.0 / scaleFactor));
}

// кнопка добавления прямоугольника
void MainWindow::on_btnRectangle_clicked()
{
    RectangleDialog dialog(this);                               // диалоговое окно для ввода параметров прямоугольника
    QString defaultName = generateUniqueShapeName("Rectangle"); // генерируем уникальное имя
    dialog.setDefaultName(defaultName);                         // отображаем сгенерированное имя фигуры

    if (dialog.exec() == QDialog::Accepted)
    {
        QList<QPointF> coords = dialog.getCoordinates(); // получаем координаты
        QString name = dialog.getRectangleName();        // получаем имя фигуры

        // Проверяем уникальность имени
        if (!isShapeNameUnique(name))
        {
            QMessageBox::warning(this, "Ошибка", "Фигура с таким именем уже существует!");
            return;
        }
        // Построение по 4 координатам
        if (dialog.isCoordMode())
        {
            if (coords.size() == 4)
            {
                RectangleShape *rectangle = new RectangleShape(coords, name);
                coordinate_scene->addItem(rectangle);
                list_of_Shapes.append(rectangle); // Сохраняем в список
                updateShapeList();                // Обновляем виджет с именами
            }
        }
        // Построение по стартовой точке и размерам
        else if (dialog.isSizeMode())
        {
            QPointF startPoint = dialog.getStartPoint();
            double width = dialog.getWidth();
            double height = dialog.getHeight();

            RectangleShape *rectangle = new RectangleShape(startPoint, width, height, name); // Создаем прямоугольник с заданными параметрами
            coordinate_scene->addItem(rectangle);                                            // Добавляем прямоугольник на сцену
            list_of_Shapes.append(rectangle);                                                // Сохраняем в список
            updateShapeList();                                                               // Обновляем виджет с именами
        }
    }
}
// кнопка добавления круга
void MainWindow::on_btnCircle_clicked()
{
    CircleDialog dialog(this);                               // диалоговое окно для ввода параметров круга
    QString defaultName = generateUniqueShapeName("Circle"); // генерируем уникальное имя
    dialog.setDefaultName(defaultName);                      // отображаем сгенерированное имя фигуры

    if (dialog.exec() == QDialog::Accepted)
    {
        // Получаем координаты центра и радиус
        QPointF center = dialog.getCenter();
        double radius = dialog.getRadius();
        QString name = dialog.getCircleName();

        // Проверяем уникальность имени
        if (!isShapeNameUnique(name))
        {
            QMessageBox::warning(this, "Ошибка", "Фигура с таким именем уже существует!");
            return;
        }

        CircleShape *circle = new CircleShape(center, radius, name); // Создаем круг с заданными параметрами
        coordinate_scene->addItem(circle);                           // Добавляем круг на сцену
        list_of_Shapes.append(circle);                               // Сохраняем в список
        updateShapeList();                                           // Обновляем виджет с именами
    }
}
// кнопка добавления треугольника
void MainWindow::on_btnTriangle_clicked()
{
    TriangleDialog dialog(this);                               // диалоговое окно для ввода параметров треугольника
    QString defaultName = generateUniqueShapeName("Triangle"); // генерируем уникальное имя
    dialog.setDefaultName(defaultName);                        // отображаем сгенерированное имя фигуры

    if (dialog.exec() == QDialog::Accepted)
    {
        QList<QPointF> coords = dialog.getCoordinates();
        QString name = dialog.getTriangleName();

        // Проверяем уникальность имени
        if (!isShapeNameUnique(name))
        {
            QMessageBox::warning(this, "Ошибка", "Фигура с таким именем уже существует!");
            return;
        }

        if (coords.size() == 3)
        {
            TriangleShape *triangle = new TriangleShape(coords, name); // Создаем треугольник с заданными параметрами
            coordinate_scene->addItem(triangle);                       // Добавляем треугольник на сцену
            list_of_Shapes.append(triangle);                           // Сохраняем в список
            updateShapeList();                                         // Обновляем виджет с именами
        }
    }
}

// проверка наличия введенного имени
bool MainWindow::isShapeNameUnique(const QString &name)
{

    for (auto *item : list_of_Shapes)
    {
        auto *shape = dynamic_cast<Shape *>(item);
        if (shape && shape->getName() == name)
            return false; // Данное имя имеется
    }
    return true; // Имя уникальное
}

// Кнопка очистки графика
void MainWindow::on_btnClearScene_clicked()
{
    // Удаляем все фигуры со сцены
    for (auto *item : list_of_Shapes)
    {
        coordinate_scene->removeItem(item); // Удаляем из `QGraphicsScene`
        delete item;                        // Освобождаем память
    }

    list_of_Shapes.clear();                                        // Очищаем список фигур
    ui->listWidgetShapes->clear();                                 // Очищаем `QListWidget`
    coordinate_scene->update();                                    // Обновляем сцену
    selectedShape = nullptr;                                       // Сбрасываем выбор фигуры
    ui->tabWidgetProperties->setEnabled(selectedShape != nullptr); // Выключаем tabWidgetProperties
}

// Обновление виджета списка (listWidgetShapes)
void MainWindow::updateShapeList()
{
    ui->listWidgetShapes->clear(); // Очищаем виджет перед обновлением

    // Проходим по всем фигурам в списке
    for (auto *item : list_of_Shapes)
    {
        // Приводим QGraphicsItem к классу Shape
        auto *shape = dynamic_cast<Shape *>(item);
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
    if (!item)
        return; // Защита от null

    QString shapeName = item->text(); // Получаем имя фигуры из QListWidget
    selectedShape = nullptr;          // Выбранная фигура

    qDebug() << "Выбрана фигура из списка: " << shapeName;

    // Проходим по списку всех фигур
    for (auto *item : list_of_Shapes)
    {
        // Приводим (item) QGraphicsItem к классу Shape
        auto *shape = dynamic_cast<Shape *>(item);

        // Ищем фигуру в списке
        if (shape && shape->getName() == shapeName)
        {
            qDebug() << "Фигура найдена в списке!";

            selectedShape = shape;            // Назначаем найденную фигуру выбранной
            selectedShape->setSelected(true); // Ставим флаг выделения
        }
        else
        {
            shape->setSelected(false); // Снимаем выделение с остальных фигур
        }
        shape->update(); // Перерисовываем фигуру
    }

    ui->tabWidgetProperties->setEnabled(true); // Включаем tabWidgetProperties
    coordinate_scene->update();                // Обновляем сцену
    setWidgetPropertiesShape(selectedShape);   // настраиваем отображение виджета с парамметрами выбранной фигуры
}

// Выбор фигуры на сцене графика (QGraphicsScene)
void MainWindow::onSceneSelectShape()
{
    QList<QGraphicsItem *> selectedItems = ui->graphicsView->scene()->selectedItems();

    if (selectedItems.isEmpty())
    {
        deselectShape(); // Снятие выделения всех фигур
        return;
    }

    // Получаем первую выбранную фигуру
    Shape *shape = dynamic_cast<Shape *>(selectedItems.first());
    if (!shape)
        return;

    selectedShape = shape; // Назначаем выбранную фигуру

    // Выбираем её в `QListWidget`
    for (int i = 0; i < ui->listWidgetShapes->count(); ++i)
    {
        QListWidgetItem *item = ui->listWidgetShapes->item(i);
        if (item->text() == selectedShape->getName())
        {
            item->setSelected(true);
            break;
        }
    }
    ui->tabWidgetProperties->setEnabled(true); // Включаем tabWidgetProperties
    coordinate_scene->update();                // Обновляем сцену
    setWidgetPropertiesShape(selectedShape);   // настраиваем отображение виджета с парамметрами выбранной фигуры
}

// Сброс выделения фигур
void MainWindow::deselectShape()
{
    if (selectedShape)
    {
        selectedShape->setSelected(false);                             // Убираем выделение
        selectedShape = nullptr;                                       // Обнуляем указатель
        ui->tabWidgetProperties->setEnabled(selectedShape != nullptr); // Выключаем tabWidgetProperties
        ui->listWidgetShapes->clearSelection();                        // Снимаем выделение в списке
    }
}

// Обработка изменения выделения в списке фигур
void MainWindow::onSelectionChanged() 
{
    // Если нет выбранных объектов
    if (ui->graphicsView->scene()->selectedItems().isEmpty())
    {
        deselectShape(); // Сбрасываем выделение
    }
}

// Генератор имен фигур с учетом порядкового номера
QString MainWindow::generateUniqueShapeName(const QString &type)
{
    int index = 1; 
    QString proposedName; 

    while (true)
    {
        proposedName = QString("%1_%2").arg(type).arg(index);
        bool exists = std::any_of(list_of_Shapes.begin(), list_of_Shapes.end(), [&](QGraphicsItem *item)
                                  {
            if (auto *shape = dynamic_cast<Shape *>(item)) {
                return shape->getName() == proposedName;
            }
            return false; });

        if (!exists)
            break;

        ++index;
    }

    return proposedName;
}
