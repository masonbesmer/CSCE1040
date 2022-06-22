#include <stdio.h>
#include <math.h>


int isPrime(int num)
{
    int i;
    for(i = 2; i < sqrt(num); i++)
    if( (num % i == 0) )
    {
	return 0;
    }
    return 1;
}

int main()
{
    int i;
    for( i = 50000; i > 49900; i-- )
    if( isPrime(i) ) 
        printf("%d is prime\n",i);
    return 0;
}
