/*Anil Kumar Gupta*/
#include <stdio.h>
int main()
{
    char a[10],b[10],c[10];
    printf("Enter 3 word name:");
    scanf("%s %s %s",a,b,c);
    printf("%s %.1s. %s\n",a,b,c);
    printf("%.1s.%.1s. %s\n",a,b,c);
    printf("%s %.1s.%.1s.\n",c,a,b);
}
