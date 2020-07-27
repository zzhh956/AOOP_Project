#include "..\\header_file\\treewalk.h"

string TreeWalk::solve(string s)
{
    v = stringtoVectorString(s);
    ans = "\0";
    length = v[0].length();
    int pre[length];
    int in[length];

    for(int i=0; i<length; i++){
        pre[i] = int(v[0][i]);
        in[i] = int(v[1][i]);
    }
    getPostOrder(in, pre, length, ans);

    return ans;
}

int TreeWalk::search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void TreeWalk::getPostOrder(int in[], int pre[], int n, string& ans)
{
    int root = search(in, pre[0], n);

    if (root != 0)
        getPostOrder(in, pre + 1, root, ans);

    if (root != n - 1)
        getPostOrder(in + root + 1, pre + root + 1, n - root - 1, ans);

    ans += pre[0];
}
