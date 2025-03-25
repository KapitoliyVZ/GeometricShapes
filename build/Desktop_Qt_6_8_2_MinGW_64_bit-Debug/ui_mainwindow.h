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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QSpinBox *spinBox_triangle_rotation;
    QSpinBox *spinBox_triangle_x3;
    QSpinBox *spinBox_triangle_x2;
    QSpinBox *spinBox_triangle_y2;
    QPushButton *pushButton_triangle_Cancel;
    QPushButton *pushButton_triangle_Apply;
    QSpinBox *spinBox_triangle_y3;
    QSpinBox *spinBox_triangle_y1;
    QPushButton *pushButton_triangle_Delete;
    QWidget *tab_rectangle;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBox_rectangle_y1;
    QSpinBox *spinBox_rectangle_y2;
    QSpinBox *spinBox_rectangle_x1;
    QSpinBox *spinBox_rectangle_y3;
    QPushButton *pushButton_rectangle_Delete;
    QSpinBox *spinBox_rectangle_x4;
    QSpinBox *spinBox_rectangle_x2;
    QPushButton *pushButton_rectangle_Apply;
    QSpinBox *spinBox_rectangle_y4;
    QSpinBox *spinBox_rectangle_x3;
    QPushButton *pushButton_rectangle_Cancel;
    QSpinBox *spinBox_rectangle_rotation;
    QWidget *tab_circle;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBox_circle_YCenter;
    QPushButton *pushButton_circle_Cancel;
    QSpinBox *spinBox_circle_XCenter;
    QPushButton *pushButton_circle_Apply;
    QSpinBox *spinBox_circle_radius;
    QPushButton *pushButton_circle_Delete;
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
        listWidgetShapes->setGeometry(QRect(20, 190, 151, 311));
        tabWidgetProperties = new QTabWidget(centralwidget);
        tabWidgetProperties->setObjectName("tabWidgetProperties");
        tabWidgetProperties->setGeometry(QRect(190, 180, 311, 331));
        tab_triagnle = new QWidget();
        tab_triagnle->setObjectName("tab_triagnle");
        gridLayoutWidget = new QWidget(tab_triagnle);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(9, 10, 291, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_triangle_x1 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_x1->setObjectName("spinBox_triangle_x1");
        spinBox_triangle_x1->setMinimum(-500);
        spinBox_triangle_x1->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_x1, 1, 0, 1, 1);

        spinBox_triangle_rotation = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_rotation->setObjectName("spinBox_triangle_rotation");
        spinBox_triangle_rotation->setMaximum(360);

        gridLayout->addWidget(spinBox_triangle_rotation, 4, 0, 1, 2);

        spinBox_triangle_x3 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_x3->setObjectName("spinBox_triangle_x3");
        spinBox_triangle_x3->setMinimum(-500);
        spinBox_triangle_x3->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_x3, 3, 0, 1, 1);

        spinBox_triangle_x2 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_x2->setObjectName("spinBox_triangle_x2");
        spinBox_triangle_x2->setMinimum(-500);
        spinBox_triangle_x2->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_x2, 2, 0, 1, 1);

        spinBox_triangle_y2 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_y2->setObjectName("spinBox_triangle_y2");
        spinBox_triangle_y2->setMinimum(-500);
        spinBox_triangle_y2->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_y2, 2, 1, 1, 1);

        pushButton_triangle_Cancel = new QPushButton(gridLayoutWidget);
        pushButton_triangle_Cancel->setObjectName("pushButton_triangle_Cancel");

        gridLayout->addWidget(pushButton_triangle_Cancel, 5, 0, 1, 1);

        pushButton_triangle_Apply = new QPushButton(gridLayoutWidget);
        pushButton_triangle_Apply->setObjectName("pushButton_triangle_Apply");

        gridLayout->addWidget(pushButton_triangle_Apply, 5, 1, 1, 1);

        spinBox_triangle_y3 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_y3->setObjectName("spinBox_triangle_y3");
        spinBox_triangle_y3->setMinimum(-500);
        spinBox_triangle_y3->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_y3, 3, 1, 1, 1);

        spinBox_triangle_y1 = new QSpinBox(gridLayoutWidget);
        spinBox_triangle_y1->setObjectName("spinBox_triangle_y1");
        spinBox_triangle_y1->setMinimum(-500);
        spinBox_triangle_y1->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_y1, 1, 1, 1, 1);

        pushButton_triangle_Delete = new QPushButton(gridLayoutWidget);
        pushButton_triangle_Delete->setObjectName("pushButton_triangle_Delete");
        pushButton_triangle_Delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: black;\n"
