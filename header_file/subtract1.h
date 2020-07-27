#ifndef SUBTRACT1_H
#define SUBTRACT1_H

#include "mymath.h"

class Subtract1 : public MyMath
{
    vector<int> v;
    public:
        Subtract1(){}
        ~Subtract1(){}
        string solve(string s);
};

#endif // SUBTRACT1_H
