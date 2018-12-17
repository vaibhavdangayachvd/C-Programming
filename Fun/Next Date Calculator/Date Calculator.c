#include<stdio.h>
#include<conio.h>
struct date
{
    int date;
    int month;
    int year;
};
int main()
{
    int days,i;
    int max_days[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};//Set max to all days except Feb
    struct date today={0},nextday;
    do
    {
        printf("Input Today's Date(dd/mm/yyyy) : ");
        scanf("%d/%d/%d",&today.date,&today.month,&today.year);
        if(today.month<=12 && today.month>=1)//Set max days of Feb
        {
            if((today.year%4==0)&&(today.year%100!=0)||(today.year%400==0))//Check for leap year
                max_days[2]=29;
            else
                max_days[2]=28;
        }
        if((today.month>12||today.month<1)||(today.date<1 ||today.date>max_days[today.month]))
            printf("Wrong Input !!\n");
    }
    while((today.month>12||today.month<1)||(today.date<1 ||today.date>max_days[today.month]));
    printf("Enter number of days to skip : ");
    scanf("%d",&days);
    nextday=today;//copy date
    for(i=days;i>0;--i)
    {
        if(nextday.date<max_days[nextday.month])//If days are left in a month
            ++(nextday.date);
        else if(nextday.month<12)//If month are left in a year
        {
            ++(nextday.month);
            nextday.date=1;
        }
        else//Goto next year
        {
            nextday.year++;
            nextday.month=1;
            nextday.date=1;
            if((nextday.year%4==0)&&(nextday.year%100!=0)||(nextday.year%400==0))
                max_days[2]=29;
            else
                max_days[2]=28;
        }
    }
    printf("\nNext Day is : %02d/%02d/%04d",nextday.date,nextday.month,nextday.year);
    printf("\n\n\tPress Enter to exit...");
    getch();
    return 0;
}
