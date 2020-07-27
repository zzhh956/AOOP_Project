#include "..\\header_file\\largehex.h"

int LargeHex::to_Digits(char c)
{
    if(c < 58)
        return c-48;
    else
        return c - 97 + 10;
}

string LargeHex::transtostring(vector<int> n)
{
    string tmp;

    for(int i=0; i<n.size(); i++){
        if(n[n.size()-1-i] < 10)
            tmp += to_string(n[n.size()-1-i]);
        else
            tmp += 97 - 10 + n[n.size()-1-i];
    }

    return tmp;
}

string LargeHex::solve(string s)
{
    v = stringtoVectorString(s);
    v.pop_back();
    maxlength = 0;
    tmp = 0;
    ans.clear();

    int **dig = new int *[v.size()];
    for(int i=0; i<v.size(); i++){
        dig[i] = new int [v[i].size()];
        for(int j=0; j<v[i].size(); j++)
            dig[i][j] = to_Digits(v[i][v[i].size()-1-j]);
        if(maxlength < v[i].size())
            maxlength = v[i].size();
    }

    int carry = 0;
    for(int i=0; i<maxlength; i++){
        tmp = 0;
        for(int j=0; j<v.size(); j++)
            if(v[j].size() > i)
                tmp += dig[j][i];
            else
                tmp += 0;
        tmp += carry;
        carry = tmp / 16;
        ans.push_back(tmp%16);
    }

    if(carry)
        ans.push_back(carry);

    for(int i=0; i<v.size(); i++)
        delete []dig[i];
    delete []dig;

    return transtostring(ans);
}
