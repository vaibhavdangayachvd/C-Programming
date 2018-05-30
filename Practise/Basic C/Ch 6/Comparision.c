/*Comparision*/
#include <stdio.h>
int main()
{
    int n;
    printf("FOR\n");
    for (n=1;n<=10;++n)
    {
        printf("%d ",n);
    }
    printf("\nWHILE\n");
    n = 0;
    while(n<=10)
    {
        printf("%d ",n);
        n++;
    }
    printf("\nDO-WHILE\n");
    n = 0;
    do
    {
        ++n;
        printf("%d ",n);
    }
    while(n<=10);
}
