#ifndef LONGESTSHORTESTDISTANCE_H
#define LONGESTSHORTESTDISTANCE_H

#include "mydatabase.h"

class LongestShortestDistance : public MyDataBase
{
    QSqlQuery query;
    public:
        LongestShortestDistance(QSqlDatabase db) : query(db){}
        ~LongestShortestDistance(){}
        string solve(string s);
};

#endif // LONGESTSHORTESTDISTANCE_H
