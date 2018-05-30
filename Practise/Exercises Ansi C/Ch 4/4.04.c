/* Bar Chart */
#include <stdio.h>
int main()
{
    float a;
    int i,j;
    for (i=1;i<=4;++i)
    {
        printf("Enter numbers:");
        scanf("%f",&a);
        a += 0.5;
        a = (int)a;
        for (j=1;j<=a;++j)
        {
            printf("*");
        }
            printf("\n");
    }
}
