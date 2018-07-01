/**
    Purpose: Home Casino Manager (Red Black Tree)(Windows API)
    #created 15/06/18 8:10PM

    @author Vaibhav As VD
    @version 1.0 (15/06/18 - 8:10PM)
    @version 2.0 (21/06/18 - 4:18PM)

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
       - Forgot password option
       Bugfix : - Superadmin can now see admins in users list while admins cant see other admins(16/06/18)
                - Minor Bug Fix(Making Result Move Random)(17/06/18)
                - Admin can see pending coins(17/06/18)

    v2.0 - Code Rebased
         - Integrated GUI using Win32Api
         - OOP Approach
         - Added reset request for users
         - Added reset casino for admins
         - Minimum Cashout amount
         - Better betting system
         - Better event handling
         - Free Coins on user login
         - Connected window open and close without stack
         - First Boot Information Message
         - Some Major and Minor bug fixes
         - Removed Unused Code
    v2.1 - Feature Add : Leaderboard for Top Cashouts using Sorted Linked List(23/06/18)
           Major Bug Fix : Users with no cashout dont appear in leaderboard(23/06/18)
           Minor Change : Maximize option removed(27/06/18)
           Major Bug Fix : Default Name of super admin changed(removed underscore) to show menu items(01/07/18)
*/
//Preprocessor Directives
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
//Macros Define
#define FILE_MENU_EXIT 1
#define SHOW_HELP 2
#define NEW_USER_ID 3
#define USER_LOGIN 4
#define ADMIN_LOGIN 5
#define FORGOT_ID 6
#define FORGOT_PASS 7
#define REQ 8
#define COUT 9
#define PLAY 10
#define CHANGE 11
#define LIST 12
#define DELETE_ID 13
#define CLEAR 14
#define RESET 15
#define GIVE_COINS 16
#define HEAD_TAIL 17
#define UP_DOWN 18
#define STONE_PAPER 19
#define HEAD 23
#define TAIL 24
#define TOSS 25
#define UP 26
#define DOWN 27
#define ROLL_DICE 28
#define STONE 29
#define PAPER 30
#define SCISSOR 31
#define LEADER 32
typedef enum{false,true} boole;//For Admin status
//Red-Black Tree Structure
struct rb_tree
{
    boole admin;
    int coins,request,id,cashout;
    char name[20],password[20];
    enum {red,black} color;
    struct rb_tree *lchild;
    struct rb_tree *rchild;
    struct rb_tree *parent;
};
typedef struct rb_tree tree_node;
tree_node *root,*sentinel,*user;
int users = 0;
int casino_gate=0,bet_flag=1,bet_amount=0;
//Leader Board Structure
struct leader
{
    char name[20];
    int amount;
    struct leader *next;
}*head=NULL;
typedef struct leader node;
//Game Global Variables
//Internal Functions
//File Handeling Functions
void start_check_db(void);//Check for database file during startup
void load_from_file(void);//Load file contents
void clear_file(void);//Clear File
void reappend_file(tree_node *);//Reappend File
void append_to_file(int,char[],char[],int,int,int,int);//Insert data in file
//Creation Functions
void  create_new_user(int,char[],char[],int,int,int,boole);//Insert New User
void balance_after_insert(tree_node *);//Balance Tree
void rotate_left(tree_node*);//rotate tree left
void rotate_right(tree_node*);//Rotate Tree Right
//Find Node Functions
tree_node *find_admin_node(int);//Find user node
tree_node *find_user_node(int);//Find user node
//Admin Menu Functions
void list_users(tree_node *,int,char *);
void pending_req(tree_node *,char *);//Print Pending requests
void reset_casino(tree_node *);//Reset Casino
//Search User Function
int search_userid(tree_node *,char[]);//Search User
//Delete User Functions
void del_user(int);//User delete function
void balance_del(tree_node *);//Tree balance
int find(tree_node **,int);//Find Node to Delete
tree_node *in_succ(tree_node *);//Find Inorder successor
void check_bet(int,HWND);//Check bet
void post_game_exit(void);//Reset Global variables after exit
int rps_win(char ,char );//RPS win algorithm
void create_leaderboard(tree_node *);//Create Leader board
void insert_leader_board(char[],int);//Insert In Leader Board
void show_leader_board(HWND);//Show leader board
void free_list(void);//Free List
//GUI Functions
//Window Procedures
//Home
LRESULT CALLBACK WindowProcedureHome(HWND,UINT,WPARAM,LPARAM);//Home Window
LRESULT CALLBACK WindowProcedureCreateId(HWND,UINT,WPARAM,LPARAM);//Create ID
LRESULT CALLBACK WindowProcedureLogin(HWND,UINT,WPARAM,LPARAM);//Login both panels
LRESULT CALLBACK WindowProcedureUser(HWND,UINT,WPARAM,LPARAM);//User Panel Menu
LRESULT CALLBACK WindowProcedureAdmin(HWND,UINT,WPARAM,LPARAM);//Admin Panel Menu
LRESULT CALLBACK WindowProcedureForgotId(HWND,UINT,WPARAM,LPARAM);//Forgot ID
//User Menu
LRESULT CALLBACK WindowProcedureCasino(HWND,UINT,WPARAM,LPARAM);//Casino
LRESULT CALLBACK WindowProcedureReq(HWND,UINT,WPARAM,LPARAM);//Request Coins
LRESULT CALLBACK WindowProcedureCashout(HWND,UINT,WPARAM,LPARAM);//Cashout
LRESULT CALLBACK WindowProcedureChangePw(HWND,UINT,WPARAM,LPARAM);//Change Password also for admin
//Admin Menu
LRESULT CALLBACK WindowProcedureGiveCoins(HWND,UINT,WPARAM,LPARAM);//Give Coins
LRESULT CALLBACK WindowProcedureDeleteUser(HWND,UINT,WPARAM,LPARAM);//Delete User
//Games
LRESULT CALLBACK WindowProcedureHeadTail(HWND,UINT,WPARAM,LPARAM);//Head Tail
LRESULT CALLBACK WindowProcedureStonePaper(HWND,UINT,WPARAM,LPARAM);//Stone Paper
LRESULT CALLBACK WindowProcedureUpDown(HWND,UINT,WPARAM,LPARAM);//7 Up 7 Down
//Control Create Functions
//Home Controls and subcontrols
void AddMenusHome(HWND);//Add Menu Home
void AddMenusAdmin(HWND);//Add Menu Admin
void AddMenusUni(HWND);//Add Menu Universal
void AddControlsHome(HWND);//Control for home
void AddControlsCreateID(HWND);//Control for create id
void AddControlsLogin(HWND);//Control for login base
void AddControlsUser(HWND);//Control for user panel
void AddControlsAdmin(HWND);//Control for admin panel
void AddControlsForgotID(HWND);//Control for forgot id
//User Panel Controls
void AddControlsCasino(HWND);//Control for casino
void AddControlsChangePw(HWND);//Control for change pw also for admin
void AddControlsReq(HWND);//Control for request coins
void AddControlsCashout(HWND);//Control for cashout
//Admin Menu Controls
void AddControlsGiveCoins(HWND);//Give Coins
void AddControlsDeleteUser(HWND);//Delete User
void AddControlsGame(HWND);//Game
void AddControlsHT(HWND);//Head Tail
void AddControlsUD(HWND);//7 Up 7 Down
void AddControlsSP(HWND);//Stone Paper
//Global Handlers
HMENU hMenu;
HWND hName,hOut,hPass,hRePass,hBet,hCoins;
//Message Loops
//Home
void create_id(void);//Create ID
void login_user(void);//Login User
void login_admin(void);//Login Admin
void forgot_id(void);//Forgot ID
//User Panel
void user_panel(void);//User Panel
void admin_panel(void);//Admin Panel
void change_pw(void);//Change PW also for admin
void cashout(void);//Cashout
void req_coins(void);//Request Coins
void play_casino(void);//Enter Casino
//admin panel
void give_coins(void);//give coins
void delete_user(void);//Delete User
//Games
void head_tail(void);//Head Tail
void up_down(void);//7UP7DOwn
void stone_paper(void);//Stone Paper
//Main Functions WINMAIN
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR args,int ncmdshow)
{
    //Initilise Root and Sentinel
    sentinel=(tree_node*)malloc(sizeof(tree_node));
    sentinel->color=black;
    sentinel->id=-1;
    sentinel->admin=0;
    root=sentinel;
    //Check for file and load
    start_check_db();
    //Home Class
    WNDCLASS home={0};
    home.hbrBackground = (HBRUSH)COLOR_WINDOW;
    home.hCursor=LoadCursor(NULL,IDC_ARROW);
    home.hInstance=hInst;
    home.lpszClassName= "home";
    home.lpfnWndProc=WindowProcedureHome;
    if(!RegisterClass(&home))
        return -1;
    //Forgot ID Class
    WNDCLASS forgotid={0};
    forgotid.hbrBackground = (HBRUSH)COLOR_WINDOW;
    forgotid.hCursor=LoadCursor(NULL,IDC_ARROW);
    forgotid.hInstance=hInst;
    forgotid.lpszClassName= "forgotid";
    forgotid.lpfnWndProc=WindowProcedureForgotId;
    if(!RegisterClass(&forgotid))
        return -1;
    //Create ID Class
    WNDCLASS createid={0};
    createid.hbrBackground = (HBRUSH)COLOR_WINDOW;
    createid.hCursor=LoadCursor(NULL,IDC_ARROW);
    createid.hInstance=hInst;
    createid.lpszClassName= "createid";
    createid.lpfnWndProc=WindowProcedureCreateId;
    if(!RegisterClass(&createid))
        return -1;
    //Login Class
    WNDCLASS login={0};
    login.hbrBackground = (HBRUSH)COLOR_WINDOW;
    login.hCursor=LoadCursor(NULL,IDC_ARROW);
    login.hInstance=hInst;
    login.lpszClassName= "login";
    login.lpfnWndProc=WindowProcedureLogin;
    if(!RegisterClass(&login))
        return -1;
    //User Class
    WNDCLASS user={0};
    user.hbrBackground = (HBRUSH)COLOR_WINDOW;
    user.hCursor=LoadCursor(NULL,IDC_ARROW);
    user.hInstance=hInst;
    user.lpszClassName= "user";
    user.lpfnWndProc=WindowProcedureUser;
    if(!RegisterClass(&user))
        return -1;
    //Admin Class
    WNDCLASS admin={0};
    admin.hbrBackground = (HBRUSH)COLOR_WINDOW;
    admin.hCursor=LoadCursor(NULL,IDC_ARROW);
    admin.hInstance=hInst;
    admin.lpszClassName= "admin";
    admin.lpfnWndProc=WindowProcedureAdmin;
    if(!RegisterClass(&admin))
        return -1;
    //Casino Class
    WNDCLASS casino={0};
    casino.hbrBackground = (HBRUSH)COLOR_WINDOW;
    casino.hCursor=LoadCursor(NULL,IDC_ARROW);
    casino.hInstance=hInst;
    casino.lpszClassName= "casino";
    casino.lpfnWndProc=WindowProcedureCasino;
    if(!RegisterClass(&casino))
        return -1;
    //ChangePW class
    WNDCLASS change_pw={0};
    change_pw.hbrBackground = (HBRUSH)COLOR_WINDOW;
    change_pw.hCursor=LoadCursor(NULL,IDC_ARROW);
    change_pw.hInstance=hInst;
    change_pw.lpszClassName= "change_pw";
    change_pw.lpfnWndProc=WindowProcedureChangePw;
    if(!RegisterClass(&change_pw))
        return -1;
    //Request Coins class
    WNDCLASS req={0};
    req.hbrBackground = (HBRUSH)COLOR_WINDOW;
    req.hCursor=LoadCursor(NULL,IDC_ARROW);
    req.hInstance=hInst;
    req.lpszClassName= "req";
    req.lpfnWndProc=WindowProcedureReq;
    if(!RegisterClass(&req))
        return -1;
    //Cashout class
    WNDCLASS cashout={0};
    cashout.hbrBackground = (HBRUSH)COLOR_WINDOW;
    cashout.hCursor=LoadCursor(NULL,IDC_ARROW);
    cashout.hInstance=hInst;
    cashout.lpszClassName= "cashout";
    cashout.lpfnWndProc=WindowProcedureCashout;
    if(!RegisterClass(&cashout))
        return -1;
    //Give Coins Class
    WNDCLASS give_coins={0};
    give_coins.hbrBackground = (HBRUSH)COLOR_WINDOW;
    give_coins.hCursor=LoadCursor(NULL,IDC_ARROW);
    give_coins.hInstance=hInst;
    give_coins.lpszClassName= "give_coins";
    give_coins.lpfnWndProc=WindowProcedureGiveCoins;
    if(!RegisterClass(&give_coins))
        return -1;
    //delete-user class
    WNDCLASS delete_user={0};
    delete_user.hbrBackground = (HBRUSH)COLOR_WINDOW;
    delete_user.hCursor=LoadCursor(NULL,IDC_ARROW);
    delete_user.hInstance=hInst;
    delete_user.lpszClassName= "delete_user";
    delete_user.lpfnWndProc=WindowProcedureDeleteUser;
    if(!RegisterClass(&delete_user))
        return -1;
    //Game Head Tail
    WNDCLASS head_tail={0};
    head_tail.hbrBackground = (HBRUSH)COLOR_WINDOW;
    head_tail.hCursor=LoadCursor(NULL,IDC_ARROW);
    head_tail.hInstance=hInst;
    head_tail.lpszClassName= "head_tail";
    head_tail.lpfnWndProc=WindowProcedureHeadTail;
    if(!RegisterClass(&head_tail))
        return -1;
    //Game Sone Paper
    WNDCLASS stone_paper={0};
    stone_paper.hbrBackground = (HBRUSH)COLOR_WINDOW;
    stone_paper.hCursor=LoadCursor(NULL,IDC_ARROW);
    stone_paper.hInstance=hInst;
    stone_paper.lpszClassName= "stone_paper";
    stone_paper.lpfnWndProc=WindowProcedureStonePaper;
    if(!RegisterClass(&stone_paper))
        return -1;
    //Game 7 UP 7 Down
    WNDCLASS up_down={0};
    up_down.hbrBackground = (HBRUSH)COLOR_WINDOW;
    up_down.hCursor=LoadCursor(NULL,IDC_ARROW);
    up_down.hInstance=hInst;
    up_down.lpszClassName= "up_down";
    up_down.lpfnWndProc=WindowProcedureUpDown;
    if(!RegisterClass(&up_down))
        return -1;
    //Creating Home Window
    CreateWindow("home","Home Casino",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,500,200,500,270,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
//Window Procedures
LRESULT CALLBACK WindowProcedureHome(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char *leader;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case SHOW_HELP:
            MessageBeep(MB_ICONINFORMATION);
            MessageBox(hWnd,"This is a Centralize Casino Management Program.You can use this to run or play casino at home.\n\nTo Play :-\n\nMake a user id.\nLogin ID and start playing.\nUsers will get bonus 10 coins on each login.\nIf you want more coins you can request from admin or buy from him directly.\n\nTo Manage :-\n\nLogin Super admin and create other admins to manage you casino.\nNormal admins cant delete or add admins.\n","How To Use",MB_OK);
            break;
        case FORGOT_PASS:
            MessageBox(hWnd,"Contact admin to know you password.","Forgot Password",MB_OK|MB_ICONINFORMATION);
            break;
        case FORGOT_ID:
            forgot_id();
            break;
        case NEW_USER_ID:
            user=sentinel;
            create_id();
            break;
        case USER_LOGIN:
            login_user();
            break;
        case ADMIN_LOGIN:
            login_admin();
            break;
        case LEADER:
            create_leader_board(root);
            show_leader_board(hWnd);
            free(leader);
            break;
        }
        break;
    case WM_CREATE:
        AddMenusHome(hWnd);
        AddControlsHome(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureCreateId(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char name[50],pass[20],repass[20];
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case CLEAR:
            SetWindowText(hName,"");
            SetWindowText(hPass,"");
            SetWindowText(hRePass,"");
            break;
        case NEW_USER_ID:
            GetWindowText(hName,name,50);
            if(!strcmp(name,""))
            {
                MessageBox(hWnd,"Name is empty","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            GetWindowText(hPass,pass,20);
            GetWindowText(hRePass,repass,20);
            if(strcmp(pass,repass) || !strcmp(pass,""))
            {
                MessageBox(hWnd,"Passwords Do Not Match","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            if(user->admin==true)
            {
                if(user->id==0)
                {
                    create_new_user(users,name,pass,500,0,0,true);
                    sprintf(name,"Admin Created !!\nID : %d",users-1);
                    MessageBox(hWnd,name,"Message",MB_OK|MB_ICONINFORMATION);
                    clear_file();
                    reappend_file(root);
                }
                else
                {
                    MessageBox(hWnd,"Only Super Admin Can Create Admins","Message",MB_OK|MB_ICONEXCLAMATION);
                }
                DestroyWindow(hWnd);
                break;
            }
            else
            {
                create_new_user(users,name,pass,500,0,0,false);
                clear_file();
                reappend_file(root);
                sprintf(name,"User Created !!\nYour ID is %d\nRemember it!",users-1);
                MessageBox(hWnd,name,"Message",MB_OK|MB_ICONINFORMATION);
                DestroyWindow(hWnd);
                break;
            }
        }
        break;
    case WM_CREATE:
        AddControlsCreateID(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        if(user->admin==true)
            admin_panel();
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureLogin(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char name[20],pass[20];
    int id;
    tree_node *test;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case CLEAR:
            SetWindowText(hName,"");
            SetWindowText(hPass,"");
            break;
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case USER_LOGIN:
            GetWindowText(hName,name,30);
            if(!strcmp(name,""))
            {
                MessageBox(hWnd,"Name is empty","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            if(!isdigit(name[0]))
            {
                MessageBox(hWnd,"Enter Numeric Id","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            id = atoi(name);
            user=find_user_node(id);
            test=find_admin_node(id);
            if(user==sentinel && test == sentinel)
            {
                MessageBox(hWnd,"User not found !!","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                break;
            }
            else if(user==sentinel)
            {
                MessageBox(hWnd,"Admins cant login in user panel.\nGoto Admin Panel","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                SetWindowText(hPass,"");
                break;
            }
            GetWindowText(hPass,pass,20);
            if(!strcmp(pass,""))
            {
                MessageBox(hWnd,"Password is empty","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            if(strcmp(user->password,pass))
            {
                MessageBox(hWnd,"Wrong Password","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hPass,"");
                break;
            }
            MessageBox(hWnd,"Login Successful !!","Message",MB_OK|MB_ICONINFORMATION);
            DestroyWindow(hWnd);
            user->coins+=10;
            clear_file();
            reappend_file(root);
            user_panel();
            break;
        case ADMIN_LOGIN:
            GetWindowText(hName,name,30);
            if(!strcmp(name,""))
            {
                MessageBox(hWnd,"Name is empty","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            if(!isdigit(name[0]))
            {
                MessageBox(hWnd,"Enter Numeric Id","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            id = atoi(name);
            user=find_admin_node(id);
            test=find_user_node(id);
            if(user==sentinel && test == sentinel)
            {
                MessageBox(hWnd,"User not found !!","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                break;
            }
            if(user==sentinel)
            {
                MessageBox(hWnd,"User cant login in admin panel.\nGoto User Panel","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                SetWindowText(hPass,"");
                break;
            }
            GetWindowText(hPass,pass,20);
            if(!strcmp(pass,""))
            {
                MessageBox(hWnd,"Password is empty","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            if(strcmp(user->password,pass))
            {
                MessageBox(hWnd,"Wrong Password","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hPass,"");
                break;
            }
            MessageBox(hWnd,"Login Successful !!","Message",MB_OK|MB_ICONINFORMATION);
            DestroyWindow(hWnd);
            admin_panel();
            break;
        }
        break;
    case WM_CREATE:
        AddControlsLogin(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureUser(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case SHOW_HELP:
            MessageBox(hWnd,"Users will get bonus 10 coins on each login.\nIf you want more coins you can request from admin or buy from him directly.\n","Free Coins",MB_OK|MB_ICONINFORMATION);
                break;
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case CHANGE:
            DestroyWindow(hWnd);
            change_pw();
            break;
        case REQ:
            if(user->request)
            {
                MessageBox(hWnd,"Already a pending request yet to be accepted.","Message",MB_OK|MB_ICONINFORMATION);
                break;
            }
            DestroyWindow(hWnd);
            req_coins();
            break;
        case PLAY:
            if(user->coins<50)
            {
                MessageBox(hWnd,"You don't have enough coins.","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            DestroyWindow(hWnd);
            play_casino();
            break;
        case COUT:
            if(user->coins<2000)
            {
                MessageBox(hWnd,"You need atleast 2000 coins to cashout.","Message",MB_OK|MB_ICONINFORMATION);
                break;
            }
            DestroyWindow(hWnd);
            cashout();
            break;
        case RESET:
            if(!user->request)
            {
                MessageBox(hWnd,"You dont have any pending request.","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            if((MessageBox(hWnd,"Are you sure you want to reset coin request?","Message",MB_YESNO|MB_ICONQUESTION))!=IDYES)
                break;
            user->request=0;
            clear_file();
            reappend_file(root);
            MessageBox(hWnd,"Request Reset Successful !!","Message",MB_OK|MB_ICONINFORMATION);
            break;
        }
        break;
    case WM_CREATE:
        AddControlsUser(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureAdmin(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char *name;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case GIVE_COINS:
            DestroyWindow(hWnd);
            give_coins();
            break;
        case CHANGE:
            DestroyWindow(hWnd);
            change_pw();
            break;
        case LIST:
            name = (char *)malloc(users*80);
            *name='\0';
            if(user->id==0)
            {
                list_users(root,1,name);
                if(!strcmp(name,""))
                    MessageBox(hWnd,"List Empty","User list",MB_OK|MB_ICONINFORMATION);
                else
                    MessageBox(hWnd,name,"User List",MB_OK|MB_ICONINFORMATION);
            }
            else
            {
                list_users(root,0,name);
                if(!strcmp(name,""))
                    MessageBox(hWnd,"List Empty","User list",MB_OK|MB_ICONINFORMATION);
                else
                    MessageBox(hWnd,name,"User List",MB_OK|MB_ICONINFORMATION);
            }
            free(name);
            break;
        case REQ:
            name = (char *)malloc(users*80);
            *name='\0';
            pending_req(root,name);
            if(!strcmp(name,""))
                MessageBox(hWnd,"No Pending Request","Pending Requests",MB_OK|MB_ICONINFORMATION);
            else
                MessageBox(hWnd,name,"Pending Requests",MB_OK|MB_ICONINFORMATION);
            break;
        case NEW_USER_ID:
            DestroyWindow(hWnd);
            create_id();
            break;
        case RESET:
            if(user->id)
            {
                MessageBox(hWnd,"Only Super Admin Can Perform Reset","Reset Casino",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            if((MessageBox(hWnd,"Are you sure you want to reset the whole casino?","Reset Casino",MB_YESNO|MB_ICONQUESTION))!=IDYES)
                break;
            reset_casino(root);
            users=0;
            root=(tree_node*)malloc(sizeof(tree_node));
            root->parent=sentinel;
            root->id=users++;
            strcpy(root->password,"password");
            strcpy(root->name,"SuperAdmin");
            root->coins=500;
            root->request=0;
            root->admin=true;
            root->lchild=sentinel;
            root->rchild=sentinel;
            root->color=black;
            user = root;
            clear_file();
            reappend_file(root);
            MessageBox(hWnd,"Reset Successful\nSuper Admin ID : 0\nPassword : password","Reset Casino",MB_OK|MB_ICONINFORMATION);
            break;
        case DELETE_ID:
            DestroyWindow(hWnd);
            delete_user();
            break;
        }
        break;
    case WM_CREATE:
        AddControlsAdmin(hWnd);
        AddMenusAdmin(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureForgotId(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char name[30];
    int id;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case CLEAR:
            SetWindowText(hName,"");
            SetWindowText(hOut,"");
            break;
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case FORGOT_ID:
            GetWindowText(hName,name,30);
            id = search_userid(root,name);
            if(!id)
                SetWindowText(hOut,"User ID not found !!!");
            else
            {
                sprintf(name,"Your ID is %d",id);
                SetWindowText(hOut,name);
            }
            break;
        }
        break;
    case WM_CREATE:
        AddControlsForgotID(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureChangePw(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char old_pw[20],new_pw[20],re_new_pw[20];
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case CLEAR:
             SetWindowText(hName,"");
             SetWindowText(hPass,"");
             SetWindowText(hRePass,"");
             break;
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case CHANGE:
            GetWindowText(hName,old_pw,20);
            GetWindowText(hPass,new_pw,20);
            GetWindowText(hRePass,re_new_pw,20);
            if(!strcmp(old_pw,""))
            {
                MessageBox(hWnd,"Password is empty","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            else if(!strcmp(new_pw,""))
            {
                MessageBox(hWnd,"New Password is empty","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            else if(!strcmp(re_new_pw,""))
            {
                MessageBox(hWnd,"Password is empty","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            else if(strcmp(new_pw,re_new_pw))
            {
                MessageBox(hWnd,"Passwords do not match","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            else if(strcmp(old_pw,user->password))
            {
                MessageBox(hWnd,"Wrong Password !!","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            else
            {
                strcpy(user->password,new_pw);
                clear_file();
                reappend_file(root);
                MessageBox(hWnd,"New Password Set Successfully !!","Message",MB_OK|MB_ICONINFORMATION);
                DestroyWindow(hWnd);
                break;
            }
        }
        break;
    case WM_CREATE:
        AddControlsChangePw(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        if(user->admin==true)
            admin_panel();
        else
            user_panel();
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureReq(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    int coins;
    char name[10];
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case REQ:
            GetWindowText(hName,name,10);
            if(!strcmp(name,""))
            {
                MessageBox(hWnd,"Enter Coins","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            else if(!isdigit(name[0]))
            {
                MessageBox(hWnd,"Enter numeric value","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                break;
            }
            coins = atoi(name);
            user->request=coins;
            clear_file();
            reappend_file(root);
            MessageBox(hWnd,"Request Successfully Made","Message",MB_OK|MB_ICONINFORMATION);
            DestroyWindow(hWnd);
            break;
        }
        break;
    case WM_CREATE:
        AddControlsReq(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        user_panel();
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureCasino(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case UP_DOWN:
            casino_gate=1;
            DestroyWindow(hWnd);
            up_down();
            break;
        case HEAD_TAIL:
            casino_gate=1;
            DestroyWindow(hWnd);
            head_tail();
            break;
        case STONE_PAPER:
            casino_gate=1;
            DestroyWindow(hWnd);
            stone_paper();
            break;
        }
        break;
    case WM_CREATE:
        AddControlsCasino(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        if(!casino_gate)
            user_panel();
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureCashout(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    int coins;
    char name[10];
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case COUT:
            GetWindowText(hName,name,10);
            if(!strcmp(name,""))
            {
                MessageBox(hWnd,"Enter Coins","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            else if(!isdigit(name[0]))
            {
                MessageBox(hWnd,"Enter numeric value","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                break;
            }
            coins = atoi(name);
            if(coins>user->coins)
            {
                MessageBox(hWnd,"You cant withdraw more than you actually have !!","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                break;
            }
            else if(coins<500)
            {
                MessageBox(hWnd,"Minimum Cashout : 500 coins","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                break;
            }
            user->coins-=coins;
            user->cashout+=coins;
            clear_file();
            reappend_file(root);
            MessageBox(hWnd,"Cashout Successful !! Collect Cash from Counter","Message",MB_OK|MB_ICONINFORMATION);
            DestroyWindow(hWnd);
            break;
        }
        break;
    case WM_CREATE:
        AddControlsCashout(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        user_panel();
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureGiveCoins(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char *name,temp[30];
    int id,coins;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case CLEAR:
            SetWindowText(hName,"");
            SetWindowText(hPass,"");
            break;
        case GIVE_COINS:
            GetWindowText(hName,temp,30);
            if(!strcmp(temp,""))
            {
                MessageBox(hWnd,"Enter ID","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            else if(!isdigit(temp[0]))
            {
                MessageBox(hWnd,"Enter numeric ID","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                break;
            }
            id = atoi(temp);
            GetWindowText(hPass,temp,30);
            if(!strcmp(temp,""))
            {
                MessageBox(hWnd,"Enter Coin Amount","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            else if(!isdigit(temp[0]))
            {
                MessageBox(hWnd,"Enter numeric value","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hPass,"");
                break;
            }
            coins = atoi(temp);
            user=find_user_node(id);
            if(user==sentinel)
            {
                MessageBox(hWnd,"User not found","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                SetWindowText(hPass,"");
                break;
            }
            user->coins += coins;
            if(user->request)
            {
                user->request-=coins;
                if(user->request<0)
                    user->request=0;
            }
            clear_file();
            reappend_file(root);
            MessageBox(hWnd,"Coins Transferred","Message",MB_OK|MB_ICONINFORMATION);
            SetWindowText(hName,"");
            SetWindowText(hPass,"");
            break;
        case LIST:
            name = (char *)malloc(users*80);
            *name='\0';
            if(user->id==0)
            {
                list_users(root,1,name);
                if(!strcmp(name,""))
                    MessageBox(hWnd,"List Empty","User list",MB_OK|MB_ICONINFORMATION);
                else
                    MessageBox(hWnd,name,"User List",MB_OK|MB_ICONINFORMATION);
            }
            else
            {
                list_users(root,0,name);
                if(!strcmp(name,""))
                    MessageBox(hWnd,"List Empty","User list",MB_OK|MB_ICONINFORMATION);
                else
                    MessageBox(hWnd,name,"User List",MB_OK|MB_ICONINFORMATION);
            }
            free(name);
            break;
        case REQ:
            name = (char *)malloc(users*80);
            *name='\0';
            pending_req(root,name);
            if(!strcmp(name,""))
                MessageBox(hWnd,"No Pending Request","Pending Requests",MB_OK|MB_ICONINFORMATION);
            else
                MessageBox(hWnd,name,"Pending Requests",MB_OK|MB_ICONINFORMATION);
            break;
        }
        break;
    case WM_CREATE:
        AddControlsGiveCoins(hWnd);
        AddMenusAdmin(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        admin_panel();
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureDeleteUser(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char *name,temp[20];
    int id;
    tree_node *testu,*testa;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case LIST:
            name = (char *)malloc(users*80);
            *name='\0';
            if(user->id==0)
            {
                list_users(root,1,name);
                if(!strcmp(name,""))
                    MessageBox(hWnd,"List Empty","User list",MB_OK|MB_ICONINFORMATION);
                else
                    MessageBox(hWnd,name,"User List",MB_OK|MB_ICONINFORMATION);
            }
            else
            {
                list_users(root,0,name);
                if(!strcmp(name,""))
                    MessageBox(hWnd,"List Empty","User list",MB_OK|MB_ICONINFORMATION);
                else
                    MessageBox(hWnd,name,"User List",MB_OK|MB_ICONINFORMATION);
            }
            free(name);
            break;
        case REQ:
            name = (char *)malloc(users*80);
            *name='\0';
            pending_req(root,name);
            if(!strcmp(name,""))
                MessageBox(hWnd,"No Pending Request","Pending Requests",MB_OK|MB_ICONINFORMATION);
            else
                MessageBox(hWnd,name,"Pending Requests",MB_OK|MB_ICONINFORMATION);
            break;
        case DELETE_ID:
            GetWindowText(hName,temp,20);
            if(!strcmp(temp,""))
            {
                MessageBox(hWnd,"Enter ID","Message",MB_OK|MB_ICONEXCLAMATION);
                break;
            }
            else if(!isdigit(temp[0]))
            {
                MessageBox(hWnd,"Enter numeric value","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                break;
            }
            id = atoi(temp);
            if(id == 0)
            {
                MessageBox(hWnd,"You cant delete super admin !!","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                break;
            }
            testu = find_user_node(id);
            testa = find_admin_node(id);
            if(testa==sentinel && testu==sentinel)
            {
                MessageBox(hWnd,"User not found !!","Message",MB_OK|MB_ICONEXCLAMATION);
                SetWindowText(hName,"");
                break;
            }
            if(!user->id)
                del_user(id);
            else
            {
                if(testu==sentinel)
                {
                    MessageBox(hWnd,"Only Super Admin can delete admins","Message",MB_OK|MB_ICONEXCLAMATION);
                    SetWindowText(hName,"");
                    break;
                }
                else
                    del_user(id);
            }
            clear_file();
            reappend_file(root);
            MessageBox(hWnd,"User Successfully Deleted","Message",MB_OK|MB_ICONINFORMATION);
            SetWindowText(hName,"");
            break;
        }
        break;
    case WM_CREATE:
        AddControlsDeleteUser(hWnd);
        AddMenusAdmin(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        admin_panel();
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureHeadTail(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char output[10],input[10];
    int  result;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
            case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case SHOW_HELP:
            MessageBeep(MB_ICONINFORMATION);
            MessageBox(hWnd,"Rules:-\n1 - Choose a bet greater than or equals to 50\n2 - Choose between head or tail\n3 - If you win you get double else u lose bet","Head Tail",MB_OK);
            break;
        //Bet Cases
        case 50000:
            check_bet(50000,hWnd);
            break;
        case 10000:
            check_bet(10000,hWnd);
            break;
        case 2500:
            check_bet(2500,hWnd);
            break;
        case 500:
            check_bet(500,hWnd);
            break;
        case 100:
            check_bet(100,hWnd);
            break;
        case 50:
            check_bet(50,hWnd);
            break;
        case 999:
            check_bet(999,hWnd);
            break;
        //Head Tail cases
        case HEAD:
            if(!bet_amount)
                MessageBox(hWnd,"Place bet first","Message",MB_OK|MB_ICONEXCLAMATION);
            else if(!bet_flag)
                MessageBox(hWnd,"Toss The Coin","Message",MB_OK|MB_ICONEXCLAMATION);
            else
            {
                bet_flag=0;
                SetWindowText(hPass,"Head");
            }
            break;
        case TAIL:
            if(!bet_amount)
                MessageBox(hWnd,"Place bet first","Message",MB_OK|MB_ICONEXCLAMATION);
            else if(!bet_flag)
                MessageBox(hWnd,"Toss The Coin","Message",MB_OK|MB_ICONEXCLAMATION);
            else
            {
                bet_flag=0;
                SetWindowText(hPass,"Tail");
            }
            break;
        case TOSS:
            if(bet_flag)
                MessageBox(hWnd,"Choose between head or tail","Message",MB_OK|MB_ICONEXCLAMATION);
            else
            {
                srand(time(NULL));
                result=rand();
                if(result>1)
                    result%=2;
                if(!result)
                    SetWindowText(hRePass,"Head");
                else
                    SetWindowText(hRePass,"Tail");
                GetWindowText(hPass,input,10);
                GetWindowText(hRePass,output,10);
                if(!strcmp(input,output))
                {
                    SetWindowText(hName,"You Win");
                    user->coins+=bet_amount*2;
                    bet_amount=0;
                    bet_flag=1;
                    sprintf(output,"%d",bet_amount);
                    SetWindowText(hBet,output);
                    sprintf(output,"Coin Balance : %d",user->coins);
                    SetWindowText(hCoins,output);
                    clear_file();
                    reappend_file(root);
                }
                else
                {
                    SetWindowText(hName,"You Lose");
                    bet_flag=1;
                    bet_amount=0;
                    sprintf(output,"%d",bet_amount);
                    SetWindowText(hBet,output);
                }
            }
            break;
        }
        break;
    case WM_CREATE:
        AddControlsGame(hWnd);
        AddControlsHT(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        post_game_exit();//Reset Game Specific Global Variables
        play_casino();
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureUpDown(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char output[10],input[10];
    int  result,d1,d2;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
            case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case SHOW_HELP:
            MessageBeep(MB_ICONINFORMATION);
            MessageBox(hWnd,"Rules:-\n1 - Choose a bet greater than or equals to 50\n2 - Choose between 7Up and 7Down\n3 - 2 Dice will roll if their sum matches your choice u will will.\n4 - If you win you get triple else u lose bet","Stone Paper Scissors",MB_OK);
            break;
        //Bet Cases
        case 50000:
            check_bet(50000,hWnd);
            break;
        case 10000:
            check_bet(10000,hWnd);
            break;
        case 2500:
            check_bet(2500,hWnd);
            break;
        case 500:
            check_bet(500,hWnd);
            break;
        case 100:
            check_bet(100,hWnd);
            break;
        case 50:
            check_bet(50,hWnd);
            break;
        case 999:
            check_bet(999,hWnd);
            break;
        //7Up 7Down cases
        case UP:
            if(!bet_amount)
                MessageBox(hWnd,"Place bet first","Message",MB_OK|MB_ICONEXCLAMATION);
            else if(!bet_flag)
                MessageBox(hWnd,"Roll the dice","Message",MB_OK|MB_ICONEXCLAMATION);
            else
            {
                bet_flag=0;
                SetWindowText(hPass,"7Up");
            }
            break;
        case DOWN:
            if(!bet_amount)
                MessageBox(hWnd,"Place bet first","Message",MB_OK|MB_ICONEXCLAMATION);
            else if(!bet_flag)
                MessageBox(hWnd,"Roll the dice","Message",MB_OK|MB_ICONEXCLAMATION);
            else
            {
                bet_flag=0;
                SetWindowText(hPass,"7Down");
            }
            break;
        case ROLL_DICE:
            if(bet_flag)
                MessageBox(hWnd,"Choose between 7Up and 7Down","Message",MB_OK|MB_ICONEXCLAMATION);
            else
            {
                srand(time(NULL));
                d1 =rand();
                srand(time(NULL));
                d2 =rand();
                if(d1>5)
                d1%=6;
                if(d2>5)
                d2%=6;
                d1++,d2++;
                result=d1+d2;
                if(result>7)
                {
                    sprintf(output,"7Up(%d)",result);
                    SetWindowText(hRePass,output);
                }
                else if(result<7)
                {
                    sprintf(output,"7Down(%d)",result);
                    SetWindowText(hRePass,output);
                }
                else
                {
                    sprintf(output,"Equal(%d)",result);
                    SetWindowText(hRePass,output);
                }
                GetWindowText(hPass,input,10);
                GetWindowText(hRePass,output,10);
                if(!strncmp(input,output,2))
                {
                    SetWindowText(hName,"You Win");
                    user->coins+=bet_amount*2;
                    bet_amount=0;
                    bet_flag=1;
                    sprintf(output,"%d",bet_amount);
                    SetWindowText(hBet,output);
                    sprintf(output,"Coin Balance : %d",user->coins);
                    SetWindowText(hCoins,output);
                    clear_file();
                    reappend_file(root);
                }
                else
                {
                    SetWindowText(hName,"You Lose");
                    bet_flag=1;
                    bet_amount=0;
                    sprintf(output,"%d",bet_amount);
                    SetWindowText(hBet,output);
                }
            }
            break;
        }
        break;
    case WM_CREATE:
        AddControlsGame(hWnd);
        AddControlsUD(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        post_game_exit();//Reset Game Specific Global Variables
        play_casino();
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
LRESULT CALLBACK WindowProcedureStonePaper(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    char output[10],input[10],option,win;
    int  result;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
            case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case SHOW_HELP:
            MessageBeep(MB_ICONINFORMATION);
            MessageBox(hWnd,"Rules:-\n1 - Choose a bet greater than or equals to 50\n2 - Choose among stone,paper and scissors\n3 - If you win you get triple else u lose bet","Stone Paper Scissors",MB_OK);
            break;
        //Bet Cases
        case 50000:
            check_bet(50000,hWnd);
            break;
        case 10000:
            check_bet(10000,hWnd);
            break;
        case 2500:
            check_bet(2500,hWnd);
            break;
        case 500:
            check_bet(500,hWnd);
            break;
        case 100:
            check_bet(100,hWnd);
            break;
        case 50:
            check_bet(50,hWnd);
            break;
        case 999:
            check_bet(999,hWnd);
            break;
        //Stone Paper Cases
        case STONE:
            GetWindowText(hName,output,10);
            if(!bet_amount)
                MessageBox(hWnd,"Place bet first","Message",MB_OK|MB_ICONEXCLAMATION);
            else if(!bet_flag&&strcmp(output,"Same"))
                MessageBox(hWnd,"Click Play","Message",MB_OK|MB_ICONEXCLAMATION);
            else
            {
                bet_flag=0;
                SetWindowText(hPass,"Stone");
            }
            break;
        case PAPER:
           GetWindowText(hName,output,10);
            if(!bet_amount)
                MessageBox(hWnd,"Place bet first","Message",MB_OK|MB_ICONEXCLAMATION);
            else if(!bet_flag&&strcmp(output,"Same"))
                MessageBox(hWnd,"Click Play","Message",MB_OK|MB_ICONEXCLAMATION);
            else
            {
                bet_flag=0;
                SetWindowText(hPass,"Paper");
            }
            break;
        case SCISSOR:
            GetWindowText(hName,output,10);
            if(!bet_amount)
                MessageBox(hWnd,"Place bet first","Message",MB_OK|MB_ICONEXCLAMATION);
            else if(!bet_flag&&strcmp(output,"Same"))
                MessageBox(hWnd,"Click Play","Message",MB_OK|MB_ICONEXCLAMATION);
            else
            {
                bet_flag=0;
                SetWindowText(hPass,"Scissor");
            }
            break;
        case PLAY:
            if(bet_flag)
                MessageBox(hWnd,"Choose among Rock ,Paper and Scissor","Message",MB_OK|MB_ICONEXCLAMATION);
            else
            {
                GetWindowText(hPass,input,10);
                option=tolower(input[0]);
                if(input[1]=='t')
                    option='r';//Converting stone to rock for rps algorithm
                srand(time(NULL));
                result=rand();
                if(result>2)
                    result%=3;
                if(!result)
                {
                    SetWindowText(hRePass,"Stone");
                    win='r';
                }
                else if(result==1)
                {
                    SetWindowText(hRePass,"Paper");
                    win='p';
                }
                else
                {
                    SetWindowText(hRePass,"Scissor");
                    win='s';
                }
                if(!rps_win(option,win))
                {
                    SetWindowText(hName,"You Lose");
                    bet_flag=1;
                    bet_amount=0;
                    sprintf(output,"%d",bet_amount);
                    SetWindowText(hBet,output);
                }
                else if((rps_win(option,win))==1)
                {
                    SetWindowText(hName,"Same");
                }
                else
                {
                    SetWindowText(hName,"You Win");
                    user->coins+=bet_amount*3;
                    bet_amount=0;
                    bet_flag=1;
                    sprintf(output,"%d",bet_amount);
                    SetWindowText(hBet,output);
                    sprintf(output,"Coin Balance : %d",user->coins);
                    SetWindowText(hCoins,output);
                    clear_file();
                    reappend_file(root);
                }
            }
            break;
        }
        break;
    case WM_CREATE:
        AddControlsGame(hWnd);
        AddControlsSP(hWnd);
        AddMenusUni(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        post_game_exit();//Reset Game Specific Global Variables
        play_casino();
        break;
    default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}
//Message Loops
void forgot_id(void)
{
    CreateWindow("forgotid","Forgot ID",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void create_id(void)
{
    if(user->admin==true)
        CreateWindow("createid","Create New Admin ID",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    else
        CreateWindow("createid","Create New ID",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void login_user(void)
{
    HWND hWnd;
    hWnd = CreateWindow("login","Login User",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    CreateWindow("static","Here Users Can Login",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Login",WS_VISIBLE|WS_CHILD|SS_CENTER,260,130,100,20,hWnd,(HMENU)USER_LOGIN,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void login_admin(void)
{
    HWND hWnd;
    hWnd = CreateWindow("login","Login Admin",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    CreateWindow("static","Here Admins Can Login",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Login",WS_VISIBLE|WS_CHILD|SS_CENTER,260,130,100,20,hWnd,(HMENU)ADMIN_LOGIN,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void user_panel(void)
{
    HWND hWnd;
    hWnd = CreateWindow("user","User Panel",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    AppendMenu(hMenu,MF_STRING,SHOW_HELP,"Free Coins");
    SetMenu(hWnd,hMenu);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void admin_panel(void)
{
    CreateWindow("admin","Admin Panel",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void change_pw(void)
{
    CreateWindow("change_pw","Change Password",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void cashout(void)
{
    CreateWindow("cashout","Cashout",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void req_coins(void)
{
    CreateWindow("req","Request Coins",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void play_casino(void)
{
    CreateWindow("casino","Play Casino",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void give_coins(void)
{
    CreateWindow("give_coins","Give Coins",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void delete_user(void)
{
    CreateWindow("delete_user","Delete User",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void head_tail(void)
{
    HWND hWnd;
    hWnd=CreateWindow("head_tail","Head Tail",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    AppendMenu(hMenu,MF_STRING,SHOW_HELP,"Rules");
    SetMenu(hWnd,hMenu);
    AddControlsGame(hWnd);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void up_down(void)
{
    HWND hWnd;
    hWnd=CreateWindow("up_down","7 Up 7 Down",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    AppendMenu(hMenu,MF_STRING,SHOW_HELP,"Rules");
    SetMenu(hWnd,hMenu);
    AddControlsGame(hWnd);
    MSG msg={0};
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void stone_paper(void)
{
    HWND hWnd;
    hWnd=CreateWindow("stone_paper","Stone Paper",WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,530,230,500,270,NULL,NULL,NULL,NULL);
    AppendMenu(hMenu,MF_STRING,SHOW_HELP,"Rules");
    SetMenu(hWnd,hMenu);
    MSG msg={0};
    AddControlsGame(hWnd);
    while(GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
//Add Controls and Menus
void AddMenusHome(HWND hWnd)
{
    hMenu = CreateMenu();
    HMENU hFileMenu = CreateMenu();
    (AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu,"File"))==NULL;
    AppendMenu(hMenu,MF_STRING,SHOW_HELP,"Help");
    AppendMenu(hFileMenu,MF_STRING,FILE_MENU_EXIT,"Exit");
    SetMenu(hWnd,hMenu);
}
void AddMenusAdmin(HWND hWnd)
{
    hMenu = CreateMenu();
    HMENU hFileMenu = CreateMenu();
    (AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu,"File"))==NULL;
    AppendMenu(hMenu,MF_STRING,LIST,"List Users");
    AppendMenu(hMenu,MF_STRING,REQ,"Pending Requests");
    AppendMenu(hFileMenu,MF_STRING,FILE_MENU_EXIT,"Exit");
    SetMenu(hWnd,hMenu);
}
void AddMenusUni(HWND hWnd)
{
    hMenu = CreateMenu();
    HMENU hFileMenu = CreateMenu();
    (AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu,"File"))==NULL;
    AppendMenu(hFileMenu,MF_STRING,FILE_MENU_EXIT,"Exit");
    SetMenu(hWnd,hMenu);
}
void AddControlsHome(HWND hWnd)
{
    CreateWindow("static","WELCOME TO HOME CASINO by VD",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Choose Option :-",WS_VISIBLE|WS_CHILD,20,50,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Leaderboard",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,320,50,150,20,hWnd,(HMENU)LEADER,NULL,NULL);
    CreateWindow("button","Create New User ID",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,160,80,150,20,hWnd,(HMENU)NEW_USER_ID,NULL,NULL);
    CreateWindow("button","Login USER",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,60,120,150,20,hWnd,(HMENU)USER_LOGIN,NULL,NULL);
    CreateWindow("button","Login ADMIN",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,260,120,150,20,hWnd,(HMENU)ADMIN_LOGIN,NULL,NULL);
    CreateWindow("button","Forgot ID",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,60,160,150,20,hWnd,(HMENU)FORGOT_ID,NULL,NULL);
    CreateWindow("button","Forgot Password",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,260,160,150,20,hWnd,(HMENU)FORGOT_PASS,NULL,NULL);
}
void AddControlsForgotID(HWND hWnd)
{
    CreateWindow("static","Here You Can Search Your ID",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Name :-",WS_VISIBLE|WS_CHILD,100,50,110,20,hWnd,NULL,NULL,NULL);
    hName = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER,220,50,130,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Search",WS_VISIBLE|WS_CHILD|SS_CENTER,260,90,100,20,hWnd,(HMENU)FORGOT_ID,NULL,NULL);
    CreateWindow("button","Clear",WS_VISIBLE|WS_CHILD|SS_CENTER,140,90,100,20,hWnd,(HMENU)CLEAR,NULL,NULL);
    CreateWindow("static","Result :-",WS_VISIBLE|WS_CHILD,100,130,110,20,hWnd,NULL,NULL,NULL);
    hOut = CreateWindow("static","",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,170,130,150,20,hWnd,NULL,NULL,NULL);
}
void AddControlsCreateID(HWND hWnd)
{
    if(user->admin==true)
        CreateWindow("static","Here You Can Create Admin ID",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    else
        CreateWindow("static","Here You Can Create Your ID",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Name :-",WS_VISIBLE|WS_CHILD,100,50,150,20,hWnd,NULL,NULL,NULL);
    hName = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER,270,50,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Password :-",WS_VISIBLE|WS_CHILD,100,80,150,20,hWnd,NULL,NULL,NULL);
    hPass = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_PASSWORD,270,80,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Re-Enter Password :-",WS_VISIBLE|WS_CHILD,100,110,150,20,hWnd,NULL,NULL,NULL);
    hRePass = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_PASSWORD,270,110,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Create",WS_VISIBLE|WS_CHILD|SS_CENTER,260,150,100,20,hWnd,(HMENU)NEW_USER_ID,NULL,NULL);
    CreateWindow("button","Clear",WS_VISIBLE|WS_CHILD|SS_CENTER,140,150,100,20,hWnd,(HMENU)CLEAR,NULL,NULL);
}
void AddControlsLogin(HWND hWnd)
{
    CreateWindow("static","Enter UserID :-",WS_VISIBLE|WS_CHILD,100,50,150,20,hWnd,NULL,NULL,NULL);
    hName = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER,240,50,130,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Password :-",WS_VISIBLE|WS_CHILD,100,80,150,20,hWnd,NULL,NULL,NULL);
    hPass = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_PASSWORD,240,80,130,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Clear",WS_VISIBLE|WS_CHILD|SS_CENTER,140,130,100,20,hWnd,(HMENU)CLEAR,NULL,NULL);
}
void AddControlsUser(HWND hWnd)
{
    char name[40]="Welcome ",coin_bal[30];
    sprintf(coin_bal,"Coin Balance : %d",user->coins);
    strcat(name,user->name);
    strcat(name," !! Its your User Panel.");
    CreateWindow("static",name,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,80,10,310,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static",coin_bal,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,250,40,210,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Choose Option :-",WS_VISIBLE|WS_CHILD,20,50,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Enter Casino",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,160,80,150,20,hWnd,(HMENU)PLAY,NULL,NULL);
    CreateWindow("button","Request Coins",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,60,120,150,20,hWnd,(HMENU)REQ,NULL,NULL);
    CreateWindow("button","Reset Request",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,260,120,150,20,hWnd,(HMENU)RESET,NULL,NULL);
    CreateWindow("button","Cashout Coins",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,60,160,150,20,hWnd,(HMENU)COUT,NULL,NULL);
    CreateWindow("button","Change Password",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,260,160,150,20,hWnd,(HMENU)CHANGE,NULL,NULL);
}
void AddControlsAdmin(HWND hWnd)
{
    char name[40]="Welcome ",status[30];
    if(user->id)
        strcpy(status,"Admin Type : Normal");
    else
        strcpy(status,"Admin Type : Super");
    CreateWindow("static",status,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,330,40,140,20,hWnd,NULL,NULL,NULL);
    strcat(name,user->name);
    strcat(name," !! Its your Admin Panel.");
    CreateWindow("static",name,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,80,10,310,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Choose Option :-",WS_VISIBLE|WS_CHILD,20,50,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Give Coins",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,160,80,150,20,hWnd,(HMENU)GIVE_COINS,NULL,NULL);
    CreateWindow("button","Add Admin",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,60,120,150,20,hWnd,(HMENU)NEW_USER_ID,NULL,NULL);
    CreateWindow("button","Remove User",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,60,160,150,20,hWnd,(HMENU)DELETE_ID,NULL,NULL);
    CreateWindow("button","Reset Casino",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,260,120,150,20,hWnd,(HMENU)RESET,NULL,NULL);
    CreateWindow("button","Change Password",WS_VISIBLE|WS_CHILD|SS_CENTER|WS_BORDER,260,160,150,20,hWnd,(HMENU)CHANGE,NULL,NULL);

}
void AddControlsChangePw(HWND hWnd)
{
    CreateWindow("static","Here You Can Change Password",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Old Password :-",WS_VISIBLE|WS_CHILD,100,50,150,20,hWnd,NULL,NULL,NULL);
    hName = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_PASSWORD,270,50,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter New Password :-",WS_VISIBLE|WS_CHILD,100,80,150,20,hWnd,NULL,NULL,NULL);
    hPass = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_PASSWORD,270,80,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Re-Enter New Password :-",WS_VISIBLE|WS_CHILD,80,110,180,20,hWnd,NULL,NULL,NULL);
    hRePass = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_PASSWORD,270,110,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Change Password",WS_VISIBLE|WS_CHILD|SS_CENTER,260,150,130,20,hWnd,(HMENU)CHANGE,NULL,NULL);
    CreateWindow("button","Clear",WS_VISIBLE|WS_CHILD|SS_CENTER,140,150,100,20,hWnd,(HMENU)CLEAR,NULL,NULL);
}
void AddControlsCasino(HWND hWnd)
{
    char coin_bal[30];
    sprintf(coin_bal,"Coin Balance : %d",user->coins);
    CreateWindow("static","Here You Can Play Games",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Game List :-",WS_VISIBLE|WS_CHILD,20,50,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static",coin_bal,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,250,40,210,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Head Tail",WS_VISIBLE|WS_CHILD|SS_CENTER,180,80,100,20,hWnd,(HMENU)HEAD_TAIL,NULL,NULL);
    CreateWindow("button","7UP-7Down",WS_VISIBLE|WS_CHILD|SS_CENTER,180,120,100,20,hWnd,(HMENU)UP_DOWN,NULL,NULL);
    CreateWindow("button","Stone-Paper",WS_VISIBLE|WS_CHILD|SS_CENTER,180,160,100,20,hWnd,(HMENU)STONE_PAPER,NULL,NULL);
}
void AddControlsReq(HWND hWnd)
{
    CreateWindow("static","Here You Can Request Coins",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Amount :-",WS_VISIBLE|WS_CHILD,100,50,150,20,hWnd,NULL,NULL,NULL);
    hName = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER,270,50,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Request",WS_VISIBLE|WS_CHILD|SS_CENTER,200,100,100,20,hWnd,(HMENU)REQ,NULL,NULL);
}
void AddControlsCashout(HWND hWnd)
{
    char coin_bal[30];
    sprintf(coin_bal,"Coin Balance : %d",user->coins);
    CreateWindow("static","Here You Can Cashout Coins",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static",coin_bal,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,250,40,210,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Amount :-",WS_VISIBLE|WS_CHILD,100,80,150,20,hWnd,NULL,NULL,NULL);
    hName = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER,270,80,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Cashout",WS_VISIBLE|WS_CHILD|SS_CENTER,200,130,100,20,hWnd,(HMENU)COUT,NULL,NULL);
}
void AddControlsGiveCoins(HWND hWnd)
{
    CreateWindow("static","Here You Can Give Coins",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter ID :-",WS_VISIBLE|WS_CHILD,100,50,150,20,hWnd,NULL,NULL,NULL);
    hName = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER,270,50,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Amount :-",WS_VISIBLE|WS_CHILD,100,90,150,20,hWnd,NULL,NULL,NULL);
    hPass = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER,270,90,110,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Transfer",WS_VISIBLE|WS_CHILD|SS_CENTER,260,140,100,20,hWnd,(HMENU)GIVE_COINS,NULL,NULL);
    CreateWindow("button","Clear",WS_VISIBLE|WS_CHILD|SS_CENTER,140,140,100,20,hWnd,(HMENU)CLEAR,NULL,NULL);
}
void AddControlsDeleteUser(HWND hWnd)
{
    CreateWindow("static","Here You Can Delete Users",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Enter UserID :-",WS_VISIBLE|WS_CHILD,100,50,150,20,hWnd,NULL,NULL,NULL);
    hName = CreateWindow("edit","",WS_VISIBLE|WS_CHILD|WS_BORDER,240,50,130,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Remove",WS_VISIBLE|WS_CHILD|SS_CENTER,200,100,100,20,hWnd,(HMENU)DELETE_ID,NULL,NULL);
}
void AddControlsGame(HWND hWnd)
{
    char coin_bal[30],bet[20];
    sprintf(bet,"%d",bet_amount);
    sprintf(coin_bal,"Coin Balance : %d",user->coins);
    hCoins = CreateWindow("static",coin_bal,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,250,40,210,20,hWnd,NULL,NULL,NULL);
    CreateWindow("static","Current Bet",WS_VISIBLE|WS_CHILD,50,40,110,20,hWnd,NULL,NULL,NULL);
    hBet = CreateWindow("static",bet,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,50,60,80,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","50",WS_VISIBLE|WS_CHILD|SS_CENTER,20,90,40,20,hWnd,(HMENU)50,NULL,NULL);
    CreateWindow("button","2.5K",WS_VISIBLE|WS_CHILD|SS_CENTER,20,120,40,20,hWnd,(HMENU)2500,NULL,NULL);
    CreateWindow("button","100",WS_VISIBLE|WS_CHILD|SS_CENTER,70,90,40,20,hWnd,(HMENU)100,NULL,NULL);
    CreateWindow("button","10K",WS_VISIBLE|WS_CHILD|SS_CENTER,70,120,40,20,hWnd,(HMENU)10000,NULL,NULL);
    CreateWindow("button","500",WS_VISIBLE|WS_CHILD|SS_CENTER,120,90,40,20,hWnd,(HMENU)500,NULL,NULL);
    CreateWindow("button","50K",WS_VISIBLE|WS_CHILD|SS_CENTER,120,120,40,20,hWnd,(HMENU)50000,NULL,NULL);
    CreateWindow("button","Reset",WS_VISIBLE|WS_CHILD|SS_CENTER,50,160,50,20,hWnd,(HMENU)999,NULL,NULL);
    hPass = CreateWindow("static","Input",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,210,140,60,20,hWnd,NULL,NULL,NULL);
    hRePass = CreateWindow("static","Output",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,340,140,70,20,hWnd,NULL,NULL,NULL);
    hName = CreateWindow("static","Result",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,270,170,80,20,hWnd,NULL,NULL,NULL);
}
void AddControlsSP(HWND hWnd)
{
    CreateWindow("static","Welcome to Stone Paper Game",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Stone",WS_VISIBLE|WS_CHILD|SS_CENTER,200,80,70,20,hWnd,(HMENU)STONE,NULL,NULL);
    CreateWindow("button","Paper",WS_VISIBLE|WS_CHILD|SS_CENTER,290,80,70,20,hWnd,(HMENU)PAPER,NULL,NULL);
    CreateWindow("button","Scissor",WS_VISIBLE|WS_CHILD|SS_CENTER,380,80,70,20,hWnd,(HMENU)SCISSOR,NULL,NULL);
    CreateWindow("button","Play",WS_VISIBLE|WS_CHILD|SS_CENTER,270,110,90,20,hWnd,(HMENU)PLAY,NULL,NULL);

}
void AddControlsHT(HWND hWnd)
{
    CreateWindow("static","Welcome to Head Tail Game",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","Head",WS_VISIBLE|WS_CHILD|SS_CENTER,220,80,90,20,hWnd,(HMENU)HEAD,NULL,NULL);
    CreateWindow("button","Tail",WS_VISIBLE|WS_CHILD|SS_CENTER,320,80,90,20,hWnd,(HMENU)TAIL,NULL,NULL);
    CreateWindow("button","Toss Coin",WS_VISIBLE|WS_CHILD|SS_CENTER,270,110,90,20,hWnd,(HMENU)TOSS,NULL,NULL);
}
void AddControlsUD(HWND hWnd)
{
    CreateWindow("static","Welcome to 7Up7Down Game",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,10,260,20,hWnd,NULL,NULL,NULL);
    CreateWindow("button","7UP",WS_VISIBLE|WS_CHILD|SS_CENTER,220,80,90,20,hWnd,(HMENU)UP,NULL,NULL);
    CreateWindow("button","7Down",WS_VISIBLE|WS_CHILD|SS_CENTER,320,80,90,20,hWnd,(HMENU)DOWN,NULL,NULL);
    CreateWindow("button","Roll Dice",WS_VISIBLE|WS_CHILD|SS_CENTER,270,110,90,20,hWnd,(HMENU)ROLL_DICE,NULL,NULL);
}
//----------------------------------Main Program Functions---------------------------------------
void start_check_db(void)
{
    FILE *fp=fopen("database","r");
    if(fp==NULL)
    {
        root=(tree_node*)malloc(sizeof(tree_node));
        root->parent=sentinel;
        root->id=users++;
        strcpy(root->password,"password");
        strcpy(root->name,"SuperAdmin");
        root->coins=500;
        root->request=0;
        root->cashout=0;
        root->admin=true;
        root->lchild=sentinel;
        root->rchild=sentinel;
        root->color=black;
        clear_file();//Can be used to create new file
        reappend_file(root);
        MessageBox(NULL,"Welcome to HOME Casino by VD\n\nYou are the Super Admin !!\nID : 0\nPassword : password\n\nClick Help on home page for more information.\n\nImportant Note : Please change password from Admin Panel as soon as possible to avoid any security issues.","Welcome",MB_OK);
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
    int id,coins,request,admin,cashout;
    char name[20],pass[20];
    fp=fopen("database","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %s %d %d %d %d",&id,name,pass,&coins,&request,&cashout,&admin);
        if(id==-999)
            continue;
        if(admin)
            create_new_user(id,name,pass,coins,request,cashout,true);
        else
            create_new_user(id,name,pass,coins,request,cashout,false);
        users = id+1;
    }
    fclose(fp);
}
//New File
void clear_file(void)
{
    FILE *fp;
    fp=fopen("database","w");
    fprintf(fp,"%d %s %s %d %d %d %d\n",-999,"start","start",500,0,0,0);
    fclose(fp);
}
//Reappend File
void reappend_file(tree_node *ptr)
{
    if(ptr==sentinel)
        return;
    reappend_file(ptr->lchild);
    append_to_file(ptr->id,ptr->name,ptr->password,ptr->coins,ptr->request,ptr->cashout,ptr->admin);
    reappend_file(ptr->rchild);
}
//Insert Data in file
void append_to_file(int id,char name[],char pass[],int coins,int request,int cashout,int admin)
{
    FILE *fp;
    fp=fopen("database","a");
    fprintf(fp,"%d %s %s %d %d %d %d\n",id,name,pass,coins,request,cashout,admin);
    fclose(fp);
}//Search User ID
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
        flag = ptr->id;
    }
    search_userid(ptr->rchild,name);
    return flag;
}
//New User
void create_new_user(int id,char name[],char pass[],int coins,int request,int cashout,boole admin)
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
            return;
        }
    }
        temp=(tree_node*)malloc(sizeof(tree_node));
        temp->id=id;
        strcpy(temp->password,pass);
        strcpy(temp->name,name);
        temp->request=request;
        temp->coins=coins;
        temp->cashout=cashout;
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
//Find User node
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
                return sentinel;
            }
        }
    }
    return sentinel;
}
//Find Admin Node
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
                return sentinel;
            }
        }
    }
    return sentinel;
}
//List Users
void list_users(tree_node *ptr,int super_admin,char *ch)
{
    char temp[80];
    if(ptr==sentinel)
        return;
    list_users(ptr->lchild,super_admin,ch);
    if(super_admin==true)
    {
         sprintf(temp,"User ID : %d\nName : %s\nPassword : %s\nCoin Balance : %d\n\n",ptr->id,ptr->name,ptr->password,ptr->coins);
         strcat(ch,temp);
    }
    else
    {
        if(ptr->admin==false)
        {
            sprintf(temp,"User ID : %d\nName : %s\nPassword : %s\nCoin Balance : %d\n\n",ptr->id,ptr->name,ptr->password,ptr->coins);
            strcat(ch,temp);
        }
    }
    list_users(ptr->rchild,super_admin,ch);
    return;
}
//List Pending Request
void pending_req(tree_node *ptr,char *ch)
{
    char temp[80];
    if(ptr==sentinel)
        return;
    pending_req(ptr->lchild,ch);
    if(ptr->request)
    {
        sprintf(temp,"Name : %s\nCoin Balance : %d\nUser ID : %d\nPending Coins : %d\n\n",ptr->name,ptr->coins,ptr->id,ptr->request);
        strcat(ch,temp);
    }
    pending_req(ptr->rchild,ch);
    return;
}
void reset_casino(tree_node *ptr)
{
    if(ptr==sentinel)
        return;
    reset_casino(ptr->lchild);
    reset_casino(ptr->rchild);
    free(ptr);
}
void del_user(int key)
{
    tree_node *succ,*ptr,*child;
    if(!find(&ptr,key))
    {
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
void check_bet(int amount,HWND hWnd)
{
    char temp[30];
    SetWindowText(hName,"Result");
    SetWindowText(hPass,"Input");
    SetWindowText(hRePass,"Output");
    if(bet_flag==0)
    {
        MessageBox(hWnd,"You cant bet while the game is running.","Bet Error",MB_OK|MB_ICONEXCLAMATION);
        return;
    }
    if((amount>(user->coins))&&amount != 999)
    {
        MessageBox(hWnd,"You cant bet more than you actually have.","Bet Error",MB_OK|MB_ICONEXCLAMATION);
        return;
    }
    if(amount==999)
    {
        if(bet_amount==0)
        {
            MessageBox(hWnd,"Place Bet First","Reset",MB_OK|MB_ICONEXCLAMATION);
            return;
        }
        user->coins+=bet_amount;
        bet_amount=0;
        sprintf(temp,"%d",bet_amount);
        SetWindowText(hBet,temp);
        sprintf(temp,"Coin Balance : %d",user->coins);
        SetWindowText(hCoins,temp);
        MessageBox(hWnd,"Bet Reset Successful","Reset",MB_OK|MB_ICONINFORMATION);
    }
    else
    {
        bet_amount+=amount;
        user->coins-=amount;
        sprintf(temp,"%d",bet_amount);
        SetWindowText(hBet,temp);
        sprintf(temp,"Coin Balance : %d",user->coins);
        SetWindowText(hCoins,temp);
    }
    clear_file();
    reappend_file(root);
}
void post_game_exit(void)
{
    casino_gate = 0;//Admin menu can open after casino exit will open
    user->coins+=bet_amount;
    bet_amount=0;//Remaining Bet Amount Transferred
    bet_flag=1;// For Unexpected shutdowns
    clear_file();
    reappend_file(root);
}
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
void create_leader_board(tree_node *ptr)
{
    if(ptr==sentinel)
        return;
    create_leader_board(ptr->lchild);
    if(!ptr->admin&&ptr->cashout)
        insert_leader_board(ptr->name,ptr->cashout);
    create_leader_board(ptr->rchild);
}
void insert_leader_board(char name[],int amount)
{
    node *ptr=head,*prev=NULL,*temp;
    if(head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        strcpy(head->name,name);
        head->amount=amount;
        head->next=NULL;
        return;
    }
    while(ptr->amount>amount)
    {
        prev=ptr;
        ptr=ptr->next;
        if(ptr==NULL)
        {
            break;
        }
    }
    temp=(node*)malloc(sizeof(node));
    strcpy(temp->name,name);
    temp->amount=amount;
    temp->next=ptr;
    if(prev==NULL)
        head=temp;
    else
        prev->next=temp;
    return;
}
void show_leader_board(HWND hWnd)
{
    node *ptr;
    char *leader,buffer[30];
    leader=(char*)malloc(sizeof(char)*users*30);
    *leader='\0';
    strcat(leader,"*Top Cash Winners*\n\n");
    ptr=head;
    if(ptr==NULL)
    {
        MessageBox(hWnd,"No Cashouts Yet","Leaderboard",MB_OK);
    }
    else
    {
        while(ptr!=NULL)
        {
            sprintf(buffer,"%s - Rs %d\n",ptr->name,ptr->amount);
            strcat(leader,buffer);
            ptr=ptr->next;
        }
        MessageBox(hWnd,leader,"Leaderboard",MB_OK);
    }
    free_list();
    free(leader);
    return;
}
void free_list(void)
{
    node *temp;
    while(head!=NULL)
    {
        head=head->next;
        free(head);
        head=temp;
    }
}
