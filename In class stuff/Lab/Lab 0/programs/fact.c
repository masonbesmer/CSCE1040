#include <stdio.h>

int fact(int n)
{
    int result;
    if ( n == 1 ) 
        result =  1;
    else
       result = n * fact(n-1);
    return result;
}


int main()
{
    int i;
    for(i = 1; i <= 10; i++)
       printf("Fact(%d) = %d\n",i,fact(i));
    return 0;
}
 
