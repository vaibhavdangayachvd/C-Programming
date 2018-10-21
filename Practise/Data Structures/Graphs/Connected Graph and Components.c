#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
#define INITIAL 0
#define VISITED 1
#define FINISHED 2
int n;
int status[MAX];
int time;
int ft[MAX];
void create_graph(int adj[][MAX]);
void rev(int adj[][MAX],int adj_rev[][MAX]);
void dfs(int adj[][MAX],int ver);
void dfs_time(int adj[][MAX],int ver);
void check_status(void);
void reset_status(void);
int get_max_time(void);
int main()
{
    int i,adj[MAX][MAX]={0},adj_rev[MAX][MAX]={0},temp;
    create_graph(adj);
    rev(adj,adj_rev);
    for(i=0;i<n;++i)
    {
        if(status[i]==INITIAL)
            dfs_time(adj,i);
    }
    //check_status();
    for(i=0;i<n;++i)
    {
        temp=get_max_time();
        if(temp==-999)
            break;
        dfs(adj_rev,temp);
        printf("\n");
    }
    return 0;
}
void check_status(void)
{
    int i;
    for(i=1;i<n;++i)
    {
        if(!status[i])
        {
            printf("\nGraph Is Not Strongly Connected !!");
            getch();
            exit(0);
        }
    }
}
void rev(int adj[][MAX],int adj_rev[][MAX])
{
    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(adj[i][j])
                adj_rev[j][i]=1;
        }
    }
}
void dfs_time(int adj[][MAX],int ver)
{
    int i;
    ++time;
    status[ver]=VISITED;
    for(i=0;i<n;++i)
    {
        if(adj[ver][i] && !status[i])
            dfs_time(adj,i);
    }
    ft[ver]=++time;
}
void dfs(int adj[][MAX],int ver)
{
    int i;
    printf("%d ",ver);
    status[ver]=FINISHED;
    for(i=0;i<n;++i)
    {
        if(adj[ver][i] && status[i]==VISITED)
            dfs(adj,i);
    }
}
void create_graph(int graph[][MAX])
{
    int i,max_edges,start,end,type;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("Enter graph type(0 - Directed , 1 - Undirected) : ");
    scanf("%d",&type);
    if(type)
        max_edges=n*(n-1)/2;
    else
        max_edges=n*(n-1);
    for(i=0;i<max_edges;++i)
    {
        printf("Enter start and end vertex(-1 and -1 to end) : ");
        scanf("%d %d",&start,&end);
        if(start==-1 && end==-1)
            break;
        if(start<0 && end <0 && start>=n && end>=n)
        {
            printf("Wrong Input !! Try Again !!\n");
            --i;
            continue;
        }
        if(graph[start][end])
        {
            printf("Edge Already Present !!\n");
            --i;
            continue;
        }
        graph[start][end]=1;
        if(type)
            graph[end][start]=1;
    }
}
void reset_status(void)
{
    for(int i=0;i<n;++i)
        status[i]=INITIAL;
}
int get_max_time(void)
{
    int i,max=-999;
    for(i=0;i<n;++i)
    {
        if(status[i]==VISITED)
        {
            if(max==-999)
                max=i;
            else if(ft[i]>ft[max])
                max=i;
        }
    }
    return max;
}
