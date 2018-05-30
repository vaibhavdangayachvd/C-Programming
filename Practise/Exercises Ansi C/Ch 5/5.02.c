#include <stdio.h>
#define MIN 100
#define MAX 200
int main()
{
    int x,count=0,sum,y;
    x = MIN;
    while(x%7!= 0)
    {
        x +=1;
    }
    sum = x;
    while(x<MAX)
        {
        x = x+ 7;
        sum += x;
        count += 1;}
        printf("Sum  = %d\nCount = %d",sum,count);
}
