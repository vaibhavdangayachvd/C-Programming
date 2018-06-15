/**
    Purpose: Home Casino Manager (Red Black Tree)
    #created 15/06/18 8:10PM

    @author Vaibhav As VD
    @version 1.0 (15/06/18 - 8:10PM)

    Change log :-
    v1 - Initial Release
       - Basic code ported from DBMS by VD
       - Complete File Handling
       - 3 Games Integrated
       - Separate admin and user panel
       - 1 Super admin to manage admins(default id : 0 , pass : password)
       - Request Coin Feature for users
       - Cross Panel Login Prevention
       - Admins cant add or remove other admins
       - Search UserID
       - Separate game page
       - Change password feature for all
       - Admins can directly give coins to any id
       - Added How to use option
*/
//Preprocessor directives
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef enum{false,true} boolean;//For Admin status
//Red-Black Tree Structure
struct rb_tree
{
    boolean admin;
    int coins,request,id;
    char name[20],password[20];
    enum {red,black} color;
    struct rb_tree *lchild;
    struct rb_tree *rchild;
    struct rb_tree *parent;
};
typedef struct rb_tree tree_node;
tree_node *root,*sentinel;
int users = 0;//Initilise Total of users
//User defined function prototypes
//1 - Create New User Functions
void special_read_pw(char[]);//Read password in special way
void re_special_read_pw(char[]);//ReEnter password in special way
void hold_screen(void);//Hold Screen
int set_new_pw(char[]);//Set New Password
int cmp_pw(char[],char[]);//Compare Password
void  create_new_user(int,char[],char[],int,int,boolean);//Insert New User
void balance_after_insert(tree_node *);//Balance Tree
void rotate_left(tree_node*);//rotate tree left
void rotate_right(tree_node*);//Rotate Tree Right
//2 - User Login Functions
tree_node *find_user_node(int);//Find user node
void open_user_menu(tree_node *);//Open user menu
//2.1 User menu functions
//Open Casino
void open_casino(tree_node *);//Open Main Game Page
int check_bet(tree_node *,int *);//Check if bet is correct
//casino Games
void head_tail(tree_node *);//Head Tail Game
void rock_paper(tree_node *);//Rock Paper Game
int rps_win(char ,char );//RPS win algorithm
void up_down(tree_node *);//7up 7down
//Casino game end
void req_coins(tree_node *);//request coins from admin
void cashout(tree_node *);//Cashout Money
void change_pw(tree_node *);//Change Password
//3 - Admin login functions
tree_node *find_admin_node(int);//Find user node
void open_admin_menu(tree_node *);//Open user menu
//3.1 Admin menu functions
void list_users(tree_node *);//List Users
void give_coins(void);//Give Coins
void print_pending_req(tree_node *);//Print Pending requests
void del_user(int);//User delete function
void balance_del(tree_node *);//Tree balance
int find(tree_node **,int);//Find Node to Delete
tree_node *in_succ(tree_node *);//Find Inorder successor
//4 - Search UserID
int search_userid(tree_node *,char[]);//Search Userid
//5 - Print Help
void print_help(void);//Print Help
//File Handeling Functions
void start_check_db(void);//Check for database file during startup
void load_from_file(void);//Load file contents
void clear_file(void);//Clear File
void reappend_file(tree_node *);//Reappend File
void append_to_file(int,char[],char[],int,int,int);//Insert data in file
//Main Function
int main()
{
    //Variable Declaration
    char option,pass[20],name[20];
    int id;
    tree_node *user;
    //Initilize sentinel and root
    sentinel=(tree_node*)malloc(sizeof(tree_node));
    sentinel->color=black;
    sentinel->id=-1;
    root=sentinel;
    start_check_db();
    //Option Loop
    while(1)
    {
        system("cls");
        printf("\n\t\t  Welcome to HOME CASINO By VD\n\n");
        printf("Choose Option:-\n1 - Create new User ID\n2 - User Login\n3 - Admin Login\n4 - Forgot UserID\n5 - How to Use\n Backspace - Exit\n\n->");
        fflush(stdin);
        option = getch();
        system("cls");
        switch(option)
        {
        case '1':
            printf("Enter name : ");
            fflush(stdin);
            scanf(" %[^\n]",name);
            while(1)
            {
                system("cls");
                printf("Enter password\n->");
                fflush(stdin);
                special_read_pw(pass);
                if(pass[0]==0)
                {
                    printf("Wrong Input !! Try Again !!");
                    hold_screen();
                    continue;
                }
                system("cls");
                if(set_new_pw(pass))
                   break;
                printf("Password do not match !!! Try Again !!!\n");
                hold_screen();
            }
            create_new_user(users,name,pass,500,0,false);
            printf("User Successfully Created !!\n");
            printf("Your ID is %d (Remember it !!)",users-1);
            clear_file();
            reappend_file(root);
            hold_screen();
            break;
        case '2':
            printf("Enter User ID : ");
            fflush(stdin);
            scanf(" %d",&id);
            user=find_user_node(id);
            if(user==sentinel)
            {
                break;
            }
            while(1)
            {
                system("cls");
                printf("Enter password\n->");
                fflush(stdin);
                special_read_pw(pass);
                if(cmp_pw(user->password,pass))
                {
                    open_user_menu(user);
                    break;
                }
                else
                {
                    printf("Wrong password !!\n\n");
                    printf("Press Enter to try again !!\n\tBackspace to go back...");
                    option = getch();
                    if(option==8)
                        break;
                }
             }
             break;
        case '3':
            printf("Enter Admin ID : ");
            fflush(stdin);
            scanf(" %d",&id);
            user=find_admin_node(id);
            if(user==sentinel)
            {
                break;
            }
            while(1)
            {
                system("cls");
                printf("Enter password\n->");
                special_read_pw(pass);
                if(cmp_pw(user->password,pass))
                {
                    open_admin_menu(user);
                    break;
                }
                else
                {
                    printf("Wrong password !!\n\n");
                    printf("Press Enter to try again !!\n\tBackspace to go back...");
                    option = getch();
                    if(option==8)
                        break;
                }
            }
            break;
        case '4':
            printf("Enter you name to search for your User ID : ");
            fflush(stdin);
            scanf(" %[^\n]",name);
            id = search_userid(root,name);
            if(!id)
                printf("UserID not found !!");
            hold_screen();
            break;
        case '5':
            print_help();
            hold_screen();
            break;
        case 8://Backspace ascii key
            printf("Press Enter to Exit\n\tBackspace to go back...");
            fflush(stdin);
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
}//End Of Main
//User Defined Functions
//1 - Create New User Functions
//1.1 Read Password in Star Format
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
//1.1 Re Enter Password in Star Format
void re_special_read_pw(char check[])
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
            printf("Re Enter password\n->");
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
        printf("Re Enter password\n->");
        for(j=0;j<i;++j)
        {
            putchar('*');
        }
        putchar(c);
    }
    check[i+1]='\0';
    printf("\n");
}
//1.2 Hold screen function
void hold_screen(void)
{
    printf("\n\nPress Enter to continue...");
    getch();
}
//1.3 Set new Password
int set_new_pw(char pw1[])
{
    char pw2[20];
    printf("Re Enter password\n->");
    re_special_read_pw(pw2);
    if(cmp_pw(pw1,pw2))
    {
        return 1;
    }
    return 0;
}
//1.3.1 Compare Passwords
int cmp_pw(char pw1[],char pw2[])
{
    if(!strcmp(pw1,pw2))
        return 1;
    else
    {
        return 0;
    }
}
//1.4 Insert New User Functiom
void create_new_user(int id,char name[],char pass[],int coins,int request,boolean admin)
{
    tree_node *ptr,*par,*temp;
    ptr=root;
    par=sentinel;
    while(ptr!=sentinel)
    {
        par=ptr;
        if(id<ptr->id)
            ptr=ptr->lchild;
        else if(id>ptr->id)
            ptr=ptr->rchild;
        else
        {
            printf("Duplicate User !!\n");
            return;
        }
    }
        temp=(tree_node*)malloc(sizeof(tree_node));
        temp->id=id;
        strcpy(temp->password,pass);
        strcpy(temp->name,name);
        temp->request=request;
        temp->coins=coins;
        temp->admin=admin;
        temp->lchild=sentinel;
        temp->rchild=sentinel;
        temp->color=red;
        temp->parent=par;
        if(par==sentinel)
            root=temp;
        else if(temp->id<par->id)
            par->lchild=temp;
        else
            par->rchild=temp;
        balance_after_insert(temp);
        ++users;
}
//1.4.1 Tree balance Function
void balance_after_insert(tree_node *node)
{
    tree_node *grand,*par,*uncle;
    par=node->parent;
    grand=par->parent;
    while(node->parent->color==red)
    {
        par=node->parent;
        grand=par->parent;
        if(par==grand->lchild)
        {
            uncle=grand->rchild;
            if(uncle->color==red)
            {
                grand->color=red;
                uncle->color=black;
                par->color=black;
                node=grand;
            }
            else
            {
                if(node==par->rchild)
                {
                    rotate_left(par);
                    node=par;
                    par=node->parent;
                }
                grand->color=red;
                par->color=black;
                rotate_right(grand);
            }
        }
        else
        {
            uncle=grand->lchild;
            if(uncle->color==red)
            {
                grand->color=red;
                uncle->color=black;
                par->color=black;
                node = grand;

            }
            else
            {
                if(node==par->lchild)
                {
                    rotate_right(par);
                    node=par;
                    par=node->parent;
                }
                grand->color=red;
                par->color=black;
                rotate_left(grand);
            }
        }
    }
    root->color=black;
}
//1.4.2 Rotate Tree left
void rotate_left(tree_node*pptr)
{
    tree_node *aptr=pptr->rchild;
    pptr->rchild=aptr->lchild;
    if(aptr->lchild!=sentinel)
        aptr->lchild->parent=pptr;
    aptr->parent=pptr->parent;
    if(pptr->parent==sentinel)
        root=aptr;
    else if(pptr==pptr->parent->lchild)
        pptr->parent->lchild=aptr;
    else
        pptr->parent->rchild=aptr;
    aptr->lchild=pptr;
    pptr->parent=aptr;
}
//1.4.3 Rotate Tree Right
void rotate_right(tree_node*pptr)
{
    tree_node *aptr=pptr->lchild;
    pptr->lchild=aptr->rchild;
    if(aptr->rchild!=sentinel)
        aptr->rchild->parent=pptr;
    aptr->parent=pptr->parent;
    if(pptr->parent==sentinel)
        root=aptr;
    else if(pptr==pptr->parent->lchild)
        pptr->parent->lchild=aptr;
    else
        pptr->parent->rchild=aptr;
    aptr->rchild=pptr;
    pptr->parent=aptr;
}
//2 - User Login Functions
//Find User Node
tree_node *find_user_node(int id)
{
    tree_node *ptr;
    if(id<root->id)
        ptr=root->lchild;
    else if(id>root->id)
        ptr=root->rchild;
    else
        ptr=root;
    while(ptr!=sentinel)
    {
        if(id<ptr->id)
            ptr=ptr->lchild;
        else if(id>ptr->id)
            ptr=ptr->rchild;
        else
        {
            if(ptr->admin==false)
                return ptr;
            else
            {
                printf("You cant login as Admin !!! Goto Admin Panel !!");
                hold_screen();
                return sentinel;
            }
        }
    }
    printf("User ID not found !!");
    hold_screen();
    return sentinel;
}
//Open User Menu
void open_user_menu(tree_node *user)
{
    char option;

    while(1)
    {
        system("cls");
        printf("Welcome %s !! Its your User Panel !!\t\t\tCoin Balance - %d\n\n",user->name,user->coins);
        printf("Choose Option:-\n1 - Enter Casino\n2 - Request Coins\n3 - Cashout\n4 - Change Password\n Backspace - Logout\n\n->");
        fflush(stdin);
        option = getch();
        system("cls");
        switch(option)
        {
        case '1':
            if(user->coins<50)
            {
                printf("\nYou are low on coins !! Please request or Buy !!");
                hold_screen();
                break;
            }
            open_casino(user);
            break;
        case '2':
            req_coins(user);
            clear_file();
            reappend_file(root);
            break;
        case '3':
            cashout(user);
            clear_file();
            reappend_file(root);
            break;
        case '4':
            change_pw(user);
            clear_file();
            reappend_file(root);
            break;
        case 8://Backspace ascii key
            printf("Press Enter to Logout\n\tBackspace to go back...");
            fflush(stdin);
            option = getch();
            if(option==8)
                break;
            else
            {
                return;
            }
        default:
            printf("Wrong Key Pressed!!\n");
            hold_screen();
        }
    }
}
//2 User menu functions
//2.1 Open Casino Page
void open_casino(tree_node *user)
{
    char option;
    while(1)
    {
        if(user->coins<50)
        {
            break;
        }
        system("cls");
        printf("Welcome to open casino %s !!! Here you can play different games !!\t\tCoin Balance - %d\n\n",user->name,user->coins);
        printf("Choose Option:-\n1 - Play Head/Tail\n2 - Play Rock Paper\n3 - 7Up7Down\n Backspace - Exit Casino\n\n->");
        fflush(stdin);
        option = getch();
        system("cls");
        switch(option)
        {
        case '1':
            printf("Rules:-\n1 - Choose a bet greater than or equals to 50\n2 - Choose between head or tail\n3 - If you win you get double else u lose bet");
            hold_screen();
            head_tail(user);
            break;
        case '2':
            printf("Rules:-\n1 - Choose a bet greater than or equals to 50\n2 - Choose between rock,paper and scissors\n3 - If you win you get triple else u lose bet");
            hold_screen();
            rock_paper(user);
            break;
        case '3':
            printf("Rules:-\n1 - Choose a bet greater than or equals to 50\n2 - Choose between up or down\n3 - If you win you get double else u lose bet");
            hold_screen();
            up_down(user);
            break;
        case 8://Backspace ascii key
            printf("Press Enter to Exit\n\tBackspace to go back...");
            fflush(stdin);
            option = getch();
            if(option==8)
                break;
            else
            {
                return;
            }
        default:
            printf("Wrong Key Pressed!!\n");
            hold_screen();
        }
    }
}
//2.1 Check for correct bet
int check_bet(tree_node *user,int *bet)
{
    char option;
    while(1)
    {
        system("cls");
        printf("\t\t\t\tCoin Balance - %d\n\n",user->coins);
        printf("Enter your bet amount : ");
        scanf(" %d",bet);
        if(*bet<50)
        {
            printf("Wrong Bet !!\n\n");
            printf("Press Enter to Continue\n\tBackspace to leave room...\n");
            fflush(stdin);
            option = getch();
            if(option==8)
                return 0;
            else
                continue;
        }
        else if(*bet>user->coins)
        {
            printf("You dont have enough coins !!\n\n");
            printf("Press Enter to Continue\n\tBackspace to leave room...\n");
            fflush(stdin);
            option = getch();
            if(option==8)
                return 0;
            else
                continue;
        }
        return 1;
    }
    return 1;
}
//Casino Games Start
//2.1.1 Head Tail
void head_tail(tree_node *user)
{
    char option,win;
    int bet,result;
    while(1)
    {
        if(user->coins<50)
        {
            printf("\nYou are low on coins !! Please request or Buy !!");
            hold_screen();
            break;
        }
        if(!check_bet(user,&bet))
            return;
        user->coins-=bet;
        jump:
        printf("Press 'h' for head and 't' for tail : ");
        option = getche();
        if(option!='h'&&option!='t')
        {
            printf("Wrong Input!!\n");
            goto jump;
        }
        srand(time(NULL));
        result=rand();
        result%=2;
        if(!result)
            win='h';
        else
            win='t';
        printf("\n");
        if(option==win)
        {
            printf("You WIN !!");
            bet*=2;
            user->coins+=bet;
        }
        else
        {
            printf("You Lose !! Better Luck Next Time !!");
        }
        clear_file();
        reappend_file(root);
        printf("\n\nPress Enter to Continue\n\tBackspace to leave room...\n");
        fflush(stdin);
        option = getch();
        if(option==8)
            break;
        else
            continue;
    }
}
//2.1.2 Rock Paper
void rock_paper(tree_node *user)
{
    char option,win;
    int bet,result;
    while(1)
    {
        if(user->coins<50)
        {
            printf("\nYou are low on coins !! Please request or Buy !!");
            hold_screen();
            break;
        }
        if(!check_bet(user,&bet))
            return;
        user->coins-=bet;
        while(1)
        {
            jump:
            printf("Press 'r' for rock , 'p' for paper and 's' for scissors : ");
            option = getche();
            printf("\n");
            if(option!='r'&&option!='p'&&option!='s')
            {
                printf("Wrong Input!!\n");
                goto jump;
            }
            srand(time(NULL));
            result=rand();
            result%=3;
            if(result==0)
                win='r';
            else if(result==1)
                win='p';
            else
                win='s';
            if(!rps_win(option,win))
            {
                printf("You Lose !! Better Luck Next Time !!");
                break;
            }
            else if((rps_win(option,win))==1)
            {
                printf("Draw!!\n");
                continue;
            }
            else
            {
                printf("You WIN !!");
                bet*=3;
                user->coins+=bet;
                break;
            }
        }
        clear_file();
        reappend_file(root);
        printf("\n\nPress Enter to Continue\n\tBackspace to leave room...\n");
        fflush(stdin);
        option = getch();
        if(option==8)
            break;
        else
            continue;
    }
}
//2.1.2.1 RPS WIN
int rps_win(char a,char b)
{
    if( a=='r' &&  b=='p')
        return 0;
    else if( a=='r' &&  b=='s')
        return 2;
    else if( a=='p' && b=='r')
        return 2;
    else if( a=='p' &&  b=='s')
        return 0;
    else if( a=='s' &&  b=='r')
        return 0;
    else if(a=='s' &&  b=='p')
        return 2;
    else
        return 1;
}
//2.2.3 - 7up_down
void up_down(tree_node *user)
{
    char option,win='k';
    int bet,result,d1,d2;
    while(1)
    {
        if(user->coins<50)
        {
            printf("\nYou are low on coins !! Please request or Buy !!");
            hold_screen();
            break;
        }
        if(!check_bet(user,&bet))
            return;
        user->coins-=bet;
        jump:
        printf("Enter 'u' for up and 'd' for down : ");
        option = getche();
        printf("\n");
        if(option !=  'u' && option != 'd')
        {
            printf("Wrong Input!!\n");
            goto jump;
        }
        srand(time(NULL));
        d1 =rand();
        srand(time(NULL));
        d2 =rand();
        d1%=6;
        d2%=6;
        d1++,d2++;
        result=d1+d2;
        if(result>7)
            win = 'u';
        else if(result<7)
            win = 'd';
        if(win==option)
        {
                bet*=2;
                user->coins+=bet;
            printf("You Win !!!");
        }
        else
            printf("You Lose !! Better Luck Next Time !!");
        clear_file();
        reappend_file(root);
        printf("\n\nPress Enter to Continue\n\tBackspace to leave room...\n");
        fflush(stdin);
        option = getch();
        if(option==8)
            break;
        else
            continue;
    }
}
//Casino Games End
//2.2 Request Coins Function
void req_coins(tree_node *user)
{
    int req;
    if(user->request)
        printf("You already have a pending request !!");
    else
    {
        printf("Enter number of coins you want to request from admin.\n  Note - Unreasonable requests will be rejected !!\n->");
        fflush(stdin);
        scanf(" %d",&req);
        user->request=req;
        printf("Request made !!");
    }
    hold_screen();
}
//2. 3 Cashout Function
void cashout(tree_node *user)
{
    char option;
    int coins;
    if(user->coins<2000)
        printf("You need atleast 2000 coins to cashout !!! Come back after winning !!");
    else
    {
        while(1)
        {
            system("cls");
            printf("How many coins you want to cashout ? Current balance - %d\n->",user->coins);
            fflush(stdin);
            scanf(" %d",&coins);
            if(coins>user->coins)
            {
                printf("You cant withdraw more than you actually have !!");
                printf("Press Enter to try again !!\n\tBackspace to go back...");
                option = getch();
                if(option==8)
                    break;
            }
            else
            {
                printf("Successfully Withdrawn Rs %d !! Collect it from counter !!",coins);
                user->coins=user->coins-coins;
                break;
            }
        }
    }
    hold_screen();
}
//2 .4 Change Password
void change_pw(tree_node *user)
{
    char pass[20];
    printf("Enter old password\n->");
    special_read_pw(pass);
    if(cmp_pw(pass,user->password))
    {
        printf("You can now set new pw !!");
        hold_screen();
        while(1)
        {
            system("cls");
            printf("Enter password\n->");
            special_read_pw(pass);
            if(pass[0]==0)
            {
                printf("Wrong Input !! Try Again !!");
                hold_screen();
                continue;
            }
            system("cls");
            if(set_new_pw(pass))
            {
                strcpy(user->password,pass);
                printf("New password set !!");
                hold_screen();
                break;
            }
            printf("Password do not match !!! Try Again !!!\n");
            hold_screen();
        }
    }
    else
    {
        printf("Wrong password !!!");
        hold_screen();
    }
}
//3 - Admin Login Functions
//Find admin Node
tree_node *find_admin_node(int id)
{
    tree_node *ptr;
    if(id<root->id)
        ptr=root->lchild;
    else if(id>root->id)
        ptr=root->rchild;
    else
        ptr=root;
    while(ptr!=sentinel)
    {
        if(id<ptr->id)
            ptr=ptr->lchild;
        else if(id>ptr->id)
            ptr=ptr->rchild;
        else
        {
            if(ptr->admin==true)
                return ptr;
            else
            {
                printf("You cant login as user !!! Goto User Panel !!");
                hold_screen();
                return sentinel;
            }
        }
    }
    printf("Admin ID not found !!");
    hold_screen();
    return sentinel;
}
//3 Open admin Menu
void open_admin_menu(tree_node *admin)
{
    int id;
    char option;
    char name[20],pass[20];
    tree_node *user;
    while(1)
    {
        system("cls");
        printf("Welcome %s !! Its your Admin Panel !!\n\n",admin->name);
        printf("Choose Option:-\n1 - List users\n2 - Give Coins\n3 - Proceed Pending Requests\n4 - Remove User\n5 - Add Sub-Admin\n6 - Change Password\n Backspace - Logout\n\n->");
        fflush(stdin);
        option = getch();
        system("cls");
        switch(option)
        {
        case '1':
            list_users(root);
            hold_screen();
            break;
        case '2':
            give_coins();
            clear_file();
            reappend_file(root);
            break;
        case '3':
            print_pending_req(root);
            printf("End of List !!\n\n");
            printf("Press Enter to Give Coins\n\tBackspace to go back...\n\n");
            fflush(stdin);
            option = getch();
            if(option==8)
                break;
            else
                give_coins();
            clear_file();
            reappend_file(root);
            break;
        case '4':
            printf("Enter User ID to be deleted : ");
            scanf("%d",&id);
            if(!admin->id)
            {
                del_user(id);
                hold_screen();
                break;
            }
            user = find_user_node(id);
            if(user==sentinel && admin->id != 0)
            {
                break;
            }
            del_user(id);
            clear_file();
            reappend_file(root);
            hold_screen();
            break;
        case '5':
            if(admin->id)
            {
                printf("Only Super Admin can add new admins !!");
                hold_screen();
                break;
            }
            printf("Enter name : ");
            fflush(stdin);
            scanf(" %[^\n]",name);
            while(1)
            {
                system("cls");
                printf("Enter password\n->");
                fflush(stdin);
                special_read_pw(pass);
                if(pass[0]==0)
                {
                    printf("Wrong Input !! Try Again !!");
                    hold_screen();
                    continue;
                }
                system("cls");
                if(set_new_pw(pass))
                   break;
                printf("Password do not match !!! Try Again !!!\n");
                hold_screen();
            }
            create_new_user(users,name,pass,500,0,true);
            printf("Admin Successfully Created !!\n");
            printf("ID is %d",users-1);
            clear_file();
            reappend_file(root);
            hold_screen();
            break;
        case '6':
            change_pw(admin);
            clear_file();
            reappend_file(root);
            break;
        case 8://Backspace ascii key
            printf("Press Enter to Logout\n\tBackspace to go back...");
            fflush(stdin);
            option = getch();
            if(option==8)
                break;
            else
            {
                return;
            }
        default:
            printf("Wrong Key Pressed!!\n");
            hold_screen();
        }
    }
}
//3 Admin menu functions
//3.1 List Users Function
void list_users(tree_node *ptr)
{
    if(ptr==sentinel)
        return;
    list_users(ptr->lchild);
    printf("User ID : %d\nName : %s\nCoin Balance : %d\n\n",ptr->id,ptr->name,ptr->coins);
    list_users(ptr->rchild);
    return;
}
//3.2 Give Coin Function
void give_coins(void)
{
    int id,coins;
    tree_node *user;
    printf("Enter User ID : ");
    scanf(" %d",&id);
    user=find_user_node(id);
    if(user==sentinel)
    {
        return;
    }
    printf("Current coins of %s is %d , pending %d\n\n",user->name,user->coins,user->request);
    printf("Enter how many coins you want to give : ");
    scanf(" %d",&coins);
    user->coins += coins;
    if(user->request)
    {
        user->request-=coins;
        if(user->request<0)
            user->request=0;
    }
    printf("Coins transferred !!\n\n");
    printf("Current coins of %s is %d , pending %d\n",user->name,user->coins,user->request);
    hold_screen();
    return;
}
//3 3 Pending Requests
void print_pending_req(tree_node *ptr)
{
    if(ptr==sentinel)
        return;
    print_pending_req(ptr->lchild);
    if(ptr->request)
        printf("Name : %s\nCoin Balance : %d\nUser ID : %d\n\n",ptr->name,ptr->coins,ptr->id);
    print_pending_req(ptr->rchild);
    return;
}
//3.4 Delete User
void del_user(int key)
{
    tree_node *succ,*ptr,*child;
    if(!find(&ptr,key))
    {
        printf("UserID not found!!");
        return;
    }
    if(ptr->lchild != sentinel && ptr->rchild!=sentinel)
    {
        succ=in_succ(ptr);
        ptr->id=succ->id;
        ptr=succ;
    }
    if(ptr->lchild!=sentinel)
        child=ptr->lchild;
    else
        child=ptr->rchild;
    child->parent=ptr->parent;
    if(ptr->parent==sentinel)
        root=child;
    else if(ptr==ptr->parent->lchild)
        ptr->parent->lchild=child;
    else
        ptr->parent->rchild=child;
    if(child==root)
        child->color=black;
    else if(ptr->color==black)
    {
        if(child!=sentinel)
            child->color=black;
        else
            balance_del(child);
    }
    printf("User ID Deleted !!");
}

