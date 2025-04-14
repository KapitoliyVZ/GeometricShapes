#ifndef TRIANGLEDIALOG_H
#define TRIANGLEDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui
{
    class TriangleDialog;
}

class TriangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TriangleDialog(QWidget *parent = nullptr);
    ~TriangleDialog();

    QList<QPointF> getCoordinates() const; // Возвращает 3 координаты
    QString getTriangleName() const;       // Возвращает имя

    void setDefaultName(const QString &name); // Отображение сгенерированного имени фигуры

private slots:
    void on_cancelButton_clicked(); // Отменить ввод параметров
    void on_applyButton_clicked();  // Применить параметры

private:
    Ui::TriangleDialog *ui;
    QList<QPointF> coordinates; // заданные координаты
    QString nameUser;           // заданное имя
};

#endif // TRIANGLEDIALOG_H
