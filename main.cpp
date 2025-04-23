#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QTextStream>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("light_theme.qss"); // путь — если файл в папке проекта
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QString styleSheet = file.readAll();
        a.setStyleSheet(styleSheet);
    }
    else
    {
        qDebug() << "Не удалось открыть light_theme.qss";
    }

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "geometricshapes_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
