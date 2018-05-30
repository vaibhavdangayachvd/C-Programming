#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree
{
    int num;
    struct tree *lchild;
    struct tree *rchild;
};
typedef struct tree node;
void create(node *);
void rec_pre(node*);
//void rec_in(node*);
//void rec_pos(node*);
//void nrec_pre(node*);
//void nrec_in(node*);
//void nrec_pos(node*);
void main()
{
    node *root;
    root=(node*)malloc(sizeof(node));
    printf("Enter Data in Tree in preorder\n");
    create(root);
    printf("Data in tree in preorder\n");
    rec_pre(root);
    printf("\nPress Enter to exit...");
    getch();
}
void create(node *root)
{
    int temp;
    scanf("%d",&temp);
    if(temp!=-999)
    {
        root->num=temp;
        root->lchild=(node*)malloc(sizeof(node));
        root->rchild=(node*)malloc(sizeof(node));
        create(root->lchild);
        create(root->rchild);
        return;
    }
    else
    {
        root=NULL;
        return;
    }
}
void rec_pre(node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->num);
    rec_pre(root->lchild);
    rec_pre(root->rchild);
    return;
}
