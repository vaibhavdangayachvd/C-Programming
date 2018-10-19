//DFS Implementation
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define INITIAL 0
#define VISITED 1
//Stack Function and variables
int stack[MAX];
int top=-1;
void push(int);
int pop(void);
int is_empty(void);
//UD Functions
int status[MAX];
int graph[MAX][MAX];
int n;
void create_graph(void);
void dfs(int num);
void dfs_rec(int num);
//Main Function
int main()
{
    int num;
    create_graph();
    printf("Enter starting vertex : ");
    do
        scanf("%d",&num);
    while(num<0 || num>=n);
    dfs_rec(num);
    return 0;
}
//Stack Functions
void push(int n)
{
    if(top==MAX-1)
        return;
    stack[++top]=n;
}
int pop(void)
{
    if(is_empty())
        return -999;
    return stack[top--];
}
int is_empty(void)
{
    if(top==-1)
        return 1;
    else
        return 0;
}
//UD Functions
void create_graph(void)
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
void dfs(int num)
{
    int i;
    push(num);
    while(!is_empty())
    {
        num=pop();
        printf("%d ",num);
        status[num]=VISITED;
        for(i=0;i<n;++i)
        {
            if(graph[num][i] && status[i]==INITIAL)
                push(i);
        }
    }
}
void dfs_rec(int num)
{
    int i;
    printf("%d ",num);
    status[num]=VISITED;
    for(i=0;i<n;++i)
    {
        if(graph[num][i] && status[i]==INITIAL)
            dfs_rec(i);
    }
}
