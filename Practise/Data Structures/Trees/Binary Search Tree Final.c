//Binary Search Tree Final Program
//Header Files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Tree structure
struct tree
{
    int num;
    struct tree *lchild;
    struct tree *rchild;
};
typedef struct tree tree_node;
//User defined Functions
void print_options(void);//Print Options
void hold(void);//Hold screen
tree_node *insert(tree_node*,int);//Insertion in tree
tree_node *del(tree_node*,int);//Deletion from tree
void ser(tree_node *,int);//Searching the tree
void min(tree_node*);//Finding minimum key
void max(tree_node*);//Finding maximum key
int height(tree_node*);//Height of the tree
void pre(tree_node*);//Preorder Transversal
void in(tree_node*);//Inorder Transversal
void pos(tree_node*);//Postorder Transversal
//Main Function
int main()
{
    //Tree Pointer
    tree_node *root=NULL;
    int key;//Loop
    char i;
    jump://Multiple Trials
    system("cls");
    printf("\t\t\t    WELCOME TO TREE DATA-STRUCTURE\n");
    printf("Choose operation :-\n");
    print_options();
    i = getch();
    system("cls");
    switch(i)
    {
    case '1':
        printf("Enter Key to be inserted : ");
        scanf("%d",&key);
        root=insert(root,key);
        printf("Key Inserted !!!");
        hold();
        break;
    case '2':
        printf("Enter Key to be deleted : ");
        scanf("%d",&key);
        root=del(root,key);
        printf("Key Deleted !!!");
        hold();
        break;
    case '3':
        printf("Enter Key to be searched : ");
        scanf("%d",&key);
        ser(root,key);
        hold();
        break;
    case '4':
        min(root);
        max(root);
        hold();
        break;
    case '5':
        key = height(root);
        printf("Height of the tree is : %d",key);
        hold();
        break;
    case '6':
        pre(root);
        hold();
        break;
    case '7':
        in(root);
        hold();
        break;
    case '8':
        pos(root);
        hold();
        break;
    case 8:
        printf("Press Enter to exit...");
        getch();
        return 0;
    default:
        printf("Wrong Input !!!");
        hold();
        break;
    }
    goto jump;
}
//Print Function
void print_options(void)
{
    printf("1 - Insert Element\n");
    printf("2 - Delete Element\n");
    printf("3 - Search Element\n");
    printf("4 - Find Minimum and Maximum Key\n");
    printf("5 - Find Height of Tree\n");
    printf("6 - Pre-Order Transversal\n");
    printf("7 - In-Order Transversal\n");
    printf("8 - Post-Order Transversal\n");
    printf("   Backspace - Exit\n\n");
    printf("->");
}
//HoldFunction
void hold(void)
{
    printf("\n\nPress Enter to continue...");
    getch();
}
//Insert Function
tree_node *insert(tree_node*root,int key)
{
    tree_node *temp;
    if(root==NULL)
    {
        temp=(tree_node*)malloc(sizeof(tree_node));
        temp->num=key;
        temp->lchild=NULL;
        temp->rchild=NULL;
        return temp;
    }
    if(key<root->num)
        root->lchild=insert(root->lchild,key);
    else if(key>root->num)
        root->rchild=insert(root->rchild,key);
    else
        printf("Duplicate Key !!!\n");
    return root;
}
//Delete function
tree_node *del(tree_node*root,int key)
{
    tree_node *ptr,*par,*temp,*succ,*par_succ,*child;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        if(ptr->num==key)
            break;
        par=ptr;
        if(key<ptr->num)
            ptr=ptr->lchild;
        else
            ptr=ptr->rchild;
    }
    if(ptr==NULL)
        printf("Key not found !!!\n");
    else if(ptr->lchild!=NULL && ptr->rchild!=NULL)
    {
        succ=ptr->rchild;
        par_succ=ptr;
        while(succ->lchild!=NULL)
        {
            par_succ=ptr;
            succ=succ->lchild;
        }
        ptr->num=succ->num;
        ptr=succ;
        par=par_succ;
    }
    if(ptr->lchild!=NULL)
        child=ptr->lchild;
    else
        child=ptr->rchild;
    if(par==NULL)
        root=NULL;
    else if(ptr=par->lchild)
        par->lchild=child;
    else
        par->rchild=child;
    free(ptr);
    return(root);
}
//Search Function
void ser(tree_node *root,int key)
{
    if(root==NULL)
    {
        printf("Key not found!!!");
        return;
    }
    if(key<root->num)
        ser(root->lchild,key);
    else if(key>root->num)
        ser(root->rchild,key);
    else
    {
        printf("Key Found !!!\n");
    }
    return;
}
//Min function
void min(tree_node*root)
{
    if(root==NULL)
    {
        printf("Tree is empty !!\n");
        return;
    }
    else
    {
        if(root->lchild==NULL)
        {
            printf("Min = %d\n",root->num);
            return;
        }
        min(root->lchild);
    }
}
//Max function
void max(tree_node*root)
{
    if(root==NULL)
    {
        printf("Tree is empty !!\n");
        return;
    }
    else
    {
        if(root->rchild==NULL)
        {
            printf("Max = %d\n",root->num);
            return;
        }
        max(root->rchild);
    }
}
//Height function
int height(tree_node*root)
{
    int lh,rh;
    if(root==NULL)
        return 0;
    lh=height(root->lchild);
    rh=height(root->rchild);
    if(lh>=rh)
        return lh+1;
    else
        return rh+1;
}
//Pre trans Function
void pre(tree_node*root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->num);
    pre(root->lchild);
    pre(root->rchild);
}
//In trans Function
void in(tree_node*root)
{
    if(root==NULL)
    {
        return;
    }
    in(root->lchild);
    printf("%d ",root->num);
    in(root->rchild);
}
//Post trans Function
void pos(tree_node*root)
{
    if(root==NULL)
    {
        return;
    }
    pos(root->lchild);
    pos(root->rchild);
    printf("%d ",root->num);
}
