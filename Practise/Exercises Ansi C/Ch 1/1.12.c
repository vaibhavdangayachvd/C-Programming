/*Circle*/
#include <stdio.h>
#include <math.h>
#define PIE 3.14
int main()
{
	float x1,y1,x2,y2,r,area,perimeter;
	x1=0,y1=0,x2=4,y2=5;
	r=sqrt(pow(x2-x1,2) + pow(y2-y1,2));
	area=PIE*r*r;
	perimeter=2*PIE*r;
	
	printf("In a Circle of Radius %2.1f :-\nArea = %3.2f\nPerimeter = %3.2f",r,area,perimeter);
}
