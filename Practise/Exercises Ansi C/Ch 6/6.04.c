/*Series*/
#include <stdio.h>
int main()
{
    int x=1,y=1,m,count=3;;
    printf("Till when u wanna print the series : ");
    scanf("%d",&m);
    printf("%d ",x);
    printf("%d ",y);
    while(count<=m)
    {
        x+=y;
        if(count<=m)
        {
        printf("%d ",x);
        count++;
        }
        y+=x;
        if(count<=m)
        {
        printf("%d ",y);
        count++;
        }
    }
}
