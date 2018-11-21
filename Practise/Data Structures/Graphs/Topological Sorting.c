#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int n;
void create_graph(void);
int front=-1;
int rear=-1;
int queue[MAX];
void insert(int);
int del(void);
int is_empty(void);
int ind(int i);
void topo_sort(int list[]);
int main()
{
    int list[MAX],i;
    create_graph();
    topo_sort(list);
    for(i=0;i<n;++i)
        printf("%d ",list[i]);
    printf("\n\n\tPress Enter to exit...");
    getch();
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
void insert(int ver)
{
    if(front==-1)
        front=0;
    queue[++rear]=ver;
}
int del(void)
{
    if(is_empty())
        return 9999;
    return queue[front++];
}
int is_empty(void)
{
    if(front==-1 || front==rear+1)
        return 1;
    else
        return 0;
}
int ind(int v)
{
    int i,count=0;
    for(i=0;i<n;++i)
    {
        if(adj[i][v])
            count++;
    }
    return count;
}
void topo_sort(int list[])
{
    int i,in[MAX],count=-1,num;
    for(i=0;i<n;++i)
    {
        in[i]=ind(i);
        if(!in[i])
            insert(i);
    }
    while(!is_empty() && count<n-1)
    {
        num=del();
        list[++count]=num;
        for(i=0;i<n;++i)
        {
            if(adj[num][i])
            {
                adj[num][i]=0;
                in[i]=in[i]-1;
                if(!in[i])
                    insert(i);
            }
        }
    }
    if(count<n-1)
    {
        printf("Topological Sort not possible !!!");
        getch();
        exit(0);
    }
}
