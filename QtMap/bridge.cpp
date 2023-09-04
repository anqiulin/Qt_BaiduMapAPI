#include "bridge.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QJSEngine>
#include <QDebug>
#include<QFile>


bridge::bridge()
{
}

void bridge::getYourName()
{
    emit sigYourName("hello, world!");
}
int keys_num = 1;
void bridge::getCoordinate(QString lon, QString lat)//经纬度抓取函数
{
    qDebug()<<lon<<lat;
    QFile file(qApp->applicationDirPath() + "/getkeys.txt");
   // QFile file(path);  //创建文件对象
   file.open(QIODevice::ReadWrite|QIODevice::Text);	//以读且写的方式打开
   //QTextCodec *codec=QTextCodec::codecForName("GBK");	 //防止乱码
   QByteArray array=file.readAll();
               //读取原文件内容（必须先读出来，才不会被新内容## 标题覆盖掉)
  // QString str=newName;	//字符串，名字可变，这里只是举例
   QTextStream out(&file);		//输入流
   out<< keys_num++ <<' '<< lon << ' ' << lat <<"\n";			//写入内容
   file.close();              //关闭文件流
    //QMessageBox::information(NULL, "QMessageBox::information", "get point from BaiduMap", QMessageBox::Ok) ;
}
/*void bridge::getCoordinate(QString lng, QString lat)
{
    MainWindow::point p;
    p.x = lng.toDouble();
    p.y = lat.toDouble();
    MainWindow mainwindow;
    mainwindow.getPoint(p);
    qDebug()<<lng<<lat;
    QMessageBox::information(NULL, "QMessageBox::information", "get point from BaiduMap", QMessageBox::Ok) ;
}
*/
