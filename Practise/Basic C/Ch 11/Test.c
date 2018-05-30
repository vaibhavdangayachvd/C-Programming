#include <stdio.h>
#include <conio.h>
int *scan(void);
void main()
{
    int *p;
    p = scan();
    printf("%d %d %d %d",*p,*(p+1),*(p+2),*(p+3));
}
int *scan(void)
{
    int a[4]={1,2,3,4};
    int *p=a;
    return a;
}
