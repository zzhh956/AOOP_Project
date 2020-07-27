#ifndef SHORTEST_SUM_DISTANCE_H
#define SHORTEST_SUM_DISTANCE_H

#include "mymath.h"

class Shortest_Sum_Distance : public MyMath
{
    vector<int> v;
    const int INF  =  0x3f3f3f3f;
    double dp[1<<21];
    string ans;
    int node;
    public:
        Shortest_Sum_Distance(){}
        ~Shortest_Sum_Distance(){}
        string solve(string s);
};

#endif // 10_SHORTEST_SUM_DISTANCE_H
