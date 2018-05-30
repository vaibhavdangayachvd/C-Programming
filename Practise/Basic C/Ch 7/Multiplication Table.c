#include <stdio.h>
#include <conio.h>
#define ROW 5
#define COL 5
void main()
{
    int i,j,value[ROW][COL];
    printf("\tMultiplication Table\n\n");
    printf("     ");
    for(j=1;j<=COL;++j)
    {
        printf("%4d",j);
    }
    printf("\n");
    for(j=1;j<=COL*4+6;++j)
    {
        printf("-");
    }
    printf("\n");
    for(i=0;i<ROW;++i)
    {
        printf("%2d | ",i+1);
        for(j=0;j<COL;++j)
        {
            value[i][j]=(i+1)*(j+1);
            printf("%4d",value[i][j]);
        }
        printf("\n");
    }
}
