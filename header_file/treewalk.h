#ifndef TREEWALK_H
#define TREEWALK_H

#include "mytree.h"

class TreeWalk : public MyTree
{
    vector<string> v;
    string ans;
    int length;
    public:
        TreeWalk(){}
        ~TreeWalk(){}
        int search(int arr[], int x, int n);
        void getPostOrder(int in[], int pre[], int n, string& ans);
        string solve(string s);
};

#endif // TREEWALK_H
