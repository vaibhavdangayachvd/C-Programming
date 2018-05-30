/*Convert Temperature*/
#include <stdio.h>
int main()
{
	float c,f;
	c = 37;
	f = (9*c)/5 + 32;
	
	printf("%2.1f° Celsius = %2.1f° Fahrenheit",c,f);
}
