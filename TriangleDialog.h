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
<<<<<<< Updated upstream
    void on_cancelButton_clicked();

    void on_applyButton_clicked();

private:
    Ui::TriangleDialog *ui;
    QList<QPointF> coordinates;
=======
    void on_cancelButton_clicked(); // отменить ввод параметров
    void on_applyButton_clicked();  // применить параметры

private:
    Ui::TriangleDialog *ui;
    QList<QPointF> coordinates; // заданные координаты
    QString nameByUser;           // заданное имя
>>>>>>> Stashed changes
};

#endif // TRIANGLEDIALOG_H
