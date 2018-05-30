/*Print*/
#include <stdio.h>
int main()
{
    int x,y,z;
    printf("Enter three integers:");
    scanf("%d %d %d",&x,&y,&z);
    printf("%d ",x);
    printf("%d ",y);
    printf("%d\n",z);
    printf("%2d %4d %6d\n",x,y,z);
    printf("%d %d %d\n",x,y,z);
}
