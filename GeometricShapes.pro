QT       += core gui
QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Circle.cpp \
    CircleDialog.cpp \
    CoordinateSystem.cpp \
    Rectangle.cpp \
    RectangleDialog.cpp \
    Shape.cpp \
    Triangle.cpp \
    TriangleDialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Circle.h \
    CircleDialog.h \
    CoordinateSystem.h \
    Rectangle.h \
    RectangleDialog.h \
    Shape.h \
    Triangle.h \
    TriangleDialog.h \
    mainwindow.h

FORMS += \
    CircleDialog.ui \
    RectangleDialog.ui \
    TriangleDialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
