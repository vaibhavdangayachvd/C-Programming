/*Binomial Coffecients*/
#include <stdio.h>
#define MAX 10
int main()
{
    int m,x,binom;
    printf("mx");
    for (m=0;m<=10;++m)
        printf("%4d", m);
    printf("\n===============================================\n");
    m = 0;
    do
    {
        printf("%2d ", m);
        x=0;binom=1;
        while(x<=m)
        {
            if (!m||!x)
                printf("%4d", binom);
            else
            {
                binom = binom*(m-x+1)/x;
                printf("%4d", binom);
            }
            x += 1;
        }
        printf("\n");
        m += 1;
    }
    while(m<=MAX);
    printf("================================================");
}
