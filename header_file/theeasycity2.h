#ifndef THEEASYCITY2_H
#define THEEASYCITY2_H

#include "mydatabase.h"

class TheEasyCity2 : public MyDataBase
{
    QSqlQuery query;
    public:
        TheEasyCity2(QSqlDatabase db) : query(db){}
        ~TheEasyCity2(){}
        string solve(string s);
};

#endif // THEEASYCITY2_H
