#include <stdio.h>
struct marks
{
    int sub[3];
    int total;
};
void main()
{
    int i,j;
    struct marks student[3]={{10,10,10,0},
                             {20,20,20,0},
                             {30,30,30,0}};
    struct marks total={0};
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            student[i].total+=student[i].sub[j];
            total.sub[j]+=student[i].sub[j];
        }
        total.total+=student[i].total;
    }
    printf("Student             Marks\n\n");
    for(i=0;i<3;++i)
    {
        printf("Student[%d]       %d\n",i+1,student[i].total);
    }
    printf("\nSubject            Marks\n\n");
    for(i=0;i<3;++i)
    {
        printf("Subject[%d]        %d\n",i+1,total.sub[1]);
    }
    printf("\nGrand Total = %d",total.total);
}
