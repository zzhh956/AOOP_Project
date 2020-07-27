#ifndef DISTANCEOFPRIME_H
#define DISTANCEOFPRIME_H

#include "mymath.h"

class DistanceOfPrime : public MyMath
{
    vector<int> v;
    int min;
    int max;
    public:
        DistanceOfPrime(){}
        ~DistanceOfPrime(){}
        string solve(string s);
};

#endif // DISTANCEOFPRIME_H
