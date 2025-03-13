#include "circledialog.h"
#include "ui_circledialog.h"

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

QPointF CircleDialog::getCenter() const
{
    return center;
}

double CircleDialog::getRadius() const
{
    return radius;
}
