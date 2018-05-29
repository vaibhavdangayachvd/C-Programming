#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue_arr[MAX];
int top=-1;
int low=-1;
void enq(int);
void deq(void);
int is_full(void);
int is_empty(void);
void main()
{
    int i,x;
    printf("Enter 10 numbers to enter in queue\n");
    for(i=0;i<11;++i)
    {
        scanf("%d",&x);
        enq(x);
    }
    printf("\nEntered elements in queue\n");
    for(i=0;i<11;++i)
    {
        deq();
    }
    printf("\n\nPress Enter to exit...");
    getch();
}
void enq(int x)
{
    if(is_full())
    {
        printf("Queue Overflow\n");
        return;
    }
    low++;
    if(top==-1)
        top++;
    queue_arr[low]=x;
}
void deq(void)
{
    if(is_empty())
    {
        printf("\nStack Underflow\n");
        return;
    }
    printf("%d ",queue_arr[top]);
    top++;

}
int is_empty(void)
{
    if(top==-1||top==low+1)
        return 1;
    else
        return 0;
}
int is_full(void)
{
    if(low==MAX-1)
        return 1;
    else
        return 0;
}
