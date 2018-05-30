/*Circle*/
#include <stdio.h>
#include <math.h>
#define PIE 3.14
int main()
{
	float x1,y1,x2,y2,r,area;
	x1=2,y1=2,x2=5,y2=6;
	r=sqrt(pow(x2-x1,2) + pow(y2-y1,2))/2;
	area=PIE*pow(r,2);
	
	printf("In a circle of Radius %2.1f :-\nArea = %3.2f",r,area);
}
