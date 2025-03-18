#include "RectangleDialog.h"
#include "ui_RectangleDialog.h"
#include <QMessageBox>
#include <cmath>

RectangleDialog::RectangleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RectangleDialog)
{
    ui->setupUi(this);

    connect(ui->radioSetCoord, &QRadioButton::toggled, this, &RectangleDialog::onRadioTypeEnter);
    connect(ui->radioSetSides, &QRadioButton::toggled, this, &RectangleDialog::onRadioTypeEnter);

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

// Реакция на кнопку Cancel
void RectangleDialog::on_cancelButton_clicked()
{
    reject(); // Закрываем диалог с результатом "Отмена"
}

// Реакция на кнопку Apply
void RectangleDialog::on_applyButton_clicked()
{

    // Получаем координаты из полей ввода
    coordinates.clear();
    coordinates.append(QPointF(ui->x1->value(), ui->y1->value()));
    coordinates.append(QPointF(ui->x2->value(), ui->y2->value()));
    coordinates.append(QPointF(ui->x3->value(), ui->y3->value()));
    coordinates.append(QPointF(ui->x4->value(), ui->y4->value()));
    nameUser = ui->LineCircleName->text();

    if (!isValidRectangle(coordinates)) {
        QMessageBox::warning(this, "Ошибка", "Точки не формируют прямоугольник!");
        return;
    }

    accept(); // Закрываем диалог с результатом "Принять
}

// Считать координаты
QList<QPointF> RectangleDialog::getCoordinates() const
{
    return coordinates;
}

// Считать имя
QString RectangleDialog::getRectangleName() const
{
    return nameUser;
}

// функция для выбора параметров ввода
void RectangleDialog::onRadioTypeEnter()
{
    if(ui->radioSetCoord->isChecked())
    {
        ui->x1->setEnabled(true);
        ui->x2->setEnabled(true);
        ui->x3->setEnabled(true);
        ui->x4->setEnabled(true);
        ui->y1->setEnabled(true);
        ui->y2->setEnabled(true);
        ui->y3->setEnabled(true);
        ui->y4->setEnabled(true);

        ui->startPointX->setEnabled(false);
        ui->startPointY->setEnabled(false);
        ui->width->setEnabled(false);
        ui->height->setEnabled(false);
    }
    else if (ui->radioSetSides->isChecked())
    {
        ui->x1->setEnabled(false);
        ui->x2->setEnabled(false);
        ui->x3->setEnabled(false);
        ui->x4->setEnabled(false);
        ui->y1->setEnabled(false);
        ui->y2->setEnabled(false);
        ui->y3->setEnabled(false);
        ui->y4->setEnabled(false);

        ui->startPointX->setEnabled(true);
        ui->startPointY->setEnabled(true);
        ui->width->setEnabled(true);
        ui->height->setEnabled(true);
    }
}

// Проверяем, выбран ли режим "По двум точкам"
bool RectangleDialog::isCoordMode() const
{
    return ui->radioSetCoord->isChecked();
}

// Проверяем, выбран ли режим "По стартовой точке и размерам"
bool RectangleDialog::isSizeMode() const
{
    return ui->radioSetSides->isChecked();
}

// Получаем начальную точку
QPointF RectangleDialog::getStartPoint() const
{
    double x = ui->startPointX->value();
    double y = ui->startPointY->value();
    return QPointF(x, y);
}

// Получаем ширину
double RectangleDialog::getWidth() const
{
    return ui->width->value();
}

// Получаем высоту
double RectangleDialog::getHeight() const
{
    return ui->height->value();
}
