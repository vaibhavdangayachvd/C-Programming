/*Using ScanF Function*/
#include <stdio.h>
int main()
{
	int number;
	printf("Enter an Integer\n-->");
	scanf("%d",&number);
	
	if(number < 100)
	  printf("Your number is less than 100\n\n");
	else 
	  printf("Your number contains more than 2 digits\n");
}
