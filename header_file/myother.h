#ifndef MYOTHER_H
#define MYOTHER_H

#include "problemset.h"

class MyOther : public ProblemSet
{
    public:
        MyOther(){}
        ~MyOther(){}
        virtual string solve(string){}
        vector<string> stringtoVectorString(string s);
        vector<int> stringtoVectorInt(string);
};

#endif // MYOTHER_H
