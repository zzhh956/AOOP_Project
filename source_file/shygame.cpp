#include "..\\header_file\\shygame.h"

string ShyGame::solve(string s)
{
    v = stringtoVectorInt(s);
    ans = "\0";
    count = 0;

    int person, tmp;
    for(int i=1; i<v.size(); i++){
        if(v[i]%2==0)
            person = 1;
        else
            person = 2;
        for(int j=3; j<=v[0]; j++){
            tmp = (person - 1 + v[i]) % j + 1;
            person = tmp;
        }
        ans += to_string(person);
        if(i != v.size()-1)
            ans += " ";
    }

    return ans;
}
