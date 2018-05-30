#include<stdio.h>
#include<conio.h>
int main()
{
 int e;
 float p;
 printf("Enter the value of p\n->");
 scanf("%f",&p);
 do
 {
     e=(int)p%100;
 }
 while (e>100);
 printf("%d",e);
}
