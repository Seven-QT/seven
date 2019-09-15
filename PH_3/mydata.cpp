#include "mydata.h"
#include "xlsxdocument.h"
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ <<"]"

MyData::MyData(QObject *parent) : QObject(parent)
{
    SeriesPoint = new QList<QPointF>;
}

QList<QPointF>* MyData::getData()
{
    QXlsx::Document xlsx("../data.xlsx");
    XNum = 9000;
    MInterval = 0.1;
    for(int i = 0 ; i < XNum; i ++)
    {
        points[i].setX((i + 1) * MInterval);
        points[i].setY(xlsx.read(i+1, 1).toDouble()/1000);
        //得到坐标范围
        if(points[i].y() > YMax)
        {
            YMax = points[i].y();
        }
        else if(points[i].y() < YMin)
        {
            YMin = points[i].y();
        }

        SeriesPoint->append(points[i]);
    }
    return SeriesPoint;
}
