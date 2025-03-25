/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnCircle;
    QPushButton *btnRectangle;
    QPushButton *btnTriangle;
    QPushButton *btnClearScene;
    QGraphicsView *graphicsView;
    QListWidget *listWidgetShapes;
    QTabWidget *tabWidgetProperties;
    QWidget *tab_triagnle;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_triangle_x1;
    QSpinBox *spinBox_triangle_x2;
    QSpinBox *spinBox_triangle_y1;
    QSpinBox *spinBox_triangle_y2;
    QSpinBox *spinBox_triangle_x3;
    QSpinBox *spinBox_triangle_y3;
    QPushButton *pushButton_triangle_Apply;
    QPushButton *pushButton_triangle_Cancel;
    QSpinBox *spinBox_triangle_rotation;
    QWidget *tab_rectangle;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QSpinBox *spinBox_10;
    QSpinBox *spinBox_11;
    QSpinBox *spinBox_9;
    QSpinBox *spinBox_12;
    QSpinBox *spinBox_13;
    QSpinBox *spinBox_14;
    QWidget *tab_circle;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_circle_name;
    QSpinBox *spinBox_circle_XCenter;
    QSpinBox *spinBox_circle_YCenter;
    QSpinBox *spinBox_circle_radius;
    QPushButton *pushButton_circle_Apply;
    QPushButton *pushButton_circle_Cancel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1055, 639);
        MainWindow->setMouseTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnCircle = new QPushButton(centralwidget);
        btnCircle->setObjectName("btnCircle");
        btnCircle->setGeometry(QRect(20, 30, 83, 29));
        btnRectangle = new QPushButton(centralwidget);
        btnRectangle->setObjectName("btnRectangle");
        btnRectangle->setGeometry(QRect(20, 70, 83, 29));
        btnTriangle = new QPushButton(centralwidget);
        btnTriangle->setObjectName("btnTriangle");
        btnTriangle->setGeometry(QRect(20, 110, 83, 29));
        btnClearScene = new QPushButton(centralwidget);
        btnClearScene->setObjectName("btnClearScene");
        btnClearScene->setGeometry(QRect(330, 30, 131, 21));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(520, 40, 500, 500));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        graphicsView->setInteractive(true);
        listWidgetShapes = new QListWidget(centralwidget);
        listWidgetShapes->setObjectName("listWidgetShapes");
        listWidgetShapes->setGeometry(QRect(20, 190, 151, 271));
        tabWidgetProperties = new QTabWidget(centralwidget);
        tabWidgetProperties->setObjectName("tabWidgetProperties");
        tabWidgetProperties->setGeometry(QRect(200, 180, 281, 291));
        tab_triagnle = new QWidget();
        tab_triagnle->setObjectName("tab_triagnle");
        gridLayoutWidget = new QWidget(tab_triagnle);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(29, 30, 191, 122));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_triangle_x1 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_x1->setObjectName("spinBox_triangle_x1");

        gridLayout->addWidget(spinBox_triangle_x1, 0, 0, 1, 1);

        spinBox_triangle_x2 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_x2->setObjectName("spinBox_triangle_x2");

        gridLayout->addWidget(spinBox_triangle_x2, 1, 0, 1, 1);

        spinBox_triangle_y1 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_y1->setObjectName("spinBox_triangle_y1");

        gridLayout->addWidget(spinBox_triangle_y1, 0, 1, 1, 1);

        spinBox_triangle_y2 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_y2->setObjectName("spinBox_triangle_y2");

        gridLayout->addWidget(spinBox_triangle_y2, 1, 1, 1, 1);

        spinBox_triangle_x3 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_x3->setObjectName("spinBox_triangle_x3");

        gridLayout->addWidget(spinBox_triangle_x3, 2, 0, 1, 1);

        spinBox_triangle_y3 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_y3->setObjectName("spinBox_triangle_y3");

        gridLayout->addWidget(spinBox_triangle_y3, 2, 1, 1, 1);

        pushButton_triangle_Apply = new QPushButton(tab_triagnle);
        pushButton_triangle_Apply->setObjectName("pushButton_triangle_Apply");
        pushButton_triangle_Apply->setGeometry(QRect(140, 160, 91, 24));
        pushButton_triangle_Cancel = new QPushButton(tab_triagnle);
        pushButton_triangle_Cancel->setObjectName("pushButton_triangle_Cancel");
        pushButton_triangle_Cancel->setGeometry(QRect(30, 160, 91, 24));
        spinBox_triangle_rotation = new QSpinBox(tab_triagnle);
        spinBox_triangle_rotation->setObjectName("spinBox_triangle_rotation");
        spinBox_triangle_rotation->setGeometry(QRect(40, 190, 151, 29));
        spinBox_triangle_rotation->setMaximum(360);
        tabWidgetProperties->addTab(tab_triagnle, QString());
        tab_rectangle = new QWidget();
        tab_rectangle->setObjectName("tab_rectangle");
        gridLayoutWidget_2 = new QWidget(tab_rectangle);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(40, 30, 160, 123));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox_7 = new QSpinBox(gridLayoutWidget_2);
        spinBox_7->setObjectName("spinBox_7");

        gridLayout_2->addWidget(spinBox_7, 1, 1, 1, 1);

        spinBox_8 = new QSpinBox(gridLayoutWidget_2);
        spinBox_8->setObjectName("spinBox_8");

        gridLayout_2->addWidget(spinBox_8, 1, 0, 1, 1);

        spinBox_10 = new QSpinBox(gridLayoutWidget_2);
        spinBox_10->setObjectName("spinBox_10");

        gridLayout_2->addWidget(spinBox_10, 0, 1, 1, 1);

        spinBox_11 = new QSpinBox(gridLayoutWidget_2);
        spinBox_11->setObjectName("spinBox_11");

        gridLayout_2->addWidget(spinBox_11, 2, 0, 1, 1);

        spinBox_9 = new QSpinBox(gridLayoutWidget_2);
        spinBox_9->setObjectName("spinBox_9");

        gridLayout_2->addWidget(spinBox_9, 0, 0, 1, 1);

        spinBox_12 = new QSpinBox(gridLayoutWidget_2);
        spinBox_12->setObjectName("spinBox_12");

        gridLayout_2->addWidget(spinBox_12, 2, 1, 1, 1);

        spinBox_13 = new QSpinBox(gridLayoutWidget_2);
        spinBox_13->setObjectName("spinBox_13");

        gridLayout_2->addWidget(spinBox_13, 3, 0, 1, 1);

        spinBox_14 = new QSpinBox(gridLayoutWidget_2);
        spinBox_14->setObjectName("spinBox_14");

        gridLayout_2->addWidget(spinBox_14, 3, 1, 1, 1);

        tabWidgetProperties->addTab(tab_rectangle, QString());
        tab_circle = new QWidget();
        tab_circle->setObjectName("tab_circle");
        verticalLayoutWidget = new QWidget(tab_circle);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 8, 261, 184));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_circle_name = new QLineEdit(verticalLayoutWidget);
        lineEdit_circle_name->setObjectName("lineEdit_circle_name");

        verticalLayout->addWidget(lineEdit_circle_name);

        spinBox_circle_XCenter = new QSpinBox(verticalLayoutWidget);
        spinBox_circle_XCenter->setObjectName("spinBox_circle_XCenter");

        verticalLayout->addWidget(spinBox_circle_XCenter);

        spinBox_circle_YCenter = new QSpinBox(verticalLayoutWidget);
        spinBox_circle_YCenter->setObjectName("spinBox_circle_YCenter");

        verticalLayout->addWidget(spinBox_circle_YCenter);

        spinBox_circle_radius = new QSpinBox(verticalLayoutWidget);
        spinBox_circle_radius->setObjectName("spinBox_circle_radius");
        spinBox_circle_radius->setMinimum(1);
        spinBox_circle_radius->setMaximum(500);

        verticalLayout->addWidget(spinBox_circle_radius);

        pushButton_circle_Apply = new QPushButton(tab_circle);
        pushButton_circle_Apply->setObjectName("pushButton_circle_Apply");
        pushButton_circle_Apply->setGeometry(QRect(140, 190, 131, 24));
        pushButton_circle_Cancel = new QPushButton(tab_circle);
        pushButton_circle_Cancel->setObjectName("pushButton_circle_Cancel");
        pushButton_circle_Cancel->setGeometry(QRect(10, 190, 131, 24));
        tabWidgetProperties->addTab(tab_circle, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1055, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidgetProperties->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        btnCircle->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Set parametrs and create circle</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        btnCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        btnRectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        btnTriangle->setText(QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        btnClearScene->setText(QCoreApplication::translate("MainWindow", "Clear all shapes", nullptr));
        spinBox_triangle_x1->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        spinBox_triangle_x2->setPrefix(QCoreApplication::translate("MainWindow", "x2 = ", nullptr));
        spinBox_triangle_y1->setPrefix(QCoreApplication::translate("MainWindow", "y1 = ", nullptr));
        spinBox_triangle_y2->setPrefix(QCoreApplication::translate("MainWindow", "y2 = ", nullptr));
        spinBox_triangle_x3->setPrefix(QCoreApplication::translate("MainWindow", "x3 = ", nullptr));
        spinBox_triangle_y3->setPrefix(QCoreApplication::translate("MainWindow", "y3 = ", nullptr));
        pushButton_triangle_Apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pushButton_triangle_Cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        spinBox_triangle_rotation->setPrefix(QCoreApplication::translate("MainWindow", "rotation = ", nullptr));
        tabWidgetProperties->setTabText(tabWidgetProperties->indexOf(tab_triagnle), QCoreApplication::translate("MainWindow", "triangle", nullptr));
        tabWidgetProperties->setTabText(tabWidgetProperties->indexOf(tab_rectangle), QCoreApplication::translate("MainWindow", "rectangle", nullptr));
        lineEdit_circle_name->setText(QString());
        spinBox_circle_XCenter->setPrefix(QCoreApplication::translate("MainWindow", "Center(X) = ", nullptr));
        spinBox_circle_YCenter->setPrefix(QCoreApplication::translate("MainWindow", "Center(Y) = ", nullptr));
        spinBox_circle_radius->setPrefix(QCoreApplication::translate("MainWindow", "radius = ", nullptr));
        pushButton_circle_Apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pushButton_circle_Cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        tabWidgetProperties->setTabText(tabWidgetProperties->indexOf(tab_circle), QCoreApplication::translate("MainWindow", "circle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
