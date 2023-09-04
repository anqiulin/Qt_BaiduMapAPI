#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bridge.h"
#include<QFileDialog>
#include<QFile>
#include<QStringList>
#include<QDebug>
#include<QtWebEngineWidgets/QWebEnginePage>
#include <QDir>
#include <QWebChannel>
#include<vector>
#include<unordered_map>
using namespace std;
#define inf 0x3f3f3f3f
//dijkstra
const int maxn = 200;
typedef pair<int, int> P;

int cmp(const pair<int, double>& x, const pair<int, double>& y)
{
    return x.second > y.second;   // 按照降序排序
}
int cmp_vec(const vector<pair<int, double>>& x, const vector<pair<int, double>>& y)
{
    return x[0].first < y[0].first;
}
struct site{
    int to;//到达地
    int dis;
    site(int t,int di) : to(t), dis(di){}
};

vector<site> G[maxn];//邻接表
int pre[maxn];//记录每个点的前一个点（弧尾求弧头）
priority_queue<P, vector<P>, greater<P> > que;//构建小顶堆
vector <int> Dijkstra(int Start, int End, int &dis);
vector<int> getpath(int t);
//dijkstra
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_view=new QWebEngineView(this);
    setCentralWidget(m_view);
    channel = new QWebChannel(this);   //创建通道对象用于与JS交互
    bridge *mybride=new bridge();        //创建通道对象用于与JS交互
    channel->registerObject("bridge_name",(QObject*)mybride);
    // 这里注册对象名"bridge_name"需要与JS函数用到的名称一致
    //见baidumap.html文件第94行 window.bridge_js = channel.objects.bridge_name;
    // C++对象"bridge_name", JS对象bridge_js。101行，JS调用QT中C++函数只需
    //  bridge_js.getCoordinate(e.point.lng, e.point.lat);网页向QT传递经纬度坐标
    //这就实现了JS调用C++函数，实现网页向QT传递数据
    m_view->page()->setWebChannel(channel);


    //QDir temDir("../baidumap.html");
    //QString absDir = temDir.absolutePath();
    //QString filePath = "file:///" + absDir;  qDebug()<<filePath;
    QString filePath ="file:///" + qApp->applicationDirPath() + "/baidumap.html"; qDebug()<<filePath;
    m_view->page()->load(QUrl(filePath));//load the map in relevant path
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getPoint(point poi)
{
    ui->textEdit->clear();
    for(int i = 0; i < pointNum; i++){
        if(poi.x == p->x && poi.y == p->y){
            poi.num = p->num;
            break;
        }
    }
    double weightpoi = 0;
    for(int j = 0; j < edgeNum; j++){
        if(e[j].point1.num == poi.num){
            weightpoi = e[j].weight;
            break;
        }
        if(e[j].point2.num == poi.num){
            weightpoi = e[j].weight;
            break;
        }
    }
    ui->textEdit->append(QString::number(poi.num,'f',0)+" "+QString::number(poi.x,'f',6)+" "+QString::number(poi.y,'f',6)+" "+QString::number(weightpoi,'f',0));
}

void MainWindow::on_pushButton_clicked()
{
    QString cmd=QString("addmarker(%0,%1,%2)")
            .arg(ui->doubleSpinBox->value())
            .arg(ui->spinlong->value())
            .arg(ui->spinlat->value());
    //把要调用的JS命令当做QString传递给网页
    //对应baidumap.html 第77行
    //这就实现了QT通过C++调用JS函数
    m_view->page()->runJavaScript(cmd);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"打开文件","file:///" + qApp->applicationDirPath());
    ui->textEdit->setText(path);

    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        //ui->textEdit->append(line);
        QStringList subs = line.split(" ");
        double lng=0,lat=0;
        int number = 0;
        number = subs.at(0).toInt();
        lng = subs.at(1).toDouble();
        lat = subs.at(2).toDouble();
        p[number].num = number;
        p[number].x = lng;
        p[number].y = lat;
        pointNum++;
        QString cmd=QString("addmarker1(%0,%1,%2)")
                .arg(lng)
                .arg(lat)
                .arg(number);
        m_view->page()->runJavaScript(cmd);

        ui->textEdit->append(QString::number(p[pointNum].num,'f',6)+" "+QString::number(p[pointNum].x,'f',6)+" "+QString::number(p[pointNum].y,'f',6));
        //pointNum++;
    }
    file.close();


}

