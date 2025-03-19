/********************************************************************************
** Form generated from reading UI file 'RectangleDialog.ui'
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RectangleDialog
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QSpinBox *y1;
    QRadioButton *radioSetSides;
    QSpinBox *y3;
    QPushButton *applyButton;
    QSpinBox *x1;
    QPushButton *cancelButton;
    QLineEdit *LineCircleName;
    QSpinBox *y4;
    QSpinBox *x3;
    QSpinBox *startPointY;
    QSpinBox *x4;
    QSpinBox *width;
    QSpinBox *y2;
    QSpinBox *startPointX;
    QSpinBox *height;
    QSpinBox *x2;
    QRadioButton *radioSetCoord;

    void setupUi(QDialog *RectangleDialog)
    {
        if (RectangleDialog->objectName().isEmpty())
            RectangleDialog->setObjectName("RectangleDialog");
        RectangleDialog->resize(656, 414);
        gridLayoutWidget_2 = new QWidget(RectangleDialog);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(170, 90, 331, 245));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        y1 = new QSpinBox(gridLayoutWidget_2);
        y1->setObjectName("y1");
        y1->setMinimum(-500);
        y1->setMaximum(500);
        y1->setValue(10);

        gridLayout_2->addWidget(y1, 3, 1, 1, 1);

        radioSetSides = new QRadioButton(gridLayoutWidget_2);
        radioSetSides->setObjectName("radioSetSides");

        gridLayout_2->addWidget(radioSetSides, 1, 2, 1, 1);

        y3 = new QSpinBox(gridLayoutWidget_2);
        y3->setObjectName("y3");
        y3->setMinimum(-500);
        y3->setMaximum(500);
        y3->setValue(30);

        gridLayout_2->addWidget(y3, 6, 1, 1, 1);

        applyButton = new QPushButton(gridLayoutWidget_2);
        applyButton->setObjectName("applyButton");

        gridLayout_2->addWidget(applyButton, 9, 2, 1, 1);

        x1 = new QSpinBox(gridLayoutWidget_2);
        x1->setObjectName("x1");
        x1->setMinimum(-500);
        x1->setMaximum(500);
        x1->setValue(10);

        gridLayout_2->addWidget(x1, 3, 0, 1, 1);

        cancelButton = new QPushButton(gridLayoutWidget_2);
        cancelButton->setObjectName("cancelButton");

        gridLayout_2->addWidget(cancelButton, 9, 0, 1, 1);

        LineCircleName = new QLineEdit(gridLayoutWidget_2);
        LineCircleName->setObjectName("LineCircleName");

        gridLayout_2->addWidget(LineCircleName, 0, 0, 1, 3);

        y4 = new QSpinBox(gridLayoutWidget_2);
        y4->setObjectName("y4");
        y4->setMinimum(-500);
        y4->setMaximum(500);
        y4->setValue(30);

        gridLayout_2->addWidget(y4, 7, 1, 1, 1);

        x3 = new QSpinBox(gridLayoutWidget_2);
        x3->setObjectName("x3");
        x3->setMinimum(-500);
        x3->setMaximum(500);
        x3->setValue(40);

        gridLayout_2->addWidget(x3, 6, 0, 1, 1);

        startPointY = new QSpinBox(gridLayoutWidget_2);
        startPointY->setObjectName("startPointY");
        startPointY->setMaximum(500);
        startPointY->setValue(0);

        gridLayout_2->addWidget(startPointY, 5, 2, 1, 1);

        x4 = new QSpinBox(gridLayoutWidget_2);
        x4->setObjectName("x4");
        x4->setMinimum(-500);
        x4->setMaximum(500);
        x4->setValue(10);

        gridLayout_2->addWidget(x4, 7, 0, 1, 1);

        width = new QSpinBox(gridLayoutWidget_2);
        width->setObjectName("width");
        width->setMaximum(500);

        gridLayout_2->addWidget(width, 6, 2, 1, 1);

        y2 = new QSpinBox(gridLayoutWidget_2);
        y2->setObjectName("y2");
        y2->setMinimum(-500);
        y2->setMaximum(500);
        y2->setValue(10);

        gridLayout_2->addWidget(y2, 5, 1, 1, 1);

        startPointX = new QSpinBox(gridLayoutWidget_2);
        startPointX->setObjectName("startPointX");
        startPointX->setMinimum(-500);
        startPointX->setMaximum(500);

        gridLayout_2->addWidget(startPointX, 3, 2, 1, 1);

        height = new QSpinBox(gridLayoutWidget_2);
        height->setObjectName("height");
        height->setMaximum(500);

        gridLayout_2->addWidget(height, 7, 2, 1, 1);

        x2 = new QSpinBox(gridLayoutWidget_2);
        x2->setObjectName("x2");
        x2->setMinimum(-500);
        x2->setMaximum(500);
        x2->setValue(40);

        gridLayout_2->addWidget(x2, 5, 0, 1, 1);

        radioSetCoord = new QRadioButton(gridLayoutWidget_2);
        radioSetCoord->setObjectName("radioSetCoord");

        gridLayout_2->addWidget(radioSetCoord, 1, 0, 1, 1);


        retranslateUi(RectangleDialog);

        QMetaObject::connectSlotsByName(RectangleDialog);
    } // setupUi

    void retranslateUi(QDialog *RectangleDialog)
    {
        RectangleDialog->setWindowTitle(QCoreApplication::translate("RectangleDialog", "Dialog", nullptr));
        y1->setPrefix(QCoreApplication::translate("RectangleDialog", "y1 =", nullptr));
        radioSetSides->setText(QCoreApplication::translate("RectangleDialog", "to set sides", nullptr));
        y3->setPrefix(QCoreApplication::translate("RectangleDialog", "y3 = ", nullptr));
        applyButton->setText(QCoreApplication::translate("RectangleDialog", "Apply", nullptr));
        x1->setPrefix(QCoreApplication::translate("RectangleDialog", "x1 = ", nullptr));
        cancelButton->setText(QCoreApplication::translate("RectangleDialog", "Cancel", nullptr));
        y4->setPrefix(QCoreApplication::translate("RectangleDialog", "y4 = ", nullptr));
        x3->setPrefix(QCoreApplication::translate("RectangleDialog", "x3 = ", nullptr));
        startPointY->setPrefix(QCoreApplication::translate("RectangleDialog", "y0 = ", nullptr));
        x4->setPrefix(QCoreApplication::translate("RectangleDialog", "x4 =", nullptr));
        width->setPrefix(QCoreApplication::translate("RectangleDialog", "width = ", nullptr));
        y2->setPrefix(QCoreApplication::translate("RectangleDialog", "y2 = ", nullptr));
        startPointX->setPrefix(QCoreApplication::translate("RectangleDialog", "x0 = ", nullptr));
        height->setPrefix(QCoreApplication::translate("RectangleDialog", "height = ", nullptr));
        x2->setPrefix(QCoreApplication::translate("RectangleDialog", "x2 =", nullptr));
        radioSetCoord->setText(QCoreApplication::translate("RectangleDialog", "to set coordinates", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RectangleDialog: public Ui_RectangleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTANGLEDIALOG_H
