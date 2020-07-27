#include "..\\header_file\\mydatabase.h"

vector<string> MyDataBase::stringtoVectorString(string s)
{
    vector<string> v;
    string::size_type prev = 0, pos = 0;

    while( (pos = s.find_first_of(' ', pos)) != string::npos ){
        v.push_back(s.substr(prev, pos-prev));
        prev = ++pos;
    }
    v.push_back(s.substr(prev));

    return v;
}
