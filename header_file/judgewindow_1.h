#ifndef JUDGEWINDOW_1_H
#define JUDGEWINDOW_1_H

#include <QSqlResult>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <string>
#include <QtGlobal>
#include <fstream>
#include <QTimer>
#include <QElapsedTimer>
#include <iostream>
#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
using namespace std;

namespace Ui {
class JudgeWindow_1;
}

class JudgeWindow_1 : public QWidget
{
    Q_OBJECT

    public:
        explicit JudgeWindow_1(QWidget *parent = nullptr);
        ~JudgeWindow_1();
        string getData(int floor,int b, int& datatimes);//input 0-26
        bool submitData(string ans);
        qint64 getSpendTime(){return costtime;}
        int getConditionNum(){return rand()%300+1;}//return 1-300
        int getDistance(){return totaldistance;}
        void scheduleEnd();
        void setdisabled();
        long long current_condition[27][4];
        QLineEdit showline[27][4];

private slots:
        void on_pushButton_clicked();

private:
        QLabel F[27];
        QCheckBox giveup[27];
        int floordatatimes[27];
        int floorcurrenttimes[27];
        int QuesPass[27][2];
        Ui::JudgeWindow_1 *ui;
        string ans;
        QElapsedTimer timer;
        qint64 costtime;
        int movedistance;
        int totaldistance;
        int prefloor;    
};

#endif // JUDGEWINDOW_1_H
