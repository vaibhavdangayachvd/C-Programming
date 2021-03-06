//Merging Linked List
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <linked.h>
node *sort(node*,node*);
void merge(node *,node*,node *,node*,node*);
void insert(node*,int);
void main()
{
    node *head1,*head2,*head3,*last1,*last2;
    head1=(node*)malloc(sizeof(node));
    head2=(node*)malloc(sizeof(node));
    head3=(node*)malloc(sizeof(node));
    head3->num=-999,head3->next=NULL;
    printf("Enter data of List 1\n");
    scan(head1);
    printf("\nEnter Data of list 2\n");
    scan(head2);
    printf("\nEntered Data of List 1\n");
    print(head1);
    printf("\nEntered Data of list 2\n");
    print(head2);
    last1=ser_last(head1);
    last2=ser_last(head2);
    head1=sort(head1,last1);
    head2=sort(head2,last2);
    merge(head1,head2,head3,last1,last2);
    printf("\nMerged List\n");
    print(head3);
    hold();
}
void merge(node *head1,node *head2,node *head3,node *last1,node *last2)
{
    while(head1!=last1&&head2!=last2)
    {
        if(head1->num<head2->num)
        {
            insert(head3,head1->num);
            head1=head1->next;
        }
        else if(head2->num<head1->num)
        {
            insert(head3,head2->num);
            head2=head2->next;
        }
        else
        {
            insert(head3,head1->num);
            head1=head1->next;
            head2=head2->next;
            continue;
        }
    }
    while(head1!=last1)
    {
        insert(head3,head1->num);
        head1=head1->next;
    }
    while(head2!=last2)
    {
        insert(head3,head2->num);
        head2=head2->next;
    }
}
void insert(node *head,int num)
{
    head=ser_last(head);
    head->num=num;
    head->next=(node*)malloc(sizeof(node));
    head=head->next;
    head->num=-999,head->next=NULL;
    return;
}
