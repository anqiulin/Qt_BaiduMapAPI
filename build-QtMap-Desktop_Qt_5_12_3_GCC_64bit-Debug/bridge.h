#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>
#include <QJSValue>
#include <functional>
#include <QVariant>


class bridge : QObject
{
Q_OBJECT
public:
    bridge();
    struct point{
            int num;
            QString x;
            QString y;
            QString sss;
            double distance;
        }p1[10000];
    int pointNum1 = 0;
signals:
    void sigYourName(const QString &name);
public slots:
    void getYourName();
    //void getCoordinate(QString lon,QString lat);
    void getCoordinate(QString x,QString y, QString num);
    void getpoi(int begin_id, int end_id);
};

#endif // BRIDGE_H
