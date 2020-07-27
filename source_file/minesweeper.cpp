#include "..\\header_file\\minesweeper.h"

string Minesweeper::solve(string s)
{
    v = stringtoVectorString(s);
    r = stoi(v[0]);
    c = stoi(v[1]);

    v.erase(v.begin());
    v.erase(v.begin());

    int map[r+2][c+2];
    for(int i=0;i<r+2;i++)
        for(int j=0;j<c+2;j++)
            map[i][j]=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(v[i][j]=='*'){
                map[i+1][j+1]=-10;
                for(int a=-1; a<2; a++)
                    for(int b=-1; b<2; b++)
                        map[i+1+a][j+1+b]++;
            }
        }
    }

    ans = "\0";
    char map2[r][c];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(map[i+1][j+1]<0)
                map2[i][j]='*';
            else
                map2[i][j]=map[i+1][j+1]+48;
            ans+=map2[i][j];
        }
        if(i!=r-1)
            ans+=' ';
    }

    return ans;
}
