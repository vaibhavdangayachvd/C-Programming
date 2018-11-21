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
node *redix_sort(node *head);
int get_max_count(node *head);
int get_last_digit(int num,int i);
void enqueue(node **front,node **rear,int num);
node *dequeue(node **front,node **rear);
void print(node *head);
int main()
{
    node *head;
    head=(node*)malloc(sizeof(node));
    printf("Enter elements(-999 to end) : ");
    head=create_list(head);
    head=redix_sort(head);
    printf("Sorted Element : ");
    print(head);
    printf("\n\n\tPress Enter to exit...");
    getch();
    return 0;
}
node *create_list(node *head)
{
    scanf("%d",&head->num);
    if(head->num==-999)
    {
        head->next=NULL;
        return head;
    }
    else
    {
        head->next=(node*)malloc(sizeof(node));
        head->next=create_list(head->next);
        return head;
    }
}
void print(node *head)
{
    if(head->next==NULL)
        return;
    printf("%d ",head->num);
    print(head->next);
}
node *redix_sort(node *head)
{
    int max,i,last_digit;
    node *temp;
    node *front[10],*rear[10];
    node *ptr;
    max=get_max_count(head);
    for(i=0;i<max;++i)
    {
        for(int i=0;i<10;++i)
        {
            front[i]=NULL;
            rear[i]=NULL;
        }
        for(ptr=head;ptr->next!=NULL;ptr=ptr->next)
        {
            last_digit=get_last_digit(ptr->num,i+1);
            enqueue(&front[last_digit],&rear[last_digit],ptr->num);
        }
        ptr=head;
        last_digit=0;
        while(ptr->next!=NULL)
        {
            temp=dequeue(&front[last_digit],&rear[last_digit]);
            if(temp==NULL)
            {
                ++last_digit;
                continue;
            }
            ptr->num=temp->num;
            ptr=ptr->next;
            free(temp);
        }
    }
    return head;
}
int get_max_count(node *head)
{
    int max=-999,count=0;
    while(head->next!=NULL)
    {
        if(head->num>max)
            max=head->num;
        head=head->next;
    }
    while(max)
    {
        max/=10;
        ++count;
    }
    return count;
}
int get_last_digit(int num,int i)
{
    for(int j=1;j<i;++j)
    {
        num/=10;
        if(num==0)
            return 0;
    }
    num%=10;
    return num;
}
void enqueue(node **front,node **rear,int num)
{
    if(*front==NULL)
    {
        *rear=(node*)malloc(sizeof(node));
        (*rear)->num=num;
        (*rear)->next=NULL;
        *front= *rear;
        return;
    }
    (*rear)->next=(node*)malloc(sizeof(node));
    *rear= (*rear)->next;
    (*rear)->num=num;
    (*rear)->next=NULL;
    return;
}
node *dequeue(node **front,node **rear)
{
    node *temp;
    if((*front)==NULL)
        return NULL;
    temp= *front;
    *front= (*front)->next;
    return temp;
}
