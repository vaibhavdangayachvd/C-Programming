/*Password Generator*/
#include <stdio.h>
int main()
{
    char c;
    int n,sum,count;
    sum=0,n = 1;
    printf("Enter your name to find your password and sum (use small caps)\n->");
    for (count=0;c!='\n';++count)
    {
    scan:
    c = getchar();
    if (c=='\n')
    {
        goto end;
    }
    else if (c == ' ')
    {
        goto scan;
    }
    else
    {
        if (n==1)
        {
            printf("\nPassword    = ");
            n += 1;
        }
        printf("%d",c-96);
        sum += (int)c-96;
    }
    }
    end:
        printf("\n");
        printf("Word Sum    = %d\n",sum);
        printf("Total Words = %d\n\n",count);
        printf("Press enter to continue..");
        getchar();
}
