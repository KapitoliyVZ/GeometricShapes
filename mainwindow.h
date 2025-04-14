#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QWheelEvent>

#include <QMainWindow>
#include <QGraphicsScene> // библиотека для графической сцены
#include <QGraphicsItem>
#include <QListWidget>

#include <Shape.h>
#include <Circle.h>
#include <Rectangle.h>
#include <Triangle.h>
#include "CoordinateSystem.h" // Подключаем наш новый класс

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow // – класс основного окна приложения
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); // Конструктор класса
    ~MainWindow();                         // Деструктор класса

private slots:

    // Нажатие кнопок
    void on_btnRectangle_clicked();  // кнопка добавления прямоугольника
    void on_btnCircle_clicked();     // кнопка добавления круга
    void on_btnTriangle_clicked();   // кнопка добавления треугольника
    void on_btnClearScene_clicked(); // кнопка очистки графика

    void on_listWidgetShapes_itemClicked(QListWidgetItem *item); // Нажатие на фигуру в списке
    void onSceneSelectShape();                                   // Нажатие на фигуру на сцене

    // включить кнопки Apply
    void enableCircleApplyButton();
    void enableTriangleApplyButton();
    void enableRectangleApplyButton();

    // Нажатие кнопок Apply
    void on_pushButton_circle_Apply_clicked();    // Применить новые координаты круга
    void on_pushButton_triangle_Apply_clicked();  // Применить новые координаты треугольника
    void on_pushButton_rectangle_Apply_clicked(); // Применить новые координаты прямоугольника
    // Нажатие кнопок Cancel
    void on_pushButton_circle_Cancel_clicked();    // Отменить изменения для круга
    void on_pushButton_triangle_Cancel_clicked();  // Отменить изменения для треугольника
    void on_pushButton_rectangle_Cancel_clicked(); // Отменить изменения для прямоугольника

    // Нажатие кнопок удаления фигур
    void on_pushButton_circle_Delete_clicked();    // удалить круг
    void on_pushButton_triangle_Delete_clicked();  // удалить треугольник
    void on_pushButton_rectangle_Delete_clicked(); // удалить прямоугольник

protected:
    void resizeEvent(QResizeEvent *event) override; // при изменении размера окна
    void wheelEvent(QWheelEvent *event) override;   // при масштабирование сцены с помощью колеса мыши

private:
    Ui::MainWindow *ui;
    QGraphicsScene *coordinate_scene;                       // Сцена для отображения фигур как объект отрисовки
    CoordinateSystem *coordinateSystem;                     // Объект для настройки координатной системой
    QList<QGraphicsItem *> list_of_Shapes;                  // Список фигур
    Shape *selectedShape = nullptr;                         // Указатель на выбранную фигуру
    void setupScene();                                      // Метод для настройки сцены
    void updateShapeList();                                 // Обновление сцены
    bool isShapeNameUnique(const QString &name);            // Проверка наличия имени фигуры в списке
    void setWidgetPropertiesShape(Shape *selectedShape);    // отображение параметров выбранной фигуры
    void deselectShape();                                   // Отмена выбора фигуры
    void onSelectionChanged();                              // Обработка изменения выделения в списке фигур
    void selectShape(Shape *shape);                         // Выделяет фигуру и синхронизирует UI
    void updateRectanglePoints();                           // задание и обновление координат для прямоугольника
    QString generateUniqueShapeName(const QString &type);   // Генерация уникального имени для фигуры
    int getNextShapeIndex(const QString &typePrefix) const; // Получение следующего индекса для уникального имени фигуры
};

#endif // MAINWINDOW_H
