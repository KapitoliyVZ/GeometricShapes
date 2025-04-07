// Заголовочный файл для инициализации родительского класса Фигуры

#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem> // библиотека для графических объектов для сцены
#include <QPainter>      // библиотека для инструментов отрисовки объектов
#include <QString>
#include <QUuid>

class Shape : public QGraphicsItem
{

public:
    // Конструктор с опциональным именем
    explicit Shape(const QString &type, const QString &customName = "");
    // Виртуальный деструктор
    virtual ~Shape() = default;

    // Геттеры
    QString getName() const;
    QUuid getId() const;

    // Сеттер для имени
    void setName(const QString &newName);

    virtual QRectF boundingRect() const override = 0;                                                            // Границы объекта
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0; // Отрисовка

protected:
    QString name; // Имя фигуры
    QUuid id;     // Уникальный ID
    QColor color; // Цвет фигуры

};

#endif // SHAPE_H
