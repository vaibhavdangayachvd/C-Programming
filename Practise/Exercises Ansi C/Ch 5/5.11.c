/*P.Triplet*/
#include <stdio.h>
int main()
{
    int x,y,z,a;
    printf("Enter sides of the triangle:");
    scanf("%d %d %d",&x,&y,&z);
    a = (x>y&&x>z?x:(y>z?y:z));
    if (a*a == x*x + y*y + z*z - a*a)
        printf("Yes , they are sides of right triangle.");
    else
        printf("NO , they are not the sides of right triangle.");
}
