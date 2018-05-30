#include <stdio.h>
#include <conio.h>
void print(int);
void (*x)(int);
void main()
{
    int x=4;
    print(*x)(5);
}
void print(int a)
{
    printf("%d",a);
}
