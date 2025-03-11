#ifndef CIRCLEDIALOG_H
#define CIRCLEDIALOG_H

#include <QDialog>

namespace Ui {
class CircleDialog;
}

class CircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CircleDialog(QWidget *parent = nullptr);
    ~CircleDialog();

    QPointF getCenter() const;
    double getRadius() const;

private slots:
    void on_applyButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CircleDialog *ui;
    QPointF center;
    double radius;
};

#endif // CIRCLEDIALOG_H
