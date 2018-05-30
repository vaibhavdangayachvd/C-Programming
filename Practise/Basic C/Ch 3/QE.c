/*Quadratic Equation*/
#include <stdio.h>
#include <math.h>
int main()
{
   float a,b,c,d,r1,r2;
   printf("Input values of a ,b and c\n-->");
   scanf("%f %f %f",&a,&b,&c);
   d = b*b - 4*a*c;
   if(d <0)
        printf("\n\nRoots are imaginary\n");
   else
   {
       r1 = (-b + sqrt(d))/(2*a);
       r2 = (-b - sqrt(d))/(2*a);
       printf("\n\nRoot 1 = %5.2f\n\nRoot 2 = %5.2f\n",r1,r2);
   }
}
