//Dijkstra's Algorithm
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define TEMP 0
#define PERM 1
#define NIL -1
#define INFINITY 9999
int adj[MAX][MAX];
int n;
int status[MAX];
int path_len[MAX];
int pred[MAX];
void create_graph(void);
void dijkstra(int num);
int get_min(void);
void get_shortest_path(void);
int main()
{
    int num;
    create_graph();
    printf("\nEnter starting vertex : ");
    scanf("%d",&num);
    dijkstra(num);
    get_shortest_path();
    printf("\n\nPress Enter to exit...");
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
void dijkstra(int num)
{
    int i,current;
    for(i=0;i<n;++i)
    {
	path_len[i]=INFINITY;
	pred[i]=NIL;
	status[i]=TEMP;
    }
    path_len[num]=0;
    while(1)
    {
	current=get_min();
	if(current==NIL)
	    return;
	status[current]=PERM;
	for(i=0;i<n;++i)
	{
	    if(adj[current][i] && status[i]==TEMP)
	    {
		if(path_len[current]+adj[current][i] < path_len[i])
		{
		    pred[i]=current;
		    path_len[i]=path_len[current]+adj[current][i];
		}
	    }
	}
    }
}
int get_min(void)
{
    int i,temp_len,node;
    temp_len=INFINITY;
    node=NIL;
    for(i=0;i<n;++i)
    {
	if(status[i]==TEMP && path_len[i] < temp_len)
	{
	    temp_len=path_len[i];
	    node=i;
	}
    }
    return node;
}
void get_shortest_path(void)
{
    int count,i,path[MAX],dest,len;
    while(1)
    {
	printf("\nEnter destination(-1 to end) : ");
	scanf("%d",&dest);
	if(dest==-1)
	     break;
	if(dest<0 || dest>=n)
	{
	    printf("Wrong Destination\n");
	    continue;
	}
	if(status[dest]==TEMP)
	{
	    printf("No Path !!\n");
	    continue;
	}
	count=-1;
	len=path_len[dest];
	while(dest!=NIL)
	{
	    path[++count]=dest;
	    dest=pred[dest];
	}
	printf("Shortest Path : ");
	for(i=count;i>0;--i)
	    printf("%d->",path[i]);
	printf("%d\n",path[i]);
	printf("Distance : %d\n",len);
    }
}