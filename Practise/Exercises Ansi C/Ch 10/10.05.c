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
int scan(int);
void validate(int,int,int);
void print(int,int,int);
void update(int,int,int);
void main()
{
    start:
    printf("Enter Day Month Year : ");
    date.day=scan(date.day);
    date.month=scan(date.month);
    date.year=scan(date.year);
    validate(date.day,date.month,date.year);
    print(date.day,date.month,date.year);
    printf("Press Enter to increase day by 1...");
    getch();
    printf("\n\n");
    update(date.day,date.month,date.year);
    printf("\t\t\t    Press Enter to try again...");
    getch();
    printf("\n\n");
    goto start;
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
    printf("\n\n");
    return;
}
void update(int x,int y,int z)
{
    int leap=0;
    if(((z%4==0)&&(z%100!=0))||(z%400==0))
        leap = 1;
    x+=1;
    {
        if((x==31&&(y==4||y==6||y==9||y==11))||x==32)
           {
               x = 1;
               y+=1;
               if(y==13)
               {
                   y = 1;
                   z+=1;
               }
           }
        else if((y==2&&((x==29&&leap==0)||x==30)))
        {
            x=1;
            y+=1;
            if(y==13)
            {
                y = 1;
                z+=1;
            }
        }
    }
    printf("New Date - ");
    print(x,y,z);
    return;
}
