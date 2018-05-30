#include <stdio.h>
#include <conio.h>
struct test
{
    int roll;
    int grade;
};
void transfer(struct test[]);
void main()
{
    struct test std[3]={{1,1},{2,2},{3,3}};
    transfer(std);
    printf("%d",std[0].roll);
}
void transfer(struct test std[])
{
    std[0]=std[2];
    return;
}
