#include<stdio.h>
#include<conio.h>
#define MAX 10
int top=-1;
int stack_arr[MAX];
void push(int);
void pop(void);
int is_empty(void);
int is_full(void);
void main()
{
    int i,x;
    printf("Enter 10 numbers to enter in stack\n");
    for(i=0;i<11;++i)
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
    if(is_full())
    {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack_arr[top]=x;
}
void pop(void)
{
    if(is_empty())
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("%d ",stack_arr[top]);
    top--;
}
int is_empty(void)
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int is_full(void)
{
    if(top==9)
        return 1;
    else
        return 0;
}
