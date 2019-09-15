#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>
#include <QPointF>
#include <QList>

class MyData : public QObject
{
    Q_OBJECT
public:
    explicit MyData(QObject *parent = nullptr);

    QList<QPointF> * getData();
    QPointF points[100000];
    QList<QPointF>*SeriesPoint;
    int XNum;//X轴的数据个数
    double MInterval;//x轴的最小间隔

    double YMax;
    double YMin;

private:


signals:

public slots:
};

#endif // MYDATA_H
