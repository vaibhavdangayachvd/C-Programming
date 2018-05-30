/*Factorial*/
#include <stdio.h>
int main()
{
    int m,n,f=1;
    printf("Enter any value to find factorial : ");
    scanf("%d",&m);
    for (n=1;n<m;++n)
        {
           f = f*(m-n);
        }
        printf("%d",f*m);
}
