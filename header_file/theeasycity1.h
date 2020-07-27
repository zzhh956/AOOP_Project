#ifndef THEEASYCITY1_H
#define THEEASYCITY1_H

#include "mydatabase.h"

class TheEasyCity1 : public MyDataBase
{
    QSqlQuery query;
    public:
        TheEasyCity1(QSqlDatabase db) : query(db){}
        ~TheEasyCity1(){}
        string solve(string s);
};

#endif // THEEASYCITY1_H