void MainWindow::on_pushButton_3_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"打开文件","file:///" + qApp->applicationDirPath());
    ui->textEdit->setText(path);

    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList subs = line.split(" ");
        e[edgeNum].point1.num = subs.at(0).toInt();
        e[edgeNum].point2.num = subs.at(1).toInt();
        e[edgeNum].weight = subs.at(2).toInt();

        G[e[edgeNum].point1.num].push_back(site(e[edgeNum].point2.num,e[edgeNum].weight));// 无向图存储方法，一个边的两端点互通
        G[e[edgeNum].point2.num].push_back(site(e[edgeNum].point1.num,e[edgeNum].weight));

        edgeNum++;
    }

    for(int i = 0; i < edgeNum; i++){
        QString cmd=QString("addedgemarker(%0,%1,%2,%3,%4)")
                .arg(p[e[i].point1.num].x)
                .arg(p[e[i].point1.num].y)
                .arg(p[e[i].point2.num].x)
                .arg(p[e[i].point2.num].y)
                .arg(e[i].weight);
        m_view->page()->runJavaScript(cmd);
        ui->textEdit->append(QString::number(e[i].point1.x,'f',6)+" "+QString::number(e[i].point1.y,'f',6)+" "+QString::number(e[i].point2.x,'f',6)+" "+QString::number(e[i].point2.y,'f',6)+" "+QString::number(e[i].weight,'f',0));
        //qDebug()<<e[i].point1.x<<" "<<e[i].point1.y<<"\n"<<e[i].point2.x<<" "<<e[i].point2.y<<endl;
    }

}

void MainWindow::on_btn_query_show_clicked()
{
    int clear_num = 0;
    int start = ui->query_start->text().toInt();
    int end = ui->query_end->text().toInt();
    QString base_path = ui->query_basepath->text();
    qDebug() << start << ' ' << end << endl;
    qDebug() << base_path;
    QStringList subs = base_path.split(" ");
    QString cmd=QString("addbasepathedge(%0,%1,%2,%3)")
            .arg(p[start].x)
            .arg(p[start].y)
            .arg(p[subs[0].toInt()].x)
            .arg(p[subs[0].toInt()].y);
    m_view->page()->runJavaScript(cmd);
    clear_num++;
    for(int i = 0; i < subs.size()-1; i++)
    {
        int tmp_s = subs[i].toInt();
        int tmp_t = subs[i+1].toInt();
        QString cmd2=QString("addbasepathedge(%0,%1,%2,%3)")
                .arg(p[tmp_s].x)
                .arg(p[tmp_s].y)
                .arg(p[tmp_t].x)
                .arg(p[tmp_t].y);
        m_view->page()->runJavaScript(cmd2);
        clear_num++;
    }
    QString cmd1=QString("addbasepathedge(%0,%1,%2,%3)")
            .arg(p[subs[subs.size()-1].toInt()].x)
            .arg(p[subs[subs.size()-1].toInt()].y)
            .arg(p[end].x)
            .arg(p[end].y);
    m_view->page()->runJavaScript(cmd1);
    clear_num++;
    clear.push_back(clear_num);
}

