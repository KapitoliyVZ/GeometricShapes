// окно для настройки параметров круга при его создании
#include "CircleDialog.h"
#include "ui_CircleDialog.h"

CircleDialog::CircleDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::CircleDialog)
{
    ui->setupUi(this);
}

CircleDialog::~CircleDialog()
{
    delete ui;
}

// Реакция на кнопку Apply
void CircleDialog::on_applyButton_clicked()
{
    center = QPointF(ui->xCenter->value(), ui->yCenter->value()); // запись координат центра круга
    radius = ui->radius->value();                                 // запись радиуса круга
    nameByUser = ui->LineCircleName->text();                      // запись имени
    accept();                                                     // сохранение параметров и закрытие окна
}

// Реакция на кнопку Cancel
void CircleDialog::on_cancelButton_clicked()
{
    reject(); // закрыть окно без сохранения параметров
}

// считать значение координат центра круга
QPointF CircleDialog::getCenter() const
{
    return center;
}

// cчитать значение радиуса круга
double CircleDialog::getRadius() const
{
    return radius;
}

// считать имя
QString CircleDialog::getCircleName() const
{
    return nameByUser;
}

// Отображение сгенерированного имени фигуры
void CircleDialog::setDefaultName(const QString &name)
{
    ui->LineCircleName->setText(name);
}
