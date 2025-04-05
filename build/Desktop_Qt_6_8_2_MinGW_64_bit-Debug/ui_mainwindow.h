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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QSplitter *splitter_5;
    QWidget *widget;
    QGridLayout *gridLayout_7;
    QPushButton *btnTriangle;
    QPushButton *btnCircle;
    QPushButton *btnRectangle;
    QLabel *label;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QLabel *label_2;
    QListWidget *listWidgetShapes;
    QSplitter *splitter;
    QSplitter *splitter_4;
    QLabel *label_3;
    QTabWidget *tabWidgetProperties;
    QWidget *tab_circle;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBox_circle_radius;
    QSpinBox *spinBox_circle_XCenter;
    QPushButton *pushButton_circle_Delete;
    QPushButton *pushButton_circle_Cancel;
    QPushButton *pushButton_circle_Apply;
    QSpinBox *spinBox_circle_YCenter;
    QWidget *tab_triagnle;
    QGridLayout *gridLayout_10;
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
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBox_rectangle_x1;
    QSpinBox *spinBox_rectangle_y1;
    QSpinBox *spinBox_rectangle_x2;
    QSpinBox *spinBox_rectangle_y2;
    QSpinBox *spinBox_rectangle_x3;
    QSpinBox *spinBox_rectangle_y3;
    QSpinBox *spinBox_rectangle_x4;
    QSpinBox *spinBox_rectangle_y4;
    QSpinBox *spinBox_rectangle_rotation;
    QPushButton *pushButton_rectangle_Cancel;
    QPushButton *pushButton_rectangle_Apply;
    QPushButton *pushButton_rectangle_Delete;
    QGraphicsView *graphicsView;
    QPushButton *btnClearScene;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(992, 766);
        MainWindow->setMouseTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName("gridLayout_4");
        splitter_5 = new QSplitter(centralwidget);
        splitter_5->setObjectName("splitter_5");
        splitter_5->setOrientation(Qt::Orientation::Vertical);
        widget = new QWidget(splitter_5);
        widget->setObjectName("widget");
        gridLayout_7 = new QGridLayout(widget);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        btnTriangle = new QPushButton(widget);
        btnTriangle->setObjectName("btnTriangle");

        gridLayout_7->addWidget(btnTriangle, 4, 0, 1, 1);

        btnCircle = new QPushButton(widget);
        btnCircle->setObjectName("btnCircle");

        gridLayout_7->addWidget(btnCircle, 3, 0, 1, 1);

        btnRectangle = new QPushButton(widget);
        btnRectangle->setObjectName("btnRectangle");

        gridLayout_7->addWidget(btnRectangle, 5, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout_7->addWidget(label, 2, 0, 1, 1);

        splitter_5->addWidget(widget);
        splitter_3 = new QSplitter(splitter_5);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Orientation::Vertical);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Orientation::Vertical);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName("label_2");
        splitter_2->addWidget(label_2);
        listWidgetShapes = new QListWidget(splitter_2);
        listWidgetShapes->setObjectName("listWidgetShapes");
        splitter_2->addWidget(listWidgetShapes);
        splitter_3->addWidget(splitter_2);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Vertical);
        splitter_4 = new QSplitter(splitter);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setOrientation(Qt::Orientation::Vertical);
        label_3 = new QLabel(splitter_4);
        label_3->setObjectName("label_3");
        splitter_4->addWidget(label_3);
        tabWidgetProperties = new QTabWidget(splitter_4);
        tabWidgetProperties->setObjectName("tabWidgetProperties");
        tabWidgetProperties->setMinimumSize(QSize(314, 0));
        tab_circle = new QWidget();
        tab_circle->setObjectName("tab_circle");
        gridLayout_11 = new QGridLayout(tab_circle);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        spinBox_circle_radius = new QSpinBox(tab_circle);
        spinBox_circle_radius->setObjectName("spinBox_circle_radius");
        spinBox_circle_radius->setMinimum(1);
        spinBox_circle_radius->setMaximum(500);

        gridLayout_3->addWidget(spinBox_circle_radius, 1, 0, 1, 2);

        spinBox_circle_XCenter = new QSpinBox(tab_circle);
        spinBox_circle_XCenter->setObjectName("spinBox_circle_XCenter");
        spinBox_circle_XCenter->setMinimum(-500);
        spinBox_circle_XCenter->setMaximum(500);

        gridLayout_3->addWidget(spinBox_circle_XCenter, 0, 0, 1, 1);

        pushButton_circle_Delete = new QPushButton(tab_circle);
        pushButton_circle_Delete->setObjectName("pushButton_circle_Delete");
        pushButton_circle_Delete->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);"));

        gridLayout_3->addWidget(pushButton_circle_Delete, 5, 0, 1, 2);

        pushButton_circle_Cancel = new QPushButton(tab_circle);
        pushButton_circle_Cancel->setObjectName("pushButton_circle_Cancel");

        gridLayout_3->addWidget(pushButton_circle_Cancel, 4, 0, 1, 1);

        pushButton_circle_Apply = new QPushButton(tab_circle);
        pushButton_circle_Apply->setObjectName("pushButton_circle_Apply");

        gridLayout_3->addWidget(pushButton_circle_Apply, 4, 1, 1, 1);

        spinBox_circle_YCenter = new QSpinBox(tab_circle);
        spinBox_circle_YCenter->setObjectName("spinBox_circle_YCenter");
        spinBox_circle_YCenter->setMinimum(-500);
        spinBox_circle_YCenter->setMaximum(500);

        gridLayout_3->addWidget(spinBox_circle_YCenter, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidgetProperties->addTab(tab_circle, QString());
        tab_triagnle = new QWidget();
        tab_triagnle->setObjectName("tab_triagnle");
        gridLayout_10 = new QGridLayout(tab_triagnle);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        spinBox_triangle_x1 = new QSpinBox(tab_triagnle);
        spinBox_triangle_x1->setObjectName("spinBox_triangle_x1");
        spinBox_triangle_x1->setMinimum(-500);
        spinBox_triangle_x1->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_x1, 1, 0, 1, 1);

        spinBox_triangle_rotation = new QSpinBox(tab_triagnle);
        spinBox_triangle_rotation->setObjectName("spinBox_triangle_rotation");
        spinBox_triangle_rotation->setMaximum(360);

        gridLayout->addWidget(spinBox_triangle_rotation, 4, 0, 1, 2);

        spinBox_triangle_x3 = new QSpinBox(tab_triagnle);
        spinBox_triangle_x3->setObjectName("spinBox_triangle_x3");
        spinBox_triangle_x3->setMinimum(-500);
        spinBox_triangle_x3->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_x3, 3, 0, 1, 1);

        spinBox_triangle_x2 = new QSpinBox(tab_triagnle);
        spinBox_triangle_x2->setObjectName("spinBox_triangle_x2");
        spinBox_triangle_x2->setMinimum(-500);
        spinBox_triangle_x2->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_x2, 2, 0, 1, 1);

        spinBox_triangle_y2 = new QSpinBox(tab_triagnle);
        spinBox_triangle_y2->setObjectName("spinBox_triangle_y2");
        spinBox_triangle_y2->setMinimum(-500);
        spinBox_triangle_y2->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_y2, 2, 1, 1, 1);

        pushButton_triangle_Cancel = new QPushButton(tab_triagnle);
        pushButton_triangle_Cancel->setObjectName("pushButton_triangle_Cancel");

        gridLayout->addWidget(pushButton_triangle_Cancel, 5, 0, 1, 1);

        pushButton_triangle_Apply = new QPushButton(tab_triagnle);
        pushButton_triangle_Apply->setObjectName("pushButton_triangle_Apply");

        gridLayout->addWidget(pushButton_triangle_Apply, 5, 1, 1, 1);

        spinBox_triangle_y3 = new QSpinBox(tab_triagnle);
        spinBox_triangle_y3->setObjectName("spinBox_triangle_y3");
        spinBox_triangle_y3->setMinimum(-500);
        spinBox_triangle_y3->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_y3, 3, 1, 1, 1);

        spinBox_triangle_y1 = new QSpinBox(tab_triagnle);
        spinBox_triangle_y1->setObjectName("spinBox_triangle_y1");
        spinBox_triangle_y1->setMinimum(-500);
        spinBox_triangle_y1->setMaximum(500);

        gridLayout->addWidget(spinBox_triangle_y1, 1, 1, 1, 1);

        pushButton_triangle_Delete = new QPushButton(tab_triagnle);
        pushButton_triangle_Delete->setObjectName("pushButton_triangle_Delete");
        pushButton_triangle_Delete->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);"));
        pushButton_triangle_Delete->setAutoRepeat(false);

        gridLayout->addWidget(pushButton_triangle_Delete, 6, 0, 1, 2);


        gridLayout_10->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidgetProperties->addTab(tab_triagnle, QString());
        tab_rectangle = new QWidget();
        tab_rectangle->setObjectName("tab_rectangle");
        gridLayout_9 = new QGridLayout(tab_rectangle);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        spinBox_rectangle_x1 = new QSpinBox(tab_rectangle);
        spinBox_rectangle_x1->setObjectName("spinBox_rectangle_x1");
        spinBox_rectangle_x1->setMinimum(-500);
        spinBox_rectangle_x1->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_x1, 0, 0, 1, 1);

        spinBox_rectangle_y1 = new QSpinBox(tab_rectangle);
        spinBox_rectangle_y1->setObjectName("spinBox_rectangle_y1");
        spinBox_rectangle_y1->setMinimum(-500);
        spinBox_rectangle_y1->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_y1, 0, 1, 1, 1);

        spinBox_rectangle_x2 = new QSpinBox(tab_rectangle);
        spinBox_rectangle_x2->setObjectName("spinBox_rectangle_x2");
        spinBox_rectangle_x2->setMinimum(-500);
        spinBox_rectangle_x2->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_x2, 1, 0, 1, 1);

        spinBox_rectangle_y2 = new QSpinBox(tab_rectangle);
        spinBox_rectangle_y2->setObjectName("spinBox_rectangle_y2");
        spinBox_rectangle_y2->setMinimum(-500);
        spinBox_rectangle_y2->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_y2, 1, 1, 1, 1);

        spinBox_rectangle_x3 = new QSpinBox(tab_rectangle);
        spinBox_rectangle_x3->setObjectName("spinBox_rectangle_x3");
        spinBox_rectangle_x3->setMinimum(-500);
        spinBox_rectangle_x3->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_x3, 2, 0, 1, 1);

        spinBox_rectangle_y3 = new QSpinBox(tab_rectangle);
        spinBox_rectangle_y3->setObjectName("spinBox_rectangle_y3");
        spinBox_rectangle_y3->setMinimum(-500);
        spinBox_rectangle_y3->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_y3, 2, 1, 1, 1);

        spinBox_rectangle_x4 = new QSpinBox(tab_rectangle);
        spinBox_rectangle_x4->setObjectName("spinBox_rectangle_x4");
        spinBox_rectangle_x4->setMinimum(-500);
        spinBox_rectangle_x4->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_x4, 3, 0, 1, 1);

        spinBox_rectangle_y4 = new QSpinBox(tab_rectangle);
        spinBox_rectangle_y4->setObjectName("spinBox_rectangle_y4");
        spinBox_rectangle_y4->setMinimum(-500);
        spinBox_rectangle_y4->setMaximum(500);

        gridLayout_2->addWidget(spinBox_rectangle_y4, 3, 1, 1, 1);

        spinBox_rectangle_rotation = new QSpinBox(tab_rectangle);
        spinBox_rectangle_rotation->setObjectName("spinBox_rectangle_rotation");
        spinBox_rectangle_rotation->setMaximum(360);

        gridLayout_2->addWidget(spinBox_rectangle_rotation, 4, 0, 1, 2);

        pushButton_rectangle_Cancel = new QPushButton(tab_rectangle);
        pushButton_rectangle_Cancel->setObjectName("pushButton_rectangle_Cancel");

        gridLayout_2->addWidget(pushButton_rectangle_Cancel, 5, 0, 1, 1);

        pushButton_rectangle_Apply = new QPushButton(tab_rectangle);
        pushButton_rectangle_Apply->setObjectName("pushButton_rectangle_Apply");

        gridLayout_2->addWidget(pushButton_rectangle_Apply, 5, 1, 1, 1);

        pushButton_rectangle_Delete = new QPushButton(tab_rectangle);
        pushButton_rectangle_Delete->setObjectName("pushButton_rectangle_Delete");
        pushButton_rectangle_Delete->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
