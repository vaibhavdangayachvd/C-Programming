/**
    Purpose: Easy Contribution (Linked List)
    #created 28/08/18 3:10AM

    @author Vaibhav As VD
    @version 1.0 (28/08/18 3:10AM)

    Change log :-
    v1 - Initial Release
       - Inter Group Payments
       - Club Entry Manager
       - Added Documentation
       - Can be compiled on turbo c by just changing type in macro define from 1 to 2
       Major Bugfix :- Wrong extra amount passed to distribute function.
       Minor Bugfix :- Reset was not working properly.
                     - Removed extra parameter in set entry function.
*/
//Preprocessor Directives
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define TYPE 1//1 for Code blocks and any other for turbo
#if TYPE == 1
#define CLS system("cls")
#else
#define CLS clrscr()
#endif // TYPE
//Structure of members
struct details
{
    char name[20];
    float per;
    float grp;
    float total;
    struct details *next;
};
typedef struct details node;
//Global Variables
float entry,per_tot=0,grp_tot=0,bill_amt=0;
int members = 0;
//UD Functions
void hold_screen(void);//Hold Screen
void create_list(node *head);//Create List
void set_entry_fee(void);//Set Entry Fee
void set_group_activity(node *head);//Set Inter group activity
node *find_user_node(node *head,char ch[]);//Find node from name
void calculate(node *head);//Calculate Result
void distri_extra(node *head,float extra,int count);//Recursively Distribute Extra Amount
void reset(node *head);//Reset Casino
int main()
{
    node *head=NULL;
    char option;
    while(1)
    {
        CLS;
        printf("\t\t\tWelcome to Easy Conti by VD\n\n");
        printf("Choose Option :-\n1 - Create List\n2 - Set Entry Fee (optional)\n3 - Inter group payments (optional)\n4 - Calculate\n5 - Reset\n\tBackspace - END\n");
        option = getch();
        CLS;
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
                grp_tot=bill_amt-per_tot;//Set Group Total
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
                set_entry_fee();
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
                free(head);
                head=NULL;
                entry = 0,per_tot=0;
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
        //If last member set next to null else allot memory
        if(i == members-1)
            head->next=NULL;
        else
            head->next = (node*)malloc(sizeof(node));
        head=head->next;
    }
}
void set_entry_fee(void)
{
    printf("Enter entry fee : ");
    jump:
    scanf("%f",&entry);
    if(entry>bill_amt)
    {
        printf("Wrong Amount !!");
        goto jump;
    }
    //Treat entry fee as group activity
    grp_tot+=entry;
    printf("\n\t\tEntry Fee Included !!");
}
void calculate(node *head)
{
    node *ptr=head;
    float extra=0.0;
    int count=0;
    //Add Group amt to grp balance of each
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
            //If someone spend less than the entry fee
            if(ptr->grp+ptr->per - entry/members <=entry/members)
            {
                ptr->total=entry/members;
                //Save its leftover balance
                extra += entry/members-(ptr->grp+ptr->per - entry/members);
                //Count number of members whose result is calculated and saved in total field
                count++;
            }
            ptr=ptr->next;
        }
        //Distribute Extra Balance in other members who spent more than entry
        distri_extra(head,extra,count);
    }
    ptr = head;
    printf("\t\t\tShare of Each Member :- \n\n");
    //Print Result
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
        //Check if any extra balance left after giving extra
        if(ptr->total==0 && amount<= entry/members)
        {
            ptr->total=entry/members;
            extra-=extra/(members-count);//Reduce Extra Balance
            extra+=entry/members-amount;//Add leftover balance to extra
            //Count number of members whose result is calculated and saved in total field
            count++;
        }
        ptr=ptr->next;
    }
    //If not extra balance can be accumulated
    if(temp_count==count)
    {
        ptr=head;
        //Set Result of all by reducing accumulated extra balance from their balance
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
    //if balance is accumulated try again with updated extra balance and count
    distri_extra(head,extra,count);
}
void reset(node *head)
{
    node *ptr=head;
    while(head->next != NULL)
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
    //Sub-Total is added while calculating group total so it is reduced
    grp_tot-=total;
    total/=(float)num;
    //Adding total to their individual personal grp expenditure
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
