#include <stdio.h>
#include <conio.h>
void main()
{
    int i,group[11]={0},high,low,marks[50];
    printf("Enter marks\n->");
    for(i=0;i<50;++i)
    {
        scanf("%d",&marks[i]);
        ++group[(int)(marks[i]/10)];
    }
    printf("\n");
    printf("Group\t   Range\tFrequency\n\n");
    for(i=0;i<11;++i)
    {
        low = i*10;
        if(i==10)
        {
            high=100;
        }
        else
        {
            high=low+9;
        }
        printf("%2d\t%3d to %3d\t%2d\n",i+1,low,high,group[i]);
    }
}
