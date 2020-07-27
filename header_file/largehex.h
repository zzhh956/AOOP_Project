#ifndef LARGEHEX_H
#define LARGEHEX_H

#include "mymath.h"

class LargeHex : public MyMath
{
    vector<string> v;
    vector<int> ans;
    int maxlength;
    int tmp;
    public:
        LargeHex(){}
        ~LargeHex(){}
        int to_Digits(char s);
        string solve(string s);
        string transtostring(vector<int> n);
};

#endif // 15_LARGEHEX_H
