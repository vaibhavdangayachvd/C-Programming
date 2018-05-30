#include <stdio.h>
#include <conio.h>
void main()
{
    //Declaration
    int value[4][3];
    int gt[4]={0},it[3]={0};
    register int i,j,total=0;
    //Total Girls
    printf("Input Data\n");
    printf("Enter values , one at a time, row-wise\n\n");

    for(i=0;i<4;++i)
    {
        for(j=0;j<3;++j)
        {
            scanf("%d",&value[i][j]);
            gt[i]=gt[i]+value[i][j];
        }
    }
    //Item Total
    for(j=0;j<3;++j)
    {
        for(i=0;i<4;++i)
        {
            it[j]=it[j]+value[i][j];
        }
    }
    //Grand Total
    for(i=0;i<4;++i)
    {
        total=total+gt[i];
    }
    //Printing Output
    printf("\nGirl Total\n\n");
    for(i=0;i<4;++i)
    {
        printf("Salesgirl[%d] = %d\n",i+1,gt[i]);
    }
    printf("\nItem Total\n\n");
    for(j=0;j<3;++j)
    {
        printf("Item[%d] = %d\n",j+1,it[j]);
    }
    printf("\nGrand Total\n\n");
    printf("%d\n",total);
}
