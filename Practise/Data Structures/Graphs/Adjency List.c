//Adjency list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct vertex
{
    int num;
    struct vertex *next;
    struct edge *first_edge;
};
typedef struct vertex v_node;
struct edge
{
    struct vertex *dest;
    struct edge *next;
};
typedef struct edge e_node;
void hold_screen(void);
v_node *insert_vertex(v_node *head,int ver);
v_node *get_ver_add(v_node *head,int ver);
void insert_edge(v_node*head,int source,int destination);
void delete_edge(v_node*head,int source,int destination);
void free_node(e_node *head);
void del_edges(v_node *head,int ver);
v_node *delete_vertex(v_node *head,int ver);
void display(v_node *head);
int main()
{
    int source,destination,ver;
    char option;
    v_node *head=NULL;
    while(1)
    {
        system("cls");
        printf("\t\t\t\tAdjacency List Implementation\n\n");
        printf("Choose Option :-\n\n1 - Insert Vertex\n2 - Insert Edge\n3 - Delete Edge\n4 - Delete Vertex\n5 - Display\n\tBackspace - Exit\n");
        option = getch();
        system("cls");
        switch(option)
        {
        case '1':
            printf("\t\t\t\tHere you can insert vertex\n\n");
            printf("Enter vertex to be inserted : ");
            scanf("%d",&ver);
            head=insert_vertex(head,ver);
            hold_screen();
            break;
        case '2':
            printf("\t\t\t\tHere you can insert an edge\n\n");
            printf("Enter source : ");
            scanf("%d",&source);
            printf("Enter destination : ");
            scanf("%d",&destination);
            insert_edge(head,source,destination);
            hold_screen();
            break;
        case '3':
            printf("\t\t\t\tHere you can delete an edge\n\n");
            printf("Enter source : ");
            scanf("%d",&source);
            printf("Enter destination : ");
            scanf("%d",&destination);
            delete_edge(head,source,destination);
            hold_screen();
            break;
        case '4':
            printf("Enter vertex to be deleted : ");
            scanf("%d",&ver);
            head=delete_vertex(head,ver);
            hold_screen();
            break;
        case '5':
            display(head);
            hold_screen();
            break;
        case 8:
            return 0;
        }
    }
}
void hold_screen(void)
{
    printf("\n\nPress Enter to continue...");
    getch();
}
v_node * insert_vertex(v_node *head,int ver)
{
    v_node *ptr=head;
    if(ptr==NULL)
    {
        ptr=(v_node*)malloc(sizeof(v_node));
        ptr->num=ver;
        ptr->next=NULL;
        ptr->first_edge=NULL;
        head=ptr;
    }
    else
    {
        while(1)
        {
            if(ptr->num==ver)
            {
                printf("\nDuplicate Vertex !!");
                return head;
            }
            if(ptr->next==NULL)
                break;
            ptr=ptr->next;
        }
        ptr->next=(v_node*)malloc(sizeof(v_node));
        ptr=ptr->next;
        ptr->num=ver;
        ptr->next=NULL;
        ptr->first_edge=NULL;
    }
    printf("\nVertex Inserted !!");
    return head;
}
v_node *get_vertex_add(v_node *head,int ver)
{
    v_node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->num==ver)
            return ptr;
        ptr=ptr->next;
    }
    return NULL;
}
void insert_edge(v_node *head,int source,int destination)
{
    v_node *srs=get_vertex_add(head,source);
    v_node *dest=get_vertex_add(head,destination);
    e_node *temp;
    if(srs==NULL||dest==NULL)
    {
        printf("\nWrong Input !!");
        return;
    }
    if(srs->first_edge==NULL)
    {
        srs->first_edge=(e_node*)malloc(sizeof(e_node));
        temp=srs->first_edge;
        temp->dest=dest;
        temp->next=NULL;
    }
    else
    {
        temp=srs->first_edge;
        while(1)
        {
            if(temp->dest->num==destination)
            {
                printf("\nEdge Already Present !!");
                return;
            }
            if(temp->next==NULL)
                break;
            temp=temp->next;
        }
        temp->next=(e_node*)malloc(sizeof(e_node));
        temp=temp->next;
        temp->dest=dest;
        temp->next=NULL;
    }
    printf("\nEdge Inserted");
}
void delete_edge(v_node*head,int source,int destination)
{
    v_node *srs=get_vertex_add(head,source);
    v_node *dest=get_vertex_add(head,destination);
    e_node *temp,*prev=NULL;
    if(srs==NULL||dest==NULL)
    {
        printf("\nWrong Input !!");
        return;
    }
    temp = srs->first_edge;
    while(temp!=NULL)
    {
        if(temp->dest->num==destination)
            break;
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
        printf("\nEdge not present !!");
    else
    {
        if(prev==NULL)
            srs->first_edge=NULL;
        else
            prev->next=temp->next;
        free(temp);
        printf("\nEdge Deleted !!");
    }
}
void free_node(e_node *head)
{
    e_node *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
void del_edges(v_node *head,int ver)
{
    e_node *ptr,*prev=NULL;
    while(head!=NULL)
    {
        if(head->num!=ver)
        {
            ptr=head->first_edge;
            while(ptr!=NULL)
            {
                if(ptr->dest->num==ver)
                    break;
                prev=ptr;
                ptr=ptr->next;
            }
            if(ptr!=NULL)
            {
                if(prev==NULL)
                    head->first_edge=NULL;
                else
                    prev->next=ptr->next;
                free(ptr);
            }
        }
        head=head->next;
    }
}
v_node *delete_vertex(v_node *head,int ver)
{
    v_node *temp=get_vertex_add(head,ver);
    v_node *ptr=head,*prev=NULL;
    if(temp==NULL)
    {
        printf("\nVertex not found !!!");
        return head;
    }
    del_edges(head,ver);
    free_node(temp->first_edge);
    while(ptr!=temp)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    if(prev==NULL)
        head=head->next;
    else
        prev->next=ptr->next;
    free(ptr);
    printf("\nVertex Deleted !!");
    return head;
}
void display(v_node *head)
{
    v_node *ver=head;
    e_node *edg;
    if(head==NULL)
    {
        printf("Graph not found !!!");
        return;
    }
    while(ver!=NULL)
    {
        printf("%d ->",ver->num);
        edg=ver->first_edge;
        while(edg!=NULL)
        {
            printf(" %d",edg->dest->num);
            edg=edg->next;
        }
        if(ver->next!=NULL)
            printf("\n");
        ver=ver->next;
    }
}
