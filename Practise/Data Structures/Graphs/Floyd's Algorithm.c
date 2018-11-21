#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
#define NIL -1
#define INFINITY 9999
int adj[MAX][MAX];
int m[MAX][MAX];
int pred[MAX][MAX];
int n;
void create_graph(void);
void floyd(void);
void get_shortest_path(void);
void find_path(int srs,int dest);
int main()
{
    create_graph();
    floyd();
    get_shortest_path();
    printf("\n\n\tPress Enter to exit...");
    getch();
    return 0;
}
void create_graph(void)
{
    int max_edge,i,start,end,weight;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    max_edge=n*(n-1);
    for(i=0;i<max_edge;++i)
    {
	printf("\nEnter start and end(-1 -1 to end) : ");
	scanf("%d %d",&start,&end);
	if(start==-1 && end==-1)
	    break;
	if(start<0 || end<0 || start>=n || end>=n)
	{
	    printf("Invalid Vertex !! Try Again\n");
	    --i;
	    continue;
	}
	if(adj[start][end])
	{
	    printf("Edge Already Present !!\n");
	    --i;
	    continue;
	}
	printf("Enter weight : ");
	scanf("%d",&weight);
	adj[start][end]=weight;
    }
}
void floyd(void)
{
    int i,j,k;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(adj[i][j])
            {
                m[i][j]=adj[i][j];
                pred[i][j]=i;
            }
            else
            {
                m[i][j]=INFINITY;
                pred[i][j]=NIL;
            }
        }
    }
    for(k=0;k<n;++k)
    {
        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)
            {
                if(m[i][k]+m[k][j] < m[i][j])
                {
                    printf("Change : %d %d %d\n",i,j,k);
                    printf("%d %d %d\n",m[i][k],m[k][j],m[i][j]);
                    m[i][j]=m[i][k]+m[k][j];
                    pred[i][j]=pred[k][j];
                }
            }
        }
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(m[i][j]<0)
            {
                printf("Negative Cycle in Graph !!!");
                getch();
                exit(1);
            }
        }
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("%4d",m[i][j]);

        }
        printf("\n");
    }
    printf("=====\n");
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("%5d",pred[i][j]);
        }
        printf("\n");
    }
}
void get_shortest_path(void)
{
    int dest,srs;
    while(1)
    {
	    printf("\nEnter source(-1 to end) : ");
        scanf("%d",&srs);
        if(srs==-1)
            break;
	    printf("\nEnter destination(-1 to end) : ");
        scanf("%d",&dest);
        if(dest==-1)
            break;
	    if(srs<0 || dest<0 || srs>=n || dest>=n)
	    {
	        printf("Wrong Input !! Try Again\n");
	        continue;
	    }
	    if(m[srs][dest]==INFINITY)
	    {
	        printf("No Path !!\n");
	        continue;
	    }
	    printf("Shortest Path : ");
        find_path(srs,dest);
	    printf("Distance : %d\n",m[srs][dest]);
    }
}
void find_path(int srs,int dest)
{
    int path[MAX],count,i;
    count=-1;
    do
    {
        path[++count]=dest;
        dest=pred[srs][dest];
    }
    while(srs!=dest);
    path[++count]=srs;
    for(i=count;i>0;--i)
        printf("%d->",path[i]);
    printf("%d\n",path[i]);
}
