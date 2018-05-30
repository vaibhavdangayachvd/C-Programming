/*Word Processing*/
#include <stdio.h>
int main()
{
    char x[5],y[11];
    printf("Enter the string:");
    scanf("%4s %10s",x,y);
    printf("%s %s\n",x,y);
    printf("%s\n",x);
    printf("%s\n",y);
    printf("%.1s.%.1s.\n",x,y);
}
