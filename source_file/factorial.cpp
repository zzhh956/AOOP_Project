#include "..\\header_file\\factorial.h"

string Factorial::solve(string s)
{
    v = stringtoVectorInt(s);
    vector<int> factorial;
    ans = "\0";

    factorial.push_back(1);

    for(int i=0; i<v.size(); i++){
        int count = 0;
        int total = 0;
        int node = 2, keepnode = 2;
        while(total < v[i]){
            if(node > factorial.size()+1){
                for(int k=2; k<=keepnode; k++){
                    if(!(node % k)){
                        count++;
                        node /= k;
                        k--;
                        if(node == 1){
                            factorial.push_back(count);
                            total += count;
                            break;
                        }
                        else if(node <= factorial.size()+1){
                            total += factorial[node-2] + count;
                            factorial.push_back(factorial[node-2] + count);
                            break;
                        }
                    }
                }
            }
            else
                total += factorial[keepnode-2];

            node = ++keepnode;
            count = 0;
        }

        if(total == v[i])
            ans += to_string(keepnode-1) + '!';
        else
            ans += 'N';

        if(i < v.size()-1)
            ans += ' ';
    }

    return ans;
}
