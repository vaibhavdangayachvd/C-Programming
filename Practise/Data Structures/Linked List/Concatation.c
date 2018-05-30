#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<linked.h>
node* cc(node *head1,node*head2,node*head3);
void main()
{
    node *head1,*head2,*head3;
    head1=(node*)malloc(sizeof(node));
    head2=(node*)malloc(sizeof(node));
    head3=(node*)malloc(sizeof(node));
    printf("Enter data of list 1\n");
    scan(head1);
    printf("\nEnter data of list 2\n");
    scan(head2);
    head3=cc(head1,head2,head3);
    printf("\nConcanitated List\n");
    print(head3);
    hold();

}
node *cc(node*head1,node*head2,node*head3)
{
    node *p=head1;
    head3=head1;
    while(p->next->next!=NULL)
        p=p->next;
    p->next=head2;
    return head3;
}
