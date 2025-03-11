#include "dialogsetcircle.h"
#include "ui_dialogsetcircle.h"

#include <QColorDialog>

DialogSetCircle::DialogSetCircle(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogSetCircle)
{
    ui->setupUi(this);
}

DialogSetCircle::~DialogSetCircle()
{
    delete ui;
}

int DialogSetCircle::getX() const {
    return ui->spinBox_setX->value();
}

int DialogSetCircle::getY() const {
    return ui->spinBox_setY->value();
}

int DialogSetCircle::getRadius() const {
    return ui->spinBox_setRadius->value();
}

QColor DialogSetCircle::getColor() const {
    return selectedColor;
}

void DialogSetCircle::on_pushButton_setColour_clicked() {
    QColor color = QColorDialog::getColor(selectedColor, this, "Выберите цвет");
    if (color.isValid()) {
        selectedColor = color;
    }
}


