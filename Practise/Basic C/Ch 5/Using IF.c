/*Using If Statement*/
#include <stdio.h>
int main()
{
    int a,b,c,d;
    float ratio;
    printf("Enter four integer values:");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(c-d != 0)
    {
        ratio = (float)(a+b)/(float)(c-d);
        printf("Ratio = %3.2f\n",ratio);
    }
}
