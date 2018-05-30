#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <linked.h>
node * ss(node *);
node *insert(node *,int);
void main()
{
    node *head;
    head=(node*)malloc(sizeof(node));
    printf("Enter data and -999 to end\n");
    head = ss(head);
    printf("\nSOred List\n");
    print(head);
}
node * ss(node *head)
{
    int i;
    scanf("%d",&i);
    head->num=i;
    head->next=(node*)malloc(sizeof(node));
    head->next->num=-999;
    head->next->next=NULL;
    while(1)
    {
        scanf("%d",&i);
        if(i==-999)
            break;
        else
            head=insert(head,i);
    }
    return head;
}
node *insert(node *head,int i)
{
    node *p=head,*r=head,*q;
    if(i<head->num)
    {
        q=(node*)malloc(sizeof(node));
        q->num=i;
        q->next=head;
        head=q;
        return head;
    }
    else
    {
        while(p->num<=i)
        {
            r=p;
            p=p->next;
            if(p->next==NULL)
            {
                q=(node*)malloc(sizeof(node));
                q->num=i;
                q->next=p;
                r->next=q;
                return head;
            }
        }
        q=(node*)malloc(sizeof(node));
        q->num=i;
        q->next=p;
        r->next=q;
        return head;
    }
}
