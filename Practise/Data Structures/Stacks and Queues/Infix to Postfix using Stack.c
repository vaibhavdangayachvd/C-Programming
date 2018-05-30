#include<stdio.h>
#include<conio.h>
#include<string.h>
void push(char);
void solve(char);
char stack[20];
char postfix[20];
int fronts=-1;
int frontp=-1;
void main()
{
    char ch[20];
    int len,i;
    printf("Enter an infix expression to convert into postfix\n");
    gets(ch);
    len=strlen(ch);
    for(i=0;i<len;++i)
    {
        if(ch[i]=='^'||ch[i]=='/'||ch[i]=='*'||ch[i]=='+'||ch[i]=='-'||ch[i]=='('||ch[i]==')')
        {
            push(ch[i]);
        }
        else
        {
            frontp++;
            postfix[frontp]=ch[i];
        }
    }
    for(i=fronts;i>=0;--i)
    {
        ++frontp;
        postfix[frontp]=stack[i];
        fronts--;
    }
    frontp++;
    postfix[frontp]='\0';
    printf("Postfix Expression = %s",postfix);
    for(i=0;i<frontp;++i)
    {
        if(postfix[i]!='^'&&postfix[i]!='*'&&postfix[i]!='/'&&postfix[i]!='+'&&postfix[i]!='-')
        {
            solve(postfix[i]);
        }
    }
    printf("Answer = %s")
    printf("\n\nPress Enter to exit...");
    getch();
}
void push(char ch)
{
    int i;
    if(ch=='(')
    {
        fronts++;
        stack[fronts]=ch;
    }
    else if(ch==')')
    {
        for(i=fronts;stack[i]!='(';--i)
        {
            ++frontp;
            postfix[frontp]=stack[i];
            fronts--;
        }
        fronts--;
    }
    else
    {
        if(ch=='^')
        {
            for(i=fronts;stack[i]=='^';--i)
            {
                ++frontp;
                postfix[frontp]=stack[i];
                fronts--;
            }
            fronts++;
            stack[fronts]=ch;
        }
        else if(ch=='*'||ch=='/')
        {
            for(i=fronts;stack[i]=='^'||stack[i]=='*'||stack[i]=='/';--i)
            {
                ++frontp;
                postfix[frontp]=stack[i];
                fronts--;
            }
            fronts++;
            stack[fronts]=ch;
        }
        else
        {
            for(i=fronts;stack[i]=='^'||stack[i]=='*'||stack[i]=='/'||stack[i]=='+'||stack[i]=='-';--i)
            {
                ++frontp;
                postfix[frontp]=stack[i];
                fronts--;
            }
            fronts++;
            stack[fronts]=ch;
        }
    }
}
