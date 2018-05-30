/* a */
#include <stdio.h>
int main()
{
    int x;
    char a,b;
    printf("Enter number:");
    scanf("%d",&x);
    x = x%2==0?printf("Number is Even"):printf("Number is 2Odd");
}

/* b */
int main()
{
    int x;
    char a,b;
    printf("Enter number:");
    scanf("%d",&x);
    if(x%2 == 0)
        printf("Number is even");
    else
        printf("Number is odd");
}
