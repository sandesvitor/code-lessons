/*
    Fibonacci Series:
    0, 1, 1, 2, 3, 5, 8, 13, ...

    fib(n) = if n> 1  [fib(n-2) + fib(n-1)]
             if n = 0 [0]
             if n = 1 [1]

    Time Consuming:
        1) Recursive ==> O(2^n) 
        1) Iterative ==> O(n)

    
    EXCESSIVE RESCURSION => call itself for the same paramethers!

    Optimizing Recursion ==> only call recursive functions we don't
        know the awnser ( O(n) )

        Cache value of know value of result functions and use it
        when needed

        -> "MEMOIZATION METHOD!!!"

*/


int fib(int n){
    if(n <= 1) return n;
    return fib(n-2) + fib(n-1);
}

int F[10];
int fibWithMemoization(int n){
    if(n <= 1){
        F[n] = n;
        return n;
    } else {
        if(F[n-2] == - 1){
            F[n-2] = fibWithMemoization(n-2);
        }
        if(F[n-1] == -1){
            F[n-1] = fibWithMemoization(n-1);
        }
        return F[n-2] + F[n-1];
    }
}

int fibFor(int n){
    int t0 = 0;
    int t1 = 1;
    int s;
    if(n <= 1) return n;
    for (int i = 2; i <= n; i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

#include <iostream>


int main() {
    std::cout << fib(8) << std::endl;
    std::cout << fibFor(8) << std::endl;

    for(int i=0; i<10; i++){
        F[i] = -1;
    }
    std::cout << fibWithMemoization(8) << std::endl;
    return 0;
}