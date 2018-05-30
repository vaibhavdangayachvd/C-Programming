#include <stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=5;++x)
    {
        if(x==3)
        {
            for(y=1;y<=5;++y)
            {
                if(y==3)
                {
                    printf("O ");
                }
                else
                {
                    printf("S ");
                }
            }
        }
        else
        {
            for(y=1;y<=5;++y)
            {
                printf("S ");
            }
        }
        printf("\n");
    }
}
