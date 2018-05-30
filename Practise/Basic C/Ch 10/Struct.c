#include <stdio.h>
struct personal
{
    char name[20];
    int day;
    char month[10];
    int year;
    float salary;
};
void main()
{
    struct personal vaibhav;
    printf("Input Values\n->");
    scanf("%s %d %s %d %f",vaibhav.name,&vaibhav.day,vaibhav.month,&vaibhav.year,&vaibhav.salary);
    printf("Name : %s\nDOB : %d %s %d\nSalary : %.2f\n",vaibhav.name,vaibhav.day,vaibhav.month,vaibhav.year,vaibhav.salary);
}
