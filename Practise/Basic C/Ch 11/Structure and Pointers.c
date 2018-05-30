#include <stdio.h>
#include <conio.h>
struct sensus
{
    char name[20];
    int age;
};
void scan(struct sensus *);
void main()
{
    int i=1;
    struct sensus person[3],*ptr;
    ptr=person;
    scan(ptr);
    for(i=0;i<3;++i)
    {
        printf("Name : %s , Age = %d\n",person[i].name,person[i].age);
    }
}
void scan(struct sensus *ptr)
{
    int i;
    for(i=0;i<3;++i&&++ptr)
    {
        printf("Enter name of person %d : ",i+1);
        scanf("%s",ptr->name);
        printf("Enter age of person %d : ",i+1);
        scanf("%d",&ptr->age);
        printf("\n");
    }
    return;
}
