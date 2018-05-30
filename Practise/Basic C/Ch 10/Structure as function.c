#include <stdio.h>
#include <conio.h>
struct detail
{
    char name[20];
    int roll;
};
struct detail scan(struct detail);
void print(struct detail);
void main()
{
    struct detail student;
    student = scan(student);
    print(student);
}
struct detail scan(struct detail x)
{
    printf("Enter name : ");
    scanf("%s",x.name);
    printf("Enter roll number : ");
    scanf("%d",&x.roll);
    return(x);
}
void print(struct detail x)
{
    printf("Name : %s\n",x.name);
    printf("Roll Number : %d",x.roll);
    return;
}
