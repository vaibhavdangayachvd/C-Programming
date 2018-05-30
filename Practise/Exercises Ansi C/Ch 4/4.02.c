/*Print in one line*/
#include <stdio.h>
int main()
{
    float x,y,a,b,c;
    printf("Enter values of x and y:");
    scanf("%f %f",&x,&y);
    if(x-y == 0)
    {printf("a = Imagionary\t");}
    else
        {
            printf("a = %.2f\t",(x+y)/(x-y));
        }
        printf("b = %.2f\t",(x+y)/2);
        printf("c = %.2f",(x+y)*(x-y));
}
