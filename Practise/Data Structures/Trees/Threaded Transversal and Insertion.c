#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef enum{false,true} boolean;
struct threaded_tree
{
    struct threaded_tree *lchild;
    boolean lthread;
    int num;
    boolean rthread;
    struct threaded_tree *rchild;
};
typedef struct threaded_tree tree_node;
void hold(void);
tree_node *insert(tree_node *,int);
tree_node *in_succ(tree_node*);
void in(tree_node*);
int main()
{
    tree_node *root=NULL;
    int key;
    char i;
    jump://Multiple Trials
    system("cls");
    printf("\t\t\t    WELCOME TO TREE DATA-STRUCTURE\n");
    printf("Choose operation :-\n1 - Insert\n2 - In Transverse\n->");
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
        in(root);
        hold();
        break;
    default:
        return 0;
    }
    goto jump;
}
void hold(void)
{
    printf("\n\nPress Enter to continue...");
    getch();
}
tree_node *insert(tree_node *root,int key)
{
    tree_node *ptr=root,*par=NULL,*temp;
    while(ptr!=NULL)
    {
        par=ptr;
        if(key<ptr->num)
        {
            if(ptr->lthread==false)
                ptr=ptr->lchild;
            else
                break;
        }
        else if(key>ptr->num)
        {
            if(ptr->rthread==false)
                ptr=ptr->rchild;
            else
                break;
        }
        else
        {
            printf("Duplicate Key !!!\n");
            return root;
        }
    }
    temp=(tree_node*)malloc(sizeof(tree_node));
    temp->num=key;
    temp->lthread=true;
    temp->rthread=true;
    if(par==NULL)
    {
        temp->lchild=NULL;
        temp->rchild=NULL;
        root=temp;
    }
    else if(key<ptr->num)
    {
        temp->lchild=ptr->lchild;
        temp->rchild=ptr;
        ptr->lchild=temp;
        ptr->lthread=false;
    }
    else
    {
        temp->rchild=ptr->rchild;
        temp->lchild=ptr;
        ptr->rthread=false;
        ptr->rchild=temp;
    }
    printf("Key Inserted !!!");
    return root;
}
void in(tree_node*root)
{
    if(root==NULL)
    {
        printf("Tree is empty!!");
        return;
    }
    while(root->lthread==false)
    {
        root=root->lchild;
    }
    while(root!=NULL)
    {
        printf("%d ",root->num);
        root= in_succ(root);
    }
}
tree_node *in_succ(tree_node*ptr)
{
    if(ptr->rthread==true)
        return ptr->rchild;
    else
    {
        ptr=ptr->rchild;
        while(ptr->lthread==false)
            ptr=ptr->lchild;
    }
    return ptr;
}
