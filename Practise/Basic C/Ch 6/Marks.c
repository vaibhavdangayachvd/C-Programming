/*mMarks Calculation*/
#include <stdio.h>
#define FIRST 360
#define SECOND 240
int main()
{
    int n,m,i,j,roll,marks,total;
    printf("Enter number os students and subjects\n->");
    scanf("%d %d",&n,&m);
    printf("\n");
    for (i=1;i<=n;++i)
    {
        printf("Enter Roll Number : ");
        scanf("%d",&roll);
        total = 0;
        printf("Enter marks of %d subjects for roll number %d\n->",m,roll);
        for (j=1;j<=m;++j)
        {
            scanf("%d",&marks);
            total += marks;
        }
        printf("TOTAL MARKS = %d ",total);
        if(total >= FIRST)
            printf("( First Division )\n\n");
        else if (total >= SECOND)
            printf("( Second Division )\n\n");
            else
            printf("(***FAIL***)\n\n");
    }
}
