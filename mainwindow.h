#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

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
    void on_btnRectangle_clicked();

    // кнопка добавления круга
    void on_btnCircle_clicked();

    // кнопка очистки графика
    void on_btnClearScene_clicked();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene; // Сцена для отображения фигур
    QList<QGraphicsItem*> shapes; // Список фигур

    void setupScene(); // Метод для настройки сцены
};

#endif // MAINWINDOW_H
