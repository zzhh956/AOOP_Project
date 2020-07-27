#ifndef THEMEDIAN_H
#define THEMEDIAN_H

#include "mydatabase.h"

class TheMedian : public MyDataBase
{
    QSqlQuery query;
    public:
        TheMedian(QSqlDatabase db) : query(db){}
        ~TheMedian(){}
        string solve(string s);
};

#endif // THEMEDIAN_H
