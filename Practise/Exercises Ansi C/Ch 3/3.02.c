#include<stdio.h>
#include<conio.h>
int main()
{
 int e;
 float p;
 printf("Enter the value of p\n");
 scanf("%f",&p);
 do
 {
     e=(int)p%10;
 }
 while (e>10);
 printf("%d",e);
}
