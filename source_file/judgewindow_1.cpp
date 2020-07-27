#include "..\\header_file\\judgewindow_1.h"
#include "ui_judgewindow_1.h"
#include <QDebug>
#include <cmath>

JudgeWindow_1::JudgeWindow_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow_1)
{
    ui->setupUi(this);

    for(int i=0; i<27; i++){
        string tmp = to_string(i+1) + "F";
        for(int j=0; j<4; j++){
            ui->gridLayout->addWidget(&showline[i][j], i, j);
            showline[i][j].setText(QString::fromStdString("0"));
            showline[i][j].setDisabled(true);
        }
        ui->gridLayout->addWidget(&giveup[i], i, 4);
        F[i].setText(QString::fromStdString(tmp));
        ui->gridLayout->addWidget(&F[i], i, 5);
    }

    ui->lineEdit->setText("0710738");
    ui->lineEdit_2->setText("巴斯昊");
    ui->lineEdit_3->setText("0710846");
    ui->lineEdit_4->setText("林子昊");

    QSqlDatabase database;
    database=QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("123456789");
    database.setPort(3306);
    bool ok=database.open();
    if(ok){
        qDebug()<<"Successful connection.";
    }
    else {
        qDebug()<<"Error connot connection.";
    }

    QSqlQuery query;
    query.exec("drop database if exists Final");
    query.exec("create database Final");
    query.exec("use Final");

    query.exec("drop table if exists testdata");
    query.exec("create table testdata (id char(8)primary key,Floor int,Question TEXT,Answer TEXT)");
    query.exec("load data infile'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata_1225.csv' into table testdata fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");

    query.exec("drop table if exists FinalTable");
    query.exec("create table FinalTable (id char(8)primary key,Nowfloor int,Destination int,Number int)");
    query.exec("load data infile'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/simple_initial_condition.csv' into table FinalTable fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");


    for(int i=0; i<21; i++)
        floordatatimes[i] = 10;
    for(int i=21; i<27; i++)
        floordatatimes[i] = 1;

    movedistance = 0;
    totaldistance=0;
    prefloor = 1;
    for(int i=0;i<27;i++){
        floorcurrenttimes[i] = 0;
        QuesPass[i][0]=0;
        QuesPass[i][1]=0;
    }
}

string JudgeWindow_1::getData(int floor,int b, int& datatimes){
    QSqlQuery query;
    query.exec("use Final");
    QuesPass[floor-1][0]++;
    datatimes = floordatatimes[floor-1];
    floorcurrenttimes[floor-1]++;
    movedistance = abs(floor - prefloor);
    totaldistance+=movedistance;
    prefloor = floor;
    if(b){
        current_condition[floor-1][0]--;
        showline[floor-1][0].setText(QString::fromStdString(to_string(current_condition[floor-1][0])));
    }
    else{
        current_condition[floor-1][1]--;
        showline[floor-1][1].setText(QString::fromStdString(to_string(current_condition[floor-1][1])));
    }

    if(giveup[floor-1].isChecked())
        return "GIVEUP";

    string s;
    s = "select * from testdata where id like'";
    if(floor < 10)
        s += "0" + to_string(floor);
    else
        s += to_string(floor);
    s += "-000";
    if(floorcurrenttimes[floor-1]-1 < 10)
        s += "0" + to_string(floorcurrenttimes[floor-1]-1);
    else
        s += to_string(floorcurrenttimes[floor-1]-1);
    s += "'";

    query.exec(QString::fromStdString(s));
    query.next();
    ans = query.value(3).toString().toStdString();
    if(floor < 22)
        timer.start();

    return query.value(2).toString().toStdString();
}

bool JudgeWindow_1::submitData(string anser){
    if(prefloor < 22){
        costtime = timer.nsecsElapsed();
        costtime /= floordatatimes[prefloor-1];
        current_condition[prefloor-1][2] += costtime;
    }
    showline[prefloor-1][2].setText(QString::fromStdString(to_string(current_condition[prefloor-1][2])));

    if(anser == ans){
        QuesPass[prefloor-1][1]++;
        current_condition[prefloor-1][3] += 10000000000 + pow(2, floorcurrenttimes[prefloor-1]-1);
        showline[prefloor-1][3].setText(QString::fromStdString(to_string(current_condition[prefloor-1][3])));
        return true;
    }
    return false;
}

void JudgeWindow_1::setdisabled()
{
    /*
    for(int i=0; i<27; i++){
        if(i==18 || i==21 || i==22 || i==23 || i==24 || i==25 || i==26)
            giveup[i].setChecked(true);
        giveup[i].setDisabled(true);
    }
    */
    ui->pushButton->setDisabled(true);
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setDisabled(true);
    ui->lineEdit_3->setDisabled(true);
    ui->lineEdit_4->setDisabled(true);
}

void JudgeWindow_1::scheduleEnd()
{

    ui->pushButton->setEnabled(true);
    /*
    for(int i=0; i<27; i++){
        if(i==18 || i==21 || i==22 || i==23 || i==24 || i==25 || i==26)
            giveup[i].setTristate(true);
        giveup[i].setEnabled(true);
    }
    */
}

void JudgeWindow_1::on_pushButton_clicked()
{
    QSqlDatabase database;
    database=QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("140.113.146.126");
    database.setUserName("aoopstudent");
    database.setPassword("tsaimother");
    database.setPort(3306);
    bool ok=database.open();
    if(ok){
        qDebug()<<"Successful connection2.";
    }
    else {
        qDebug()<<"Error connot connection2.";
    }
    QSqlQuery query;
    query.exec("use aoopstudentuse");
    string s,s2;
    QString l1,l2,l3,l4;
    l1=ui->lineEdit->text();
    l2=ui->lineEdit_2->text();
    l3=ui->lineEdit_3->text();
    l4=ui->lineEdit_4->text();

    //s="insert into floorscore values('"+l1.toStdString()+"','"+l3.toStdString()+"','"+l2.toStdString()+"','"+l4.toStdString()+"',";
    s="insert into floorscore values('0710738','巴斯昊','0710846','林子昊',";
    for(int i=0;i<27;i++){
        s2=s;
        s2+="'"+to_string(i+1)+"',"+"'"+to_string(current_condition[i][2])+"',"+"'"+to_string(QuesPass[i][1])+"',"+"'"+to_string(QuesPass[i][0])+"',"+"'"+to_string(current_condition[i][3])+"')";
        query.exec(QString::fromStdString(s2));
    }
    //s="insert into totalpath values('"+l1.toStdString()+"','"+l3.toStdString()+"','"+l2.toStdString()+"','"+l4.toStdString()+"','";
    s2="insert into totalpath values('0710738','巴斯昊','0710846','林子昊','";
    s2+=(to_string(totaldistance))+"')";
    query.exec(QString::fromStdString(s2));
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->lineEdit_4->setEnabled(true);
}
