#ifndef TRIANGLEDIALOG_H
#define TRIANGLEDIALOG_H

#include <QDialog>
#include <QString>

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
    QString getTriangleName() const;

private slots:
    void on_cancelButton_clicked();
    void on_applyButton_clicked();

private:
    Ui::TriangleDialog *ui;
    QList<QPointF> coordinates; // заданные координаты
    QString nameUser; // заданное имя
};

#endif // TRIANGLEDIALOG_H
