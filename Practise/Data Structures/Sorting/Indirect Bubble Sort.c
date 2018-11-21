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
    node *ptr=head,*prev,*next;
    node *last,*temp,*end;
    int exchanges;
    while(ptr->next!=NULL)
    {
        last=ptr;
        ptr=ptr->next;
    }
    while(head!=last)
    {
        for(ptr=head,prev=NULL;ptr!=end;prev=ptr,ptr=ptr->next)
        {
            next=ptr->next;
            if(ptr->num>next->num)
            {
                ptr->next=next->next;
                next->next=ptr;
                if(prev==NULL)
                    head=next;
                else
                    prev->next=next;
                ptr=next;
                if(last==next)
                    last=ptr->next;
            }
            if(ptr->next==last)
            {
                last=ptr;
                break;
            }
        }
    }
    return head;
}
