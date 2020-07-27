#include "..\\header_file\\subtract1.h"

string Subtract1::solve(string s)
{
    v = stringtoVectorInt(s);

    for(int i=0; i<v.size(); i++)
        --v[i];

    return vectorIntToString(v);
}
