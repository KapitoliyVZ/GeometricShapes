#ifndef DIALOGSETCIRCLE_H
#define DIALOGSETCIRCLE_H

#include <QDialog>
#include <QColor>

namespace Ui {
class DialogSetCircle;
}

class DialogSetCircle : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSetCircle(QWidget *parent = nullptr);
    ~DialogSetCircle();

    int getRadius() const; // задаем радиус
    int getX() const; // заданием X - центра
    int getY() const; // заданием Y - центра
    QColor getColor() const; // задаем цвет

private slots:
    void on_pushButton_setColour_clicked();


private:
    Ui::DialogSetCircle *ui;
    QColor selectedColor;
};

#endif // DIALOGSETCIRCLE_H
