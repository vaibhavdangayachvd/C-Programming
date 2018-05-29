#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct details
{
    int num;
    struct details *next;
}*front=NULL,*rear=NULL;
typedef struct details node;
void enq(int);
void deq(void);
int is_empty(void);
void main()
{
    int i,x;
    printf("Enter 10 numbers to enter in queue\n");
    for(i=0;i<10;++i)
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
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Queue Overflow\n");
        return;
    }
    temp->num=x;
    temp->next=NULL;
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=rear->next;
    }
}
void deq(void)
{
    node *temp;
    if(is_empty())
    {
        printf("\nQueue Underflow\n");
        return;
    }
    printf("%d ",front->num);
    temp=front->next;
    free(front);
    front=temp;
}
int is_empty(void)
{
    if(front==NULL)
        return 1;
    else
        return 0;
}
