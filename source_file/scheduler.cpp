#include "..\\header_file\\scheduler.h"

void Scheduler::setSchedule()
{
    bool end = false;
    bool up = true;
    int people = 0;
    int node = 0;
    int go;

    do{
        while(people < 10){
            if(initial[node][1] != 0){   
                initial[node][1]--;
                people++;
                path.push_back(node+1);
                inout.push_back(1);
                destination.push_back(initial[node][0]);
            }
            else if(initial[node][1] == 0){
                go = node;
                if(up)
                    do{
                        go++;
                    }while(go <= 26 && !(initial[go][1] && initial[go][0] > go+1));
                else
                    do{
                         go--;
                    }while(go >= 0 && !(initial[go][1] && initial[go][0] < go+1));

                if( ( (go > 26 || go < 0) || (go+1 == initial[node][0]) ) && people )
                    break;
                else if( go > 26 && !people){
                    go = 26;
                    up = false;
                }
                else if( go < 0 && !people){
                    go = 1;
                    up = true;
                }
                node = go;
            }
        }

        sort(destination.begin(), destination.end());
        if(!up)
            reverse(destination.begin(), destination.end());

        for(int i=0; i<destination.size(); i++){
            people--;
            node = destination[i] - 1;
            path.push_back(destination[i]);
            inout.push_back(0);
        }
        destination.clear();

        if(initial[node][0] > node+1)
            up = true;
        else
            up = false;

        end = true;
        for(int i=0; i<27; i++)
            if(initial[i][1])
                end = false;

    }while(!end);

    path.push_back(0);
}
