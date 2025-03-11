#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "graphFrame.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // кнопки отрисовки фигур
    void on_btnCircle_clicked();

    void on_btnRectangle_clicked();
    void on_btnTriangle_clicked();

    // кнопка очистки графика
    void on_btnClear_clicked();

private:
    Ui::MainWindow *ui;
    GraphFrame *graph; // Добавляем графическое окно
};
#endif // MAINWINDOW_H
