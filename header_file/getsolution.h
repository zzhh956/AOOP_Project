#ifndef GETSOLUTION_H
#define GETSOLUTION_H

#include "mymath.h"

class GetSolution : public MyMath
{
    vector<double> v;
    int N;
    string ans;
    public:
        GetSolution():ans("\0"){}
        ~GetSolution(){}
        string solve(string s);
};

#endif // GETSOLUTION_H
