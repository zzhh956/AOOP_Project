#include "..\\header_file\\building.h"

Building::Building(){
    floor[0] = new Floor(new F1);
    floor[1] = new Floor(new F2);
    floor[2] = new Floor(new F3);
    floor[3] = new Floor(new F4);
    floor[4] = new Floor(new F5);
    floor[5] = new Floor(new F6);
    floor[6] = new Floor(new F7);
    floor[7] = new Floor(new F8);
    floor[8] = new Floor(new F9);
    floor[9] = new Floor(new F10);
    floor[10] = new Floor(new F11);
    floor[11] = new Floor(new F12);
    floor[12] = new Floor(new F13);
    floor[13] = new Floor(new F14);
    floor[14] = new Floor(new F15);
    floor[15] = new Floor(new F16);
    floor[16] = new Floor(new F17);
    floor[17] = new Floor(new F18);
    floor[18] = new Floor(new F19);
    floor[19] = new Floor(new F20);
    floor[20] = new Floor(new F21);
    floor[21] = new Floor(new F22(judgewindow.getDatabase()));
    floor[22] = new Floor(new F23(judgewindow.getDatabase()));
    floor[23] = new Floor(new F24(judgewindow.getDatabase()));
    floor[24] = new Floor(new F25(judgewindow.getDatabase()));
    floor[25] = new Floor(new F26(judgewindow.getDatabase()));
    floor[26] = new Floor(new F27(judgewindow.getDatabase()));

    //---------------------------------------------------

    judgewindow.show();
    int n = judgewindow.getConditionNum();

    QSqlQuery query(judgewindow.getDatabase());
    query.exec("use final");

    string s = "select * from peoplelist where id like '%";

    if(n < 10)
        s += "0000" + to_string(n);
    else
        s += to_string(n);
    s += "-%'";
    query.exec(QString::fromStdString(s));

    for(int i=0; i<27; i++){
        query.next();
        scheduler.initial[i][0] = query.value(2).toInt();
        scheduler.initial[i][1] = query.value(3).toInt();
    }
    //---------------------------------------------------
    scheduler.setSchedule();
    data.elevatorpeople = 0;
    data.distance = 0;
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this, SLOT(update()));
}

void Building::run()
{
    //answer
    int times;
    string sub = judgewindow.getData(data.nowfloor-1, scheduler.getInOut(), times);
    data.testdata = sub;
    string ans;
    if(sub != "GIVEUP"){
        for(int i=0;i<times;i++)
            ans = floor[data.nowfloor-1]->p->solve(sub);
        data.correct = judgewindow.submitData(ans);
    }
    else{
        ans = "";
        data.correct = 0;
    }

    data.myanswer = ans;

    //distance
    data.distance = judgewindow.getDistance();

    //elevatorpeople
    if(scheduler.getInOut())
        data.elevatorpeople++;
    else
        data.elevatorpeople--;

    //time
    if(sub != "GIVEUP" && data.nowfloor < 22)
        data.spendtime = judgewindow.getSpendTime();
    else
        data.spendtime = 0;
}

void Building::startSimulation()
{
    scheduler.resetIndex();
    timer->start(100);
    timer->setSingleShot(true);
}

void Building::update()
{
    data.nowfloor = scheduler.getNowFloor();
    if(data.nowfloor){
        run();
        scheduler.update();
        timer->start(100);
    }
    else{
        judgewindow.scheduleEnd();
        timer->stop();
    }

    emit this->updateGUI();
}
