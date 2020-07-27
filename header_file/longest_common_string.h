#ifndef LONGEST_COMMON_STRING_H
#define LONGEST_COMMON_STRING_H

#include "mystring.h"

class Longest_Common_String : public MyString
{
    vector<string> v;
    int m;
    int n;
    int len;
    int pos;
    public:
        Longest_Common_String(){}
        ~Longest_Common_String(){}
        string solve(string s);
};

#endif // LONGEST_COMMON_STRING_H
