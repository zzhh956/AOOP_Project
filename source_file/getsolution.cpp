#include "..\\header_file\\getsolution.h"

string GetSolution::solve(string s)
{
    v = stringtoVectorDouble(s);
    N = v[0];
    ans = "\0";
    double matrix[N][N+1];
    for(int i=0; i<N; i++){
        matrix[i][N] = v[N*N+i+1];
        for(int j=0; j<N; j++)
            matrix[i][j] = v[i*N+j+1];
    }

    double tmp;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(matrix[i][i] > -1e-9 && matrix[i][i] < 1e-9){
                if((matrix[j][i] > 1e-9 || matrix[j][i] < -1e-9) && (matrix[i][j] > 1e-9 || matrix[i][j] < -1e-9))
                    for(int k=0; k<N+1; k++){
                        tmp = matrix[j][k];
                        matrix[j][k] = matrix[i][k];
                        matrix[i][k] = tmp;
                    }
            }
            if((matrix[i][i] < -1e-9 || matrix[i][i] > 1e-9) && (matrix[j][i] > 1e-9 || matrix[j][i] < -1e-9))
                for(int k=N; k>=i; k--)
                    matrix[j][k] -= matrix[i][k] * matrix[j][i] / matrix[i][i];
        }
    }

    for(int i=N-1; i>=0; i--){
        matrix[i][N] /= matrix[i][i];
        matrix[i][i] /= matrix[i][i];
        for(int j=i-1; j>=0; j--){
            if((matrix[j][i] > 1e-9 || matrix[j][i] < -1e-9))
                for(int k=N; k>=i; k--)
                    matrix[j][k] -= matrix[i][k] * matrix[j][i];
        }
    }

    string s1;
    for(int i=0; i<N; i++){
        if(matrix[i][N] > -1e-9 && matrix[i][N] < 1e-9)
            matrix[i][N] = 0;
        s1 = to_string(matrix[i][N]);
        s1 = s1.substr(0, s1.find(".")+4);
        if(s1[s1.size()-1] > '4')
            if(s1[s1.size()-2] < '9')
                s1[s1.size()-2]++;
            else{
                s1[s1.size()-2] = '0';
                if(s1[s1.size()-3] < '9')
                    s1[s1.size()-3]++;
                else{
                    s1[s1.size()-3] = '0';
                    for(int i=0; i<=s1.size()-5; i++){
                        if(s1[s1.size()-5-i] < '9'){
                            s1[s1.size()-5-i]++;
                            break;
                        }
                        else
                            s1[s1.size()-5-i] = '0';
                    }
                }
            }
        s1.pop_back();

        ans += s1;
        if(i<N-1)
            ans += " ";
    }

    return ans;
}
