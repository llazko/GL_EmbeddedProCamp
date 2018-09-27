#include <stdio.h>

int main()
{
    int n = 10; // the given number.
    int i;
    int f = 1;      // the result of n!. Init value is 1
    //todo: check the input range as result may exceed the max limit. For n=10 it is still fittable to int.
        for(i=1; i<=n; ++i)
        {
            f *= i;
        }
    printf("The factorial of %d is %d \n", n, f);
    
    return 0;
}
