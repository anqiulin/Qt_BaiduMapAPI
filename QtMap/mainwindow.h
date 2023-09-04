#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWebEngineView>
//#include<QtWebEngineWidgets/QWebEngineView>
#include <QWebChannel>
#include <QDebug>
#include <vector>
#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<map>
using namespace  std;
#define inf 0x3f3f3f3f
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWebEngineView *m_view;
    QWebChannel *channel;
    struct point{
        int num;
        double x;
        double y;
    }p[10000];
    int pointNum = 1;
    struct edge{
        point point1;
        point point2;
        int weight;
    }e[10000];
    int edgeNum = 0;
    struct key{
        int number;
        double price;
        double score;
        double grade;
        int type;
    }keys[10000];
    int keysNum = 0;
    vector<int> clear;
    vector<int> jump;
    void getPoint(point poi);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_btn_query_show_clicked();

    void on_btn_query_clicked();

    void on_btn_clear_clicked();

    void on_btn_keys_clicked();

    void on_pushButton_4_clicked();

    void on_btn_clear_road_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