void MainWindow::on_btn_query_clicked()
{
    int Q_start = ui->query_start->text().toInt();
    int Q_end = ui->query_end->text().toInt();
    QString query_keys = ui->query_keys->text();
    qDebug() << query_keys;
    bool price = ui->chk_price->isChecked();
    bool sorce = ui->chk_sorce->isChecked();
    bool grade = ui->chk_grade->isChecked();
    bool detour = ui->chk_detour->isChecked();
    bool total = ui->chk_total->isChecked();
    /*
    qDebug() << " price "<< price << endl;
    qDebug() << " sorce "<< sorce << endl;
    qDebug() << " grade "<< grade << endl;
    qDebug() << " detour "<< detour << endl;
    qDebug() << " total "<< total << endl;
    */
    vector <int> shortnode;
    int Q_dis = 0;
    shortnode =  Dijkstra(Q_start, Q_end, Q_dis);
    qDebug() << "short:" <<Q_dis;
    for(auto &k : shortnode){
        qDebug() << k << ' ';
    }
    unordered_map<int, double> value;
    QStringList subs = query_keys.split(" ");
    for(int i =0; i<keysNum;i++)
    {
        qDebug()<<keys[i].type << keys[i].grade << keys[i].score << keys[i].price <<endl;
    }
    for(int i = 0; i < subs.size(); i++)
    {
        if(price)
        {
            for(int k = 0; k < keysNum; k++)
            {
                if(keys[k].type == subs[i].toInt())
                {

                    if(value.find(keys[k].number)!=value.end())
                    {
                        value[keys[k].number] -= keys[k].price/500.0;
                    }
                    else {
                        value[keys[k].number] = -keys[k].price/500.0;
                    }
                }
            }
        }
        if(sorce)
        {
            for(int k = 0; k < keysNum; k++)
            {
                if(keys[k].type == subs[i].toInt())
                {

                    if(value.find(keys[k].number)!=value.end())
                    {
                        value[keys[k].number] += keys[k].score/10.0;
                    }
                    else {
                        value[keys[k].number] = keys[k].score/10.0;
                    }
                }
            }
        }
        if(grade)
        {
            for(int k = 0; k < keysNum; k++)
            {
                if(keys[k].type == subs[i].toInt())
                {

                    if(value.find(keys[k].number)!=value.end())
                    {
                        value[keys[k].number] += keys[k].grade/5.0;
                    }
                    else {
                        value[keys[k].number] = keys[k].grade/5.0;
                    }
                }
            }
        }
    }
    qDebug() << "size"<<value.size();
    for(auto &c : value)
    {
        qDebug() <<c.first << c.second;
    }
    vector<pair<int, double>> vec;
    for(auto it=value.begin();it!=value.end();it++)
             vec.push_back(make_pair(it->first, it->second));
    sort(vec.begin(), vec.end(), cmp);  // vector根据cmp的规则进行排序

    vector<int> candidate;
    for(int i =0; i < subs.size(); i++)
    {
        int flag = 0;
        for(auto &k : vec)
        {
            for(int j = 0; j < keysNum; j++)
            {
                if(keys[j].number == k.first && keys[j].type == subs[i].toInt())
                {
                    candidate.push_back(keys[j].number);
                    flag = 1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
    }
    qDebug()<<endl;
    for(auto &c : vec)
    {
        qDebug() <<c.first << c.second;
    }
    for(auto &c : candidate)
    {
        qDebug() <<c;
    }

    for(int i = 0; i < candidate.size(); i++)
    {
        QString cmd2=QString("jumpmarker(%0,%1)")
                .arg(p[candidate[i]].x)
                .arg(p[candidate[i]].y);
        m_view->page()->runJavaScript(cmd2);
    }
    QString base_path = ui->query_basepath->text();
    QStringList subs_base_path = base_path.split(" ");
    vector <int> Bpath;
    Bpath.push_back(ui->query_start->text().toInt());
    for(int i = 0; i< subs_base_path.size(); i++)
    {
        Bpath.push_back(subs_base_path[i].toInt());
    }
    Bpath.push_back(ui->query_end->text().toInt());
    qDebug() << "heer";
    for(int c : Bpath)
    {
        qDebug() << c;
    }
    qDebug() <<"aaaa" ;
    vector<int> result;
    if(detour)
    {
        //vector<int> visit(Bpath.size(), 0);
        vector<vector<pair<int, int>>> near_node;
        vector<pair<int, int>> tmp_node {{0, 0},{0, 0}};
        for(int i = 0; i < candidate.size(); i++)
        {
            near_node.push_back(tmp_node);
        }
        int k =0;
        for(int j = 0; j < candidate.size(); j++)
        {
            int min_dis = 100000;
            int next_min = 100000;
             int pos_min = 0;
             int pos_next = 0;
            for(int i = 0; i < Bpath.size(); i++)
            {
                vector<int> dispath_cand;
                dispath_cand.clear();
                int dis_cand = 0;
                dispath_cand = Dijkstra(Bpath[i], candidate[j], dis_cand);
                if(min_dis > dis_cand)
                {
                    next_min = min_dis;
                    pos_next = pos_min;
                    min_dis = dis_cand;
                    pos_min = i;
                }
                else if(next_min > dis_cand){
                    next_min =  dis_cand;
                    pos_next = i;
                }
            }
            //visit[pos_min]++;
            //visit[pos_next]++;
            if(pos_min < pos_next)
            {
                near_node[k][0]= make_pair(pos_min,min_dis);
                near_node[k][1]= make_pair(pos_next,candidate[j]);
            }
            else {
                near_node[k][0] = make_pair(pos_next,next_min);
                near_node[k][1] = make_pair(pos_min,candidate[j]);
            }
            k++;
        }
        qDebug() << "near";
        for(int i = 0; i < near_node.size(); i++)
        {
            qDebug() << near_node[i][0].first << ' ' << near_node[i][0].second << ' ' <<near_node[i][1].first << ' ' << near_node[i][1].second;
        }
        qDebug() << "sort";

        //sort(near_node.begin(),near_node.end(),cmp_vec);

        for (int i = 0; i < near_node.size() - 1; ++i) {
             int minIndex = i;
             for (int j = i + 1; j < near_node.size(); ++j) {
                if (near_node[i][0].first > near_node[j][0].first) {
                    minIndex = j;
                }
             }
             if (minIndex != i) {
                 swap(near_node[i], near_node[minIndex]);
             }
        }
        for(auto k : near_node)
        {
            for(auto s: k)
            {
                qDebug() << s.first << ' ' << s.second;
            }
        }
        vector<int> detour_cand;
        int in,out;
        in = near_node[0][0].first;
        out = near_node[near_node.size()-1][1].first;
        for(int i = 0; i < near_node.size(); i++)
        {
            detour_cand.push_back(near_node[i][1].second);
        }
        vector<int> result;
        for(int i = 0; i < Bpath.size(); i++)
        {
            if(i == in)
            {
                vector<int> tmp;
                int dis_tmp = 0;
                tmp = Dijkstra(Bpath[i], detour_cand[0],dis_tmp);
                result.insert(result.end(),tmp.begin(),tmp.end());
                result.pop_back();
                int pos_num = detour_cand[0];
                for(int t = 1; t < detour_cand.size(); t++)
                {
                    tmp.clear();
                    tmp = Dijkstra(pos_num, detour_cand[t],dis_tmp);
                    result.insert(result.end(),tmp.begin(),tmp.end());
                    result.pop_back();
                    pos_num = detour_cand[t];
                }
                tmp.clear();
                tmp = Dijkstra(pos_num,Bpath[out],dis_tmp);
                result.insert(result.end(),tmp.begin(),tmp.end());
                i = out;
                continue;
            }
            result.push_back(Bpath[i]);
        }
        for(auto c : result)
        {
            qDebug() << c;
        }
        int clear_num = 0;
        for(int i = 0; i < result.size()-1; i++)
        {
            int tmp_s = result[i];
            int tmp_t = result[i+1];
            QString cmd2=QString("addquerypathedge_detour(%0,%1,%2,%3)")
                    .arg(p[tmp_s].x)
                    .arg(p[tmp_s].y)
                    .arg(p[tmp_t].x)
                    .arg(p[tmp_t].y);
            m_view->page()->runJavaScript(cmd2);
            clear_num++;
        }
        clear.push_back(clear_num);
    }
    if(total)
    {
        int s = ui->query_start->text().toInt();
        int t = ui->query_end->text().toInt();
        while(candidate.size() > 0){
            int min_val = 100000;
            int pos = 0;
            for(int i = 0; i < candidate.size(); i++)
            {
                vector<int> tmp;
                int dis_tmp = 0;
                tmp = Dijkstra(s, candidate[i],dis_tmp);
                if(dis_tmp < min_val)
                {
                    min_val = dis_tmp;
                    pos = i;
                }
            }
            int pos_num = candidate[pos];
            candidate.erase(candidate.begin()+pos);
            int dis_tmp = 0;
            vector<int> tmp;
            tmp = Dijkstra(s, pos_num,dis_tmp);
            result.insert(result.end(),tmp.begin(),tmp.end());
            result.pop_back();
            s = pos_num;
        }
        int dis_tmp = 0;
        vector<int> tmp;
        tmp = Dijkstra(s, t,dis_tmp);
        result.insert(result.end(),tmp.begin(),tmp.end());
        for(auto c : result)
        {
            qDebug() << c;
        }
        int clear_num = 0;
        for(int i = 0; i < result.size()-1; i++)
        {
            int tmp_s = result[i];
            int tmp_t = result[i+1];
            QString cmd2=QString("addquerypathedge_total(%0,%1,%2,%3)")
                    .arg(p[tmp_s].x)
                    .arg(p[tmp_s].y)
                    .arg(p[tmp_t].x)
                    .arg(p[tmp_t].y);
            m_view->page()->runJavaScript(cmd2);
            clear_num++;
        }
        clear.push_back(clear_num);
    }
}

void MainWindow::on_btn_clear_clicked()
{
    QString cmd=QString("removeOverlay(%0)")
            .arg(clear[clear.size()-1]);
    m_view->page()->runJavaScript(cmd);
    clear.pop_back();
}
void MainWindow::on_pushButton_4_clicked()
{
    QString cmd="clearOverlay()";
    m_view->page()->runJavaScript(cmd);
    clear.clear();
    edgeNum = 0;
    G->clear();
    qDebug()<<"g.size()"<<G->size();
    memset(pre, 0, sizeof pre);
    memset(p, 0, sizeof(struct point)*10000);
    memset(e , 0, sizeof(struct edge)*10000);
    memset(keys, 0, sizeof(struct key)*10000);
}

void MainWindow::on_btn_keys_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"打开文件","file:///" + qApp->applicationDirPath());
    ui->textEdit->setText(path);

    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        //ui->textEdit->append(line);
        QStringList subs = line.split(" ");
        double lng=0,lat=0,price = 0, score = 0, grade = 0;
        QString name;
        int number = 0, type = 0;
        number = subs.at(0).toInt();
        lng = subs.at(1).toDouble();
        lat = subs.at(2).toDouble();
        price = subs.at(3).toDouble();
        score = subs.at(4).toDouble();
        grade = subs.at(5).toDouble();
        type = subs.at(6).toInt();
        name = subs.at(7);
        p[number].num = number;
        p[number].x = lng;
        p[number].y = lat;
        keys[keysNum].number = number;
        keys[keysNum].price = price;
        keys[keysNum].score = score;
        keys[keysNum].grade = grade;
        keys[keysNum].type = type;
        keysNum++;
        QString cmd=QString("addkeysmarker(\"%0\",\"%1\",\"%2\",\"%3\",\"%4\",\"%5\",\"%6\",\"%7\")")
            .arg(lng)
            .arg(lat)
            .arg(number)
            .arg(price)
            .arg(score)
            .arg(grade)
            .arg(type)
            .arg(name);
        m_view->page()->runJavaScript(cmd);
    }
}


