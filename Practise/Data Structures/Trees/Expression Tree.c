#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#define MAX 20
struct tree
{
    char num;
    struct tree *lchild;
    struct tree *rchild;
};
typedef struct tree tree_node;
tree_node *stack[MAX];
char post[MAX];
int top = -1;
void push(tree_node *);
tree_node *pop(void);
int is_empty(void);
int is_full(void);
void in_rec(tree_node *);
int is_white(char);
void main()
{
    tree_node *root;
    tree_node *temp;
    int i;
    printf("Enter postfix expression\n");
    gets(post);
    for(i=0;i<strlen(post);++i)
    {
        if(is_white(post[i]))
            continue;
        if(post[i]>='0'&&post[i]<='9'|| isalpha(post[i]))
        {
            temp=(tree_node*)malloc(sizeof(tree_node));
            temp->num=post[i];
            temp->lchild=NULL;
            temp->rchild=NULL;
            push(temp);
        }
        else
        {
            temp=(tree_node*)malloc(sizeof(tree_node));
            temp->num=(int)post[i];
            temp->rchild=pop();
            temp->lchild=pop();
            push(temp);
        }
    }
    root = pop();
    printf("Infix Expression : ");
    in_rec(root);
    printf("\n\nPress Enter to exit...");
    getch();
}
void push(tree_node *root)
{
    if(is_full())
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top]=root;
    return;
}
tree_node *pop(void)
{
    if(is_empty())
    {
        printf("Stack Underflow !!\n");
        exit(1);
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
int is_full(void)
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
void in_rec(tree_node *root)
{
    if(root==NULL)
        return;
    printf("(");
    in_rec(root->lchild);
    printf("%c ",root->num);
    in_rec(root->rchild);
    printf(")");
    return;
}
int is_white(char c)
{
    if (c==' ')
        return 1;
    else
        return 0;
}
