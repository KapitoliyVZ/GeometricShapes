#ifndef TRIANGLEDIALOG_H
#define TRIANGLEDIALOG_H

#include <QDialog>

namespace Ui {
class TriangleDialog;
}

class TriangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TriangleDialog(QWidget *parent = nullptr);
    ~TriangleDialog();

    // Получаем координаты от пользователя
    QList<QPointF> getCoordinates() const;

private slots:
    void on_cancelButton_clicked();

    void on_applyButton_clicked();

private:
    Ui::TriangleDialog *ui;
    QList<QPointF> coordinates;
};

#endif // TRIANGLEDIALOG_H
