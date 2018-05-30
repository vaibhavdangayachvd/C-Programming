/*Printing Char and Strings*/
#include <stdio.h>
int main()
{
    char x = 'A';
    char name[20] = "Anil Kumar Gupta";

    printf("Output of characters\n\n");
    printf("%c\n%3c\n%5c\n",x,x,x);
    printf("%3c\n%c\n\n",x,x);
    printf("Output of strings\n\n");
    printf("%20.4s\n",name);
    printf("%20.10s\n",name);
    printf("%20.16s\n",name);
    printf("%.5s\n",name);
    printf("%-20.10s\n",name);
    printf("%s\n",name);
}

