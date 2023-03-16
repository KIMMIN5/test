
#include <stdio.h>

int factorial_iter(int n)
{
    int k, result = 1 ;
    for(k = 1; k<=n; k++)
    {
        result = result * k ;
    }

    return result ;
}

int factorial_rec(int n)
{
    if(n<=1) return 1;

    return n*factorial_rec(n-1) ;
}

int main() 
{
    int n = 20 ;
    double result_iter = factorial_iter(n) ;
    double result_rec = factorial_rec(n) ;

    printf("%f\n", result_iter) ;
    printf("%f\n", result_rec) ;    
}