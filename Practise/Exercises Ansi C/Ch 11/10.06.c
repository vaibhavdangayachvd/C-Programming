#include <stdio.h>
#include <conio.h>
#include <string.h>
char* name(int);
void main()
{
int d;
printf("\n\nEnter day Number\n\n");
scanf("%d",&d);
printf("\n\n\nDAY NAME IS %s",name(d));
getch();
}
char * name(int k)
{
char n[20][9];
strcpy(n[0],"Sunday");
strcpy(n[1],"Monday");
strcpy(n[2],"Tuesday");
strcpy(n[3],"Wednesday");
strcpy(n[4],"Thesday");
strcpy(n[5],"Friday");
strcpy(n[6],"Saturday");
strcpy(n[7],"Sunday");
strcpy(n[8],"invalid day");
if(k<=7 && k >0)
return n[k];
else
return n[8];
}
