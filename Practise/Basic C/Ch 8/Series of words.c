#include <stdio.h>
#include <conio.h>
void main()
{
    int i;
    char ch,array[81];
    i=0;
    printf("Enter text and press Enter at the end\n->");
    while(ch != '\n')
    {
        ch=getchar();
        array[i]=ch;
        ++i;
    }
    i = i-1;
    array[i]= '\0';
    printf("\n%s\n",array);
    getch();
}
