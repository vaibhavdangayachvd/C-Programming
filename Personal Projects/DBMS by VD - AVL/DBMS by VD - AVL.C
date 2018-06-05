/**
    Purpose: Manage database of students of a class efficiently
    through AVL Tree.
    #created 11/03/18

    @author Vaibhav As VD
    @version 2.0 (01/04/18 - 7:25PM)
    @version 3.0 (02/05/18)- 1:45AM)
	             3.1 (02/05/18 - 4:23AM)
    @version 5.0 (06/06/18 - 3:03AM)

    Change log :-
    v2 - added database file for storing data
       - minor changes
       - better user side documentation
    v3
       -password protection
       -star password format
       -add or remove password
	v3.1
	   -password saved in secure location
	   -delete typed character
    v5.0
       -Major Code Re-factor
       -Better Documentation
       -Re-based(from Linked List to AVL Tree)
       -Removed password from Windows folder for security
       -Better code re-usability
       -Better code understanding
       -Fixed Memory Leaks
       -More Functional
       -Complete port from v3.1
       -Choose options directly without pressing enter
*/
//Preprocessor directives
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//Macro Defination
#define TRUE 1
#define FALSE 0
//AVL Tree Structure
struct avl_tree
{
    int num;
    char name[20];
    int balance;
    struct avl_tree *lchild;
    struct avl_tree *rchild;
};
typedef struct avl_tree tree_node;
//Decoration Functions
void print_options(void);//Print Options
void hold_screen(void);//Hold Screen
//Transversal
void in_trans(tree_node*);//Inorder transversal
//Searching
void search_data(tree_node *,int);
//Rotate Functions
tree_node *rotate_left(tree_node *);//Rotate left
tree_node *rotate_right(tree_node *);//Rotate right
//Insertion Functions
tree_node *insert_data(tree_node *,int,char[],int *);//base Insert Function
tree_node *insert_check_left(tree_node *,int *);//left Balance Check
tree_node *insert_check_right(tree_node *,int *);//Right Balance Check
tree_node *insert_left_balance(tree_node *);//Left balance Insert
tree_node *insert_right_balance(tree_node *);//Right Balance Insert
//Deletion Function
tree_node *delete_data(tree_node *,int,int*);//base Insert Function
tree_node *delete_check_left(tree_node *,int *);//left Balance Check
tree_node *delete_check_right(tree_node *,int *);//Right Balance Check
tree_node *delete_left_balance(tree_node *,int *);//Left balance Insert
tree_node *delete_right_balance(tree_node *,int *);//Right Balance Insert
//Balance After delete functions
void balance_after_del(tree_node*,int);//sort after delete
//Remove Complete List Function
void remove_data(tree_node *);//Clear tree
//File Handling Functions
tree_node *start_check_db(void);//Check for database during startup
tree_node *load_from_file(void);//Load from file
void append_to_file(int,char[]);//append to file
void reappend_file(tree_node *);//Re append after node deletion
void clear_file(void); // Renew file
//Password Functions
void start_check_pw(void);//Startup check for password
void check_for_entry(void);//Entry Check
int check_pw_already(void);//If password already set of not
void set_new_pw(void);//Set New Password
int cmp_pw(char[],char[]);//Compare passwords
void insert_pw(char[]);//Send password to file
void get_old_pw(char[]);//Get old password from file
void change_pw(void);//Change Password
void rem_old_pw(void);//Remove Old Password
//Extra Module
void special_read_pw(char[]);//Read password in special way
//Main Function
int main()
{
    tree_node *root;
    int num,flag;
    char option,name[20];
    root = start_check_db();//Check for database file
    start_check_pw();
    while(1)
    {
        system("cls");
        printf("\t\t  Welcome to DBMS by VD\n\n");
        print_options();
        option = getch();
        system("cls");
        switch(option)
        {
        case '1':
            if(root!=NULL)
                printf("List already Present!!");
            else
            {
                while(1)
                {
                    printf("Enter roll number(-999 to exit) : ");
                    scanf(" %d",&num);
                    if(num==-999)
                        break;
                    printf("Enter Name : ");
                    scanf(" %[^\n]",name);
                    root=insert_data(root,num,name,&flag);
                    printf("\n\n");
                    if(flag)
                        append_to_file(num,name);
                }
            }
            hold_screen();
            break;
        case '2':
            printf("List:-\n\n");
            in_trans(root);
            hold_screen();
            break;
        case '3':
            printf("Enter number to find details : ");
            scanf(" %d",&num);
            search_data(root,num);
            hold_screen();
            break;
        case '4':
            if(root==NULL)
                printf("Create List First !!");
            else
            {
                printf("Enter roll number(-999 to exit) : ");
                scanf(" %d",&num);
                if(num==-999)
                    break;
                printf("Enter Name : ");
                scanf(" %[^\n]",name);
                root=insert_data(root,num,name,&flag);
                printf("\n");
                if(flag)
                    append_to_file(num,name);
            }
            hold_screen();
            break;
        case '5':
            if(root==NULL)
                printf("Create List First !!");
            else
            {
                printf("Enter roll number(-999 to exit) : ");
                scanf(" %d",&num);
                if(num==-999)
                    break;
                root=delete_data(root,num,&flag);
                printf("\n");
                if(flag)
                {
                    balance_after_del(root,num);
                    clear_file();
                    reappend_file(root);
                }
            }
            hold_screen();
            break;
        case '6':
            printf("Do you want to remove complete list? YES/NO\n->");
            scanf(" %s",name);
            if(!strcmp(name,"YES"))
            {
                remove_data(root);
                root=NULL;
                printf("Data Completely Erased !!");
            }
            else
            {
                printf("Wrong Input !!");
            }
            hold_screen();
            break;
        case '7':
            set_new_pw();
            break;
        case '8':
            change_pw();
            break;
        case '9':
            rem_old_pw();
            break;
        case 8://Backspace ascii key
            printf("Press Enter to Exit\n\tBackspace to go back...");
            option = getch();
            if(option==8)
                break;
            else
            {
                system("cls");
                return 0;
            }
        default:
            printf("Wrong Key Pressed!!\n");
            hold_screen();
        }

    }
    return 0;
}
//Print Option Function
void print_options(void)
{
    printf("Choose Option:-\n");
    printf("1 - Create New List\n");
    printf("2 - Print List\n");
    printf("3 - Search\n");
    printf("4 - Insert New Data\n");
    printf("5 - Delete an Item\n");
    printf("6 - Remove Complete List\n");
    printf("7 - Set Password\n");
    printf("8 - Change Password\n");
    printf("9 - Remove password\n");
    printf("Backspace - Exit\n");
    printf("->");
}
//Hold screen function
void hold_screen(void)
{
    printf("\n\nPress Enter to continue...");
    getch();
}
//Transversal function
void in_trans(tree_node*root)
{
    if(root==NULL)
        return;
    in_trans(root->lchild);
    printf("%d - %s\n",root->num,root->name);
    in_trans(root->rchild);
}
//Search function
void search_data(tree_node *root,int key)
{
    if(root==NULL)
    {
        printf("Key Not Found !!");
        return;
    }
    if(key<root->num)
        search_data(root->lchild,key);
    else if(key>root->num)
        search_data(root->rchild,key);
    else
        printf("Name : %s\nRoll Number : %d",root->name,root->num);
}
//Rotate Functions
//Left Rotate
tree_node *rotate_left(tree_node *root)
{
    tree_node *aptr;
    aptr=root->rchild;
    root->rchild=aptr->lchild;
    aptr->lchild=root;
    return aptr;
}
//Right Rotate
tree_node *rotate_right(tree_node *root)
{
    tree_node *aptr;
    aptr=root->lchild;
    root->lchild=aptr->rchild;
    aptr->rchild=root;
    return aptr;
}
//Insert Functions
//Base Insert Function
tree_node *insert_data(tree_node *root,int key,char name[],int *flag)
{
    static int status;
    if(root==NULL)
    {
        root=(tree_node*)malloc(sizeof(tree_node));
        root->lchild=NULL;
        root->rchild=NULL;
        root->balance=0;
        root->num=key;
        strcpy(root->name,name);
        status = TRUE;
        *flag = TRUE;
        printf("Data Inserted !!");
    }
    else if(key<root->num)
    {
        root->lchild=insert_data(root->lchild,key,name,flag);
        if(status==TRUE)
            root=insert_check_left(root,&status);
    }
    else if(key>root->num)
    {
        root->rchild=insert_data(root->rchild,key,name,flag);
        if(status==TRUE)
            root=insert_check_right(root,&status);
    }
    else
    {
        printf("Duplicate Key !!! Data Not Inserted !!\n");
        status = FALSE;
        *flag = FALSE;
    }
    return root;
}
//Left Insert Balance Check Function
tree_node *insert_check_left(tree_node *root,int *status)
{
    switch(root->balance)
    {
    case 0:
        root->balance=1;
        break;
    case -1:
        root->balance=0;
        *status = FALSE;
        break;
    case 1:
        root=insert_left_balance(root);
        *status = FALSE;
    }
    return root;
}
//Right Insert Balance Check Function
tree_node *insert_check_right(tree_node *root,int *status)
{
    switch(root->balance)
    {
    case 0:
        root->balance=-1;
        break;
    case 1:
        root->balance=0;
        *status = FALSE;
        break;
    case -1:
        root=insert_right_balance(root);
        *status = FALSE;
    }
    return root;
}
//Left insert Balancing function
tree_node *insert_left_balance(tree_node *root)
{
    tree_node *aptr,*bptr;
    aptr=root->lchild;
    if(aptr->balance==1)
    {
        root->balance=0;
        aptr->balance=0;
        root=rotate_right(root);
    }
    else
    {
        bptr=aptr->rchild;
        switch(bptr->balance)
        {
        case -1:
            root->balance=0;
            aptr->balance=1;
            break;
        case 1:
            root->balance=-1;
            aptr->balance=0;
            break;
        case 0:
            root->balance=0;
            aptr->balance=0;
        }
        bptr->balance=0;
        root->lchild=rotate_left(aptr);
        root=rotate_right(root);
    }
    return root;
}
//Right insert Balancing function
tree_node *insert_right_balance(tree_node *root)
{
    tree_node *aptr,*bptr;
    aptr=root->rchild;
    if(aptr->balance==-1)
    {
        root->balance=0;
        aptr->balance=0;
        root=rotate_left(root);
    }
    else
    {
        bptr=aptr->lchild;
        switch(bptr->balance)
        {
        case -1:
            root->balance=1;
            aptr->balance=0;
            break;
        case 1:
            root->balance=0;
            aptr->balance=-1;
            break;
        case 0:
            root->balance=0;
            aptr->balance=0;
        }
        bptr->balance=0;
        root->rchild=rotate_right(aptr);
        root=rotate_left(root);
    }
    return root;
}
//Delete Functions
//Base delete function
tree_node *delete_data(tree_node *root,int key,int*flag)
{
    tree_node *temp,*succ;
    static int status;
    if(root==NULL)
    {
        printf("Key Not Found !!!");
        status = FALSE;
        *flag = FALSE;
        return root;
    }
    if(key<root->num)
    {
        root->lchild=delete_data(root->lchild,key,flag);
        if(status==TRUE)
            root=delete_check_left(root,&status);
    }
    else if(key>root->num)
    {
        root->rchild=delete_data(root->rchild,key,flag);
        if(status==TRUE)
            root=delete_check_right(root,&status);
    }
    else
    {
        if(root->lchild!=NULL && root->rchild !=NULL)
        {
            succ=root->rchild;
            while(succ->lchild!=NULL)
                succ=succ->lchild;
            root->num=succ->num;
            root->rchild=delete_data(root->rchild,succ->num,flag);
            if(status == TRUE)
                delete_check_right(root,&status);
        }
        else
        {
            temp=root;
            if(root->lchild!=NULL)
                root=root->lchild;
            else if(root->rchild!=NULL)
                root=root->rchild;
            else
                root=NULL;
            free(temp);
            status = TRUE;
            printf("Data Deleted !!!");
            *flag=TRUE;
        }
    }
    return root;
}
//left delete Balance Check Function
tree_node *delete_check_left(tree_node *root,int *status)
{
    switch(root->balance)
    {
    case 0:
        root->balance=-1;
        break;
    case 1:
        root->balance=0;
        *status=FALSE;
        break;
    case -1:
        root=delete_right_balance(root,status);
    }
    return root;
}
//Right delete Balance Check Function
tree_node *delete_check_right(tree_node *root,int *status)
{
    switch(root->balance)
    {
    case 0:
        root->balance=1;
        break;
    case -1:
        root->balance=0;
        *status=FALSE;
        break;
    case 1:
        root=delete_left_balance(root,status);
    }
    return root;
}
//Left delete Balancing function
tree_node *delete_left_balance(tree_node *root,int *status)
{
    tree_node *aptr,*bptr;
    aptr=root->lchild;
    if(aptr->balance==1)
    {
        root->balance=0;
        aptr->balance=0;
        root=rotate_right(root);
    }
    else if(aptr->balance==0)
    {
        root->balance=1;
        aptr->balance=-1;
        *status = FALSE;
        root=rotate_right(root);
    }
    else
    {
        bptr=aptr->rchild;
        switch(bptr->balance)
        {
        case -1:
            root->balance=0;
            aptr->balance=1;
            break;
        case 1:
            root->balance=-1;
            aptr->balance=0;
            break;
        case 0:
            root->balance=0;
            aptr->balance=0;
        }
        bptr->balance=0;
        root->lchild=rotate_left(aptr);
        root=rotate_right(root);
    }
    return root;
}
//Right Delete Balancing function
tree_node *delete_right_balance(tree_node *root,int *status)
{
    tree_node *aptr,*bptr;
    aptr=root->rchild;
    if(aptr->balance==-1)
    {
        root->balance=0;
        aptr->balance=0;
        root=rotate_left(root);
    }
    else if(aptr->balance==0)
    {
        root->balance=-1;
        aptr->balance=1;
        *status=FALSE;
        root=rotate_left(root);
    }
    else
    {
        bptr=aptr->lchild;
        switch(bptr->balance)
        {
        case -1:
            root->balance=1;
            aptr->balance=0;
            break;
        case 1:
            root->balance=0;
            aptr->balance=-1;
            break;
        case 0:
            root->balance=0;
            aptr->balance=0;
        }
        bptr->balance=0;
        root->rchild=rotate_right(aptr);
        root=rotate_left(root);
    }
    return root;
}
//Balance after Delete
void balance_after_del(tree_node*root,int key)
{
    if(root==NULL)
        return;
    balance_after_del(root->lchild,key);
    if(root->num>key)
        --(root->num);
    balance_after_del(root->rchild,key);
}
//Remove Complete Data Function
void remove_data(tree_node *root)
{
    if(root==NULL)
        return;
    remove_data(root->lchild);
    remove_data(root->rchild);
    free(root);
    clear_file();
}
//File Handling Functions
//Check for database during start
tree_node *start_check_db()
{
    tree_node *root=NULL;
    FILE *fp=fopen("database","r");
    if(fp==NULL)
    {
        clear_file();//Can be used to create new file
    }
    else
    {
        fclose(fp);
        root=load_from_file();
    }
    return root;
}
//Load from file function
tree_node *load_from_file(void)
{
    tree_node *root=NULL;
    FILE *fp;
    int flag;
    int num;
    char name[20];
    fp=fopen("database","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d %[^\n]",&num,name);
        if(num==-999)
            continue;
        root=insert_data(root,num,name,&flag);
    }
    fclose(fp);
    return root;
}
//Append to File
void append_to_file(int num,char name[])
{
    FILE *fp;
    fp=fopen("database","a");
    fprintf(fp,"%d %s\n",num,name);
    fclose(fp);
}
//Re append after delete
void reappend_file(tree_node *root)
{
    if(root==NULL)
        return;
    reappend_file(root->lchild);
    append_to_file(root->num,root->name);
    reappend_file(root->rchild);
}
//Clear FILE
void clear_file(void)
{
    FILE *fp;
    fp=fopen("database","w");
    fprintf(fp,"%d %s\n",-999,"start");
    fclose(fp);
}

