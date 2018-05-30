#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct details
{
    struct details *prev;
    int num;
    struct details *next;
};
typedef struct details node;
void scan(node *,void *);
void print(node *);
node *ser_last(node *);
void reverse(node *);

int main()
{
    node *head,*last;
    void *q=NULL;
    head=(node*)malloc(sizeof(node));
    printf("Enter elements(-999 to end)\n->");
    scan(head,q);
    printf("Entered elements\n->");
    print(head);
    printf("\nReversed Elements\n->");
    last = ser_last(head);
    reverse(last);
    printf("\n\nPress Enter to exit...");
    getch();
}
void scan(node *head,void *q)
{
    scanf("%d",&head->num);
    if(head->num==-999)
    {
        head->next=NULL;
        head->prev=q;
        return;
    }
    head->prev=q;
    head->next=(node*)malloc(sizeof(node));
    q=head;
    scan(head->next,q);
}
node *ser_last(node *head)
{
    if(head->next->next==NULL)
        return head;
    else
        ser_last(head->next);
}
void reverse(node *last)
{
    if(last->prev!=NULL)
    {
        printf("%d ",last->num);
        reverse(last->prev);
    }
    else
    {
        printf("%d",last->num);
        return;
    }
}
void print(node *head)
{
    if(head->next!=NULL)
    {
        printf("%d ",head->num);
        print(head->next);
    }
    return;
}
