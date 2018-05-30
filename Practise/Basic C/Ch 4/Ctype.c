/*character Type*/
#include <stdio.h>
#include <ctype.h>
int main()
{
    char word;
    printf("Press any key\n->");
    word = getchar();
    if (isalpha(word)>0)
        printf("The character is a letter");
    else
        if (isdigit(word)>0)
        printf("The character is a digit");
    else
        printf("The character is not alphanumeric");
}
