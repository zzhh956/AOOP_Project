#ifndef CLOSEST_PAIR_H
#define CLOSEST_PAIR_H

#include "mymath.h"

class Closest_Longest_Pair : public MyMath
{
    vector<double> v;
    double min;
    double max;
    int length;
    public:
        Closest_Longest_Pair(){}
        ~Closest_Longest_Pair(){}
        string solve(string s);
};

#endif // CLOSEST_PAIR_H
