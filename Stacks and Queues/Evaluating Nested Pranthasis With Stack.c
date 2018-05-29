#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
char arr[MAX];
int front = -1;
void push(char);
void pop(void);
int is_empty(void);
int is_full(void);
void main()
{
    int i,len;
    char ch;
    printf("Enter an expression\n");
    scanf("%s",arr);
    len=strlen(arr);
    for(i=0;i<len;++i)
    {
        if(arr[i]=='('||arr[i]=='['||arr[i]==')'||arr[i]==']')
        {
            push(arr[i]);
            if(arr[i]==')'||arr[i]==']')
            {
                pop();
            }
        }
    }
    if(is_empty())
    {
        printf("\nExpression is correct");
    }
}
void pop(void)
{

    if((arr[front]==']'&&arr[front-1]=='[')||(arr[front]==')'&&arr[front-1]=='('))
        front=front-2;
    else
    {
        printf("Invalid Expression !!");
        exit(1);
    }
}
void push(char ch)
{
        ++front;
        arr[front]=ch;
}
int is_empty(void)
{
    if(front==-1)
        return 1;
    else
        return 0;
}
