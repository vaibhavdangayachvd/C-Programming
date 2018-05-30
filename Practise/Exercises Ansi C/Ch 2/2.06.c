/*Complex Program*/
#include <stdio.h>
int main()
{
 int n,positive,negative;
 n = 0,positive=0,negative=0;
 printf("\nPress 0 to complete the data entry\n\n");
   do
   {
      printf("Enter number : ");
      scanf("%d",&n);
      if (n>0)
         {positive++;}
      if (n<0)
         (negative++);
   }
   while( n!=0 );
   printf("\n\n===OUTPUT===\n");
   printf("From the input numbers,\n%d are postive, and\n%d are negative",positive, negative);
}
