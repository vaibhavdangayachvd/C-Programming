#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
#define NIL -1
struct edge
{
    int u;
    int v;
    int weight;
    struct edge *next;
}*front=NULL;
int n;
typedef struct edge node;
void create_graph(void);
void push(int u,int v,int weight);
node *pop(void);
int is_empty(void);
void kruskal(node tree[]);
int main()
{
    node tree[MAX];
    int i,tot_weight=0;
    create_graph();
    kruskal(tree);
    printf("\nTree Edge : \n");
    for(i=n-1;i>0;--i)
    {
        printf("%d->%d\n",tree[i].u,tree[i].v);
        tot_weight+=tree[i].weight;
    }
    printf("Total weight = %d",tot_weight);
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
	    printf("Enter weight : ");
	    scanf("%d",&weight);
	    push(start,end,weight);
    }
}
void push(int start,int end,int weight)
{
    node *temp,*ptr,*prev;
    temp=(node*)malloc(sizeof(node));
    temp->u=start;
    temp->v=end;
    temp->weight=weight;
    if(is_empty())
    {
        temp->next=NULL;
        front=temp;
        return;
    }
    ptr=front;
    prev=NULL;
    while(ptr!=NULL && ptr->weight<weight)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    if(prev==NULL)
    {
        temp->next=front;
        front=temp;
    }
    else
    {
        prev->next=temp;
        temp->next=ptr;
    }
}
node *pop(void)
{
    if(is_empty())
        return NULL;
    node *temp;
    temp=front;
    front=front->next;
    return temp;
}
int is_empty(void)
{
    if(front==NULL)
        return 1;
    else
        return 0;
}
void kruskal(node tree[])
{
    int parent[MAX],i,root_u,root_v,u,v,count=0;
    node *temp;
    for(i=0;i<n;++i)
        parent[i]=NIL;
    while(!is_empty() && count<n-1)
    {
        temp=pop();
        u=temp->u;
        v=temp->v;
        while(u!=NIL)
        {
            root_u=u;
            u=parent[u];
        }
        while(v!=NIL)
        {
            root_v=v;
            v=parent[v];
        }
        if(root_u!=root_v)
        {
            count++;
            tree[count].u=temp->u;
            tree[count].v=temp->v;
            tree[count].weight=temp->weight;
            parent[root_v]=root_u;
        }
    }
    if(count<n-1)
    {
        printf("Spannning Tree Not Possible !!");
        getch();
        exit(1);
    }
}
