#ifndef MYMATH_H
#define MYMATH_H

#include "problemset.h"

class MyMath : public ProblemSet
{
    public:
        MyMath(){}
        ~MyMath(){}
        virtual string solve(string){}
        vector<int> stringtoVectorInt(string);
        string vectorIntToString(vector<int>);
        vector<double> stringtoVectorDouble(string);
        string vectorDoubleToString(vector<double>);
        vector<string> stringtoVectorString(string s);
};

#endif // MYMATH_H
