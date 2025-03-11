#include <QVBoxLayout>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphFrame.h"

#include "dialogsetcircle.h"

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graph = new GraphFrame(this);
    ui->frameGraphXY->setLayout(new QVBoxLayout());
    ui->frameGraphXY->layout()->addWidget(graph);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Обработчики кнопок
void MainWindow::on_btnCircle_clicked()
{
    DialogSetCircle dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        int radius = dialog.getRadius();
        int x = dialog.getX();
        int y = dialog.getY();
        QColor color = dialog.getColor();

        graph->addShape(new Circle(radius, x, y, color));
    }
    // QWidget *wdg = new QWidget;
    // wdg->show();
}

void MainWindow::on_btnRectangle_clicked()
{
    graph->addShape(new Rectangle());
}

void MainWindow::on_btnTriangle_clicked()
{
    graph->addShape(new Triangle());
}


// Кнопка очистки графика
void MainWindow::on_btnClear_clicked()
{
    graph->clearShapes();
}

