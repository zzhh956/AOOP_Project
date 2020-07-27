#ifndef ESCAPE_H
#define ESCAPE_H

#include "myother.h"
#include <sstream>

class Escape : public MyOther
{
    int row;
    int col;
    string **joe;
    string **fire;
    stringstream ss;
    vector<string> maze;
    public:
        Escape(){}
        ~Escape(){}
        string solve(string s);
};

#endif // ESCAPE_H
