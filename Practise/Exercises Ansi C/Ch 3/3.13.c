/*Greater of three*/
#include <stdio.h>
int main()
{
    int x,y,z,a,b;
    printf("Enter 3 Integers\n->");
    scanf("%d %d %d",&x,&y,&z);
    a = x > y ? x : y;
    b = a > z ? a : z;
    printf("Greater of %d, %d, %d is %d",x,y,z,b);
}
