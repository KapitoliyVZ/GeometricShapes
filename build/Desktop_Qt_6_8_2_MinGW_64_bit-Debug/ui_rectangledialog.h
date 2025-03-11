/********************************************************************************
** Form generated from reading UI file 'rectangledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTANGLEDIALOG_H
#define UI_RECTANGLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RectangleDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *y2;
    QSpinBox *x2;
    QSpinBox *y1;
    QSpinBox *x3;
    QSpinBox *y3;
    QSpinBox *x4;
    QSpinBox *y4;
    QSpinBox *x1;
    QPushButton *applyButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *RectangleDialog)
    {
        if (RectangleDialog->objectName().isEmpty())
            RectangleDialog->setObjectName("RectangleDialog");
        RectangleDialog->resize(322, 213);
        gridLayoutWidget = new QWidget(RectangleDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 301, 191));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        y2 = new QSpinBox(gridLayoutWidget);
        y2->setObjectName("y2");
        y2->setMinimum(-500);
        y2->setMaximum(500);

        gridLayout->addWidget(y2, 1, 1, 1, 1);

        x2 = new QSpinBox(gridLayoutWidget);
        x2->setObjectName("x2");
        x2->setMinimum(-500);
        x2->setMaximum(500);

        gridLayout->addWidget(x2, 1, 0, 1, 1);

        y1 = new QSpinBox(gridLayoutWidget);
        y1->setObjectName("y1");
        y1->setMinimum(-500);
        y1->setMaximum(500);

        gridLayout->addWidget(y1, 0, 1, 1, 1);

        x3 = new QSpinBox(gridLayoutWidget);
        x3->setObjectName("x3");
        x3->setMinimum(-500);
        x3->setMaximum(500);

        gridLayout->addWidget(x3, 2, 0, 1, 1);

        y3 = new QSpinBox(gridLayoutWidget);
        y3->setObjectName("y3");
        y3->setMinimum(-500);
        y3->setMaximum(500);

        gridLayout->addWidget(y3, 2, 1, 1, 1);

        x4 = new QSpinBox(gridLayoutWidget);
        x4->setObjectName("x4");
        x4->setMinimum(-500);
        x4->setMaximum(500);

        gridLayout->addWidget(x4, 3, 0, 1, 1);

        y4 = new QSpinBox(gridLayoutWidget);
        y4->setObjectName("y4");
        y4->setMinimum(-500);
        y4->setMaximum(500);

        gridLayout->addWidget(y4, 3, 1, 1, 1);

        x1 = new QSpinBox(gridLayoutWidget);
        x1->setObjectName("x1");
        x1->setMinimum(-500);
        x1->setMaximum(500);

        gridLayout->addWidget(x1, 0, 0, 1, 1);

        applyButton = new QPushButton(gridLayoutWidget);
        applyButton->setObjectName("applyButton");

        gridLayout->addWidget(applyButton, 4, 1, 1, 1);

        cancelButton = new QPushButton(gridLayoutWidget);
        cancelButton->setObjectName("cancelButton");

        gridLayout->addWidget(cancelButton, 4, 0, 1, 1);


        retranslateUi(RectangleDialog);

        QMetaObject::connectSlotsByName(RectangleDialog);
    } // setupUi

    void retranslateUi(QDialog *RectangleDialog)
    {
        RectangleDialog->setWindowTitle(QCoreApplication::translate("RectangleDialog", "Dialog", nullptr));
        y2->setPrefix(QCoreApplication::translate("RectangleDialog", "y2 = ", nullptr));
        x2->setPrefix(QCoreApplication::translate("RectangleDialog", "x2 =", nullptr));
        y1->setPrefix(QCoreApplication::translate("RectangleDialog", "y1 =", nullptr));
        x3->setPrefix(QCoreApplication::translate("RectangleDialog", "x3 = ", nullptr));
        y3->setPrefix(QCoreApplication::translate("RectangleDialog", "y3 = ", nullptr));
        x4->setPrefix(QCoreApplication::translate("RectangleDialog", "x4 =", nullptr));
        y4->setPrefix(QCoreApplication::translate("RectangleDialog", "y4 = ", nullptr));
        x1->setPrefix(QCoreApplication::translate("RectangleDialog", "x1 = ", nullptr));
        applyButton->setText(QCoreApplication::translate("RectangleDialog", "Apply", nullptr));
        cancelButton->setText(QCoreApplication::translate("RectangleDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RectangleDialog: public Ui_RectangleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTANGLEDIALOG_H