"}\n"
""));
        pushButton_triangle_Delete->setAutoRepeat(false);

        gridLayout->addWidget(pushButton_triangle_Delete, 6, 0, 1, 2);

        tabWidgetProperties->addTab(tab_triagnle, QString());
        tab_rectangle = new QWidget();
        tab_rectangle->setObjectName("tab_rectangle");
        gridLayoutWidget_2 = new QWidget(tab_rectangle);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 291, 281));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox_rectangle_y1 = new QSpinBox(gridLayoutWidget_2);
        spinBox_rectangle_y1->setObjectName("spinBox_rectangle_y1");
        spinBox_rectangle_y1->setMinimum(-500);
        spinBox_rectangle_y1->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_y1, 0, 1, 1, 1);

        spinBox_rectangle_y2 = new QSpinBox(gridLayoutWidget_2);
        spinBox_rectangle_y2->setObjectName("spinBox_rectangle_y2");
        spinBox_rectangle_y2->setMinimum(-500);
        spinBox_rectangle_y2->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_y2, 1, 1, 1, 1);

        spinBox_rectangle_x1 = new QSpinBox(gridLayoutWidget_2);
        spinBox_rectangle_x1->setObjectName("spinBox_rectangle_x1");
        spinBox_rectangle_x1->setMinimum(-500);
        spinBox_rectangle_x1->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_x1, 0, 0, 1, 1);

        spinBox_rectangle_y3 = new QSpinBox(gridLayoutWidget_2);
        spinBox_rectangle_y3->setObjectName("spinBox_rectangle_y3");
        spinBox_rectangle_y3->setMinimum(-500);
        spinBox_rectangle_y3->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_y3, 2, 1, 1, 1);

        pushButton_rectangle_Delete = new QPushButton(gridLayoutWidget_2);
        pushButton_rectangle_Delete->setObjectName("pushButton_rectangle_Delete");
        pushButton_rectangle_Delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: darkred;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: black;\n"
"}\n"
""));
        pushButton_rectangle_Delete->setAutoRepeat(false);

        gridLayout_2->addWidget(pushButton_rectangle_Delete, 7, 0, 1, 2);

        spinBox_rectangle_x4 = new QSpinBox(gridLayoutWidget_2);
        spinBox_rectangle_x4->setObjectName("spinBox_rectangle_x4");
        spinBox_rectangle_x4->setMinimum(-500);
        spinBox_rectangle_x4->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_x4, 3, 0, 1, 1);

        spinBox_rectangle_x2 = new QSpinBox(gridLayoutWidget_2);
        spinBox_rectangle_x2->setObjectName("spinBox_rectangle_x2");
        spinBox_rectangle_x2->setMinimum(-500);
        spinBox_rectangle_x2->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_x2, 1, 0, 1, 1);

        pushButton_rectangle_Apply = new QPushButton(gridLayoutWidget_2);
        pushButton_rectangle_Apply->setObjectName("pushButton_rectangle_Apply");

        gridLayout_2->addWidget(pushButton_rectangle_Apply, 5, 1, 1, 1);

        spinBox_rectangle_y4 = new QSpinBox(gridLayoutWidget_2);
        spinBox_rectangle_y4->setObjectName("spinBox_rectangle_y4");
        spinBox_rectangle_y4->setMinimum(-500);
        spinBox_rectangle_y4->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_y4, 3, 1, 1, 1);

        spinBox_rectangle_x3 = new QSpinBox(gridLayoutWidget_2);
        spinBox_rectangle_x3->setObjectName("spinBox_rectangle_x3");
        spinBox_rectangle_x3->setMinimum(-500);
        spinBox_rectangle_x3->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_x3, 2, 0, 1, 1);

        pushButton_rectangle_Cancel = new QPushButton(gridLayoutWidget_2);
        pushButton_rectangle_Cancel->setObjectName("pushButton_rectangle_Cancel");

        gridLayout_2->addWidget(pushButton_rectangle_Cancel, 5, 0, 1, 1);

        spinBox_rectangle_rotation = new QSpinBox(gridLayoutWidget_2);
        spinBox_rectangle_rotation->setObjectName("spinBox_rectangle_rotation");
        spinBox_rectangle_rotation->setMaximum(360);

        gridLayout_2->addWidget(spinBox_rectangle_rotation, 4, 0, 1, 2);

        tabWidgetProperties->addTab(tab_rectangle, QString());
        tab_circle = new QWidget();
        tab_circle->setObjectName("tab_circle");
        gridLayoutWidget_3 = new QWidget(tab_circle);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(10, 10, 291, 281));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        spinBox_circle_YCenter = new QSpinBox(gridLayoutWidget_3);
        spinBox_circle_YCenter->setObjectName("spinBox_circle_YCenter");
        spinBox_circle_YCenter->setMinimum(-500);
        spinBox_circle_YCenter->setMaximum(500);

        gridLayout_3->addWidget(spinBox_circle_YCenter, 0, 1, 1, 1);

        pushButton_circle_Cancel = new QPushButton(gridLayoutWidget_3);
        pushButton_circle_Cancel->setObjectName("pushButton_circle_Cancel");

        gridLayout_3->addWidget(pushButton_circle_Cancel, 4, 0, 1, 1);

        spinBox_circle_XCenter = new QSpinBox(gridLayoutWidget_3);
        spinBox_circle_XCenter->setObjectName("spinBox_circle_XCenter");
        spinBox_circle_XCenter->setMinimum(-500);
        spinBox_circle_XCenter->setMaximum(500);

        gridLayout_3->addWidget(spinBox_circle_XCenter, 0, 0, 1, 1);

        pushButton_circle_Apply = new QPushButton(gridLayoutWidget_3);
        pushButton_circle_Apply->setObjectName("pushButton_circle_Apply");

        gridLayout_3->addWidget(pushButton_circle_Apply, 4, 1, 1, 1);

        spinBox_circle_radius = new QSpinBox(gridLayoutWidget_3);
        spinBox_circle_radius->setObjectName("spinBox_circle_radius");
        spinBox_circle_radius->setMinimum(1);
        spinBox_circle_radius->setMaximum(500);

        gridLayout_3->addWidget(spinBox_circle_radius, 1, 0, 1, 2);

        pushButton_circle_Delete = new QPushButton(gridLayoutWidget_3);
        pushButton_circle_Delete->setObjectName("pushButton_circle_Delete");
        pushButton_circle_Delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: red;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: red;\n"
