#include<stdio.h>
#include<conio.h>
#define MAX 10
int arr[MAX];
int front=-1,rear=-1;
void push(int);
void pop(void);
void inject(int);
void eject(void);
int is_empty(void);
int is_full(void);
void inject(int num)
{
    if(is_full())
        printf("Queue Overflow\n");
    else
    {
        if(front==-1)
            front=0;
        if(rear==MAX-1)
            rear=0;
        else
            ++rear;
        arr[rear]=num;
    }
}
void pop(void)
{
    if(is_empty())
        printf("\nQueue Underflow\n");
    else
    {
        printf("%d ",arr[front]);
        if(front==MAX-1)
            front=0;
        else if(front==rear)
            front=rear=-1;
        else
            front++;
    }
}
void push(int num)
{
    if(is_full())
        printf("Queue Overflow\n");
    else
    {
        if(front==-1)
            rear=0,front=0;
        else if(front==0)
            front= MAX-1;
        else
            front--;
        arr[front]=num;
    }
}
void eject()
{
    if(is_empty())
        printf("\nQueue Underflow\n");
    else
    {
        printf("%d ",arr[rear]);
        if(front==rear)
            front=rear=-1;
        else if(rear==0)
            rear=MAX-1;
        else
            rear--;
        printf("%d ",arr[rear]);
    }
}
int is_full(void)
{
    if(front==0&&rear==MAX-1||front==rear+1)
        return 1;
    else
        return 0;
}
int is_empty(void)
{
    if(front==-1)
        return 1;
    else
        return 0;
}
void main()
{
}
