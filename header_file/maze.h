#ifndef MAZE_H
#define MAZE_H

#include "myother.h"

class Maze:public MyOther
{
    stringstream ss;
    int col;
    int row;
    string ans;
    public:
        Maze(){}
        ~Maze(){}
        string solve(string s);
};

#endif // MAZE_H
