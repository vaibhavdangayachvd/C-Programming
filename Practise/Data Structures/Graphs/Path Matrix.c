//Path Matrix
#include<stdio.h>
#include<conio.h>
#define MAX 100
int adj[MAX][MAX];
int n;
void create_graph(void);
void display(int arr[][MAX]);
void mul(int arr[][MAX]);
int main()
{
    int adjp[MAX][MAX],x[MAX][MAX],path[MAX][MAX];
    int i,j,p;
    create_graph();
    //Initiliase adj matrix
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            adjp[i][j]=adj[i][j];
            x[i][j]=0;
        }
    }
    //
    for(p=0;p<n;++p)
    {
        if(p>=1)
            mul(adjp);
        printf("ADJ to power %d :-n\n",p+1);
        display(adjp);
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
                x[i][j]+=adjp[i][j];
    }
    printf("The Matrix X is :-\n");
    display(x);
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(x[i][j])
                path[i][j]=1;
            else
                path[i][j]=0;
        }
    }
    printf("Path matrix :-\n\n");
    display(path);
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
            adj[srs][dest]=1;
    }
}
void display(int arr[][MAX])
{
    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}
void mul(int arr[][MAX])
{
    int i,j,k,sum;
    int temp[MAX][MAX];
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            sum=0;
            for(k=0;k<n;++k)
                sum += arr[i][k] * adj[k][j];
            temp[i][j]=sum;
        }
    }
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            arr[i][j]=temp[i][j];
}
