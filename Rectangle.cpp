#include "Rectangle.h"

// Конструктор-1 с четырьмя координатами
RectangleShape::RectangleShape(const QList<QPointF> &coords, const QString &customName)
    : Shape("Rectangle", customName)
{
    if (coords.size() == 4)
    {
        polygon = QPolygonF(coords);
        setPos(0, 0); // Устанавливаем начальную позицию
    }
    setAcceptHoverEvents(true); // для изменения курсора при наведении
}

// Конструктор-2 с начальной точкой и размерами
RectangleShape::RectangleShape(const QPointF &startPoint, double width, double height, const QString &customName)
    : Shape("Rectangle", customName)
{
    polygon = QRectF(startPoint.x(), startPoint.y(), width, height); // Прямоугольник по начальной точке и размерам
}

// Функция определяет границы объекта
QRectF RectangleShape::boundingRect() const
{
    return polygon.boundingRect();
}

// Функция отрисовки прямоугольника
void RectangleShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (polygon.isEmpty())
        return;

    // Если фигура выделена
    if (isSelected())
        painter->setPen(Qt::red); // цвет контура - красный
    else
        painter->setPen(Qt::gray); // цвет контура - черный

    painter->drawPolygon(polygon); // прорисовка фигуры
}

// получение текущих координат
QVector<QPointF> RectangleShape::getPoints() const
{
    return polygon.toVector();
}

// задать новые координаты
void RectangleShape::setNewPoints(const QVector<QPointF> &newPoints)
{
    if (newPoints.size() == 4)
    {
        polygon = QPolygonF(newPoints); // Обновляем координаты
        update();                       // Перерисовка треугольник
    }
}

// задать угол вращения
void RectangleShape::setRotationAngle(int angle)
{
    QPointF center = polygon.boundingRect().center(); // Вычисляем центр прямоугольника
    setTransformOriginPoint(center);                  // Устанавливаем центр вращения
    setRotation(angle);                               // Задаём угол
    update();                                         // Перерисовка прямоугольника
}

// получить текущий угол вращения
int RectangleShape::getRotationAngle() const
{
    return rotation(); // Возвращаем текущий угол
}
