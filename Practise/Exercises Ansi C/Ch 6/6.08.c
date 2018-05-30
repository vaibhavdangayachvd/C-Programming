/*Age Grouping*/
#include <stdio.h>
int main()
{
    int x,n,count=0,o=0;
    printf("Enter age in one line and enter negative number to end\n->");
    for (n=1;n<=100;++n)
    {
        scanf("%d",&x);
        if(x<=0)
            break;
        else if(x<=60&&x>=50)
            {
            count++;
            continue;
            }
            o++;
    }
    printf("Number of in the age group 50-60 = %d\nOthers = %d",count,o);
}
