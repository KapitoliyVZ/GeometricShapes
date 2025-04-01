/********************************************************************************
** Form generated from reading UI file 'CircleDialog.ui'
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CircleDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *xCenter;
    QSpinBox *yCenter;
    QPushButton *applyButton;
    QPushButton *cancelButton;
    QSpinBox *radius;
    QLineEdit *LineCircleName;

    void setupUi(QDialog *CircleDialog)
    {
        if (CircleDialog->objectName().isEmpty())
            CircleDialog->setObjectName("CircleDialog");
        CircleDialog->resize(265, 171);
        gridLayoutWidget = new QWidget(CircleDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 247, 152));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        xCenter = new QSpinBox(gridLayoutWidget);
        xCenter->setObjectName("xCenter");
        xCenter->setMinimum(-500);
        xCenter->setMaximum(500);

        gridLayout->addWidget(xCenter, 1, 0, 1, 1);

        yCenter = new QSpinBox(gridLayoutWidget);
        yCenter->setObjectName("yCenter");
        yCenter->setMinimum(-500);
        yCenter->setMaximum(500);

        gridLayout->addWidget(yCenter, 1, 1, 1, 1);

        applyButton = new QPushButton(gridLayoutWidget);
        applyButton->setObjectName("applyButton");

        gridLayout->addWidget(applyButton, 4, 1, 1, 1);

        cancelButton = new QPushButton(gridLayoutWidget);
        cancelButton->setObjectName("cancelButton");

        gridLayout->addWidget(cancelButton, 4, 0, 1, 1);

        radius = new QSpinBox(gridLayoutWidget);
        radius->setObjectName("radius");
        radius->setMinimum(1);
        radius->setMaximum(200);

        gridLayout->addWidget(radius, 2, 0, 1, 2);

        LineCircleName = new QLineEdit(gridLayoutWidget);
        LineCircleName->setObjectName("LineCircleName");

        gridLayout->addWidget(LineCircleName, 0, 0, 1, 2);


        retranslateUi(CircleDialog);

        applyButton->setDefault(true);


        QMetaObject::connectSlotsByName(CircleDialog);
    } // setupUi

    void retranslateUi(QDialog *CircleDialog)
    {
        CircleDialog->setWindowTitle(QCoreApplication::translate("CircleDialog", "Create circle", nullptr));
        xCenter->setPrefix(QCoreApplication::translate("CircleDialog", "x = ", nullptr));
        yCenter->setPrefix(QCoreApplication::translate("CircleDialog", "y = ", nullptr));
        applyButton->setText(QCoreApplication::translate("CircleDialog", "Apply", nullptr));
        cancelButton->setText(QCoreApplication::translate("CircleDialog", "Cancel", nullptr));
        radius->setPrefix(QCoreApplication::translate("CircleDialog", "r = ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CircleDialog: public Ui_CircleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCLEDIALOG_H
