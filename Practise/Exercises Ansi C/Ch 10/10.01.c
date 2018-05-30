#include <stdio.h>
#include <conio.h>
struct time_struct
{
    int hour;
    int minute;
    int second;
}time;
void main()
{
    printf("Enter hour minute second : ");
    scanf("%d %d %d",&time.hour,&time.minute,&time.second);
    printf("Time : %d:%d:%d",time.hour,time.minute,time.second);
}
