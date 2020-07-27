#include "..\\header_file\\shortest_sum_distance.h"

string Shortest_Sum_Distance::solve(string s)
{
    v = stringtoVectorInt(s);
    ans = "\0";
    node = 0;
    memset(dp, 0, sizeof(dp));

    while(node != v.size()){
        int n = 2 * v[node];
        double dis[n][n];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dis[i][j] = sqrt((v[node+2*i+1]-v[node+2*j+1])*(v[node+2*i+1]-v[node+2*j+1]) + (v[node+2*i+2]-v[node+2*j+2])*(v[node+2*i+2]-v[node+2*j+2]));

        node += 2 * n + 1;

        dp[0] = 0;
        for(int S=1; S<(1<<n); S++){
            dp[S] = INF;
            int i = 0, cnt = 0;
            for(int j=0; j<n; j++)
                if(S & (1<<j)){
                    i = j;
                    cnt ++;
                }
            if(cnt & 1) continue;
            for(int j=0; j<i; j++)
                if(S & (1<<j))
                    dp[S] = min(dp[S], dis[i][j] + dp[S^(1<<i)^(1<<j)]);
        }
        ans += to_string( (int)dp[(1<<n)-1] )+ "." + to_string( ( int( round(dp[(1<<n)-1]*100) ) % 100) / 10 ) + to_string( int( round(dp[(1<<n)-1]*100) ) % 10 );

        if(node != v.size())
            ans += ' ';

    }

    return ans;
}
