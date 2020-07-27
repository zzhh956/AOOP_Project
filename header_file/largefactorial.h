#ifndef LARGEFACTORIAL_H
#define LARGEFACTORIAL_H

#include "mymath.h"

class LargeFactorial : public MyMath
{
    int k;
    int length;
    int carry;
    string ans;
    public:
        LargeFactorial():length(1), carry(0){}
        ~LargeFactorial(){}
        string solve(string s);
};

#endif // 14_LARGEFACTORIAL_H
