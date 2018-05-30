//Printing Date in accurate format
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct
{
    int day;
    int month;
    int year;
}date;
int day(int);
int month(int);
int year(int);
int scan(int);
void validate(int,int,int);
void print(int,int,int);
void main()
{
    int a;
    printf("Enter Day Month Year : ");
    a = scan(a);
    date.day=day(a);
    date.month=month(a);
    date.year=year(a);
    validate(date.day,date.month,date.year);
    print(date.day,date.month,date.year);
    printf("Press Enter to exit...");
    getch();
}
int scan(int x)
{
    scanf("%d",&x);
    return(x);
}
void validate(int x,int y,int z)
{
    int leap=0;
    if(((z%4==0)&&(z%100!=0))||(z%400==0))
        leap = 1;
    if(leap==0&&y==2&&x>28)
    {
        printf("%d is not a leap year\n",z);
        printf("Press Enter to exit...");
        getch();
        exit(0);
    }
    if(x>30&&(y==4||y==6||y==9||y==11))
    {
        switch(y)
        {
        case 4:
            printf("April has only 30 days\n");
            break;
        case 6:
            printf("June has only 30 days\n");
            break;
        case 9:
            printf("September has only 30 days\n");
            break;
        case 11:
            printf("November has only 30 days\n");
            break;
        }
        printf("Press Enter to exit...");
        getch();
        exit(0);
    }
    if(x>31||x<1)
    {
        printf("Wrong Correct Date\n");
        printf("Press Enter to exit...");
        getch();
        exit(0);
    }
    if(y>12||y<1)
    {
        printf("Wrong Correct Month\n");
        printf("Press Enter to exit...");
        getch();
        exit(0);
    }
    if(y==2&&x>29)
    {
        printf("Februray has only 28/29 days\n");
        printf("Press Enter to exit...");
        getch();
        exit(0);
    }
    return;
}
void print(int x,int y,int z)
{
    switch(y)
    {
    case 1:
        printf("January %d, %d",x,z);
        break;
    case 2:
        printf("February %d, %d",x,z);
        break;
    case 3:
        printf("March %d, %d",x,z);
        break;
    case 4:
        printf("April %d, %d",x,z);
        break;
    case 5:
        printf("May %d, %d",x,z);
        break;
    case 6:
        printf("June %d, %d",x,z);
        break;
    case 7:
        printf("July %d, %d",x,z);
        break;
    case 8:
        printf("August %d, %d",x,z);
        break;
    case 9:
        printf("September %d, %d",x,z);
        break;
    case 10:
        printf("October %d, %d",x,z);
        break;
    case 11:
        printf("November %d, %d",x,z);
        break;
    case 12:
        printf("December %d, %d",x,z);
        break;
    }
    printf("\n");
    return;
}
int year (int x)
{
    x = x/10000;
    return(x);
}
int month(int x)
{
    int temp = x;
    x = x%10000;
    temp = x%100;
    x = (x-temp)/100;
}
int day(int x)
{
    x = x%100;
    return(x);
}
