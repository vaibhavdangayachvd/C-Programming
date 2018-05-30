/*Rupee to Paisa Converter*/
#include <stdio.h>
#include <math.h>
int main()
{
    float p,r;
    printf("Enter amount in Rupees to convert into paise\n->");
    scanf("%f",&r);
    p = r*100;
    printf("Rs %4.3f = %2.1f Paise",r,p);
}
