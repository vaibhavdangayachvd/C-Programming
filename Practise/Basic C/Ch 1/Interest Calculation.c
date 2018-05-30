/*Interest Calculation*/
/*Created by Vaibhav As VD*/
/*Interest Calculation*/
#include <stdio.h>
#define PERIOD 10
#define PRINCIPAL 5000
/*Main Program Begins*/
int main()
{
/*Declaration Statements*/
	int year;
	float amount, value, inrate;
/*Assignment Statement*/
	amount = PRINCIPAL;
	inrate = 0.11;
	year = 0;
/*Computation Statement*/
/*Using Loop*/
	while(year <= PERIOD)
	{ printf("%2d   %8.2f\n",year, amount);
		value = amount + inrate * amount;
		year = year + 1;
		amount = value;
	}
/*Loop End*/
}
/*Program End*/
