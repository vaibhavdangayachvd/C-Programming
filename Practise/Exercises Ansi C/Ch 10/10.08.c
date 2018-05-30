#include <stdio.h>
#include <conio.h>
struct time_struct
{
    int hour;
    int minute;
    int second;
};
struct time_struct scan(struct time_struct);
int compare(struct time_struct,struct time_struct);
void print(int);
void main()
{
    int i;
    struct time_struct time1;
    struct time_struct time2;
    time1=scan(time1);
    time2=scan(time2);
    i=compare(time1,time2);
    print(i);
}
struct time_struct scan(struct time_struct x)
{
    printf("Enter Hour Minute Second : ");
    scanf("%d",&x.hour);
    scanf("%d",&x.minute);
    scanf("%d",&x.second);
    return(x);
}
int compare(struct time_struct x,struct time_struct y)
{
    if(x.hour>y.hour||(x.hour==y.hour&&x.minute>y.minute)||(x.hour==y.hour&&x.minute==y.minute&&x.second>y.second))
       return (0);
    else
        return(1);
}
void print(int i)
{
    if(i==1)
        printf("Time 1 is earlier");
    else
        printf("Time 2 is Earlier");
    return;
}
