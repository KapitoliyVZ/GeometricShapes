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

    QPointF getCenter() const;                // получить заданные координаты центра
    double getRadius() const;                 // получить заданный радиус
    QString getCircleName() const;            // получить заданное имя
    void setDefaultName(const QString &name); // Отображение сгенерированного имени фигуры

private slots:
    void on_applyButton_clicked();  // Применение изменений параметров круга
    void on_cancelButton_clicked(); // Отмена изменений параметров круга

private:
    Ui::CircleDialog *ui;

    QPointF center;     // заданные координаты центра
    double radius;      // заданный радиус
    QString nameByUser; // заданное имя
};

#endif // CIRCLEDIALOG_H
