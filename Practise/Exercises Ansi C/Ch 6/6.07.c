/*
Triangle

#include <stdio.h>
int main()
{
    int x,n;
    for(x=1;x<=5;x++)
    {
        for(n=1;n<=x;++n)
        {
            printf("%d ",x);
        }
        printf("\n");
    }
}
*/

/*
Triangle

#include <stdio.h>
int main()
{
    int x,n;
    //Out Loop Begin //
    for(x=1;x<=5;++x)
    {
        //In Loop End//
        for(n=5;n>=x;n-=1)
        {
            printf("* ");
        }
    //In Loop End//
        printf("\n");

        //Printing Spaces Begin //
        switch (x)
        {
        case 1:
            printf("  ");
            break;
        case 2:
            printf("    ");
            break;
        case 3:
            printf("      ");
            break;
        case 4:
            printf("        ");
            break;
        }
        //Printing Spaces END//
    }
    //Out Loop END //
}
*/
