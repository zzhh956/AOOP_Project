#ifndef MYDATABASE_H
#define MYDATABASE_H

#include "problemset.h"
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtGlobal>
#include <fstream>
#include <QTimer>
#include <QElapsedTimer>
#include <QWidget>
#include <QCheckBox>
#include <QLineEdit>
#include <sstream>
#include <iomanip>
using namespace std;

class MyDataBase : public ProblemSet
{
    public:
        MyDataBase(){}
        ~MyDataBase(){}
        virtual string solve(string s){}
        vector<string> stringtoVectorString(string s);
};

#endif // MYDATABASE_H
