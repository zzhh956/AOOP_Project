#ifndef FACTORIAL_H
#define FACTORIAL_H

#include "mymath.h"

class Factorial : public MyMath
{
    vector<int> v;
    string ans;
    public:
        Factorial(){}
        ~Factorial(){}
        string solve(string s);
};

#endif // 9_FACTORIAL_H
