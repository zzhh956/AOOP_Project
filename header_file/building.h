#ifndef BUILDING_H
#define BUILDING_H

#include <QSqlResult>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QTimer>
#include <QElapsedTimer>
#include <time.h>
#include "data.h"
#include "judgewindow.h"
#include "floor.h"
#include "scheduler.h"
#include "problems.h"

using namespace std;

class Building : public QObject
{
    Q_OBJECT

    public:
        Building();
        void run();
        Data getData(){return data;}
        void startSimulation();
        void setCheckfloor(int f){data.nowfloor = f;}
    private:
        Floor *floor[27];
        JudgeWindow judgewindow;
        Data data;
        Scheduler scheduler;
        QTimer *timer;

    public slots:
        void update();
    signals:
        void updateGUI();
};

#endif // BUILDING_H
