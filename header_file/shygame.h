#ifndef SHYGAME_H
#define SHYGAME_H

#include "mymath.h"

class ShyGame : public MyMath
{
    vector<int> v;
    string ans;
    int count;
    public:
        ShyGame(){}
        ~ShyGame(){}
        string solve(string s);
};

#endif // SHYGAME_H
