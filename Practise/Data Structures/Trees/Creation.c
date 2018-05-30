#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20
struct tree
{
    int num;
    struct tree *lchild;
    struct tree *rchild;
};
struct order
{
    int num;
    struct order *next;
};
typedef struct tree tree_node;
typedef struct order order_node;
tree_node *stack[MAX];
int top= -1;
void push(tree_node *);
tree_node *pop(void);
int is_empty(void);
void create_order(order_node *);
int get_size(order_node*);
tree_node *create_tree(order_node *,order_node *,int);
void rec_pre(tree_node *);
void rec_in(tree_node *);
void rec_pos(tree_node *);
void nrec_pre(tree_node *);
void nrec_in(tree_node *);
void nrec_pos(tree_node *);
void main()
{
    int size=0;
    order_node *pre,*in;
    pre=(order_node*)malloc(sizeof(order_node));
    in=(order_node*)malloc(sizeof(order_node));
    tree_node *root;
    printf("Enter data in pre order(-999 to end)\n");
    create_order(pre);
    printf("Enter data in in-order(-999 to end)\n");
    create_order(in);
    size = get_size(in);
    root=create_tree(in,pre,size);
    printf("\nData in tree in preorder rec\n");
    rec_pre(root);
    printf("\nData in tree in inorder rec\n");
    rec_in(root);
    printf("\nData in tree in posorder rec\n");
    rec_pos(root);
    printf("\nData in tree in preorder nrec\n");
    nrec_pre(root);
    printf("\nData in tree in inorder nrec\n");
    nrec_in(root);
    printf("\nData in tree in posorder nrec\n");
    nrec_pos(root);
    printf("\n\nPress Enter to exit...");
    getch();
}
void create_order(order_node *order)
{
    scanf("%d",&order->num);
    if(order->num==-999)
    {
        order->next=NULL;
        return;
    }
    order->next=(order_node*)malloc(sizeof(order_node));
    create_order(order->next);
}
int get_size(order_node *order)
{
    int i=0;
    while(order->next!=NULL)
    {
        ++i;
        order=order->next;
    }
    return(i);
}
tree_node *create_tree(order_node *in,order_node *pre,int num)
{
    tree_node *temp;
    order_node *q;
    int i,j;
    if(num==0)
        return NULL;
    temp=(tree_node*)malloc(sizeof(tree_node));
    temp->num=pre->num;
    temp->lchild=NULL;
    temp->rchild=NULL;
    if(num==1)
        return temp;
    q=in;
    for(i=0;q->num!=pre->num;++i)
    {
        q=q->next;
    }
    temp->lchild=create_tree(in,pre->next,i);
    for(j=1;j<=i+1;++j)
    {
        pre=pre->next;
    }
    temp->rchild=create_tree(q->next,pre,num-i-1);
    return temp;
}
void rec_pre(tree_node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->num);
    rec_pre(root->lchild);
    rec_pre(root->rchild);
    return;
}
void rec_in(tree_node *root)
{
    if(root==NULL)
        return;
    rec_pre(root->lchild);
    printf("%d ",root->num);
    rec_pre(root->rchild);
    return;
}
void rec_pos(tree_node *root)
{
    if(root==NULL)
        return;
    rec_pre(root->lchild);
    rec_pre(root->rchild);
    printf("%d ",root->num);
    return;
}
void nrec_pre(tree_node *root)
{
    if(root==NULL)
    {
        printf("Tree is is empty\n");
        return;
    }
    push(root);
    while(!is_empty())
    {
        root = pop();
        printf("%d ",root->num);
        if(root->rchild!=NULL)
            push(root->rchild);
        if(root->lchild!=NULL)
            push(root->lchild);
    }
}
void nrec_in(tree_node *root)
{
    if(root==NULL)
    {
        printf("Tree is is empty\n");
        return;
    }
    while(1)
    {
        while(root->lchild!=NULL)
        {
            push(root);
            root=root->lchild;
        }
        while(root->rchild==NULL)
        {
            printf("%d ",root->num);
            if(is_empty())
            {
                return;
            }
            root=pop();
        }
        printf("%d ",root->num);
        root=root->rchild;
    }
    printf("\n");
}
void nrec_pos(tree_node *root)
{
    tree_node *q;
    if(root==NULL)
    {
        printf("Tree is is empty\n");
        return;
    }
    while(1)
    {
        while(root->lchild!=NULL)
        {
            push(root);
            root=root->lchild;
        }
        while(root->rchild==NULL||root->rchild==q)
        {
            printf("%d ",root->num);
            q=root;
            if(is_empty())
            {
                return;
            }
            root=pop();
        }
        push(root);
        root=root->rchild;
    }
    printf("\n");
}
void push(tree_node *root)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow");
        exit(1);
    }
    top++;
    stack[top]=root;
    return;
}
tree_node *pop(void)
{
    if(is_empty())
    {
        printf("Stack Underflow");
        exit(0);
    }
    return(stack[top--]);
}
int is_empty(void)
{
    if(top==-1)
        return 1;
    else
        return 0;
}
