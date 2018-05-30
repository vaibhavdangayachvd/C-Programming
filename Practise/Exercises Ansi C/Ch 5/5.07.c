/*
//Floyed Triangle//

#include <stdio.h>
int main()
{
    int x=1,n=1,a;
    int i;
    printf("Enter number till where u wanna print the triangle:");
    scanf("%d",&i);
    printf("\n");
    while(x<=i)
    {
        a = 1;
        while(a<=n&&x<=i)
        {
        printf("%d ",x);
        x+=1;
        a += 1;
        }
        printf("\n");
        n += 1;
    }
*/


/*

//Floyed Triangle//
#include <stdio.h>
int main()
{
    int i,n=2,add,a;
    printf("Enter number of rows:");
    scanf("%d",&i);
    printf("\n");
    printf("1\n");
    while(n<=i)
    {
        a = 1;
        if(n%2==0)
       {
          add = 0;
          while(a<=n)
        {
            printf("%d ",add);
            if (add == 0)
            add += 1;
            else
            add -= 1;
            a += 1;
        }
        }
        else
        {
        add = 1;
        while(a<=n)
        {
            printf("%d ",add);
            if (add == 0)
            add += 1;
            else
            add -= 1;
            a += 1;
        }
        }
        printf("\n");
        n += 1;
    }
}
*/
