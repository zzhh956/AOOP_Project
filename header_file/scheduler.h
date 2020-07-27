#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Scheduler
{
    public:
        Scheduler(){index = 0;}
        int getNowFloor(){return path[index];}
        int getInOut(){return inout[index];}
        void resetIndex(){index = 0;}
        void update(){if(index<path.size())index++;}
        void setSchedule();
        int initial[27][2];
    private:
        vector<int> path;
        vector<int> inout;
        vector<int> destination;
        int index;
};

#endif // SCHEDULER_H
