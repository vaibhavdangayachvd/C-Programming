#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 30
int top=-1;
char postfix[MAX];
long int postfix_stack[MAX];
char infix[MAX];
void infix_to_postfix(void);
int is_blank(char);
void push(long int);
long int pop(void);
int prio(char);
int inc_prio(char);
int is_empty(void);
long int eval_post(void);
void main()
{
    long int value;
    printf("Enter expression\n");
    gets(infix);
    infix_to_postfix();
    printf("Postfix expression is %s\n",postfix);
    value=eval_post();
    printf("Value of expression %ld",value);
    getch();
}
void infix_to_postfix(void)
{
    unsigned int i,p=0;
    char symbol,next;
    for(i=0;i<strlen(infix);++i)
    {
        symbol=infix[i];
        if(!is_blank(symbol))
        {
            switch(symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next=pop())!='(')
                    postfix[p++]=next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(!is_empty()&&prio(postfix_stack[top])>=inc_prio(symbol))
                      postfix[p++]=pop();
                push(symbol);
                break;
            default:
                postfix[p++]=symbol;
                break;
            }
        }
    }
    while(!is_empty())
        postfix[p++]=pop();
    postfix[p]='\0';
}
int is_blank(char ch)
{
    if(ch==' ')
        return 1;
    else
        return 0;
}
int prio(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return 0;
    }
}
int inc_prio(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 2;
        break;
    case '^':
        return 4;
        break;
    default:
        return 0;
    }
}
void push(long int ch)
{
    if(top>MAX)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    postfix_stack[++top]=ch;
}
long int pop(void)
{
    if(is_empty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    return(postfix_stack[top--]);
}
int is_empty(void)
{
    if(top==-1)
        return 1;
    else
        return 0;
}
long int eval_post(void)
{
    long int a,b,temp,result;
    unsigned int i;
    for(i=0;i<strlen(postfix);++i)
    {
        if(postfix[i]<='9'&&postfix[i]>='0')
            push(postfix[i]-'0');
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
            case '+':
                temp=b+a;
                break;
            case '-':
                temp=b-a;
                break;
            case '*':
                temp=b*a;
                break;
            case '/':
                temp=b/a;
                break;
            case '%':
                temp=b%a;
                break;
            case '^':
                temp=pow(b,a);
                break;
            }
            push(temp);
        }
    }
    result=pop();
    return result;
}
