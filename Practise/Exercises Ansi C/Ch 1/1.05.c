/*Radius Of Circle*/
#include <stdio.h>
#define PIE 3.14
int main()
{
	int radius;
	float area;
	radius = 5;
	area = PIE * radius * radius ;
	printf("Area of Circle with Radius %d is = %3.2f\n(where π = %3.2f)", radius, area, PIE);
}
