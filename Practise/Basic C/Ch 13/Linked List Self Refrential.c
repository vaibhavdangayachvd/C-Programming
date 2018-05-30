#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct details
{
    int num;
    struct details *next;
};
typedef struct details node;
void scan(node*);
void print(node*);
node *sort(node*,node*);
void hold (void);
node *search(node *);
int main()
{
    node *head;
    node *q;
	system("cls");
    head = (node*)malloc(sizeof(node));
    printf("Enter a numbers-:(type -999 to end\n->");
    scan(head);
    printf("Sorted List\n->");
    q = search(head);
    head = sort(head,q);
    print(head);
    printf("\n\n");
    hold();
    return 0;
}
void scan(node *head)
{
    scanf("%d",&head->num);
    if(head->num== -999)
    {
        head->next = NULL;
    }
    else
    {
        head->next=(node*)malloc(sizeof(node));
        scan(head->next);
    }
    return;
}
node *search(node *head)
{
    if(head->next==NULL)
        return head;
    else
        search(head->next);
}
node *sort(node *head,node *q)
{
    node *p,*prev,*temp,*end;
    for(end = q;end!=head->next;end = q)
    {
        for(p=prev=head;p->next!=end;prev=p,p=p->next)
        {
            q=p->next;
            if(p->num>q->num)
            {
                p->next=q->next;
                q->next=p;
                if(p!=head)
                    prev->next=q;
                else
                    head=q;
                temp=p;
                p = q;
                q = temp;
            }
        }
    }
    return head;
}
void print(node *head)
{
    if(head->next != NULL)
    {
        printf("%d ",head->num);
        print(head->next);
    }
    return;
}
void hold(void)
{
    printf("Press Enter to continue...");
    getch();
}
