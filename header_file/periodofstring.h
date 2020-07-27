#ifndef PERIODOFSTRING_H
#define PERIODOFSTRING_H

#include "mystring.h"

class PeriodOfString : public MyString
{
    int length;
    bool period;
    public:
        PeriodOfString(){}
        ~PeriodOfString(){}
        string solve(string s);
};

#endif // 13_PERIODOFSTRING_H
