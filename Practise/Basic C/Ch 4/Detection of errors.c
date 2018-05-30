/*Errors*/
#include <stdio.h>
int main()
{
    int a;
    float b;
    char c;
    printf("Enter values of a , b and c\n->");
    if (scanf("%d %f %c",&a,&b,&c) == 3)
        printf("a = %d\nb = %3.2f\nc = %c",a,b,c);
    else
        printf("Error in input.\n");
}
