#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QWheelEvent>

#include <QMainWindow>
#include <QGraphicsScene>       // библиотека для графической сцены

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

    // кнопка очистки графика
    void on_btnClearScene_clicked();

<<<<<<< Updated upstream
    void on_btnTriangle_clicked();
=======
    // Нажатие на фигуру в списке
    void on_listWidgetShapes_itemClicked(QListWidgetItem *item);
    // Нажатие на фигуру на сцене
    void onSceneSelectShape();

    // включить кнопки Apply
    void enableCircleApplyButton();
    void enableTriangleApplyButton();
    void enableRectangleApplyButton();

    // нажатие кнопки Apply
    void on_pushButton_circle_Apply_clicked();      // Применить новые координаты круга
    void on_pushButton_triangle_Apply_clicked();    // Применить новые координаты треугольника
    void on_pushButton_rectangle_Apply_clicked();   // Применить новые координаты прямоугольника

    // нажатие кнопки Delete
    void on_pushButton_circle_Delete_clicked();     // Удалить круг
    void on_pushButton_triangle_Delete_clicked();   // Удалить треугольник
    void on_pushButton_rectangle_Delete_clicked();  // Удалить прямоугольник
>>>>>>> Stashed changes

protected:
    void resizeEvent(QResizeEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    Ui::MainWindow *ui;
<<<<<<< Updated upstream
    QGraphicsScene *coordinate_scene; // Сцена для отображения фигур
    QList<QGraphicsItem*> list_of_Shapes; // Список фигур
    void addShapeToTree(const QString &name, const QPointF &pos, const QString &size, const QColor &color);

    void setupScene(); // Метод для настройки сцены
=======
    QGraphicsScene *coordinate_scene;       // Сцена (координатный график) для отображения фигур
    QList<QGraphicsItem*> list_of_Shapes;   // Список фигур

    Shape* selectedShape = nullptr;  // Указатель на выбранную (выделенную) фигуру

    void setupScene();          // Метод для настройки сцены (координатного графика)
    void updateShapeList();     // Обновление виджета списка

    bool isShapeNameUnique(const QString& name);    // Проверка наличия имени фигуры в списке

    void setWidgetPropertiesShape(Shape* selectedShape); // отображение параметров выбранной фигуры

    void deselectShape(); // Отмена выделенной фигуры
    void onSelectionChanged();

    void selectShape(Shape* shape);  // Выделяет фигуру и синхронизирует UI

    void updateRectanglePoints();   // задание и обновление координат для прямоугольника

>>>>>>> Stashed changes
};

#endif // MAINWINDOW_H
