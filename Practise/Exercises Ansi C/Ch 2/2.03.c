/*Print even numbers*/
#include <stdio.h>
#include <math.h>
#define STEP 2
int main()
{
    int x;
    x = 2;
    printf("Even numbers from 1 - 100 :-\n");
    while(x <=100)
    {
       printf("%d\n",x);
       x = x + STEP;
    }
}
