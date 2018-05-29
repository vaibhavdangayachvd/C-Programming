#include<stdio.h>
#include<conio.h>
float power(float,int);
void main()
{
    int i;
    float f;
    printf("Enter number and power\n");
    scanf("%f %d",&f,&i);
    printf("%.2f to the power %d is %.2f\n",f,i,power(f,i));
    getch();
}
float power(float f,int i)
{
    if(i==0)
        return 1;
    else
        return(f * power(f,i-1));
}
