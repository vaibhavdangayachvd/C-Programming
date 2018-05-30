#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20
char arr[MAX];
int front = -1;
void pop(void);
void main()
{
    int i,len;
    printf("Enter a string to reverse it\n");
    scanf("%s",arr);
    len=strlen(arr);
    front=len-1;
    while(front!=-1)
    {
        pop();
    }
}
void pop(void)
{
    printf("%c",arr[front]);
    front--;
}
