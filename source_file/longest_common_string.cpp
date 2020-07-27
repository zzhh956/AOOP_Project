#include "..\\header_file\\longest_common_string.h"

string Longest_Common_String::solve(string s)
{
    v = stringtoVectorString(s);
    v[0] = toUpper(removePunctuation(v[0]));
    v[1] = toUpper(removePunctuation(v[1]));
    m = v[0].size();
    n = v[1].size();

    int LCS[m + 1][n + 1];
    len = 0;
    pos = 0;

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0)
                LCS[i][j] = 0;
            else if(v[0][i - 1] == v[1][j - 1]){
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                if(len < LCS[i][j]){
                    len = LCS[i][j];
                    pos = i;
                }
                else if(len == LCS[i][j] && v[0][pos-len] > v[0][i-len]){
                    len = LCS[i][j];
                    pos = i;
                }
            }
            else
                LCS[i][j] = 0;
        }
    }

    return v[0].substr(pos-len, len);
}
