#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "myother.h"

class Minesweeper : public MyOther
{
    vector<string> v;
    int r;
    int c;
    string ans;
    public:
        Minesweeper(){}
        ~Minesweeper(){}
        string solve(string s);
};

#endif // MINESWEEPER_H
