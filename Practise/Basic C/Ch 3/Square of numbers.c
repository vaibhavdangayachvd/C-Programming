/*Square of numbers*/
#include <stdio.h>
#define START 2
#define END 100
int main()
{
    int n = START;
    while( n < END )
    {
        printf("%d\n",n);
        n = n*=n;
    }
}
