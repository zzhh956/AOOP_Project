#include "..\\header_file\\closest_longest_pair.h"

string Closest_Longest_Pair::solve(string s)
{
    v = stringtoVectorDouble(s);
    min = DBL_MAX;
    max = DBL_MIN;
    length = 0;

    for(int i=0; i<v.size(); i+=3){
        for(int j=i+3; j<v.size(); j+=3){
           length=(v[i]-v[j]) * (v[i]-v[j]) +
                  (v[i+1]-v[j+1]) * (v[i+1]-v[j+1]) +
                  (v[i+2]-v[j+2]) * (v[i+2]-v[j+2]);
           if(length < min)
               min = length;
           if(length >= max)
               max = length;
        }
    }

    min = sqrt(min);
    int tmp_1 = int( round( ( min - int(min) ) * 100 ) );
    max = sqrt(max);
    int tmp_2 = int( round( ( max - int(max) ) * 100 ) );

    if(tmp_1 > 99){
        min++;
        tmp_1 = 0;
    }
    if(tmp_2 > 99){
        max++;
        tmp_2 = 0;
    }

    return to_string( (int)min ) + "." + to_string( tmp_1 / 10 ) + to_string( tmp_1 % 10 ) + ' ' + to_string( (int)max )+ "." + to_string( tmp_2 / 10 ) + to_string( tmp_2 % 10 );
}
