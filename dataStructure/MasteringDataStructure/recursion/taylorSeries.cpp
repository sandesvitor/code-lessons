/*
    Taylor Series:

    e^x = 1 + x/1 + x²/2! + x³/3! + ... + x^n/n!

    Other recursive functions:
        - sum(n) = sum(n - 1) + n;
        - fact(n) = fact(n - 1) * n;
        - pow(x, n) = pow(x, n-1) * x;

    Remember: CALLING TIME & RETURNING TIME!



*/

#include <stdio.h>

double e(int x, int n){
    static double p=1,f=1;
    double r;
    if(n==0) 
        return 1;    
    r=e(x,n-1);    
    p=p*x;    
    f=f*n;
    return r+p/f;
}

int main()
{
    printf("%lf \n",e(1,10));
    return 0;
}