#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ <<"]"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,800);
    chart = new MyChart(this);
    timer = new QTimer(this);
    chart->DataNum = 3000;
    IntervalTime = 20;
    timer->start(IntervalTime);

    //跟随时钟周期绘图
    connect(timer, &QTimer::timeout, [=]()
    {
        chart->getMyChart("Move");
    });

    //接受信号停止绘图
    connect(chart, &MyChart::PlotEnd, [=]()
    {
        timer->stop();
    });

    //关闭窗口
    connect(this, &MainWindow::destroyed,[=]()
    {
//        delete chart->chart;
//        delete chart->Points;
//        delete chart->SeriesPointData;
//        delete chart->data->SeriesPoint;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
