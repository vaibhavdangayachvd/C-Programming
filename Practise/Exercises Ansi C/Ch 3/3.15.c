/*3 Values */
#include <stdio.h>
int main()
{
    int x,y,z,s,x1,x2,x3,x4;
    float a;
    printf("Enter 3 Numbers\n->");
    scanf("%d %d %d",&x,&y,&z);
    s = x+y+z;
    a = (x+y+z)/3;
    x1 = x > y ? x : y;
    x2 = x1 > z ? x1 : z;
    x3 = x > y ? y : z;
    x4 = x3 > z ? z : x3;
    printf("Sum = %d\nAverage = %3.2f\nGreatest = %d\nSmallest = %d\n",s,a,x1,x4);
}
