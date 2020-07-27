#ifndef ADD1_H
#define ADD1_H

#include "mymath.h"

class Add1 : public MyMath
{
    vector<int> v;
    public:
        Add1(){}
        ~Add1(){}
        string solve(string s);
};

#endif // ADD1_H
