/********************************************************************************
** Form generated from reading UI file 'dialogsetcircle.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETCIRCLE_H
#define UI_DIALOGSETCIRCLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSetCircle
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QSpinBox *spinBox_setX;
    QSpinBox *spinBox_setY;
    QSpinBox *spinBox_setRadius;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_setColour;

    void setupUi(QDialog *DialogSetCircle)
    {
        if (DialogSetCircle->objectName().isEmpty())
            DialogSetCircle->setObjectName("DialogSetCircle");
        DialogSetCircle->resize(271, 223);
        formLayoutWidget = new QWidget(DialogSetCircle);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 20, 176, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_setX = new QSpinBox(formLayoutWidget);
        spinBox_setX->setObjectName("spinBox_setX");
        spinBox_setX->setMinimum(-10);
        spinBox_setX->setMaximum(10);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_setX);

        spinBox_setY = new QSpinBox(formLayoutWidget);
        spinBox_setY->setObjectName("spinBox_setY");
        spinBox_setY->setMinimum(-10);
        spinBox_setY->setMaximum(10);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox_setY);

        spinBox_setRadius = new QSpinBox(formLayoutWidget);
        spinBox_setRadius->setObjectName("spinBox_setRadius");
        spinBox_setRadius->setMinimum(-10);
        spinBox_setRadius->setMaximum(10);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_setRadius);

        buttonBox = new QDialogButtonBox(formLayoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        formLayout->setWidget(4, QFormLayout::FieldRole, buttonBox);

        pushButton_setColour = new QPushButton(formLayoutWidget);
        pushButton_setColour->setObjectName("pushButton_setColour");

        formLayout->setWidget(3, QFormLayout::FieldRole, pushButton_setColour);


        retranslateUi(DialogSetCircle);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogSetCircle, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogSetCircle, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogSetCircle);
    } // setupUi

    void retranslateUi(QDialog *DialogSetCircle)
    {
        DialogSetCircle->setWindowTitle(QCoreApplication::translate("DialogSetCircle", "Dialog", nullptr));
        spinBox_setX->setPrefix(QCoreApplication::translate("DialogSetCircle", "x = ", nullptr));
        spinBox_setY->setPrefix(QCoreApplication::translate("DialogSetCircle", "y = ", nullptr));
        spinBox_setRadius->setPrefix(QCoreApplication::translate("DialogSetCircle", "r = ", nullptr));
        pushButton_setColour->setText(QCoreApplication::translate("DialogSetCircle", "Colour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSetCircle: public Ui_DialogSetCircle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETCIRCLE_H
