/*Sum of digits*/
#include <stdio.h>
int main()
{
    int x,y,sum=0;
    printf("Enter a digit to find sum of its digits : ");
    scanf("%d",&x);
    y = x;
    while(x%10!=0)
    {
       sum += x%10;
       x = (x-(x%10))/10;
    }
    printf("Sum of Digits of %d : %d",y,sum);
}
