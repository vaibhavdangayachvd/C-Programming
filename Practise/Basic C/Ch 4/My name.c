/* Name Name*/
#include <stdio.h>
int main()
{
    char name;
    printf("Would you like to know my name?\n");
    printf("Type Y for Yes and N for No: ");
    name = getchar();
    if (name == 'y' || name == 'Y')
        printf("My name is Vaibhav Dangayach");
    else if (name == 'n' || name == 'N')
        printf("Goto Hell Motherfucker");
    else
        printf("Input valid answer");
}


