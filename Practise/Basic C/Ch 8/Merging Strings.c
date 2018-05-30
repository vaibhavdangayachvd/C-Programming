#include <stdio.h>
#include <conio.h>
void main()
{
    int i,j,k;
    char first[10],middle[10],last[10],name[30];
    printf("Enter First Name : ");
    scanf("%s",first);
    printf("Enter Middle Name : ");
    scanf("%s",middle);
    printf("Enter Last Name : ");
    scanf("%s",last);
    for(i=0;first[i]!='\0';++i)
    {
        name[i]=first[i];
    }
    name[i]=' ';
    for(j=0;middle[j]!='\0';++j)
    {
        name[i+j+1]=middle[j];
    }
    name[i+j+1]=' ';
    for(k=0;last[k]!='\0';++k)
    {
        name[i+j+2+k]=last[k];
    }
    name[i+j+k+2]='\0';
    printf("Your name is %s",name);
}
