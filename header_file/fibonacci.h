#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "mymath.h"

class Fibonacci : public MyMath
{
    vector<int> v;
    public:
        Fibonacci(){}
        ~Fibonacci(){}
        void countFib();
        long long int fib(int);
        string solve(string s);
};

#endif // FIBONACCI_H

