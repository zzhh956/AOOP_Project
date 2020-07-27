#include "..\\header_file\\prime.h"

string Prime::solve(string s)
{
    vector<int> num = stringtoVectorInt(s);

    for(int i=0; i<num.size(); i++){
        bool p = true;
        for(int j=2; j<=(sqrt(num[i])); j++)
            if(!(num[i] % j)){
                p = false;
                num[i]--;
                j=1;
            }
    }

    return vectorIntToString(num);
}
