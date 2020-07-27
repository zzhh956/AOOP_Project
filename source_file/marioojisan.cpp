#include "..\\header_file\\marioojisan.h"

string MarioOjisan::solve(string s)
{
    v = stringtoVectorInt(s);
    type = v[0];
    coin = 0;
    sum = 1;

    if(type <= 2)
        return to_string(2);
    else{
        sum = v[1];
        coin = 2;
        for (int i = 2; i < v.size()-1; i++)
            if (sum < v[i] && sum + v[i] < v[i + 1]){
                sum += v[i];
                coin++;
            }
    }

    return to_string(coin);
}
