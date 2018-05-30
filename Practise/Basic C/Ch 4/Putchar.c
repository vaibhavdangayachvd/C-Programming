/*Upper to lower*/
#include <stdio.h>
#include <ctype.h>
int main()
{
    char alpha;
    printf("Enter an Alphabet");
    putchar('\n');
    printf("->");
    alpha = getchar();
    if (islower(alpha))
        putchar(toupper(alpha));
    else
        if (isupper(alpha))
        putchar(tolower(alpha));
    else
        if (isdigit(alpha) > 0)
        printf("You have entered a digit");
    else
        printf("The character is not alphanumeric.\n");
}
