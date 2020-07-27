#ifndef LONGESTROOT_H
#define LONGESTROOT_H

#include "mytree.h"

class LargestRoot : public MyTree
{
    vector<double> v;
    double max;
    int keep;
    public:
        LargestRoot(){}
        ~LargestRoot(){}
        string solve(string s);
};

#endif // LONGESTROOT_H
