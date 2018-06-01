#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20

struct list
{
    int num;
    struct list *next;
};
typedef struct list list_node;
void create_list(list_node *);
int get_size(list_node *);

struct tree
{
    int num;
    struct tree *lchild;
    struct tree *rchild;
};
typedef struct tree tree_node;
tree_node *create_tree(list_node *,list_node *,int);
void tree_nrec_min(tree_node *);
void tree_rec_min(tree_node *);
void tree_nrec_max(tree_node *);
void tree_rec_max(tree_node *);
//tree_node *insert_tree_nrec(tree_node *,int);
tree_node *insert_tree_rec(tree_node *,int);
//tree_node *del_tree_nrec(tree_node*,int);
tree_node *del_tree_rec(tree_node*,int);
void nrec_in(tree_node *);

tree_node *stack[MAX];
int top = -1;
void push(tree_node*);
tree_node *pop(void);
int is_empty(void);

int main()
{
    tree_node *root;
    list_node *pre,*in;
    int size;
    pre=(list_node*)malloc(sizeof(tree_node));
    in=(list_node*)malloc(sizeof(tree_node));
    printf("Enter data in preorder\n");
    create_list(pre);
    printf("Enter data in inorder\n");
    create_list(in);
    size=get_size(in);
    root = create_tree(in,pre,size);
    printf("\n");
    tree_rec_min(root);
    tree_rec_max(root);
    tree_nrec_min(root);
    tree_nrec_max(root);
    printf("\nEnter key to insert in tree : ");
    scanf("%d",&size);
    root = insert_tree_rec(root,size);
    nrec_in(root);
    printf("\nEnter key to del in tree : ");
    scanf("%d",&size);
    root = del_tree_rec(root,size);
    nrec_in(root);
    printf("\n\nPress Enter to exit...");
    getch();
    return 0;
}

int is_empty(void)
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(tree_node *root)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow");
        exit(1);
    }
    stack[++top]=root;
    return;
}

tree_node *pop(void)
{
    if(is_empty())
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    else
    {
        return(stack[top--]);
    }
}

void create_list(list_node *head)
{
    scanf("%d",&head->num);
    if(head->num==-999)
    {
        head->next=NULL;
        return;
    }
    head->next=(list_node*)malloc(sizeof(list_node));
    create_list(head->next);
    return;
}

int get_size(list_node *head)
{
    int i;
    for(i=0;head->next!=NULL;++i)
    {
        head=head->next;
    }
    return i;
}

tree_node *create_tree(list_node *in,list_node *pre,int num)
{
    tree_node *temp;
    list_node *q;
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

void tree_nrec_min(tree_node *root)
{
    if(root!=NULL)
    {
        while(root->lchild!=NULL)
        {
            root=root->lchild;
        }
        printf("Min Key is %d\n",root->num);
    }
    else
    {
        printf("Tree is empty!!\n");
    }
}

void tree_nrec_max(tree_node *root)
{
    if(root!=NULL)
    {
        while(root->rchild!=NULL)
        {
            root=root->rchild;
        }
        printf("Max Key is %d\n",root->num);
    }
    else
    {
        printf("Tree is empty!!\n");
    }
}

void tree_rec_min(tree_node *root)
{
    if(root==NULL)
    {
        printf("Tree is empty!!!\n");
    }
    else
    {
        if(root->lchild==NULL)
            printf("Min Key is %d\n",root->num);
        else
            tree_rec_min(root->lchild);
    }
    return;
}

void tree_rec_max(tree_node *root)
{
    if(root==NULL)
    {
        printf("Tree is empty!!!\n");
    }
    else
    {
        if(root->rchild==NULL)
            printf("Max Key is %d\n",root->num);
        else
            tree_rec_max(root->rchild);
    }
    return;
}

void nrec_in(tree_node *root)
{
    if(root==NULL)
    {
        printf("Tress is empty !!!");
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
                return;
            root = pop();
        }
        printf("%d ",root->num);
        root=root->rchild;
    }
    return;
}

/*tree_node *insert_tree_nrec(tree_node *root,int key)
{
    tree_node *ptr,*par,*temp;
    ptr=root;
    par=NULL;
    while(ptr!=NULL)
    {
        par=ptr;
        if(key<ptr->num)
            ptr=ptr->lchild;
        else if(key>ptr->num)
            ptr=ptr->rchild;
        else
        {
            printf("Duplicate Key !!\n");
            return root;
        }
    }
    temp=(tree_node*)malloc(sizeof(tree_node));
    temp->num=key;
    temp->lchild=NULL;
    temp->rchild=NULL;
    if(par==NULL)
        root=temp;
    else if(key<par->num)
        par->lchild=temp;
    else
        par->rchild=temp;
    return root;
}*/

tree_node *insert_tree_rec(tree_node *root,int key)
{
    if(root==NULL)
    {
        root=(tree_node*)malloc(sizeof(tree_node));
        root->num=key;
        root->lchild=NULL;
        root->rchild=NULL;
    }
    else if(key<root->num)
        root->lchild=insert_tree_rec(root->lchild,key);
    else if(key>root->num)
        root->rchild=insert_tree_rec(root->rchild,key);
    else
        printf("Duplicate Key !!\n");
    return root;
}

/*tree_node *del_tree_nrec(tree_node*root,int key)
{
    tree_node *par,*ptr,*succ,*par_succ,*child;
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
    {
        printf("Key not found !!\n");
        return root;
    }
    if(ptr->lchild!=NULL && ptr->rchild!=NULL)
    {
        par_succ=ptr;
        succ=ptr->rchild;
        while(succ->lchild!=NULL)
        {
            par_succ=succ;
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
        root=child;
    else if(par->lchild==ptr)
        par->lchild=child;
    else
        par->rchild=child;
    free(ptr);
    return root;
}*/

tree_node *del_tree_rec(tree_node*ptr,int key)
{
    tree_node *succ,*temp;
    if(ptr==NULL)
        return NULL;
    if(key<ptr->num)
        ptr->lchild=del_tree_rec(ptr->lchild,key);
    else if(key>ptr->num)
        ptr->rchild=del_tree_rec(ptr->rchild,key);
    else
    {
        if(ptr->lchild!=NULL && ptr->rchild!=NULL)
        {
            succ=ptr->rchild;
            while(succ->lchild!=NULL)
                succ=succ->lchild;
            ptr->rchild=del_tree_rec(ptr->rchild,succ->num);
        }
        else
        {
            temp=ptr;
            if(ptr->lchild!=NULL)
                ptr=ptr->lchild;
            else if(ptr->rchild!=NULL)
                ptr=ptr->rchild;
            else
                ptr=NULL;
            free(temp);
        }
        return ptr;
    }
}
