#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct details
{
    char name[20];
    float per;
    float grp;
    float total;
    struct details *next;
};
typedef struct details node;
float entry,per_tot=0,grp_tot=0,bill_amt=0;
int members;
void hold_screen(void);
void create_list(node *head);
void set_entry_fee(node *head);
void set_group_activity(node *head);
node *find_user_node(node *head,char ch[]);
void calculate(node *head);
void distri_extra(node *head,float extra,int count);
void reset(node *head);
int main()
{
    node *head=NULL;
    char option;
    while(1)
    {
        system("cls");
        printf("\t\t\tWelcome to Easy Conti by VD\n\n");
        printf("Choose Option :-\n1 - Create List\n2 - Set Entry Fee (optional)\n3 - Inter group payments (optional)\n4 - Calculate\n5 - Reset\n\tBackspace - END\n");
        option = getch();
        system("cls");
        switch(option)
        {
        case '1':
            if(head!=NULL)
                printf("List Already Present !!");
            else
            {
                printf("\t\t\tHere You Can Create List\n\n");
                head = (node*)malloc(sizeof(node));
                create_list(head);
                jump:
                printf("\tEnter Final Bill Amount : ");
                scanf("%f",&bill_amt);
                if(bill_amt<per_tot)
                {
                    printf("  Wrong Bill Amount !!\n");
                    goto jump;
                }
                grp_tot=bill_amt-per_tot;
                printf("\n\nList Successfully Created !!");
            }
            hold_screen();
            break;
        case '2':
            if(head==NULL)
                printf("Create List First !!");
            else if(entry)
                printf("Entry Fee Already Set !!");
            else
            {
                printf("\t\t\tHere You Can Set Entry Fee\n\n");
                set_entry_fee(head);
            }
            hold_screen();
            break;
        case '3':
            if(head==NULL)
                printf("Create List First !!");
            else
            {
                printf("\t\t\tHere You Can Set Group Activity\n\n");
                set_group_activity(head);
                printf("\n\n\tGroup Activity Set !!");
            }
            hold_screen();
            break;
        case '4':
            if(head==NULL)
                printf("Create List First !!");
            else
                calculate(head);
            hold_screen();
            break;
        case '5':
            printf("\n\n\n\n\n\n\n\t\t\t\tPress Enter to Reset or Backspace to go Back\n");
            option = getch();
            if(option == 8)
                break;
            else
            {
                reset(head);
                head=NULL;
                entry = 0;
                per_tot=0;
                printf("\n\nReset Successfull !!");
                hold_screen();
                break;
            }
        case 8 :
            return 0;
        }
    }
}
void hold_screen()
{
    printf("\n\n\t\t\tPress Enter to continue...");
    getch();
}
void create_list(node *head)
{
    int i;
    printf("Enter number of people in your group : ");
    scanf("%d",&members);
    printf("\n");
    for(i=0;i<members;++i)
    {
        printf("Enter name of member %d : ",i+1);
        scanf("%s",head->name);
        printf("Enter personal expenditure of %s : ",head->name);
        scanf("%f",&head->per);
        head->total=0;
        printf("\n");
        per_tot+=head->per;
        if(i == members-1)
            head->next=NULL;
        else
            head->next = (node*)malloc(sizeof(node));
        head=head->next;
    }
}
void set_entry_fee(node *head)
{
    printf("Enter entry fee : ");
    jump:
    scanf("%f",&entry);
    if(entry>bill_amt)
    {
        printf("Wrong Amount !!");
        goto jump;
    }
    grp_tot+=entry;
    printf("\n\t\tEntry Fee Included !!");
}
void calculate(node *head)
{
    node *ptr=head;
    float extra=0.0;
    int count=0;
    while(ptr!=NULL)
    {
        ptr->grp+=(grp_tot/members);
        ptr=ptr->next;
    }
    ptr=head;
    if(entry==0)
    {
        while(ptr!=NULL)
        {
            ptr->total = ptr->grp+ptr->per;
            ptr=ptr->next;
        }
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->grp+ptr->per - entry/members <=entry/members)
            {
                ptr->total=entry/members;
                extra += entry/members-ptr->grp+ptr->per;
                count++;
            }
            ptr=ptr->next;
        }
        distri_extra(head,extra,count);
    }
    ptr = head;
    printf("\t\t\tShare of Each Member :- \n\n");
    while(ptr!=NULL)
    {
        printf("%s - Rs. %.2f\n",ptr->name,ptr->total);
        ptr=ptr->next;
    }
}
void distri_extra(node *head,float extra,int count)
{
    node *ptr=head;
    float amount;
    int temp_count=count;
    while(ptr!=NULL)
    {
        amount = ptr->grp+ptr->per - entry/members - extra/(members-count);
        if(ptr->total==0 && amount<= entry/members)
        {
            ptr->total=entry/members;
            extra-=extra/(members-count);
            extra+=entry/members-amount;
            count++;
        }
        ptr=ptr->next;
    }
    if(temp_count==count)
    {
        ptr=head;
        while(ptr!=NULL)
        {
            amount = ptr->grp+ptr->per - entry/members - extra/(members-count);
            if(ptr->total==0)
            {
                ptr->total = amount;
            }
            ptr=ptr->next;
        }
        return;
    }
    distri_extra(head,extra,count);
}
void reset(node *head)
{
    node *ptr=head;
    while(head!=NULL)
    {
        ptr=head;
        head=head->next;
        free(ptr);
    }
}
node *find_user_node(node *head,char ch[])
{
    while(head != NULL && strcmp(head->name,ch))
        head=head->next;
    if(head==NULL)
        return NULL;
    else
        return head;
}
void set_group_activity(node *head)
{
    int num,i;
    float total;
    node *ptr;
    char ch[20];
    printf("Enter number of students in sub-group : ");
    scanf("%d",&num);
    printf("\nEnter Sub Group Amount : ");
    scanf("%f",&total);
    printf("\n");
    grp_tot-=total;
    total/=(float)num;
    for(i=0;i<num;++i)
    {
        printf("Enter name of member %d : ",i+1);
        scanf("%s",ch);
        ptr=find_user_node(head,ch);
        if(ptr==NULL)
        {
            printf("User not found !! Try Again !!\n\n");
            --i;
            continue;
        }
        else
            ptr->grp+=total;
    }
}
