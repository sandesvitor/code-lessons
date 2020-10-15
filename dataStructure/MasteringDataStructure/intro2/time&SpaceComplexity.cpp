/*
    Time Complexity depends on the procedure!

    Ex:

    Array with n elements ---> "n" represents a degree (ORDER OF N)

    ===> "o(n)"

    For nested for loops ===> o(n^2)

    Time complexity is written as a degree of a polynomial

    o(log 2 n):

        for(int i = n: i>1; i = i/2){....}

    Matrices ---> if processing all the elements of a matrice n x n  => o(n^2)
             ---> if processing just a row => o(n)

    Binary Tree ---> Depends on the height o(log 2 n)
                ---> For all elements (o(n))

    Ex:

    void swap(x, y){
        int t;
                    time:
        t = x; ---->  1
        x = y; ---->  1
        y = t; ---->  1
    }
                      3 ====> f(n) = 3 * n ^ 0 => o(1) -- constant
    
*/

#include <stdio.h>

int main()
{
    printf("Time and Space Complexity!");
    return 0;
}