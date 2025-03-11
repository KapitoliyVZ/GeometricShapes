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

void CircleDialog::on_applyButton_clicked()
{
    center = QPointF(ui->xCenter->value(), ui->yCenter->value());
    radius = ui->radius->value();
    accept();
}

void CircleDialog::on_cancelButton_clicked()
{
    reject();
}

QPointF CircleDialog::getCenter() const
{
    return center;
}

double CircleDialog::getRadius() const
{
    return radius;
}
