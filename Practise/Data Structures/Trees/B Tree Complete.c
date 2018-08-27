//B Tree
//Header Files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Macro Definations
#define M 5
#define MAX (M-1)
#if M%2==0
#define CEIL_Mdiv2 (M/2)
#else
#define CEIL_Mdiv2 ((M+1)/2)
#define MIN (CEIL_Mdiv2-1)
#endif
//Tree Structure
struct b_tree
{
    int count;
    int key[M];
    struct b_tree *child[M];
} ;
typedef struct b_tree node;//Type Define
//UD Functions
//Hold Screen
void hold_screen(void);
//search
node *search(node *root,int key,int *pos);
int search_node(node *root,int key,int *pos);
node *insert(node *root,int num);
int rec_ins(node *root,int num,int *k,node **krchild);
void insert_shift(node *root,int pos,int k,node *krchild);
void split(node *root,int pos,node *krchild,int k,int *upkey,node **upright);
node *del(node *,int key);
void rec_del(node *,int key);
int copy_succ(node *root,int pos);
void restore(node*root,int pos);
void del_shift(node *root,int pos);
void combine(node *root,int pos);
void borrow_left(node *root,int pos);
void borrow_right(node *root,int pos);
//Main Function
int main()
{
    node *root=NULL,*ptr;
    char option;
    int num,pos;
    while(1)
    {
        system("cls");
        printf("Enter Choice:-\n1 - Insert Element\n2 - Search Element\n3 - Delete Element\n\tBackspace - Exit\n");
        option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            printf("Enter number to insert : ");
            scanf("%d",&num);
            root=insert(root,num);
            hold_screen();
            break;
        case '2':
            printf("Enter number to search : ");
            scanf("%d",&num);
            if((ptr=search(root,num,&pos))==NULL)
                printf("Key not found!!");
            else
                printf("Node %p , Position %d",ptr,pos);
            hold_screen();
            break;
        case '3':
            printf("Enter number to delete : ");
            scanf("%d",&num);
            root=del(root,num);
            hold_screen();
            break;
        case 8 :
            return 0;
        }
    }
}
void hold_screen(void)
{
    printf("\n\nPress Enter to continue...");
    getch();
}
node *search(node *root,int key,int *pos)
{
    int found;
    if(root==NULL)
        return NULL;
    found = search_node(root,key,pos);
    if(found)
        return root;
    else
        search(root->child[*pos],key,pos);
}
int search_node(node *root,int key,int *pos)
{
    if(key<root->key[1])
    {
        *pos=0;
        return 0;
    }
    *pos=root->count;
    while(key<root->key[*pos]&&*pos>1)
        (*pos)--;
    if(key==root->key[*pos])
        return 1;
    else
        return 0;
}
node *insert(node *root,int num)
{
    int taller,k;
    node *temp,*krchild;
    taller = rec_ins(root,num,&k,&krchild);
    if(taller)
    {
        temp=(node*)malloc(sizeof(node));
        temp->count = 1;
        temp->child[0]=root;
        temp->key[1]=k;
        temp->child[1]=krchild;
        root = temp;
    }
    return root;
}
int rec_ins(node *root,int num,int *k,node **krchild)
{
    int n,flag;
    if(root==NULL)
    {
        *k = num;
        *krchild=NULL;
        printf("Key Inserted !!");
        return 1;
    }
    if(search_node(root,num,&n))
    {
        printf("Duplicate Key !!");
        return 0;
    }
    flag = rec_ins(root->child[n],num,k,krchild);
    if(flag)
    {
        if(root->count<MAX)
        {
            insert_shift(root,n,*k,*krchild);
            printf("Shift !!");
            return 0;
        }
        else
        {
            split(root,n,*krchild,*k,k,krchild);
            printf("Split !!");
            return 1;
        }
    }
    return 0;
}
void insert_shift(node *root,int pos,int k,node *krchild)
{
    int i;
    for(i=root->count;i>pos;--i)
    {
        root->key[i+1]=root->key[i];
        root->child[i+1]=root->child[i];
    }
    root->key[pos+1]=k;
    root->child[pos+1]=krchild;
    root->count++;
}
void split(node *root,int pos,node *krchild,int k,int *upkey,node **upright)
{
    int lastkey,d,i,j;
    node *lastchild;
    d = CEIL_Mdiv2;
    if(pos==MAX)
    {
        lastkey=k;
        lastchild=krchild;
    }
    else
    {
        lastkey=root->key[MAX];
        lastchild=root->child[MAX];
        for(i=MAX-1;i>pos;--i)
        {
            root->key[i+1]=root->key[i];
            root->child[i+1]=root->child[i];
        }
        root->key[pos+1]=k;
        root->child[pos+1]=krchild;
    }
    *upkey=root->key[d];
    (*upright)=(node*)malloc(sizeof(node));
    (*upright)->child[0]=root->child[d];
    for(i=1,j=d+1;j<=MAX;++i,++j)
    {
        (*upright)->key[i]=root->key[j];
        (*upright)->child[i]=root->child[j];
    }
    root->count=d-1;
    (*upright)->key[M-d]=lastkey;
    (*upright)->child[M-d]=lastchild;
    (*upright)->count=M-d;
}
node *del(node *root,int key)
{
    node *temp;
    rec_del(root,key);
    if(root!=NULL && root->count==0)
    {
        temp=root;
        root=root->child[0];
        free(temp);
    }
    return root;
}
void rec_del(node *root,int key)
{
    int flag,pos;
    if(root==NULL)
    {
        printf("Key not found !!!");
        return;
    }
    flag = search_node(root,key,&pos);
    if(flag)
    {
        printf("Key Deleted !!");
        if(root->child[pos]==NULL)
            del_shift(root,pos);
        else
        {
            key = copy_succ(root,pos);
            rec_del(root->child[pos],key);
        }
    }
    else
        rec_del(root->child[pos],key);
    if(root->child[pos]!=NULL)
    {
        if(root->child[pos]->count<MIN)
            restore(root,pos);
    }
}
int copy_succ(node *root,int pos)
{
    node *ptr=root->child[pos];
    while(ptr->child[0]!=NULL)
        ptr=ptr->child[0];
    root->key[pos]=ptr->key[1];
    return ptr->key[1];
}
void restore(node*root,int pos)
{
    if(pos!=0 && root->child[pos-1]->count>MIN)
        borrow_left(root,pos);
    else if(pos!=root->count&&root->child[pos]->count>MIN)
        borrow_right(root,pos);
    else
    {
        if(pos==0)
            combine(root,pos+1);
        else
            combine(root,pos);
    }
}
void del_shift(node *root,int pos)
{
    int i;
    for(i=pos+1;i<=root->count;++i)
    {
        root->key[i-1]=root->key[i];
        root->child[i-1]=root->child[i];
    }
    (root->count)--;
}
void combine(node *root,int pos)
{
    node *x,*y;
    int i;
    x = root->child[pos];
    y = root->child[pos-1];
    (y->count)++;
    y->key[y->count]=root->key[pos];
    del_shift(root,pos);
    y->child[y->count]=x->child[0];
    for(i=1;i<=x->count;++i)
    {
        y->count++;
        y->key[y->count]=x->key[i];
        y->child[y->count]=x->child[i];
    }
    free(x);
}
void borrow_left(node *root,int pos)
{
    node *ptr,*ls;
    int i;
    ptr=root->child[pos];
    ls=root->child[pos-1];
    for(i=1;i<=ptr->count;++i)
    {
        ptr->key[i+1]=ptr->key[i];
        ptr->child[i+1]=ptr->child[i];
    }
    ptr->child[1]=ptr->child[0];
    ptr->key[1]=root->key[pos];
    ptr->count++;
    root->key[pos]=ls->key[ls->count];
    ptr->child[0]=ls->child[ls->count];
    (ls->count)--;
}
void borrow_right(node *root,int pos)
{
    node *ptr,*rs;
    int i;
    ptr=root->child[pos];
    rs=root->child[pos+1];
    ptr->count++;
    ptr->key[ptr->count]=root->key[pos+1];
    ptr->child[ptr->count]=rs->child[0];
    root->key[pos+1]=rs->key[1];
    rs->child[0]=rs->child[1];
    for(i=1;i<rs->count;++i)
    {
        rs->child[i]=rs->child[i+1];
        rs->key[i]=rs->key[i+1];
    }
    (rs->count)--;
}
