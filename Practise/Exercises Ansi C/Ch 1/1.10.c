/*Area Of Triangle*/
#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,s,ar,area;
	a = 5,b = 4,c = 3;
	s = (a+b+c)/2;
	ar = s*(s-a)*(s-b)*(s-c);
    area = sqrt(ar);
    printf("Side A = %2.1f\nSide B = %2.1f\nSide C = %2.1f\n[ Using Formula : A = √s(s-a)(s-b)(s-c) ]\n\nTherefore, Area = %3.2f",a,b,c,area);
}