//3.4.1 Inorder Successor
tree_node *in_succ(tree_node *ptr)
{
    ptr=ptr->rchild;
    while(ptr->lchild!=sentinel)
        ptr=ptr->lchild;
    return ptr;
}
//3.4.2 Find Node to delete
int find(tree_node **los,int key)
{
    tree_node *ptr;
    if(root==sentinel)
    {
        *los=sentinel;
        return 0;
    }
    if(key==root->id)
    {
        *los=root;
        return 1;
    }
    if(key<root->id)
        ptr=root->lchild;
    else
        ptr=root->rchild;
    while(ptr!=sentinel)
    {
        if(key<ptr->id)
            ptr=ptr->lchild;
        else if(key>ptr->id)
            ptr=ptr->rchild;
        else
        {
            *los=ptr;
            return 1;
        }
    }
    *los=ptr;
    return 0;
}
//3.4.3 Balance Tree
void balance_del(tree_node *nptr)
{
    tree_node *sib;
    while(nptr!=root)
    {
        if(nptr==nptr->parent->lchild)
        {
            sib=nptr->parent->rchild;
            if(sib->color==red)
            {
                sib->color=black;
                nptr->parent->color=red;
                rotate_left(nptr->parent);
                sib=nptr->parent->rchild;
            }
            if(sib->lchild->color==black && sib->rchild->color==black)
            {
                sib->color=red;
                if(nptr->parent->color==red)
                {
                    nptr->parent->color=black;
                    return;
                }
                else
                    nptr=nptr->parent;
            }
            else
            {
                if(sib->rchild->color==black)
                {
                    sib->lchild->color=black;
                    sib->color=red;
                    rotate_right(sib);
                    sib=nptr->parent->rchild;
                }
                sib->color=nptr->parent->color;
                nptr->parent->color=black;
                sib->rchild->color=black;
                rotate_left(nptr->parent);
                return;
            }
        }
        else
        {
            sib=nptr->parent->lchild;
            {
                if(sib->color==red)
                {
                    sib->color=black;
                    nptr->parent->color=red;
                    rotate_right(nptr->parent);
                    sib=nptr->parent->lchild;
                }
                if(sib->lchild->color==black&&sib->rchild->color==black)
                {
                    sib->color=red;
                    if(nptr->parent->color==red)
                    {
                        nptr->parent->color=black;
                        return;
                    }
                    else
                        nptr=nptr->parent;
                }
                else
                {
                    if(sib->lchild->color==black)
                    {
                        sib->rchild->color=black;
                        sib->color=red;
                        rotate_left(sib);
                        sib=nptr->parent->lchild;
                    }
                    sib->color=nptr->parent->color;
                    nptr->parent->color=black;
                    sib->lchild->color=black;
                    rotate_right(nptr->parent);
                    return;
                }
            }
        }
    }//end of while
}
//4 - Search User ID
int search_userid(tree_node *ptr,char name[])
{
    static int flag = 0;
    if(ptr==sentinel)
    {
        return flag;
    }
    search_userid(ptr->lchild,name);
    if(!strcmp(name,ptr->name))
    {
        printf("%s , You User ID is %d\n",ptr->name,ptr->id);
        flag = 1;
    }
    search_userid(ptr->rchild,name);
    return flag;
}
//5 //Print Help
void print_help(void)
{
    printf("This is a Centralize Casino Management Program.You can use this to run or play casino at home.\n\n");
    printf("To Play :-\n\n");
    printf("Make a user id.\nLogin ID and start playing.\nIf you get low on coins you can request from admin or buy from him directly.\n\n");
    printf("To Manage :-\n\n");
    printf("Login Super admin and create other admins to manage you casino.\nNormal admins cant delete or add admins.\n");
}
//File Handling Functions
//Startup Check
void start_check_db(void)
{
    FILE *fp=fopen("database","r");
    if(fp==NULL)
    {
        root=(tree_node*)malloc(sizeof(tree_node));
        root->parent=sentinel;
        root->id=users++;
        strcpy(root->password,"password");
        strcpy(root->name,"super_admin");
        root->coins=500;
        root->request=0;
        root->admin=true;
        root->lchild=sentinel;
        root->rchild=sentinel;
        root->color=black;
        clear_file();//Can be used to create new file
    }
    else
    {
        fclose(fp);
        load_from_file();
    }
}
//Load from disk
void load_from_file(void)
{

    FILE *fp;
    int id,coins,request,admin;
    char name[20],pass[20];
    fp=fopen("database","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %s %d %d %d",&id,name,pass,&coins,&request,&admin);
        if(id==-999)
            continue;
        if(admin)
            create_new_user(id,name,pass,coins,request,true);
        else
            create_new_user(id,name,pass,coins,request,false);
        users = id+1;
    }
    fclose(fp);
}
//New File
void clear_file(void)
{
    FILE *fp;
    fp=fopen("database","w");
    fprintf(fp,"%d %s %s %d %d %d\n",-999,"start","start",500,0,0);
    fclose(fp);
}
//Reappend File
void reappend_file(tree_node *ptr)
{
    if(ptr==sentinel)
        return;
    reappend_file(ptr->lchild);
    append_to_file(ptr->id,ptr->name,ptr->password,ptr->coins,ptr->request,ptr->admin);
    reappend_file(ptr->rchild);
}
//Insert Data in file
void append_to_file(int id,char name[],char pass[],int coins,int request,int admin)
{
    FILE *fp;
    fp=fopen("database","a");
    fprintf(fp,"%d %s %s %d %d %d\n",id,name,pass,coins,request,admin);
    fclose(fp);
}
