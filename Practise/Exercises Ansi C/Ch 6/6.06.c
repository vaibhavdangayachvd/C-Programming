/*
Investment
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n,p;
    float r,v;
    printf("P    R    N    :     V\n");
    for(p=1000;p<=10000;p+=1000)
    {
        for(r=0.10;r<0.21;r+=.01)
        {
            for(n=1;n<=10;++n)
            {
                v = p*(pow(1+r,n));
                printf("%5d    %.2f    %2d    :    %8.2f\n",p,r,n,v);
            }
        }
    }
}
*/
//======================================//
/*
Investment
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n,p;
    float r,v;
    printf("   P       R      N    :        V\n\n");
    for(p=1000,r=0.10,n=1;p<=10000,r<.21,n<=10;p+=1000,r+=.01,++n)
    {
        v = p*(pow(1+r,n));
        printf("%5d    %.2f    %2d    :    %9.2f\n",p,r,n,v);
    }
}
*/

