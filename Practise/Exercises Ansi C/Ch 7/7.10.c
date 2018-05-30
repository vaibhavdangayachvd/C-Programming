//Binary search
#include <stdio.h>
#include <conio.h>
#define MAX 7
void main()
{
    int i,middle,end,start,array[MAX],search;
    printf("Enter %d values\n->",MAX);
    for(i=0;i<MAX;++i)
    {
        scanf("%d",&array[i]);
    }
    printf("Enter number to search\n->");
    scanf("%d",&search);
    start=0;
    end=MAX-1;
    while(start<=end)
    {
        middle=(start+end)/2;
        if(array[middle]==search)
        {
            printf("%d found at %d",search,middle+1);
            break;
        }
        else if(array[middle]<search)
            start=middle+1;
        else
            end=middle-1;
    }
    if(start>end)
    {
        printf("Result not found\n");
    }
}
