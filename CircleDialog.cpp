// окно для настройки параметров круга при его создании
#include "CircleDialog.h"
#include "ui_CircleDialog.h"

CircleDialog::CircleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CircleDialog)
{
    ui->setupUi(this);
}

CircleDialog::~CircleDialog()
{
    delete ui;
}

void CircleDialog::on_applyButton_clicked() // Реакция на кнопку Apply
{
    center = QPointF(ui->xCenter->value(), ui->yCenter->value());   // запись координат центра круга
    radius = ui->radius->value();                                   // запись радиуса круга
    accept();                                                       // сохранение параметров и закрытие окна
}

void CircleDialog::on_cancelButton_clicked() // Реакция на кнопку Cancel
{
    reject(); // закрыть окно без сохранения параметров
}

// считать значение координат центра круга
QPointF CircleDialog::getCenter() const
{
    return center;
}

//cчитать значение радиуса круга
double CircleDialog::getRadius() const
{
    return radius;
}
