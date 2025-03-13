#include "RectangleDialog.h"
#include "ui_RectangleDialog.h"
#include <QMessageBox>
#include <cmath>

RectangleDialog::RectangleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RectangleDialog)
{
    ui->setupUi(this);
}

RectangleDialog::~RectangleDialog()
{
    delete ui;
}

// проверка на допустимость значений для прямоугольника
bool RectangleDialog::isValidRectangle(const QList<QPointF> &coords)
{
    if (coords.size() != 4) return false;

    // Вычисляем длины сторон
    double d1 = std::hypot(coords[0].x() - coords[1].x(), coords[0].y() - coords[1].y());
    double d2 = std::hypot(coords[1].x() - coords[2].x(), coords[1].y() - coords[2].y());
    double d3 = std::hypot(coords[2].x() - coords[3].x(), coords[2].y() - coords[3].y());
    double d4 = std::hypot(coords[3].x() - coords[0].x(), coords[3].y() - coords[0].y());

    double diag1 = std::hypot(coords[0].x() - coords[2].x(), coords[0].y() - coords[2].y());
    double diag2 = std::hypot(coords[1].x() - coords[3].x(), coords[1].y() - coords[3].y());

    // Проверяем равенство противоположных сторон и диагоналей
    return (d1 == d3 && d2 == d4 && diag1 == diag2);
}

void RectangleDialog::on_cancelButton_clicked()
{
    reject(); // Закрываем диалог с результатом "Отмена"
}


void RectangleDialog::on_applyButton_clicked()
{

    // Получаем координаты из полей ввода
    coordinates.clear();
    coordinates.append(QPointF(ui->x1->value(), ui->y1->value()));
    coordinates.append(QPointF(ui->x2->value(), ui->y2->value()));
    coordinates.append(QPointF(ui->x3->value(), ui->y3->value()));
    coordinates.append(QPointF(ui->x4->value(), ui->y4->value()));

    if (!isValidRectangle(coordinates)) {
        QMessageBox::warning(this, "Ошибка", "Точки не формируют прямоугольник!");
        return;
    }

    accept(); // Закрываем диалог с результатом "Принять
}

QList<QPointF> RectangleDialog::getCoordinates() const
{
    return coordinates;
}
