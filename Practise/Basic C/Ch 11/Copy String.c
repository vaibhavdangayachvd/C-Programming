#include <stdio.h>
#include <conio.h>
void copy(char *,char *);
void main()
{
    char name[20],test[20]="Vaibhav";
    copy(name,test);
    printf("%s",name);
}
void copy(char *a,char *b)
{
    while((*a++ = *b++)!=0)
    ;
}
