// Traversal BFS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
#define INITIAL 0
#define WAITING 1
#define PROCESSED 2
#define NIL -1
#define INFINITY 9999
int front=-1,rear=-1;
int pop(void);
void push(int);
int is_empty(void);
int is_full(void);
int queue[MAX];
void bfs(void);
void create_graph(void);
void display(void);
int adj[MAX][MAX];
int status[MAX];
int distance[MAX];
int pred[MAX];
int n;
int main()
{
    int i,path[MAX],count=-1;
    create_graph();
    display();
    bfs();
    while(1)
    {
        printf("Enter destination vertex(-1 to end) : ");
        scanf("%d",&i);
        if(i<-1||i>n-1)
        {
            printf("Vertex Not Found !!\n");
            continue;
        }
        if(i==-1)
            break;
        if(distance[i]==INFINITY)
        {
            printf("No Path from start vertex to this vertex !!\n");
            continue;
        }
        printf("Shortest Distance is %d \n",distance[i]);
        while(i!=NIL)
        {
            path[++count]=i;
            i=pred[i];
        }
        printf("Shorted Path : ");
        for(i=count;i>=0;--i)
            printf("%d ",path[i]);
        printf("\n");
    }
}
void create_graph(void)
{
    int i,max_edges,srs,dest;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    max_edges = (n*(n-1));
    for(i=0; i<max_edges; ++i)
    {
        printf("Enter source and destination(-1 and -1 to stop)");
        scanf("%d %d",&srs,&dest);
        if(srs == -1 && dest == -1)
            break;
        if(srs < 0 || dest < 0 || srs >= n || dest >= n )
        {
            printf("Wrong Input !!\n");
            --i;
        }
        else
            adj[srs][dest]=1;
    }
}
void display(void)
{
    int i,j;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<n; ++j)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
    printf("\n");
}
void push(int num)
{
    if(is_full())
        return;
    else
    {
        if(front==-1)
            front=0;
        queue[++rear]=num;
    }
}
int pop(void)
{
    if(is_empty())
        return -999;
    else
        return queue[front++];
}
int is_empty(void)
{
    if(front==-1 || front==rear+1)
        return 1;
    else
        return 0;
}
int is_full(void)
{
    if(rear==n-1)
        return 1;
    else
        return 0;
}
void bfs(void)
{
    int temp,i;
    for(i=0;i<n;++i)
    {
        pred[i]=NIL;
        distance[i]=INFINITY;
    }
    push(0);
    status[0]=WAITING;
    pred[0]=NIL;
    distance[0]=0;
    while(!is_empty())
    {
        temp=pop();
        printf("Vertex - %d\n",temp);
        status[temp]=PROCESSED;
        for(i=0;i<n;++i)
        {
            if(adj[temp][i] == 1 && status[i]==INITIAL)
            {
                push(i);
                status[i]=WAITING;
                pred[i]=temp;
                distance[i]=1+distance[temp];
            }
        }
    }
}
