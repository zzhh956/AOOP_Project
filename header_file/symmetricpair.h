#ifndef SYMMETRICPAIR_H
#define SYMMETRICPAIR_H

#include "mydatabase.h"

class SymmetricPair : public MyDataBase
{
    QSqlQuery query;
    public:
        SymmetricPair(QSqlDatabase db) : query(db){}
        ~SymmetricPair(){}
        string solve(string s);
};

#endif // SYMMETRICPAIR_H
