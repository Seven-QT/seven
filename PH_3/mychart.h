#ifndef MYCHART_H
#define MYCHART_H

#include <QObject>
#include <QWidget>
#include <QChartView>
#include <QtCharts>
#include <QValueAxis>
#include <QLineSeries>
#include <QList>
#include "mydata.h"



class MyChart : public QWidget
{
    Q_OBJECT
public:
    explicit MyChart(QWidget *parent = nullptr);

    void getMyChart(QString);
    void setBasicValue();

    QPointF *Points; //存储数据点数据
    QLineSeries *series; //存储某段数据
    QList<QPointF>*SeriesPointData;

    QChart *chart; //图表
    QValueAxis *axisx; //x轴
    QValueAxis *axisy; //y轴
    QChartView *view; //图表容器


    MyData *data; //原始数据对象
    int DataNum;//记录当前数据数目
    int DataOneTime;//一帧绘图增加的数据数目
    int XAxisBegin;//横坐标起始点
    int XAxisEnd;//横坐标截止点
    int XAxisWidth;//横坐标显示宽度



signals:
    void PlotEnd();//结束绘图信号

public slots:
};

#endif // MYCHART_H
