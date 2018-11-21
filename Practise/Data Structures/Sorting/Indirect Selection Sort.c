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
node *sort(node *head);
void print(node *head);
int main()
{
    node *head;
    head=(node*)malloc(sizeof(node));
    printf("Enter element : ");
    head=create_list(head);
    head=sort(head);
    printf("Sorted List : ");
    print(head);
    printf("\n\n\tPress Enter to exit...");
    getch();
    return 0;
}
void print(node *head)
{
    if(head->next==NULL)
        return;
    printf("%d ",head->num);
    print(head->next);
}
node *create_list(node *head)
{
    scanf("%d",&head->num);
    if(head->num==-999)
    {
        head->next=NULL;
        return head;
    }
    head->next=(node*)malloc(sizeof(node));
    head->next=create_list(head->next);
    return head;
}
node *sort(node *head)
{
    node *ptr=head,*prev;
    node *temp_ptr,*temp_prev;
    node *temp_last,*temp_last_prev;
    node *last;
    int exchanges;
    int max=-999;
    while(ptr!=NULL)
    {
        last=ptr;
        ptr=ptr->next;
    }
    while(head->next!=last)
    {
        for(ptr=head,prev=NULL;ptr!=last;prev=ptr,ptr=ptr->next)
        {
            if(ptr->num>max)
            {
                max=ptr->num;
                temp_ptr=ptr;
                temp_prev=prev;
            }
            if(ptr->next==last)
            {
                temp_last=ptr;
                temp_last_prev=prev;
            }
        }
        if(temp_ptr == temp_last_prev)
        {
            if(temp_ptr==head)
                head=temp_last;
            temp_last->next=temp_ptr;
            temp_ptr->next=last;
            last=temp_ptr;
        }
        else if(temp_ptr!=temp_last)
        {
            if(temp_ptr==head)
                head=temp_last;
            else
                temp_prev->next=temp_last;
            temp_last->next=temp_ptr->next;
            temp_last_prev->next=temp_ptr;
            temp_ptr->next=last;
            last=temp_ptr;
        }
        else
            last=temp_last;
        max=-999;
    }
    return head;
}
