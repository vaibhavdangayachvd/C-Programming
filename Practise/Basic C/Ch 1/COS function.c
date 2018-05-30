/*Using Cos Function*/
#include <math.h>
#include <stdio.h>
#define PI 3.1416
#define MAX 180

int main()
{	
	int angle;
	float x,y;
	
    angle = 0;
	printf(" Angle  Cos(angle)\n\n");
	
	while(angle <= MAX)
	{
		x = (PI/MAX)*angle;
		y = cos(x);
		printf("%3d     %7.4f\n", angle,y);
		angle = angle + 10;
	}
}