"}\n"
""));

        gridLayout_3->addWidget(pushButton_circle_Delete, 5, 0, 1, 2);

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

        tabWidgetProperties->setCurrentIndex(1);


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
        spinBox_triangle_rotation->setPrefix(QCoreApplication::translate("MainWindow", "rotation = ", nullptr));
        spinBox_triangle_x3->setPrefix(QCoreApplication::translate("MainWindow", "x3 = ", nullptr));
        spinBox_triangle_x2->setPrefix(QCoreApplication::translate("MainWindow", "x2 = ", nullptr));
        spinBox_triangle_y2->setPrefix(QCoreApplication::translate("MainWindow", "y2 = ", nullptr));
        pushButton_triangle_Cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        pushButton_triangle_Apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        spinBox_triangle_y3->setPrefix(QCoreApplication::translate("MainWindow", "y3 = ", nullptr));
        spinBox_triangle_y1->setPrefix(QCoreApplication::translate("MainWindow", "y1 = ", nullptr));
        pushButton_triangle_Delete->setText(QCoreApplication::translate("MainWindow", "Delete triangle", nullptr));
        tabWidgetProperties->setTabText(tabWidgetProperties->indexOf(tab_triagnle), QCoreApplication::translate("MainWindow", "triangle", nullptr));
        spinBox_rectangle_y1->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        spinBox_rectangle_y2->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        spinBox_rectangle_x1->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        spinBox_rectangle_y3->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        pushButton_rectangle_Delete->setText(QCoreApplication::translate("MainWindow", "Delete rectangle", nullptr));
        spinBox_rectangle_x4->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        spinBox_rectangle_x2->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        pushButton_rectangle_Apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        spinBox_rectangle_y4->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        spinBox_rectangle_x3->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        pushButton_rectangle_Cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        spinBox_rectangle_rotation->setPrefix(QCoreApplication::translate("MainWindow", "rotation = ", nullptr));
        tabWidgetProperties->setTabText(tabWidgetProperties->indexOf(tab_rectangle), QCoreApplication::translate("MainWindow", "rectangle", nullptr));
        spinBox_circle_YCenter->setPrefix(QCoreApplication::translate("MainWindow", "Center(y) = ", nullptr));
        pushButton_circle_Cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        spinBox_circle_XCenter->setPrefix(QCoreApplication::translate("MainWindow", "Center(x) = ", nullptr));
        pushButton_circle_Apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        spinBox_circle_radius->setPrefix(QCoreApplication::translate("MainWindow", "radius = ", nullptr));
        pushButton_circle_Delete->setText(QCoreApplication::translate("MainWindow", "Delete circle", nullptr));
        tabWidgetProperties->setTabText(tabWidgetProperties->indexOf(tab_circle), QCoreApplication::translate("MainWindow", "circle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
