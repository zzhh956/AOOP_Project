#ifndef PROBLEMSET_H
#define PROBLEMSET_H

#include <iostream>
#include <QString>
#include <string>
#include <QDebug>
#include <vector>
#include <cmath>
#include <float.h>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

class ProblemSet
{
    public:
        ProblemSet(){}
        virtual ~ProblemSet(){}
        virtual string solve(string s) = 0;
};

#endif // PROBLEMSET_H
