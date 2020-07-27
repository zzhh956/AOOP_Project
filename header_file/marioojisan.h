#ifndef MARIOOJISAN_H
#define MARIOOJISAN_H

#include "mymath.h"

class MarioOjisan : public MyMath
{
    vector<int> v;
    int type;
    int coin;
    int sum;
    public:
        MarioOjisan(){}
        ~MarioOjisan(){}
        string solve(string s);
};

#endif // MARIOOJISAN_H
