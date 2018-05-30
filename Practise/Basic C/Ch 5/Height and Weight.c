/*Height and Weight*/
#include <stdio.h>
int main()
{
    int i,count=0;
    float height,weight;
    printf("Enter height and weight for 10 boys:-\n");
    for (i=1;i<=10;++i)
    {
        printf("->");
        scanf("%f %f",&weight,&height);
        if(weight < 50 && height > 170)
            count += 1;
    }
    printf("Number of boys with weight < 50kg\nand height > 170cm = %d\n",count);
}
