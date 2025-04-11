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

QT_BEGIN_NAMESPACE

class Ui_CircleDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *applyButton;
    QSpinBox *yCenter;
    QSpinBox *xCenter;
    QPushButton *cancelButton;
    QSpinBox *radius;
    QLineEdit *LineCircleName;

    void setupUi(QDialog *CircleDialog)
    {
        if (CircleDialog->objectName().isEmpty())
            CircleDialog->setObjectName("CircleDialog");
        CircleDialog->resize(308, 170);
        gridLayout_2 = new QGridLayout(CircleDialog);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        applyButton = new QPushButton(CircleDialog);
        applyButton->setObjectName("applyButton");

        gridLayout->addWidget(applyButton, 3, 1, 1, 1);

        yCenter = new QSpinBox(CircleDialog);
        yCenter->setObjectName("yCenter");
        yCenter->setMinimum(-500);
        yCenter->setMaximum(500);
        yCenter->setValue(100);

        gridLayout->addWidget(yCenter, 1, 1, 1, 1);

        xCenter = new QSpinBox(CircleDialog);
        xCenter->setObjectName("xCenter");
        xCenter->setMinimum(-500);
        xCenter->setMaximum(500);
        xCenter->setValue(100);

        gridLayout->addWidget(xCenter, 1, 0, 1, 1);

        cancelButton = new QPushButton(CircleDialog);
        cancelButton->setObjectName("cancelButton");

        gridLayout->addWidget(cancelButton, 3, 0, 1, 1);

        radius = new QSpinBox(CircleDialog);
        radius->setObjectName("radius");
        radius->setMinimum(1);
        radius->setMaximum(200);
        radius->setValue(50);

        gridLayout->addWidget(radius, 2, 0, 1, 2);

        LineCircleName = new QLineEdit(CircleDialog);
        LineCircleName->setObjectName("LineCircleName");

        gridLayout->addWidget(LineCircleName, 0, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(CircleDialog);

        applyButton->setDefault(true);


        QMetaObject::connectSlotsByName(CircleDialog);
    } // setupUi

    void retranslateUi(QDialog *CircleDialog)
    {
        CircleDialog->setWindowTitle(QCoreApplication::translate("CircleDialog", "\320\234\320\265\320\275\321\216 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \320\272\321\200\321\203\320\263\320\260", nullptr));
        applyButton->setText(QCoreApplication::translate("CircleDialog", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\272\321\200\321\203\320\263", nullptr));
        yCenter->setPrefix(QCoreApplication::translate("CircleDialog", "y = ", nullptr));
        xCenter->setPrefix(QCoreApplication::translate("CircleDialog", "x = ", nullptr));
        cancelButton->setText(QCoreApplication::translate("CircleDialog", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        radius->setPrefix(QCoreApplication::translate("CircleDialog", "r = ", nullptr));
        LineCircleName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CircleDialog: public Ui_CircleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCLEDIALOG_H
