//Polynomial Addition
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<poly.h>
void sum(node*,node*,node*);
void main()
{
    node *head1=(node*)malloc(sizeof(node));
    node *head2=(node*)malloc(sizeof(node));
    node *head3=(node*)malloc(sizeof(node));
    printf("Enter the first expression\n");
    scan(head1);
    printf("\nEnter the second expression\n");
    scan(head2);
    printf("\nEntered Expression 1 \n");
    print(head1);
    printf("\nEntered Expression 2 \n");
    print(head2);
    sum(head1,head2,head3);
    printf("\nSum of first and second expession is \n");
    print(head3);
    free_list(head1);
    free_list(head2);
    free_list(head3);
    hold();
}
void sum(node*head1,node*head2,node*head3)
{
    while(head1->next!=NULL)
    {
        head3->con=head1->con+head2->con;
        head3->exp=head1->exp;
        head3->next=(node*)malloc(sizeof(node));
        head3=head3->next;
        head1=head1->next;
        head2=head2->next;
        if(head1->next==NULL)
        {
            head3->con=-999;
            head3->exp=-999;
            head3->next=NULL;
        }
    }
}
