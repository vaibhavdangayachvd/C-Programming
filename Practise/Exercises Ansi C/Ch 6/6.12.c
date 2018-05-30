/*Printing S*/
#include <stdio.h>
int main()
{
    int r,c;
    for(r=1;r<=15;++r)
    {
        if(r>=4&&r<=6)
        {
            for(c=1;c<=18;++c)
            {
                if(c>=5&&c<=18)
                {
                    printf(" ");
                }
                else
                {
                    printf("*");
                }
            }
        }
        else if(r>=10&&r<=12)
        {
            for(c=1;c<=18;++c)
            {
                if(c>=1&&c<=14)
                {
                    printf(" ");
                }
                else
                {
                    printf("*");
                }
            }
         }
         else
         {
             for(c=1;c<=18;++c)
             {
                 printf("*");
             }
         }
         printf("\n");
    }
}
