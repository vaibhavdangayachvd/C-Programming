#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    FILE *f1,*f2,*f3;
    int num;
    f1=fopen("DATA" , "w");
    printf("Input Data(-1 to end)\n->");
    while(num)
    {
        scanf("%d",&num);
        if(num== -1)
            break;
        else
            putw(num,f1);
    }
    fclose(f1);
    f1=fopen("DATA" , "r");
    f2=fopen("EVEN","w");
    f3=fopen("ODD","w");
    while((num=getw(f1))!= EOF)
    {
        if(num%2==0)
            putw(num,f2);
        else
            putw(num,f3);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);

    f2=fopen("EVEN","r");
    f3=fopen("ODD","r");

    printf("Even Numbers\n->");
    while((num = getw(f2))!= EOF)
    {
        printf("%d ",num);
    }
    printf("\n");

    printf("Odd Numbers\n");
    while((num = getw(f3))!= EOF)
    {
        printf("%d ",num);
    }
    printf("\n");
    fclose(f2);
    fclose(f3);
}
