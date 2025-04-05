#include "RectangleDialog.h"
#include "ui_RectangleDialog.h"
#include <QMessageBox>
#include <cmath>

RectangleDialog::RectangleDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::RectangleDialog)
{
    ui->setupUi(this);

    // группа для `QRadioButton`
    shapeModeGroup = new QButtonGroup(this);
    shapeModeGroup->addButton(ui->radioSetCoord);
    shapeModeGroup->addButton(ui->radioSetSides);

    // Устанавливаем `radioSetCoord` включённым по умолчанию
    ui->radioSetCoord->setChecked(true);

    connect(ui->radioSetCoord, &QRadioButton::toggled, this, &RectangleDialog::onRadioTypeSet);
    connect(ui->radioSetSides, &QRadioButton::toggled, this, &RectangleDialog::onRadioTypeSet);

    // Вызываем `onRadioTypeEnter()` сразу при запуске, чтобы ввод другого режима был недоступен
    onRadioTypeSet();
}

RectangleDialog::~RectangleDialog()
{
    delete ui;
}

// проверка на допустимость значений для прямоугольника
bool RectangleDialog::isValidRectangle(const QList<QPointF> &coords)
{
    if (coords.size() != 4)
        return false;

    // Проверяем, что противоположные стороны параллельны
    return (coords[0].x() == coords[3].x() && coords[1].x() == coords[2].x() &&
            coords[0].y() == coords[1].y() && coords[2].y() == coords[3].y());
}

// Реакция на кнопку Cancel
void RectangleDialog::on_cancelButton_clicked()
{
    reject(); // Закрываем диалог с результатом "Отмена"
}

// Реакция на кнопку Apply
void RectangleDialog::on_applyButton_clicked()
{
    // Получаем введённые координаты двух противоположных точек
    double x1 = ui->x1->value();
    double y1 = ui->y1->value();
    double x3 = ui->x3->value();
    double y3 = ui->y3->value();

    // Вычисляем остальные две точки
    double x2 = x3;
    double y2 = y1;
    double x4 = x1;
    double y4 = y3;

    // Заполняем список координат
    coordinates.clear();
    coordinates.append(QPointF(x1, y1));
    coordinates.append(QPointF(x2, y2));
    coordinates.append(QPointF(x3, y3));
    coordinates.append(QPointF(x4, y4));

    // Считываем имя
    nameUser = ui->LineCircleName->text();

    if (!isValidRectangle(coordinates))
    {
        QMessageBox::warning(this, "Ошибка", "Точки не формируют прямоугольник!");
        return;
    }

    accept(); // Закрываем диалог
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

// функция для отображения параметров ввода
void RectangleDialog::onRadioTypeSet()
{
    // отображение параметров для режима "По координатам"
    if (ui->radioSetCoord->isChecked())
    {
        ui->x1->setEnabled(true);
        // ui->x2->setEnabled(true);
        ui->x3->setEnabled(true);
        // ui->x4->setEnabled(true);
        ui->y1->setEnabled(true);
        // ui->y2->setEnabled(true);
        ui->y3->setEnabled(true);
        // ui->y4->setEnabled(true);

        ui->startPointX->setEnabled(false);
        ui->startPointY->setEnabled(false);
        ui->width->setEnabled(false);
        ui->height->setEnabled(false);
    }
    // отображение параметров для режима "По начальной точке и размерам"
    else if (ui->radioSetSides->isChecked())
    {
        ui->x1->setEnabled(false);
        // ui->x2->setEnabled(false);
        ui->x3->setEnabled(false);
        // ui->x4->setEnabled(false);
        ui->y1->setEnabled(false);
        // ui->y2->setEnabled(false);
        ui->y3->setEnabled(false);
        // ui->y4->setEnabled(false);

        ui->startPointX->setEnabled(true);
        ui->startPointY->setEnabled(true);
        ui->width->setEnabled(true);
        ui->height->setEnabled(true);
    }
}

// Проверяем, выбран ли режим "По координатам"
bool RectangleDialog::isCoordMode() const
{
    return ui->radioSetCoord->isChecked();
}

// Проверяем, выбран ли режим "По начальной точке и размерам"
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
