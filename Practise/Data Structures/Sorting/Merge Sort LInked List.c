#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct linked
{
    int num;
    struct linked *next;
};
typedef struct linked node;
node *create_list(node *head);
node *merge_sort(node *head);
node *divide(node *start1);
node *merge(node *start1,node *start2);
void print(node *head);
int main()
{
    node *head=NULL;
    head=create_list(head);
    head = merge_sort(head);
    printf("Sorted List : ");
    print(head);
    printf("\n\n\tPress Enter to exit...");
    getch();
}
node *create_list(node *head)
{
    int i,n=0;
    node *ptr=(node*)malloc(sizeof(node));
    printf("Enter number of elements : ");
    do
        scanf("%d",&n);
    while(n<1);
    printf("Enter elements : ");
    for(i=0;i<n;++i,ptr=ptr->next)
    {
        scanf("%d",&ptr->num);
        if(i==0)
            head=ptr;
        if(i==n-1)
            ptr->next=NULL;
        else
            ptr->next=(node*)malloc(sizeof(node));
    }
    return head;
}
void print(node *head)
{
    if(head==NULL)
        return;
    printf("%d ",head->num);
    print(head->next);
}
node *merge_sort(node *head)
{
    node *start1,*start2;
    while(head!=NULL && head->next!=NULL)
    {
        start1=head;
        start2=divide(start1);
        start1=merge_sort(start1);
        start2=merge_sort(start2);
        start1=merge(start1,start2);
        return start1;
    }
    return head;
}
node *divide(node *start1)
{
    node *start2;
    start2=start1->next->next;
    while(start2!=NULL)
    {
        start1=start1->next;
        start2=start2->next;
        if(start2!=NULL)
            start2=start2->next;
    }
    start2=start1->next;
    start1->next=NULL;
    return start2;
}
node *merge(node *start1,node *start2)
{
    node *head,*temp;
    if(start1->num<start2->num)
    {
        head=start1;
        start1=start1->next;
    }
    else
    {
        head=start2;
        start2=start2->next;
    }
    temp=head;
    while(start1!=NULL && start2!=NULL)
    {
        if(start1->num<start2->num)
        {
            temp->next=start1;
            temp=temp->next;
            start1=start1->next;
        }
        else
        {
            temp->next=start2;
            temp=temp->next;
            start2=start2->next;
        }
    }
    while(start1!=NULL)
    {
        temp->next=start1;
        temp=temp->next;
        start1=start1->next;
    }
    while(start2!=NULL)
    {
        temp->next=start2;
        temp=temp->next;
        start2=start2->next;
    }
    return head;
}
