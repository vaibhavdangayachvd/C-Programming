#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct avl_tree
{
    struct avl_tree *lchild;
    int num;
    struct avl_tree *rchild;
    int balance;
};
typedef struct avl_tree tree_node;
void hold(void);
void in_rec(tree_node *);
tree_node *insert(tree_node *,int);
tree_node *check_left(tree_node*,int *);
tree_node *check_right(tree_node*,int *);
tree_node *balance_left(tree_node*);
tree_node *balance_right(tree_node*);
tree_node *rotate_left(tree_node*);
tree_node *rotate_right(tree_node*);
int main()
{
    tree_node *root=NULL;
    int key;
    char i;
    jump://Multiple Trials
    system("cls");
    printf("\t\t\t    WELCOME TO TREE DATA-STRUCTURE\n");
    printf("Choose operation :-\n1 - Insert\n2 - In Transverse\n   Any Other Key to Exit\n->");
    i = getch();
    system("cls");
    switch(i)
    {
    case '1':
        printf("Enter Key to be inserted : ");
        scanf("%d",&key);
        root=insert(root,key);
        hold();
        break;
    case '2':
        in_rec(root);
        hold();
        break;
    default:
        printf("Exit Successful\n");
        return 0;
    }
    goto jump;
}
void hold(void)
{
    printf("\n\nPress Enter to continue...");
    getch();
}
void in_rec(tree_node*root)
{
    if(root==NULL)
        return;
    in_rec(root->lchild);
    printf("%d ",root->num);
    in_rec(root->rchild);
    return;
}
tree_node *rotate_left(tree_node*root)
{
    tree_node *aptr=root->rchild;
    root->rchild=aptr->lchild;
    aptr->lchild=root;
    return(aptr);
}
tree_node *rotate_right(tree_node*root)
{
    tree_node *aptr=root->lchild;
    root->lchild=aptr->rchild;
    aptr->rchild=root;
    return(aptr);
}
tree_node *insert(tree_node *root,int key)
{
    static int status;
    if(root==NULL)
    {
        root=(tree_node*)malloc(sizeof(tree_node));
        root->num=key;
        root->lchild=NULL;
        root->rchild=NULL;
        root->balance=0;
        status=TRUE;
    }
    else if(key<root->num)
    {
        root->lchild=insert(root->lchild,key);
        if(status==TRUE)
            root=check_left(root,&status);
    }
    else if(key>root->num)
    {
        root->rchild=insert(root->rchild,key);
        if(status==TRUE)
            root=check_right(root,&status);
    }
    else
    {
        printf("Duplicate Key !!!\n");
        status=FALSE;
        return root;
    }
    return root;
}
tree_node *check_left(tree_node*root,int *status)
{
    switch(root->balance)
    {
    case -1:
        root->balance=0;
        *status=FALSE;
        break;
    case 0:
        root->balance=1;
        break;
    case 1:
        root=balance_left(root);
        *status=FALSE;
        break;
    }
    return root;
}
tree_node *check_right(tree_node*root,int *status)
{
    switch(root->balance)
    {
    case 1:
        root->balance=0;
        *status=FALSE;
        break;
    case 0:
        root->balance=-1;
        break;
    case -1:
        root=balance_right(root);
        *status=FALSE;
        break;
    }
    return root;
}
tree_node *balance_left(tree_node*root)
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
            break;
        }
        bptr->balance=0;
        aptr=rotate_left(aptr);
        root=rotate_right(root);
    }
    return root;
}
tree_node *balance_right(tree_node*root)
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
            break;
        }
        bptr->balance=0;
        aptr=rotate_right(aptr);
        root=rotate_left(root);
    }
    return root;
}
