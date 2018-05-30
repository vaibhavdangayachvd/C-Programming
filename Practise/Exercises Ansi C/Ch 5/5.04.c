/*Marks*/
#include <stdio.h>
#define MIN 0
#define MAX 100
int main()
{
    int x,a=0,b=0,c=0,d=0;
    printf("Enter marks obtained in one line - enter more than 100 to end\n->");
    input:
    scanf("%d",&x);
    if (x>100) goto end;
    else if (x > 80)
        a++;
    else if (x > 60)
        b++;
    else if (x > 40)
        c++;
    else if (x <= 40)
        d++;
    else
        {goto end;}
    goto input;
    end:
        printf("More than 80 marks : %d\n",a);
        printf("More than 60 marks : %d\n",a+b);
        printf("More than 40 marks : %d\n",a+b+c);
        printf("More less than or 40 : %d\n",d);
        printf("80 - 100 : %d\n",a);
        printf("60-80 : %d\n",b);
        printf("40-60 : %d\n",c);
        printf("0 - 40 : %d\n",d);
}
