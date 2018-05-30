/*Divisibility*/
#include <stdio.h>
int main()
{
    int count=0,x=0,a;
    while (x%6==0&&x%4!=0)
    {
        x += 1;
    }
    for (a=x;a<100;a+=6)
    {
        if (a % 4 != 0)
           {
               printf("%d\n",a);
               count += 1;
           }

    }
    printf("Total number of such values = %d",count);
}
