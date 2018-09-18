//Warshalls Algorithms
#include<stdio.h>
#include<conio.h>
#define MAX 100
int matrix[MAX][MAX];
int n;
void create_graph(void);
void display(void);
int main()
{
    int i,j,p;
    create_graph();
    printf("Adj matrix :-\n\n");
    display();
    for(p=0;p<n;++p)
    {
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
                if(!matrix[i][j])
                    if(matrix[i][p] && matrix[p][j])
                        matrix[i][j]=1;
    }
    printf("Path Matrix :-\n\n");
    display();
    return 0;
}
void create_graph(void)
{
    int i,max_edges,srs,dest;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    max_edges = (n*(n-1));
    for(i=0;i<max_edges;++i)
    {
        printf("Enter source and destination(-1 and -1 to stop)");
        scanf("%d %d",&srs,&dest);
        if(srs == -1 && dest == -1)
            break;
        if(srs < 0 || dest < 0 || srs >= n || dest >= n )
        {
            printf("Wrong Input !!");
            --i;
        }
        else
            matrix[srs][dest]=1;
    }
}
void display(void)
{
    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}
