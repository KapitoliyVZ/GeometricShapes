#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QWheelEvent>

#include <QMainWindow>
#include <QGraphicsScene>       // библиотека для графической сцены
#include <QGraphicsItem>
#include <QListWidget>

#include <Shape.h>
#include <Circle.h>
#include <Rectangle.h>
#include <Triangle.h>
#include "CoordinateSystem.h"  // Подключаем наш новый класс

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // кнопка добавления прямоугольника
    void on_btnRectangle_clicked();

    // кнопка добавления круга
    void on_btnCircle_clicked();

    // кнопка добавления треугольника
    void on_btnTriangle_clicked();

    // кнопка очистки графика
    void on_btnClearScene_clicked();

    // Нажатие на фигуру в списке
    void on_listWidgetShapes_itemClicked(QListWidgetItem *item);
    // Нажатие на фигуру на сцене
    void onSceneSelectShape();

    // включить кнопки Apply
    void enableCircleApplyButton();
    void enableTriangleApplyButton();
    void enableRectangleApplyButton();

    void on_pushButton_circle_Apply_clicked();      // Применить новые координаты круга
    void on_pushButton_triangle_Apply_clicked();    // Применить новые координаты треугольника
    void on_pushButton_rectangle_Apply_clicked();   // Применить новые координаты прямоугольника

    // кнопки удаления фигур
    void on_pushButton_circle_Delete_clicked();
    void on_pushButton_triangle_Delete_clicked();
    void on_pushButton_rectangle_Delete_clicked();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *coordinate_scene; // Сцена для отображения фигур
    QGraphicsScene *scene;
    CoordinateSystem* coordinateSystem;      // Объект для работы с координатной системой

    QList<QGraphicsItem*> list_of_Shapes; // Список фигур

    Shape* selectedShape = nullptr;  // Указатель на выбранную фигуру

    void setupScene(); // Метод для настройки сцены
    void updateShapeList(); // Обновление сцены
    bool isShapeNameUnique(const QString& name);// Проверка наличия имени фигуры в списке

    void setWidgetPropertiesShape(Shape* selectedShape); // отображение параметров выбранной фигуры

    void deselectShape(); // Отмена выбора фигуры
    void onSelectionChanged();

    void selectShape(Shape* shape);  // Выделяет фигуру и синхронизирует UI

    void updateRectanglePoints();   // задание и обновление координат для прямоугольника

};

#endif // MAINWINDOW_H