vector<int> Dijkstra(int Start, int End, int &dis){
    //qDebug()<<Start<<' '<<End<<endl;
    vector <int> ret;
    int dist[maxn];
    int last;
    fill(dist, dist + 150, inf);//
    fill(pre, pre + 150, -1);
    dist[Start] = 0;
    while(!que.empty())
        que.pop();
    que.push(P(0, Start));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int tail = p.second;
        if(p.first > dist[tail])
            continue;
        for(unsigned int i = 0; i < G[tail].size(); ++i){
            site s = G[tail][i];
            if(dist[tail] + s.dis < dist[s.to]){// 松弛
                dist[s.to] = dist[tail] + s.dis;
                pre[s.to] = tail;
                que.push(P(dist[s.to],s.to));// 将弧尾加入队列
            }
        }
    }
    vector<int> pathPrint = getpath(End);
    vector<int>::iterator it=pathPrint.begin();
    ret.push_back(*it);
    // printf("从点%d到点%d最短路线为：",Start,End);
    //qDebug()<<*it<<' ';
    last = *it;
    ++it;
    for(; it!=pathPrint.end(); it++){
        ret.push_back(*it);
        //qDebug()<<*it<<' ';
        last = *it;
    }
    for(unsigned i = 0; i< ret.size()-1;i++)
    {
        int s=ret[i];
        for(unsigned j = 0; j < G[s].size();j++)
        {
            if(G[s][j].to == ret[i+1])
            {
                dis += G[s][j].dis;
                break;
            }
        }
    }
    //qDebug()<<dis<<'c';
    return ret;
}
vector<int> getpath(int t) {//s -> t路径生成
    vector<int> path;
    while(t!=-1) {//从 t 倒着走，一直走到 s
        path.push_back(t);
        t=pre[t];
    }
    reverse(path.begin(),path.end());
    return path;
}



