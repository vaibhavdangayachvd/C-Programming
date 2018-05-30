/*calculation Table*/
#include <stdio.h>
#define CMAX 10
#define RMAX 12
int main()
{
    int x=1,y,count;
    printf("          Multiplication Table\n");
    printf("==========================================\n");
    do
    {
        count = 1;
        do
        {
            y = x*count;
            printf("%4d", y);
            count++;
        }
        while(count<=CMAX);
        printf("\n");
        x += 1;
    }
    while(x<=RMAX);
    printf("==========================================");
}
