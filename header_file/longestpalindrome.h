#ifndef LONGESTPALINDROME_H
#define LONGESTPALINDROME_H

#include "mystring.h"

class LongestPalindrome : public MyString
{
    int n;
    int maxLength;
    public:
        LongestPalindrome(){}
        ~LongestPalindrome(){}
        string solve(string s);
};

#endif // LONGESTPALINDROME_H
