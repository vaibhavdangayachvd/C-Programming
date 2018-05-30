//copy
#include <stdio.h>
struct class
{
    char name[10];
    int num;
    int marks;
};
void main()
{
    struct class student1 = {"Vaibhav",1,100};
    struct class student2 = {"Harsh",2,50};
    struct class student3;
    student3=student2;
    printf("%s %d %d",student3.name,student3.num,student3.marks);
}