//password Functions
//Check for password during startup
void start_check_pw(void)
{
    if(!check_pw_already())
        return;
    else
    {
        check_for_entry();
    }
}
//Ask for entry
void check_for_entry(void)
{
    char epw[20],opw[20];
    printf("Enter password\n->");
    special_read_pw(epw);
    get_old_pw(opw);
    if(cmp_pw(epw,opw))
    {
        printf("Access Granted !!");
        hold_screen();
        return;
    }
    else
    {
        printf("Access Denied !!!\n\nPress enter to exit...");
        getch();
        exit(1);
    }
}
//If Password already set or not
int check_pw_already(void)
{
    FILE *fp;
    char pw[20];
    fp=fopen("pw","r");
    if(fp==NULL)
    {
        fclose(fp);
        return 0;
    }
    fscanf(fp,"%s",pw);
    if(feof(fp))
    {
        fclose(fp);
        return 0;
    }
    fclose(fp);
    return 1;
}
//Set New Password
void set_new_pw(void)
{
    char pw1[20],pw2[20];
    if(check_pw_already())
    {
        printf("Password Already Set !!");
        hold_screen();
        return;
    }
    printf("Enter password\n->");
    special_read_pw(pw1);
    system("cls");
    printf("Enter password\n->");
    special_read_pw(pw2);
    if(cmp_pw(pw1,pw1))
    {
        insert_pw(pw1);
        printf("Password Set !!");
        hold_screen();
    }
}
//Compare passwords
int cmp_pw(char pw1[],char pw2[])
{
    if(!strcmp(pw1,pw2))
        return 1;
    else
    {
        printf("Wrong Password !!");
        return 0;
    }
}
//Insert new password in file
void insert_pw(char pw[])
{
    FILE *fp;
    fp=fopen("pw","w");
    fprintf(fp,"%s\n%s","pw_file",pw);
    fclose(fp);
}
//Get old password
void get_old_pw(char pw[])
{
    FILE *fp;
    fp=fopen("pw","r");
    fscanf(fp,"%s",pw);
    fscanf(fp,"%s",pw);
    fclose(fp);
}
//Change password
void change_pw(void)
{
    FILE *fp;
    char pw1[20],pw2[20];
    if(!check_pw_already())
    {
        printf("No password Set !!!");
        hold_screen();
        return;
    }
    printf("Enter password\n->");
    special_read_pw(pw2);
    get_old_pw(pw1);
    if(cmp_pw(pw1,pw2))
    {
        printf("You can now set new pw !!");
        hold_screen();
        system("cls");
        fp=fopen("pw","w");
        fprintf(fp,"%s","pw_file");
        fclose(fp);
        set_new_pw();
    }
    else
    {
        hold_screen();
    }
}
//Remove Old Password
void rem_old_pw(void)
{
    FILE *fp;
    char pw1[20],pw2[20];
    if(!check_pw_already())
    {
        printf("No password set !!!");
        hold_screen();
        return;
    }
    printf("Enter password\n-> ");
    special_read_pw(pw1);
    get_old_pw(pw2);
    if(cmp_pw(pw1,pw2))
    {
        fp=fopen("pw","w");
        fprintf(fp,"%s","pw_file");
        fclose(fp);
        printf("Password Removed !!!");
        hold_screen();
    }
    else
    {
        hold_screen();
    }
}
//Extra Module
//Special Password Read
void special_read_pw(char check[])
{
    int i,j;
    char c;
    i=-1;
    while(1)
    {
        c=getch();
        if(c==13)
            break;
        else if(c==8)
        {
            system("cls");
            printf("Enter password\n->");
            for(j=0;j<i;++j)
            {
                putchar('*');
            }
            if(i==-1)
                continue;
            else
                i--;
            continue;
        }
        i=i+1;
        check[i]=c;
        system("cls");
        printf("Enter password\n->");
        for(j=0;j<i;++j)
        {
            putchar('*');
        }
        putchar(c);
    }
    check[i+1]='\0';
    printf("\n");
}
