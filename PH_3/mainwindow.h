#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mychart.h"
#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    MyChart *chart;
    QTimer *timer;
    int IntervalTime;//间隔时间

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
