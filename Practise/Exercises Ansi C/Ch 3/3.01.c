/*Relocate Value*/
#include <stdio.h>
int main()
{
    int x=2,y=4,z=6,temp;
    temp = x,x = y,y=z,z=temp;
    printf("%d %d %d",x,y,z);
}
