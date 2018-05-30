#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct details
{
    int num;
    struct details *next;
}*top=NULL;
typedef struct details node;
void push(int);
void pop();
int is_empty();
void main()
{
    int i,x;
    printf("Enter 10 numbers to enter in stack\n");
    for(i=0;i<10;++i)
    {
        scanf("%d",&x);
        push(x);
    }
    printf("\nEntered elements in stack\n");
    for(i=0;i<11;++i)
    {
        pop();
    }
    printf("\n\nPress Enter to exit...");
    getch();
}
void push(int x)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    temp->num=x;
    temp->next=top;
    top=temp;
}
void pop()
{
    node *temp;
    if(is_empty())
    {
        printf("\nStack Under flow\n");
        return;
    }
    printf("%d ",top->num);
    temp=top->next;
    free(top);
    top=temp;
}
int is_empty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
