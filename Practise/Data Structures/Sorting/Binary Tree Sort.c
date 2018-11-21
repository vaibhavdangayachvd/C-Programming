#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree
{
    int num;
    struct tree *left;
    struct tree *right;
};
typedef struct tree node;
node *insert(node *root,int num);
void print(node *root);
int main()
{
    node *root=NULL;
    int n,num;
    printf("Enter number of elements : ");
    do
    {
        scanf("%d",&n);
    }
    while(n<=0);
    printf("Enter elements : ");
    for(int i=0;i<n;++i)
    {
        scanf("%d",&num);
        root=insert(root,num);
        if(root==NULL)
        {
            printf("\nWrong Input !!! Start Again !!\n");
            printf("Enter elements : ");
            i=-1;
        }
    }
    printf("Sorted List : ");
    print(root);
    printf("\n\n\tPress Enter to exit...");
    getch();
    return 0;
}
void print(node *root)
{
    if(root==NULL)
        return;
    print(root->left);
    printf("%d ",root->num);
    print(root->right);
}
node *insert(node *root,int num)
{
    node *temp;
    if(root==NULL)
    {
        temp=(node*)malloc(sizeof(node));
        temp->left=NULL;
        temp->right=NULL;
        temp->num=num;
        return temp;
    }
    if(num<root->num)
        root->left=insert(root->left,num);
    else if(num>root->num)
        root->right=insert(root->right,num);
    else
        return NULL;
    return root;
}
