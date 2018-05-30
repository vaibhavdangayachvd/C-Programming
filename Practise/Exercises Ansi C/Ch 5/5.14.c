/*
Prime Number
#include <stdio.h>
int main()
{
    int x;
    printf("Enter a positive integer:");
    scanf("%d",&x);
    if (x%2!=0&&x%3!=0&&x%5!=0&&x%7!=0||x==2||x==3||x==5)
        printf("Prime Number");
    else
        printf("Non Prime Number");
}
*/

/*100-200*/
#include <stdio.h>
int main()
{
    int x,count,y;
    for (x=100;x<=200;++x)
    {
        for(y=2;y<=x;y++)
        {
           if(x%y==0)
           break;
        }
        if (x==y)
        {
            printf("%d\n",x);
            count += 1;
        }

    }
}
