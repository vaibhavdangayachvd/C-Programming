#include<stdio.h>
#include<conio.h>
#define MAX 10
int arr[MAX];
int front=-1,rear=-1;
void enq(int);
void deq(void);
int is_empty(void);
int is_full(void);
void main()
{
    int i,num;
    printf("Enter data in circular queue\n");
    for(i=0;i<MAX+1;++i)
    {
        scanf("%d",&num);
        enq(num);
    }
    printf("Data in queue\n");
    for(i=0;i<MAX+1;++i)
    {
        deq();
    }
    printf("\n\nPress Enter to exit...");
    getch();
}
void enq(int num)
{
    if(is_full())
        printf("Queue Overflow\n");
    else
    {
        if(front==-1)
        {
            front=0;
        }
        if(rear==MAX-1)
            rear=0;
        else
            rear++;
        arr[rear]=num;
    }
}
void deq(void)
{
    if(is_empty())
        printf("\nQueue Underflow\n");
    else
    {
        printf("%d ",arr[front]);
        if(front==rear)
            front=rear=-1;
        else if(front==MAX-1)
            front=0;
        else
            front++;
    }
}
int is_empty(void)
{
    if(front==-1)
        return 1;
    else
        return 0;
}
int is_full(void)
{
    if(front==rear+1||front==0&&rear==MAX-1)
        return 1;
    else
        return 0;
}
