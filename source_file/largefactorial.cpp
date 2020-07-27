#include "..\\header_file\\largefactorial.h"

string LargeFactorial::solve(string s){
    k = stoi(s);
    if(k == 0 || k == -1)
        return "1";

    int num[9000] = {0};
    length = 1;
    carry = 0;
    num[0]=1;

    for(int i=2; i<=k; i++){
        for(int j=0; j<length; j++){
            num[j] *= i;
            num[j] += carry;
            carry = num[j]/1000;
            num[j] %= 1000;
        }
        while(carry){
            num[length] = carry%1000;
            carry = carry/1000;
            length++;
        }
    }

    ans = "\0";
    for(int i=length-1; i>=0; i--){
        if((i != length-1) && (num[i] < 10))
            ans += "00";
        else if((i != length-1) && (num[i] < 100))
            ans += "0";
        ans += to_string(num[i]);
    }

    return ans;
}
