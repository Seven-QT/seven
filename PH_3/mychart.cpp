#include "mychart.h"
#include <QMessageBox>
#include <QPointF>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ <<"]"

MyChart::MyChart(QWidget *parent) : QWidget(parent)
{

    data = new MyData(this);
    series = new QLineSeries(this);
    chart = new QChart;
    Points = new QPointF;
    SeriesPointData = new QList<QPointF>;

    SeriesPointData = data->getData();
    setBasicValue();
    DataOneTime = 10;//初始化一帧绘图数据点个数
    this->resize(1200,800);

}

void MyChart::getMyChart(QString str)
{
    //如果绘图数据数目大于实际数据数目则表示绘图结束，发射信号
    if(DataNum >= data->XNum)
    {
        emit PlotEnd();
        QMessageBox::warning(this, "完成",QString("已完成绘图,共%1个数据点").arg(data->XNum));
    }
    //删除上一次折线，新建一段折线并存储数据
    delete  series;
    series = new QLineSeries(this);
    if(str == "Fixed")
    {
        XAxisBegin = 0;
    }
    else if(str == "Move")
    {
        XAxisWidth = 3000;
        XAxisBegin = DataNum - XAxisWidth;
    }
    XAxisEnd = DataNum;
    series->append(SeriesPointData->mid(XAxisBegin, XAxisEnd));
    //设置坐标范围
    axisx->setRange(XAxisBegin * data->MInterval, XAxisEnd * data->MInterval);//加不加都可以，如果不加会自动根据数值调整
    axisy->setRange(data->YMin - 0.01 , data->YMax + 0.01);
    //设置折线颜色
    series->setColor(QColor(230, 120, 120));
    //给图表空间增加折线数据绘制到view上
    chart->addSeries(series);
    chart->setAxisX(axisx, series);
    chart->setAxisY(axisy, series);

    view->setChart(chart);
    view->setFixedSize(QSize(width(), height()));
    DataNum += DataOneTime;//下一帧图的数据点数目
}

void MyChart::setBasicValue()
{
    //建立坐标环境
    axisx = new QValueAxis(this);
    axisy = new QValueAxis(this);
    view = new QChartView(this);

//    //将纵坐标范围初始化
//    YMax = 0;
//    YMin = 0;

    //设置图表标题
    chart->setTitle("PH Test3");
    QFont font("微软雅黑",24,5, true);
    chart->setTitleFont(font);

    //设置x轴坐标
    axisx->setGridLineVisible(true);
    axisx->setLabelFormat("%d");
    axisx->setTickCount(6);
    axisx->setMinorTickCount(5);
    axisx->setTitleText("横坐标/x");
    axisx->setLabelsVisible(true);
    axisx->setLabelsColor(QColor(50, 80, 80));
    chart->addAxis(axisx, Qt::AlignBottom);

    //设置y轴坐标
    axisy->setGridLineVisible(true);
    axisy->setLabelFormat("%f");
    axisy->setTickCount(5);
    axisy->setMinorTickCount(5);
    axisy->setTitleText("纵坐标/y");
    axisy->setLabelsVisible(true);
    axisy->setLabelsColor(QColor(50, 80, 80));
    chart->addAxis(axisy, Qt::AlignLeft);
    chart->createDefaultAxes();
}
