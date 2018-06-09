#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct rb_tree
{
    enum {red,black} color;
    int num;
    struct rb_tree *lchild;
    struct rb_tree *rchild;
    struct rb_tree *parent;
};
typedef struct rb_tree tree_node;
void hold(void);
void print_options(void);
void insert(int);
void in(tree_node*);
void balance(tree_node *);
void rotate_left(tree_node*);
void rotate_right(tree_node*);
tree_node *root,*sentinel;
void del(int);
void balance_del(tree_node *);
int find(tree_node **,int);
tree_node *in_succ(tree_node *);
int main()
{
    sentinel=(tree_node*)malloc(sizeof(tree_node));
    sentinel->num=-1;
    sentinel->color=black;
    root=sentinel;
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
        insert(key);
        hold();
        break;
    case '2':
        in(root);
        hold();
        break;
        case 8:
        printf("Press Enter to exit...");
        getch();
        return 0;
    case '3':
        printf("Enter Key to be deleted : ");
        scanf("%d",&key);
        del(key);
        hold();
        break;
    default:
        printf("Wrong Input !!!");
        hold();
        break;
    }
    goto jump;
}
void print_options(void)
{
    printf("1 - Insert Element\n");
    printf("2 - In-Order Transversal\n");
    printf("3 - Delete Element\n");
    printf("   Backspace - Exit\n\n");
    printf("->");
}
void hold(void)
{
    printf("\n\nPress Enter to continue...");
    getch();
}
void in(tree_node*root)
{
    if(root==sentinel)
    {
        return;
    }
    in(root->lchild);
    printf("%d ",root->num);
    in(root->rchild);
}
void rotate_left(tree_node*pptr)
{
    tree_node *aptr=pptr->rchild;
    pptr->rchild=aptr->lchild;
    if(aptr->lchild!=sentinel)
        aptr->lchild->parent=pptr;
    aptr->parent=pptr->parent;
    if(pptr->parent==sentinel)
        root=aptr;
    else if(pptr==pptr->parent->lchild)
        pptr->parent->lchild=aptr;
    else
        pptr->parent->rchild=aptr;
    aptr->lchild=pptr;
    pptr->parent=aptr;
}
void rotate_right(tree_node*pptr)
{
    tree_node *aptr=pptr->lchild;
    pptr->lchild=aptr->rchild;
    if(aptr->rchild!=sentinel)
        aptr->rchild->parent=pptr;
    aptr->parent=pptr->parent;
    if(pptr->parent==sentinel)
        root=aptr;
    else if(pptr==pptr->parent->lchild)
        pptr->parent->lchild=aptr;
    else
        pptr->parent->rchild=aptr;
    aptr->rchild=pptr;
    pptr->parent=aptr;
}
void insert(int key)
{
    tree_node *ptr,*par,*temp;
    ptr=root;
    par=sentinel;
    while(ptr!=sentinel)
    {
        par=ptr;
        if(key<ptr->num)
            ptr=ptr->lchild;
        else if(key>ptr->num)
            ptr=ptr->rchild;
        else
        {
            printf("Duplicate Key !!\n");
            return;
        }
    }
        temp=(tree_node*)malloc(sizeof(tree_node));
        temp->num=key;
        temp->lchild=sentinel;
        temp->rchild=sentinel;
        temp->color=red;
        temp->parent=par;
        if(par==sentinel)
            root=temp;
        else if(temp->num<par->num)
            par->lchild=temp;
        else
            par->rchild=temp;
        balance(temp);
        printf("Key Inserted !!!");
}
void balance(tree_node *node)
{
    tree_node *grand,*par,*uncle;
    par=node->parent;
    grand=par->parent;
    while(node->parent->color==red)
    {
        par=node->parent;
        grand=par->parent;
        if(par==grand->lchild)
        {
            uncle=grand->rchild;
            if(uncle->color==red)
            {
                grand->color=red;
                uncle->color=black;
                par->color=black;
                node=grand;
            }
            else
            {
                if(node==par->rchild)
                {
                    rotate_left(par);
                    node=par;
                    par=node->parent;
                }
                grand->color=red;
                par->color=black;
                rotate_right(grand);
            }
        }
        else
        {
            uncle=grand->lchild;
            if(uncle->color==red)
            {
                grand->color=red;
                uncle->color=black;
                par->color=black;
                node = grand;

            }
            else
            {
                if(node==par->lchild)
                {
                    rotate_right(par);
                    node=par;
                    par=node->parent;
                }
                grand->color=red;
                par->color=black;
                rotate_left(grand);
            }
        }
    }
    root->color=black;
}
int find(tree_node **los,int key)
{
    tree_node *ptr;
    if(root==sentinel)
    {
        *los=sentinel;
        return 0;
    }
    if(key==root->num)
    {
        *los=root;
        return 1;
    }
    if(key<root->num)
        ptr=root->lchild;
    else
        ptr=root->rchild;
    while(ptr!=sentinel)
    {
        if(key<ptr->num)
            ptr=ptr->lchild;
        else if(key>ptr->num)
            ptr=ptr->rchild;
        else
        {
            *los=ptr;
            return 1;
        }
    }
    *los=ptr;
    return 0;
}
void balance_del(tree_node *nptr)
{
    tree_node *sib;
    while(nptr!=root)
    {
        if(nptr==nptr->parent->lchild)
        {
            sib=nptr->parent->rchild;
            if(sib->color==red)
            {
                sib->color=black;
                nptr->parent->color=red;
                rotate_left(nptr->parent);
                sib=nptr->parent->rchild;
            }
            if(sib->lchild->color==black && sib->rchild->color==black)
            {
                sib->color=red;
                if(nptr->parent->color==red)
                {
                    nptr->parent->color=black;
                    return;
                }
                else
                    nptr=nptr->parent;
            }
            else
            {
                if(sib->rchild->color==black)
                {
                    sib->lchild->color=black;
                    sib->color=red;
                    rotate_right(sib);
                    sib=nptr->parent->rchild;
                }
                sib->color=nptr->parent->color;
                nptr->parent->color=black;
                sib->rchild->color=black;
                rotate_left(nptr->parent);
                return;
            }
        }
        else
        {
            sib=nptr->parent->lchild;
            {
                if(sib->color==red)
                {
                    sib->color=black;
                    nptr->parent->color=red;
                    rotate_right(nptr->parent);
                    sib=nptr->parent->lchild;
                }
                if(sib->lchild->color==black&&sib->rchild->color==black)
                {
                    sib->color=red;
                    if(nptr->parent->color==red)
                    {
                        nptr->parent->color=black;
                        return;
                    }
                    else
                        nptr=nptr->parent;
                }
                else
                {
                    if(sib->lchild->color==black)
                    {
                        sib->rchild->color=black;
                        sib->color=red;
                        rotate_left(sib);
                        sib=nptr->parent->lchild;
                    }
                    sib->color=nptr->parent->color;
                    nptr->parent->color=black;
                    sib->lchild->color=black;
                    rotate_right(nptr->parent);
                    return;
                }
            }
        }
    }//end of while
}
void del(int key)
{
    tree_node *succ,*ptr,*child;
    if(!find(&ptr,key))
    {
        printf("Key not found!!");
        return;
    }
    if(ptr->lchild != sentinel && ptr->rchild!=sentinel)
    {
        succ=in_succ(ptr);
        ptr->num=succ->num;
        ptr=succ;
    }
    if(ptr->lchild!=sentinel)
        child=ptr->lchild;
    else
        child=ptr->rchild;
    child->parent=ptr->parent;
    if(ptr->parent==sentinel)
        root=child;
    else if(ptr==ptr->parent->lchild)
        ptr->parent->lchild=child;
    else
        ptr->parent->rchild=child;
    if(child==root)
        child->color=black;
    else if(ptr->color==black)
    {
        if(child!=sentinel)
            child->color=black;
        else
            balance_del(child);
    }
    printf("Key Deleted !!");
}
tree_node *in_succ(tree_node *ptr)
{
    ptr=ptr->rchild;
    while(ptr->lchild!=sentinel)
        ptr=ptr->lchild;
    return ptr;
}
