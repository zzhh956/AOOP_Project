#ifndef GETSIGNATURE_H
#define GETSIGNATURE_H

#include "myother.h"
#include <set>

class GetSignature : public MyOther
{
    vector<int> v;
    int maxlength;
    int start;
    int length;
    int keepnode;
    int node;
    int count;
    public:
        GetSignature():length(0), keepnode(0){}
        ~GetSignature(){}
        string solve(string s);
};

#endif // GETSIGNATURE_H
