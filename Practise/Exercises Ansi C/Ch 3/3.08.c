/*Acceleration*/
#include <stdio.h>
#include <conio.h>
int main()
{
 int a,u,t;
 float distance;
 printf("Enter the value of a,u,t\n");
 scanf("%d %d %d",&a,&u,&t);
 distance=u*t+(a*t*t)/2;
 printf("%f",distance);
 }
