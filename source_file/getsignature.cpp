#include "..\\header_file\\getsignature.h"

string GetSignature::solve(string s)
{
    v = stringtoVectorInt(s);

    /*
    int asktosign[v[0]];
    vector<int> visited(v[0], 0);
    bool check[v[0]];
    maxlength = 0;
    start = 0;

    for(int i=0; i<v[0]; i++)
        asktosign[v[2*i+1]-1] = v[2*(i+1)];

    for(int i=0; i<v[0]; i++){
        node = i;
        set<int> s;
        s.insert(node);
        memset(check, 0, sizeof(check));

        while(!check[node] && visited[node] == 0){
            check[node] = true;
            s.insert(node);
            node = asktosign[node] - 1;
            for(int j : s)
                visited[j]++;
        }

        if(s.count(node) == 0)
            for(int j : s)
                visited[j] += visited[node];

        if(visited[i] > maxlength){
            start = i;
            maxlength = visited[i];
        }
        else if( (visited[i] == maxlength) && i < start){
            start = i;
            maxlength = visited[i];
        }
    }
    */

    keepnode = 0;
    length = 0;
    node = 0;
    count = 0;
    int asktosign[v[0]];
    bool check[v[0]];
    bool from[v[0]];
    memset(from, 0, sizeof(from));

    for(int i=0; i<v[0]; i++){
        asktosign[v[2*i+1]-1] = v[2*(i+1)];
        from[v[2*(i+1)]-1] = true;
    }

    for(int i=0; i<v[0]; i++){
        if(from[i])
            continue;
        node = i;
        count = 0;
        memset(check, 0, sizeof(check));

        while(!check[node]){
            check[node] = true;
            count++;
            node = asktosign[node] - 1;
        }

        if(length < count){
            keepnode = i;
            length = count;
        }
        else if( (length == count) && i < keepnode){
            keepnode = i;
            length = count;
        }
    }

    return to_string(keepnode+1);
}
