#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct list
{
    int num;
    struct list *next;
};
typedef struct list node;
void scan(node *);
void print(node *);
void hold (void);
int main()
{
    node *head;
    head = (node*)malloc(sizeof(node));
    printf("Enter elements:-(type -999 to end\n");
    scan(head);
    printf("Entered Number-:\n");
    print(head);
    printf("\n\n");
    hold();
    return(0);
}
void scan(node *head)
{
    scanf("%d",&head->num);
    if(head->num==-999)
    {
        head->next = NULL;
    }
    else
    {
        head->next = (node*)malloc(sizeof(node));
        scan(head->next);
    }
    return;
}
void print(node *head)
{
    if(head->next != NULL)
    {
        printf("%d ",head->num);
        print(head->next);
    }
    return;
}
void hold(void)
{
    printf("Press Enter to continue...");
    getch();
}
