#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
#define TEMP 0
#define PERM 1
#define NIL -1
#define INFINITY 9999
struct node
{
    int u;
    int v;
}tree[MAX];
int adj[MAX][MAX];
int n;
int status[MAX];
int path_len[MAX];
int pred[MAX];
void create_graph(void);
int get_min(void);
void prim(int ver);
int main()
{
    int i,weight=0,ver=-1;
    create_graph();
    printf("\n");
    do
    {
        printf("Enter vertex : ");
        scanf("%d",&ver);
    }
    while(ver<0 || ver >=n);
    prim(ver);
    printf("Included Tree Edges :- \n");
    for(i=1;i<n;++i)
    {
        printf("%d->%d\n",tree[i].u,tree[i].v);
        weight+=adj[tree[i].u][tree[i].v];
    }
    printf("Weight = %d",weight);
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
void prim(int ver)
{
    int i,current,count=0;
    for(i=0;i<n;++i)
    {
        status[i]=TEMP;
        pred[i]=NIL;
        path_len[i]=INFINITY;
    }
    path_len[ver]=0;
    while(1)
    {
        current=get_min();
        if(current==NIL)
        {
            if(count==n-1)
                return;
            else
            {
                printf("Graph not connected !!!");
                getch();
                exit(1);
            }
        }
        status[current]=PERM;
        if(current!=ver)
        {
            ++count;
            tree[count].u=pred[current];
            tree[count].v=current;
        }
        for(i=0;i<n;++i)
        {
            if(adj[current][i] && status[i]==TEMP)
            {
                if(adj[current][i] < path_len[i])
                {
                    path_len[i]=adj[current][i];
                    pred[i]=current;
                }
            }
        }
    }
}
int get_min(void)
{
    int i,k=NIL,min=INFINITY;
    for(i=0;i<n;++i)
    {
        if(path_len[i]<min && status[i]==TEMP)
        {
            min=path_len[i];
            k=i;
        }
    }
    return k;
}
