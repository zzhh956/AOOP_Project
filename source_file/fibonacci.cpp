#include "..\\header_file\\fibonacci.h"

string Fibonacci::solve(string s)
{
    v = stringtoVectorInt(s);
    int digit[60];

    digit[0]=0;
    digit[1]=1;
    for(int i=2; i<60; i++)
        digit[i] = (digit[i-1] + digit[i-2]) % 10;

    for(int i=0;i<v.size();i++)
        v[i] = digit[fib(v[i] % 60)];

    return vectorIntToString(v);
}

long long int Fibonacci::fib(int n)
{
    int sum1 = 0, sum2 = 1, sum3 = 0;

    if(n == 0)
        return sum1;
    else if(n == 1)
        return sum2;

    for(int i = 2; i <= n; i++){
        sum3 = sum1+sum2;
        if(sum3 >= 60)
            sum3 %= 60;
        sum1 = sum2;
        sum2 = sum3;
    }

    return sum3;
}
