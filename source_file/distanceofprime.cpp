#include "..\\header_file\\distanceofprime.h"

string DistanceOfPrime::solve(string s)
{
    v = stringtoVectorInt(s);

    for(int i=0; i<v.size(); i++){
        if(v[i] == 2){
            v[i] = 0;
            continue;
        }

        if(v[i] & 1)
            min = max = v[i];
        else{
            min = v[i] - 1;
            max = v[i] + 1;
        }

        for(int j=3, k=3; j<=sqrt(min) || k<=sqrt(max); j+=2, k+=2){
            if(!(min % j)){
                min -= 2;
                j = 1;
            }
            if(!(max % k)){
                max += 2;
                k = 1;
            }
        }

        v[i] = max - min;
    }

    return vectorIntToString(v);
}
