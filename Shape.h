// Заголовочный файл для инициализации родительского класса Фигуры

#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem> // библиотека для графических объектов для сцены
#include <QPainter>      // библиотека для инструментов отрисовки объектов
#include <QString>
#include <QUuid>

// Класс Shape - родительский класс для всех фигур
// Наследуется от QGraphicsItem для интеграции с графической сценой
class Shape : public QGraphicsItem
{

public:
    // Конструктор с опциональным именем
    explicit Shape(const QString &type, const QString &customName = "");
    // Виртуальный деструктор
    virtual ~Shape() = default;

    QString getName() const;              // Геттер для имени
    void setName(const QString &newName); // Сеттер для имени

    // Виртуальная функция для определения границы объекта
    virtual QRectF boundingRect() const override = 0;      
    // Виртуальная функция для отрисовки объекта                           
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0; 

protected:
    QString name; // Имя фигуры
    QColor color; // Цвет фигуры
};

#endif // SHAPE_H
