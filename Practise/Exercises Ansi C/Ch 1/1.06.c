/*Table of number*/
#include <stdio.h>
#define MAX 10
int main()
{
	int x, n, m;
	x = 5;
	n = 1;
	printf("Table of %d :-\n\n",x);
	while(n <= MAX)
	{
		m = x * n;
		printf("%d x %2d = %3d\n",x,n,m);
		n = n + 1;
    }
}
