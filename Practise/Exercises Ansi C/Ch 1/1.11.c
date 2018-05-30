/*Distance Formula*/
#include <stdio.h>
#include <math.h>
int main()
{
	float x1,x2,y1,y2,d1,d;
	x1=2,x2=6,y1=2,y2=5;
	d1=pow(x2-x1,2)+pow(y2-y1,2);
	d = sqrt(d1);
	
	printf("Distance Between (%1.0f,%1.0f) & (%1.0f,%1.0f) = %3.2f",x1,y1,x2,y2,d);
}
