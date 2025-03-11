#ifndef RECTANGLEDIALOG_H
#define RECTANGLEDIALOG_H

#include <QDialog>

namespace Ui {
class RectangleDialog;
}

class RectangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RectangleDialog(QWidget *parent = nullptr);
    ~RectangleDialog();

    // Получаем координаты от пользователя
    QList<QPointF> getCoordinates() const;

private slots:
    bool isValidRectangle(const QList<QPointF> &coords);
    void on_cancelButton_clicked(); // отменить ввод параметров
    void on_applyButton_clicked(); // Применить параметры

private:
    Ui::RectangleDialog *ui;
    QList<QPointF> coordinates;
};

#endif // RECTANGLEDIALOG_H
