#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "C:\Program Files\CodeBlocks\MinGW\linked.h"
void main()
{
    node *head;
    head=(node*)malloc(sizeof(node));
    printf("Enter number(-999 to end)\n->");
    scan(head);
    printf("Entered Number\n->");
    print(head);
    hold();
}
