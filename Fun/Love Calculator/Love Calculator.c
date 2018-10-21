/*Love Calculator*/
#include <stdio.h>
int main()
{
    char c;
    int n,sum,count;
    printf("\t   Love Calculator\n\n");
    start:
    sum=0,c=0;
    printf("Enter your and your partner's first name (use small caps)\n->");
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
        sum += (int)c-96;
    }
    }
    end:
        printf("\n");
        if (sum==144&&count==13)
            printf("*****Perfect Couple*****\nLove Level = Infinity");
        else if (sum==101&&count==10)
            printf("*****Perfect Couple*****\nLove Level = Infinity");
        else if (sum==128&&count==11)
            printf("*****Family*****\nLove Level = Infinity");
        else if (sum==119&&count==12)
            printf("*****Family*****\nLove Level = Infinity");
        else if (sum==139&&count==13)
            printf("*****Family*****\nLove Level = Infinity");
        else if (sum==108&&count==10)
            printf("*****Family*****\nLove Level = Infinity");
        else if (sum==144&&count==11)
            printf("*****Worst Couple*****\nLove Level = Zero");
        else if (sum==143&&count==11)
            printf("*****Worst Couple*****\nLove Level = Zero");
        else if (sum<=100)
            printf("Love Level = Low");
        else if (sum>150)
            printf("Love Level = Very High");
        else if (sum >125)
            printf("Love Level = High");
        else if (sum > 100)
            printf("Love Level = Medium");
        printf("\n\n");
        printf("============================================\n\n");
        goto start;
}
