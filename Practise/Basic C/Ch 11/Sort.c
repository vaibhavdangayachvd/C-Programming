#include <stdio.h>
#include <conio.h>
void sort(int *);
void main()
{
    int a[4]={3,2,1,4};
    int i;
    sort(a);
    for(i=0;i<4;++i)
    {
        printf("%d ",a[i]);
    }
}
void sort(int *b)
{
    int i,j,temp;
    for(i=0;i<3;++i)
    {
        for(j=0;j<3-i;++j)
        {
            if(*(b+j)>*(b+j+1))
            {
                temp=*(b+j);
                *(b+j)=*(b+j+1);
                *(b+j+1)=temp;
            }
        }
    }
}