""));
        pushButton_rectangle_Delete->setAutoRepeat(false);

        gridLayout_2->addWidget(pushButton_rectangle_Delete, 6, 0, 1, 2);


        gridLayout_9->addLayout(gridLayout_2, 0, 0, 1, 1);

        tabWidgetProperties->addTab(tab_rectangle, QString());
        splitter_4->addWidget(tabWidgetProperties);
        splitter->addWidget(splitter_4);
        splitter_3->addWidget(splitter);
        splitter_5->addWidget(splitter_3);

        gridLayout_4->addWidget(splitter_5, 0, 0, 2, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        graphicsView->setInteractive(true);

        gridLayout_4->addWidget(graphicsView, 0, 1, 1, 1);

        btnClearScene = new QPushButton(centralwidget);
        btnClearScene->setObjectName("btnClearScene");
        btnClearScene->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);"));

        gridLayout_4->addWidget(btnClearScene, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 992, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidgetProperties->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnTriangle->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
#if QT_CONFIG(whatsthis)
        btnCircle->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Set parametrs and create circle</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        btnCircle->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        btnRectangle->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\265\321\202\320\265 \321\202\320\270\320\277 \321\204\320\270\320\263\321\203\321\200\321\213 \320\264\320\273\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\201\320\276\320\267\320\264\320\260\320\275\320\275\321\213\321\205 \321\204\320\270\320\263\321\203\321\200:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \321\204\320\270\320\263\321\203\321\200\321\213:", nullptr));
        spinBox_circle_radius->setPrefix(QCoreApplication::translate("MainWindow", "radius = ", nullptr));
        spinBox_circle_XCenter->setPrefix(QCoreApplication::translate("MainWindow", "Center(x) = ", nullptr));
        pushButton_circle_Delete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\321\200\321\203\320\263", nullptr));
        pushButton_circle_Cancel->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_circle_Apply->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        spinBox_circle_YCenter->setPrefix(QCoreApplication::translate("MainWindow", "Center(y) = ", nullptr));
        tabWidgetProperties->setTabText(tabWidgetProperties->indexOf(tab_circle), QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        spinBox_triangle_x1->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        spinBox_triangle_rotation->setPrefix(QCoreApplication::translate("MainWindow", "rotation = ", nullptr));
        spinBox_triangle_x3->setPrefix(QCoreApplication::translate("MainWindow", "x3 = ", nullptr));
        spinBox_triangle_x2->setPrefix(QCoreApplication::translate("MainWindow", "x2 = ", nullptr));
        spinBox_triangle_y2->setPrefix(QCoreApplication::translate("MainWindow", "y2 = ", nullptr));
        pushButton_triangle_Cancel->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_triangle_Apply->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        spinBox_triangle_y3->setPrefix(QCoreApplication::translate("MainWindow", "y3 = ", nullptr));
        spinBox_triangle_y1->setPrefix(QCoreApplication::translate("MainWindow", "y1 = ", nullptr));
        pushButton_triangle_Delete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        tabWidgetProperties->setTabText(tabWidgetProperties->indexOf(tab_triagnle), QCoreApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        spinBox_rectangle_x1->setPrefix(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        spinBox_rectangle_y1->setPrefix(QCoreApplication::translate("MainWindow", "y1 = ", nullptr));
        spinBox_rectangle_x2->setPrefix(QCoreApplication::translate("MainWindow", "x2 = ", nullptr));
        spinBox_rectangle_y2->setPrefix(QCoreApplication::translate("MainWindow", "y2 = ", nullptr));
        spinBox_rectangle_x3->setPrefix(QCoreApplication::translate("MainWindow", "x3 = ", nullptr));
        spinBox_rectangle_y3->setPrefix(QCoreApplication::translate("MainWindow", "y3 = ", nullptr));
        spinBox_rectangle_x4->setPrefix(QCoreApplication::translate("MainWindow", "x4 = ", nullptr));
        spinBox_rectangle_y4->setPrefix(QCoreApplication::translate("MainWindow", "y4 = ", nullptr));
        spinBox_rectangle_rotation->setPrefix(QCoreApplication::translate("MainWindow", "rotation = ", nullptr));
        pushButton_rectangle_Cancel->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_rectangle_Apply->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        pushButton_rectangle_Delete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        tabWidgetProperties->setTabText(tabWidgetProperties->indexOf(tab_rectangle), QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        btnClearScene->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
