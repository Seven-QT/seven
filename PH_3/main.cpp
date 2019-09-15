#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ <<"]"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
