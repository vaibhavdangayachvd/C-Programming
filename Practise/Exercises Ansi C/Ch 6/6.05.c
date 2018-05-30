/*Reverse*/
#include <stdio.h>
int main()
{
    long int x;
    printf("Enter a number to reverse its digits : ");
    scanf("%ld",&x);
    for(;x!=0;)
    {
        printf("%ld",x%10);
        x = (x-(x%10))/10;
    }
}
