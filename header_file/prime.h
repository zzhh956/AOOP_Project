#ifndef PRIME_H
#define PRIME_H

#include "mymath.h"

class Prime : public MyMath
{
    public:
        Prime(){}
        ~Prime(){}
        string solve(string s);
};

#endif // PRIME_H
