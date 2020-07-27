#include "..\\header_file\\mytree.h"

vector<string> MyTree::stringtoVectorString(string s)
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

vector<double> MyTree::stringtoVectorDouble(string s)
{
    vector<double> num;
    string::size_type prev = 0, pos = 0;

    while( (pos = s.find_first_of(' ', pos)) != string::npos ){
        num.push_back( stod( s.substr(prev, pos-prev) ) );
        prev = ++pos;
    }
    num.push_back( stod( s.substr(prev) ) );

    return num;
}

string MyTree::vectorDoubleToString(vector<double> num)
{
    string s;

    for(int i=0; i<num.size(); i++){
        s += to_string(num[i]);
        if(i < num.size()-1)
            s += ' ';
    }

    return s;
}
