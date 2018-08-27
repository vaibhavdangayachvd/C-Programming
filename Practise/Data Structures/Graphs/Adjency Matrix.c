#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int n=-1,type;
void create_graph(void);
void insert(void);
void del(void);
void display(void);
void hold(void);
int main()
{
    char option;
    while(1)
    {
        system("cls");
        printf("Choose Option :-\n");
        printf("1 - Create Graph\n2 - Insert Edge\n3 - Delete Edge\n4 - Display Graph\n\tBackspace - End\n");
        option = getch();
        system("cls");
        switch(option)
        {
        case '1':
            if(n!=-1)
                printf("Graph Already Created !!");
            else
                create_graph();
            hold();
            break;
        case '2':
            insert();
            hold();
            break;
        case '3':
            del();
            hold();
            break;
        case '4':
            display();
            hold();
            break;
        case 8:
            return 0;
        }
    }
}
void hold(void)
{
    printf("\n\nPress Enter to continue...");
    getch();
}
void create_graph(void)
{
    int i,source,destination,max_edge;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("Enter graph type :- (1 - Directed , 2 - Undirected\n->");
    scanf("%d",&type);
    if(type==1)
        max_edge = n*(n-1);
    else
        max_edge = (n*(n-1))/2;
    for(i=0;i<max_edge;++i)
    {
        printf("Enter source and destination (-1 -1 to end)\n->");
        scanf("%d %d",&source,&destination);
        if(source == -1 && destination == -1)
            break;
        if(source < 0 || destination < 0 || source >= n || destination >= n)
        {
            printf("Invalid Data\n");
            --i;
        }
        else
        {
            adj[source][destination]=1;
            if(type==2)
                adj[destination][source]=1;
        }
    }
    printf("Graph Created !!");
}
void display(void)
{
    int i,j;
    printf("Adjency Matrix :-\n\n");
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
}
void insert(void)
{
    int source,destination;
    printf("Enter source and destination : ");
    scanf("%d %d",&source,&destination);
    if(source < 0 || destination < 0 || source >= n || destination >= n)
    {
        printf("Invalid Data\n");
        return;
    }
    if(adj[source][destination]==1)
    {
        printf("Already Present !!");
        return;
    }
    adj[source][destination]=1;
    if(type==2)
        adj[destination][source]=1;
    printf("Inserted !!");
}
void del(void)
{
    int source,destination;
    printf("Enter source and destination : ");
    scanf("%d %d",&source,&destination);
    if(source < 0 || destination < 0 || source >= n || destination >= n)
    {
        printf("Invalid Data\n");
        return;
    }
    if(adj[source][destination]==0)
    {
        printf("Already Deleted !!");
        return;
    }
    adj[source][destination]=0;
    if(type==2)
        adj[destination][source]=0;
    printf("Deleted !!");
}
