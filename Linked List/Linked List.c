#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <linked.h>
void main()
{
    node *head;
    head=(node *)malloc(sizeof(node));
    printf("Enter Data\n");
    scan(head);
    printf("\nEntered Data\n");
    print(head);
    hold();
}
