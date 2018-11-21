#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct student
{
    char name[MAX];
    char roll;
    int tot_marks;
    char (*grade)(int tot_marks);
};
typedef struct student node;
void get_student_info(char name[],int *roll,int *tot_marks);
node *add_student(char name[],int roll,int tot_marks);
char get_grade(int tot_marks);
void print_details(node *student);
void rem_student(node *student);
int main()
{
    char name[MAX];
    int roll,tot_marks;
    node *student;
    get_student_info(name,&roll,&tot_marks);
    student=add_student(name,roll,tot_marks);
    print_details(student);
    rem_student(student);
    printf("\n\n\tPress Enter to exit...");
    getch();
    return 0;
}
void get_student_info(char name[],int *roll,int *tot_marks)
{
    printf("Enter Name : ");
    scanf(" %[^\n]",name);
    printf("Roll Number : ");
    scanf(" %d",roll);
    do
    {
        printf("Enter Tot Marks : ");
        scanf("%d",tot_marks);
    }
    while(*tot_marks<=0 || *tot_marks>10);
}
node *add_student(char name[],int roll,int tot_marks)
{
    node *student;
    student=(node*)malloc(sizeof(node));
    strcpy(student->name,name);
    student->roll=roll;
    student->tot_marks=tot_marks;
    student->grade=get_grade(tot_marks);
    return student;
}
char get_grade(int tot_marks)
{
    switch(tot_marks)
    {
    case 1:
    case 2:
    case 3:
        return 'D';
    case 4:
    case 5:
        return 'C';
    case 6:
    case 7:
    case 8:
        return 'B';
    case 9:
    case 10:
        return 'A';
    }
}
void print_details(node *student)
{
    printf("\nName : %s\n",student->name);
    printf("Roll Number : %d\n",student->roll);
    printf("Grade : %c\n",student->grade);
}
void rem_student(node *student)
{
    if(student)
        free(student);
}
