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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
        graphicsView->setGeometry(QRect(510, 40, 500, 500));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        graphicsView->setInteractive(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1055, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
