/*Binary Equivalent*/
#include <stdio.h>
int main()
{
    int x,y;
    printf("Enter a positive integer : ");
    scanf("%d",&x);
    while(x!=0)
    {
        y = x%2;
        x/=2;
        printf("%d",y);
    }
}
