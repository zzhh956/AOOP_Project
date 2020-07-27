#include "..\\header_file\\mystring.h"

string MyString::removePunctuation(string s)
{
    string tmp;
    string::size_type pos = 0, prev = 0;
    while ((pos = s.find_first_of(",.!?", pos)) != string::npos)
    {
        tmp += s.substr(prev, pos - prev);
        prev = ++pos;
    }
    tmp += s.substr(prev);

    return tmp;
};


string MyString::toUpper(string s)
{
    string tmp;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z')
            tmp += s[i]-32;
        else
            tmp += s[i];
    }

    return tmp;
};

vector<string> MyString::stringtoVectorString(string s)
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
