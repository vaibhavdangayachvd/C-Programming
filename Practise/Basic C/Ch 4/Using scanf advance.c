/*Scanf Advance*/
#include <stdio.h>
int main()
{
    char address[80];
    printf("Enter Address\n->");
    scanf("%[a-z]",address);
    printf("%-80s\n\n",address);
}
