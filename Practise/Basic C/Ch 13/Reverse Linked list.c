#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct details
{
    int roll;
    struct details *next;
};
typedef struct details node;
void scan(node*);
void print(node*);
node *ser_lst(node*);
node *reverse(node*,void*,void*,void *);
int main()
{
    node *head,*temp;
    head=(node*)malloc(sizeof(node));
    printf("Enter elements and press -999 to end\n->");
    scan(head);
    printf("Entered elements\n->");
    print(head);
    temp = ser_lst(head);
    head = reverse(head,temp,NULL,temp);
    printf("Reversed elements\n->");
    print(head);
    return 0;
}
void scan(node*head)
{
    scanf("%d",&head->roll);
    if(head->roll==-999)
        head->next=NULL;
    else
    {
        head->next=(node*)malloc(sizeof(node));
        scan(head->next);
    }
    return;
}
void print(node *head)
{
    if(head->next!=NULL)
    {
        printf("%d ",head->roll);
        print(head->next);
    }
    if(head->next==NULL)
        printf("\n");
    return;
}
node *ser_lst(node*head)
{
    if(head->next==NULL)
        return head;
    else
        ser_lst(head->next);
}
node *reverse(node*head,void*prev,void*nxt,void *temp)
{
    if(head==temp)
        return prev;
    else
    {
        nxt=head->next;
        head->next=prev;
        prev=head;
        head=nxt;
        reverse(head,prev,nxt,temp);
    }
}

