#ifndef MYSTRING_H
#define MYSTRING_H

#include "problemset.h"

class MyString : public ProblemSet
{
    public:
        MyString(){}
        ~MyString(){}
        vector<string> stringtoVectorString(string s);
        string removePunctuation(string s);
        string toUpper(string s);
        virtual string solve(string){}
};

#endif // MYSTRING_H
