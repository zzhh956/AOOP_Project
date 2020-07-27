#include "..\\header_file\\add1.h"

string Add1::solve(string s)
{
    v = stringtoVectorInt(s);

    for(int i=0; i<v.size(); i++)
        v[i]++;

    return vectorIntToString(v);
}
