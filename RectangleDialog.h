// Заголовочный файл для инициализации диалогового окна задания параметров для прямоугольника

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
<<<<<<< Updated upstream
    bool isValidRectangle(const QList<QPointF> &coords); // проверка валидности значений координат
    void on_cancelButton_clicked(); // отменить ввод параметров
    void on_applyButton_clicked(); // Применить параметры
=======
    bool isValidRectangle(const QList<QPointF> &coords);    // проверка валидности значений координат

    void on_cancelButton_clicked();                         // Отменить ввод параметров
    void on_applyButton_clicked();                          // Применить параметры

    void onRadioTypeSet();                                  // функция для отображения вида параметров ввода
>>>>>>> Stashed changes

private:
    Ui::RectangleDialog *ui;
    QList<QPointF> coordinates;
};

#endif // RECTANGLEDIALOG_H
