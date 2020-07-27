#ifndef MYTREE_H
#define MYTREE_H

#include "problemset.h"

struct node {
     struct node *left; //left child node
     struct node *right; //right child node
     string keyStr;
     int keyInt;
};

class MyTree : public ProblemSet
{
    public:
        MyTree(){}
        ~MyTree(){}
        virtual string solve(string){}
        vector<string> stringtoVectorString(string s);
        vector<double> stringtoVectorDouble(string);
        string vectorDoubleToString(vector<double>);
};

#endif // MYTREE_H
