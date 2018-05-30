/*Even or Odd*/
#include <stdio.h>
int main()
{
    int x;
    printf("Enter Number\n->");
    scanf("%d",&x);
    if (x == 0)
        printf("0 is a unit integer");
    else if (x%2 == 0)
        printf("%d is Even",x);
    else
        printf("%d is Odd",x);
}
