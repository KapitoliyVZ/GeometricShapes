/********************************************************************************
** Form generated from reading UI file 'circledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCLEDIALOG_H
#define UI_CIRCLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CircleDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *yCenter;
    QSpinBox *radius;
    QSpinBox *xCenter;
    QPushButton *cancelButton;
    QPushButton *applyButton;

    void setupUi(QDialog *CircleDialog)
    {
        if (CircleDialog->objectName().isEmpty())
            CircleDialog->setObjectName("CircleDialog");
        CircleDialog->resize(400, 300);
        gridLayoutWidget = new QWidget(CircleDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(74, 100, 281, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        yCenter = new QSpinBox(gridLayoutWidget);
        yCenter->setObjectName("yCenter");
        yCenter->setMinimum(-500);
        yCenter->setMaximum(500);

        gridLayout->addWidget(yCenter, 0, 1, 1, 1);

        radius = new QSpinBox(gridLayoutWidget);
        radius->setObjectName("radius");
        radius->setMinimum(1);
        radius->setMaximum(200);

        gridLayout->addWidget(radius, 0, 2, 1, 1);

        xCenter = new QSpinBox(gridLayoutWidget);
        xCenter->setObjectName("xCenter");
        xCenter->setMinimum(-500);
        xCenter->setMaximum(500);

        gridLayout->addWidget(xCenter, 0, 0, 1, 1);

        cancelButton = new QPushButton(gridLayoutWidget);
        cancelButton->setObjectName("cancelButton");

        gridLayout->addWidget(cancelButton, 1, 0, 1, 1);

        applyButton = new QPushButton(gridLayoutWidget);
        applyButton->setObjectName("applyButton");

        gridLayout->addWidget(applyButton, 1, 2, 1, 1);


        retranslateUi(CircleDialog);

        applyButton->setDefault(true);


        QMetaObject::connectSlotsByName(CircleDialog);
    } // setupUi

    void retranslateUi(QDialog *CircleDialog)
    {
        CircleDialog->setWindowTitle(QCoreApplication::translate("CircleDialog", "Dialog", nullptr));
        yCenter->setPrefix(QCoreApplication::translate("CircleDialog", "y = ", nullptr));
        radius->setPrefix(QCoreApplication::translate("CircleDialog", "r = ", nullptr));
        xCenter->setPrefix(QCoreApplication::translate("CircleDialog", "x = ", nullptr));
        cancelButton->setText(QCoreApplication::translate("CircleDialog", "Cancel", nullptr));
        applyButton->setText(QCoreApplication::translate("CircleDialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CircleDialog: public Ui_CircleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCLEDIALOG_H
