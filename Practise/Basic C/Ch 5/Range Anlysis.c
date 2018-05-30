/*Range of Numbers*/
#include <stdio.h>
int main()
{
    int count;
    float value,high,low,sum,average,range;
    sum = 0;
    count = 0;
    printf("Enter numbers in a line : input a negative number to end\n->");

    input:

    scanf("%f",&value);
    if (value < 0) goto output;
    count += 1;
    if (count == 1)
        high = low = value;
    else if (value > high)
        high = value;
    else if (value < low)
        low = value;
    sum += value;
    goto input;

    output:
        average = sum/count;
        range = high - low;
        printf("\n\n");
        printf("Total Values : %d\n",count);
        printf("Highest-Value : %f\nLowest-Value : %f\n",high,low);
        printf("Range = %f\nAverage = %f",range,average);
}
