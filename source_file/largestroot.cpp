#include "..\\header_file\\largestroot.h"

string LargestRoot::solve(string s)
{
    v = stringtoVectorDouble(s);
    max = 0;
    keep = v.size()/2;

    for(int i=v.size()/2-1; i>=0; i--){
        v[i] = v[i] + ( v[2*i+1] + v[2*i+2] ) / 2;
        if(max <= v[i]){
            max = v[i];
            keep = i+1;
        }
    }

    for(int i=v.size()/2; i<v.size(); i++){
        if(max <= v[i]){
            max = v[i];
            keep = i+1;
        }
    }

    int tmp = int(round( ( max - int(max) )*1000));

    if(tmp > 999){
        max++;
        tmp = 0;
    }

    return to_string(keep) + ':' + to_string( (int)max )+ "." + to_string( tmp / 100 ) + to_string( (tmp % 100) / 10 ) + to_string( tmp % 10 );
}
