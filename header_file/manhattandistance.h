#ifndef MANHATTANDISTANCE_H
#define MANHATTANDISTANCE_H

#include "mydatabase.h"

class ManhattanDistance : public MyDataBase
{
    QSqlQuery query;
    public:
        ManhattanDistance(QSqlDatabase db) : query(db){}
        ~ManhattanDistance(){}
        string solve(string s);
};

#endif // MANHATTANDISTANCE_H
