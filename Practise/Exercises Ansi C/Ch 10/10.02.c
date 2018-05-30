#include <stdio.h>
#include <conio.h>
struct time_struct
{
    int hour;
    int minute;
    int second;
}time;
int scan(int);
void print(int,int,int);
void main()
{
    printf("Enter hour minute second : ");
    time.hour=scan(time.hour);
    time.minute=scan(time.minute);
    time.second=scan(time.second);
    print(time.hour,time.minute,time.second);
}
int scan(int x)
{
    scanf("%d",&x);
    return(x);
}
void print(int x,int y,int z)
{
    printf("Time :- %d:%d:%d",x,y,z);
    return;
}
