#include "..\\header_file\\longestpalindrome.h"

string LongestPalindrome::solve(string s)
{
    s = toUpper(removePunctuation(s));
    n = s.size();
    maxLength = 2;
    bool table[n][n];
    memset(table, 0, sizeof(table));

    int start = 0;
    for(int i=0; i<n-1; i++){
        table[i][i] = true;
        if(s[i] == s[i+1])
            table[i][i+1] = true;
        if(s[start] > s[i])
            start = i;
    }
    table[n-1][n-1] = true;

    for (int k=3; k<=n; k++){
        for (int i=0; i<n-k+1; i++){
            int j = i + k - 1;
            if (table[i+1][j-1] && s[i] == s[j]){
                table[i][j] = true;
                if (k > maxLength){
                    start = i;
                    maxLength = k;
                }
                else if(k == maxLength && s[start] > s[j]){
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    return s.substr(start, maxLength);
}
