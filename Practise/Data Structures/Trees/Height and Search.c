#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct tree
{
    int num;
    struct tree *lchild;
    struct tree *rchild;
};
struct list
{
    int num;
    struct list *next;
};

typedef struct tree tree_node;
typedef struct list list_node;

void create_list(list_node *);
int get_size(list_node *);
tree_node *create_tree(list_node *,list_node *,int);
int tree_height(tree_node *);
void search_tree_nrec(tree_node *,int);
void search_tree_rec(tree_node *,int);

int main()
{
    list_node *pre,*in;
    tree_node *root;
    int size;
    pre=(list_node*)malloc(sizeof(list_node));
    in=(list_node*)malloc(sizeof(list_node));
    printf("Enter Data in preorder(-999 to end)\n");
    create_list(pre);
    printf("Enter Data in inorder(-999 to end)\n");
    create_list(in);
    size = get_size(in);
    root=create_tree(in,pre,size);
    size = tree_height(root);
    printf("\nHeight of tree = %d\n\n",size);
    printf("Enter number to search in tree\n");
    scanf("%d",&size);
    search_tree_nrec(root,size);
    search_tree_rec(root,size);
    printf("\n\nPress Enter to exit...");
    getch();
    return 0;
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
}

int get_size(list_node *head)
{
    int i=0;
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
        q=q->next;
    temp->lchild=create_tree(in,pre->next,i);
    for(j=1;j<=i+1;++j)
        pre=pre->next;
    temp->rchild=create_tree(q->next,pre,num-i-1);
    return temp;
}

int tree_height(tree_node *root)
{
    int rh,lh;
    if(root==NULL)
        return 0;
    lh=tree_height(root->lchild);
    rh=tree_height(root->rchild);
    if(lh>=rh)
        return lh+1;
    else
        return rh+1;
}

void search_tree_nrec(tree_node *root,int key)
{
    while(root!=NULL)
    {
        if(root->num==key)
        {
            printf("Key found !!\n");
            return;
        }
        else
        {
            if(key<root->num)
                root=root->lchild;
            else
                root=root->rchild;
        }
    }
    printf("Key not found !!!\n");
    return;
}

void search_tree_rec(tree_node *root,int key)
{
    if(root==NULL)
    {
        printf("Key not found!!");
        return;
    }
    if(key<root->num)
        search_tree_rec(root->lchild,key);
    else if(key>root->num)
        search_tree_rec(root->rchild,key);
    else
        printf("Key Found !!");
    return;
}
