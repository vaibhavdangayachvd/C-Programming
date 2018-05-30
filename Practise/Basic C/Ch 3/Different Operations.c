/*Different Operations*/
#include <stdio.h>
int main()
{
    int a,b,c,d;
    a=15;
    b=10;
    c = ++a - b;// c = 6 , a = 16

    printf("a = %d b = %d c = %d\n",a,b,c);
     d = b++ + a;// d= 26 , b = 11
      printf("a = %d b = %d d = %d\n",a,b,d);
      printf("a/b = %d\n",a/b);
      printf("a%%b = %d\n",a%b);
      printf("a*=b = %d\n",a*=b);
      printf("%d\n",(c>d)? 0 : 1);
      printf("%d\n",(c<d)? 1 : 0);
}
