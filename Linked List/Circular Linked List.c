#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct details
{
    int num;
    struct details *next;
};
typedef struct details node;
void scan(node *head);
void print(node *head);
void main()
{
    node *head;
    head=(node*)malloc(sizeof(node));
    printf("Enter numbers -999 to end\n");
    scan(head);
    printf("\nEntered Numbers \n");
    print(head);
    printf("\n\nPress Enter to exit...");
    getch();
}
void scan(node *head)
{
    node *p=head;
    scanf("%d",&p->num);
    while(p->num!=-999)
    {
        p->next=(node*)malloc(sizeof(node));
        p=p->next;
        scanf("%d",&p->num);
    }
    p->next=head;
    return;
}
void print(node *head)
{
    node *p=head;
    while(p->next!=head)
    {
        printf("%d ",p->num);
        p=p->next;
    }
    return;
}
