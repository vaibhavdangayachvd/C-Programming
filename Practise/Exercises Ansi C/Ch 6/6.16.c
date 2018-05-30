/*
(a)
#include <stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=5;++x)
    {
        for(y=1;y<=5;++y)
        {
            printf("S ");
        }
        printf("\n");
    }
}
*/

/*(b)*/
#include <stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=5;++x)
    {
        if(x==1||x==5)
        {
                for(y=1;y<=5;++y)
                    {
                        printf("S ");
                    }
        }
        else
        {
            for(y=1;y<=5;++y)
                    {
                        if(y>=2&&y<=4)
                            printf("  ");
                        else
                            printf("S ");
                    }
        }
        printf("\n");
    }
}
