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
tree_node *in_pre(tree_node*);
tree_node *del(tree_node*,int);
void in(tree_node*);
int main()
{
    tree_node *root=NULL;
    int key;
    char i;
    jump://Multiple Trials
    system("cls");
    printf("\t\t\t    WELCOME TO TREE DATA-STRUCTURE\n");
    printf("Choose operation :-\n1 - Insert\n2 - Delete\n3 - In Transverse\n   Any Other Key to Exit\n->");
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
        printf("Enter Key to be deleted : ");
        scanf("%d",&key);
        root=del(root,key);
        hold();
        break;
    case '3':
        in(root);
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

tree_node *in_pre(tree_node*ptr)
{
    if(ptr->lthread==true)
        return ptr->lchild;
    else
    {
        ptr=ptr->lchild;
        while(ptr->rthread==false)
            ptr=ptr->rchild;
    }
    return ptr;
}
tree_node *del(tree_node *root,int key)
{
    tree_node *ptr,*par,*succ,*par_succ,*child,*p,*s;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        if(ptr->num==key)
            break;
        par=ptr;
        if(key<ptr->num)
        {
            if(ptr->lthread==false)
                ptr=ptr->lchild;
            else
                break;
        }
        else
        {
            if(ptr->rthread==false)
                ptr=ptr->rchild;
            else
                break;
        }
    }
    if(ptr==par)
    {
        printf("Key not found !!!");
        return root;
    }
    if(ptr->lthread==false && ptr->rthread==false)
    {
        succ=ptr->rchild;
        par_succ=ptr;
        while(succ->lchild!=NULL)
        {
            par_succ=succ;
            succ=succ->lchild;
        }
        ptr->num=succ->num;
        ptr=succ;
        par=par_succ;
    }
    if(ptr->lthread!=false&&ptr->rthread!=false)
    {
        if(par==NULL)
            root=NULL;
        else if(ptr==par->lchild)
        {
            par->lthread=true;
            par->lchild=ptr->lchild;
        }
        else
        {
            par->rthread=true;
            par->rchild=ptr->rchild;
        }
    }
    else
    {
        if(ptr->lthread==false)
            child=ptr->lchild;
        else
            child=ptr->rchild;
        if(par==NULL)
        {
            root=child;
        }
        else if(ptr==par->lchild)
            par->lchild=child;
        else
            par->rchild=child;
        p=in_pre(ptr);
        s=in_succ(ptr);
        if(ptr->lthread==false)
            p->rchild=s;
        else
            s->lchild=p;
    }
    free(ptr);
    printf("Key Deleted !!\n");
    return root;
}
