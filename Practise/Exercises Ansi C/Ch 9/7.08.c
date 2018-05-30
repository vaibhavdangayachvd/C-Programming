#include <stdio.h>
#include <conio.h>
#include <ctype.h>
void text(char[]);
void main()
{
    int c[20];
    printf("Enter name in lower case to convert into upper case\n->");
    scanf("%[^\n]",c);
    text(c);
}
void text(char c[])
{
    int i=0;
    printf("Converted String : ");
    while(c[i]!='\0')
    {
        if(islower(c[i]))
        {
            putchar(toupper(c[i]));
        }
        else
        {
            putchar(c[i]);
        }
        ++i;
    }
}
