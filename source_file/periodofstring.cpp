#include "..\\header_file\\periodofstring.h"

string PeriodOfString::solve(string s)
{
    for(length=1; length<s.length()/2; length++){
        period = true;
        if(!(s.length() % length))
            for(int i=0; i<length && period; i++){
                for(int j=i+length; j<s.length(); j+=length)
                    if(s[i] != s[j]){
                        period = false;
                        break;
                    }
            }
        else
            period = false;
        if(period)
            return to_string(length);
    }

    return to_string(s.length());
}
