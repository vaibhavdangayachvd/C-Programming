#include <stdio.h>
#include <string.h>
struct details
{
    struct mod
    {
        char first[20];
        char last[20];
    };
    int roll_no;
};
void main()
{
    struct details student;
    struct details mod.name;
    strcpy(student.name.first,"Vaibhav ");
    strcpy(student.name.last,"Dangayach");
    strcat(student.name.first,student.name.last);
    student.roll_no = 58;
    printf("Name = %s\nRoll No = %d",student.name.first,student.roll_no);
}
