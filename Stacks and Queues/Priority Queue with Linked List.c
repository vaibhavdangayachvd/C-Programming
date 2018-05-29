#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct details
{
    int prio;
    int num;
    struct details *next;
}*head=NULL;
typedef struct details node;
void scan(void);
void pop(void);
void print(void);
void insert(int,int);
int is_empty(void);
void main()
{
    scan();
    print();
    printf("\n\nPress Enter to exit..");
    getch();
}
void scan()
{
    int i,prio;
    printf("Enter num and prio\n");
    scanf("%d %d",&i,&prio);
    while(i!=-999)
    {
        insert(i,prio);
        scanf("%d %d",&i,&prio);
    }
    return;
}
void print()
{
    while(!is_empty())
        pop();
    if(is_empty())
        printf("\nQueue Underflow");
}
void insert(int i,int prio)
{
    node *p=head,*r,*temp;
    if(head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        head->num=i;
        head->prio=prio;
        head->next=NULL;
    }
    else
    {
        temp=(node*)malloc(sizeof(node));
        temp->prio=prio;
        temp->num=i;
        if(prio<head->prio)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            while(p->prio<prio)
            {
                r=p;
                p=p->next;
                if(p==NULL)
                {
                    temp->next=NULL;
                    r->next=temp;
                    return;
                }
            }
            temp->next=p;
            r->next=temp;
        }
    }
}
void pop(void)
{
    node *temp;
    if(!is_empty())
    {
        temp=head->next;
        printf("%d ",head->num);
        free(head);
        head=temp;
    }
}
int is_empty(void)
{
    if(head==NULL)
        return 1;
    else
        return 0;
}
