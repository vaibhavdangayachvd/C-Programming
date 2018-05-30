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
node *search(node *);
node *reverse(node*,void*);
void hold (void);
int main()
{
    node *head;
    void *q;
	system("cls");
    head = (node*)malloc(sizeof(node));
    printf("Enter a numbers-:(type -999 to end\n->");
    scan(head);
    printf("Reverse List\n->");
    reverse(head,q);
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
node *reverse(node *head,void *q)
{
    node *next;
    if(prev==q)
        return;
    next=p->next;
    p->next=prev;
    prev=p;
    p=next;
    reverse(p,q);
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
