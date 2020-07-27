#include "..\\header_file\\myother.h"

vector<string> MyOther::stringtoVectorString(string s)
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

vector<int> MyOther::stringtoVectorInt(string s)
{
    vector<int> num;
    string::size_type prev = 0, pos = 0;

    while( (pos = s.find_first_of(' ', pos)) != string::npos ){
        num.push_back( stoi( s.substr(prev, pos-prev) ) );
        prev = ++pos;
    }
    num.push_back( stoi( s.substr(prev) ) );

    return num;
}
