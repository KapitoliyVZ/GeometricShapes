#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QWheelEvent>

#include <QMainWindow>
#include <QGraphicsScene>       // библиотека для графической сцены
#include <QGraphicsItem>
#include <QListWidget>

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

    void on_btnTriangle_clicked();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *coordinate_scene; // Сцена для отображения фигур
    QList<QGraphicsItem*> list_of_Shapes; // Список фигур
    void addShapeToTree(const QString &name, const QPointF &pos, const QString &size, const QColor &color);

    void setupScene(); // Метод для настройки сцены

    void updateShapeList();
};

#endif // MAINWINDOW_H
