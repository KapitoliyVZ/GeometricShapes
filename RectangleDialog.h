// Заголовочный файл для инициализации диалогового окна задания параметров для прямоугольника

#ifndef RECTANGLEDIALOG_H
#define RECTANGLEDIALOG_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui
{
    class RectangleDialog;
}

class RectangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RectangleDialog(QWidget *parent = nullptr);
    ~RectangleDialog();

    // Получаем координаты от пользователя
    QList<QPointF> getCoordinates() const; // Возвращает 4 координаты

    QString getRectangleName() const; // Возвращает имя

    QPointF getStartPoint() const; // Возвращает начальную точку
    double getWidth() const;       // Возвращает ширину
    double getHeight() const;      // Возвращает высоту

    bool isCoordMode() const; // Возвращает true, если выбран режим "По координатам"
    bool isSizeMode() const;  // Возвращает true, если выбран режим "По начальной точке и размерам"

private slots:
    bool isValidRectangle(const QList<QPointF> &coords); // проверка валидности значений координат
    void on_cancelButton_clicked();                      // Отменить ввод параметров
    void on_applyButton_clicked();                       // Применить параметры
    void onRadioTypeSet();                               // функция для отображения параметров ввода

private:
    Ui::RectangleDialog *ui;

    QList<QPointF> coordinates; // заданные координаты
    QString nameUser;           // заданное имя

    QButtonGroup *shapeModeGroup; // Группа для радиокнопок
};

#endif // RECTANGLEDIALOG_H
