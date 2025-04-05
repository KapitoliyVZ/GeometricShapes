// Заголовочный файл для инициализации диалогового окна задания параметров для круга

#ifndef CIRCLEDIALOG_H
#define CIRCLEDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui
{
    class CircleDialog;
}

class CircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CircleDialog(QWidget *parent = nullptr);
    ~CircleDialog();

    QPointF getCenter() const;
    double getRadius() const;
    QString getCircleName() const;

private slots:
    void on_applyButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CircleDialog *ui;

    QPointF center;     // заданные координаты центра
    double radius;      // заданный радиус
    QString nameByUser; // заданное имя
};

#endif // CIRCLEDIALOG_H
