#include "TriangleDialog.h"
#include "ui_TriangleDialog.h"

TriangleDialog::TriangleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TriangleDialog)
{
    ui->setupUi(this);
}

TriangleDialog::~TriangleDialog()
{
    delete ui;
}

// Реакция на кнопку Cancel
void TriangleDialog::on_cancelButton_clicked()
{
    reject(); // Закрываем диалог с результатом "Отмена"
}

// Реакция на кнопку Apply
void TriangleDialog::on_applyButton_clicked()
{
    // Получаем координаты из полей ввода
    coordinates.clear();
    coordinates.append(QPointF(ui->x1->value(), ui->y1->value()));
    coordinates.append(QPointF(ui->x2->value(), ui->y2->value()));
    coordinates.append(QPointF(ui->x3->value(), ui->y3->value()));

    nameUser = ui->LineTriangleName->text(); // запись имени
    accept(); // Закрываем диалог с результатом "Apply"
}

// Считать коодинаты треугольника
QList<QPointF> TriangleDialog::getCoordinates() const
{
    return coordinates;
}

// считать имя
QString TriangleDialog::getTriangleName() const
{
    return nameUser;
}
