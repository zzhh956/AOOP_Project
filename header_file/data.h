#ifndef DATA_H
#define DATA_H

#include <string>
#include <QtGlobal>
#include <fstream>
#include <QTimer>
using namespace std;

class Data
{
    public:
        Data(){}
        qint64 spendtime;
        string testdata;
        string myanswer;
        bool correct;
        int nowfloor;
        int distance;
        int elevatorpeople;
};

#endif // DATA_H
