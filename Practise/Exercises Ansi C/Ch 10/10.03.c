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
void update(int,int,int);
void main()
{
    printf("Enter hour minute second : ");
    time.hour=scan(time.hour);
    time.minute=scan(time.minute);
    time.second=scan(time.second);
    print(time.hour,time.minute,time.second);
    printf("Press Enter to increase time by 1 sec..\n");
    getch();
    update(time.hour,time.minute,time.second);
}
int scan(int x)
{
    scanf("%d",&x);
    return(x);
}
void print(int x,int y,int z)
{
    printf("Time :- %d:%d:%d\n",x,y,z);
    return;
}
void update(int x,int y,int z)
{
    z+=1;
    if(z==60)
    {
        z = 0;
        y +=1;
        {
            if(y==60)
            {
                y = 0;
                x+=1;
                {
                    if(x==24)
                    {
                        x=0;
                    }
                }
            }
        }
    }
    printf("New Time :- %d:%d:%d\n",x,y,z);
}
