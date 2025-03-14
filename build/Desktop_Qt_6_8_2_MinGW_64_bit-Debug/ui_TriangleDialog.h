/********************************************************************************
** Form generated from reading UI file 'TriangleDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGLEDIALOG_H
#define UI_TRIANGLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TriangleDialog
{
public:
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *x1;
    QSpinBox *y1;
    QSpinBox *y2;
    QSpinBox *x3;
    QSpinBox *y3;
    QPushButton *cancelButton;
    QPushButton *applyButton;
    QSpinBox *x2;

    void setupUi(QDialog *TriangleDialog)
    {
        if (TriangleDialog->objectName().isEmpty())
            TriangleDialog->setObjectName("TriangleDialog");
        TriangleDialog->resize(400, 300);
        formLayoutWidget = new QWidget(TriangleDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(108, 60, 169, 122));
        gridLayout = new QGridLayout(formLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        x1 = new QSpinBox(formLayoutWidget);
        x1->setObjectName("x1");
        x1->setMinimum(-500);
        x1->setMaximum(500);

        gridLayout->addWidget(x1, 0, 0, 1, 1);

        y1 = new QSpinBox(formLayoutWidget);
        y1->setObjectName("y1");
        y1->setMinimum(-500);
        y1->setMaximum(500);
        y1->setValue(100);

        gridLayout->addWidget(y1, 0, 1, 1, 1);

        y2 = new QSpinBox(formLayoutWidget);
        y2->setObjectName("y2");
        y2->setMinimum(-500);
        y2->setMaximum(500);

        gridLayout->addWidget(y2, 1, 1, 1, 1);

        x3 = new QSpinBox(formLayoutWidget);
        x3->setObjectName("x3");
        x3->setMinimum(-500);
        x3->setMaximum(500);
        x3->setValue(100);

        gridLayout->addWidget(x3, 2, 0, 1, 1);

        y3 = new QSpinBox(formLayoutWidget);
        y3->setObjectName("y3");
        y3->setMinimum(-500);
        y3->setMaximum(500);
        y3->setValue(0);

        gridLayout->addWidget(y3, 2, 1, 1, 1);

        cancelButton = new QPushButton(formLayoutWidget);
        cancelButton->setObjectName("cancelButton");

        gridLayout->addWidget(cancelButton, 3, 0, 1, 1);

        applyButton = new QPushButton(formLayoutWidget);
        applyButton->setObjectName("applyButton");

        gridLayout->addWidget(applyButton, 3, 1, 1, 1);

        x2 = new QSpinBox(formLayoutWidget);
        x2->setObjectName("x2");
        x2->setMinimum(-500);
        x2->setMaximum(500);
        x2->setValue(-100);

        gridLayout->addWidget(x2, 1, 0, 1, 1);


        retranslateUi(TriangleDialog);

        QMetaObject::connectSlotsByName(TriangleDialog);
    } // setupUi

    void retranslateUi(QDialog *TriangleDialog)
    {
        TriangleDialog->setWindowTitle(QCoreApplication::translate("TriangleDialog", "Dialog", nullptr));
        x1->setPrefix(QCoreApplication::translate("TriangleDialog", "x1 = ", nullptr));
        y1->setPrefix(QCoreApplication::translate("TriangleDialog", "y1 = ", nullptr));
        y2->setPrefix(QCoreApplication::translate("TriangleDialog", "y2 = ", nullptr));
        x3->setPrefix(QCoreApplication::translate("TriangleDialog", "x3 = ", nullptr));
        y3->setPrefix(QCoreApplication::translate("TriangleDialog", "y3 = ", nullptr));
        cancelButton->setText(QCoreApplication::translate("TriangleDialog", "Cancel", nullptr));
        applyButton->setText(QCoreApplication::translate("TriangleDialog", "Apply", nullptr));
        x2->setPrefix(QCoreApplication::translate("TriangleDialog", "x2 = ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TriangleDialog: public Ui_TriangleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGLEDIALOG_H
