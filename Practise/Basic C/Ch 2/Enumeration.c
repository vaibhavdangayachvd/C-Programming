/*Enumeration*/
#include <stdio.h>
enum week{Monday=1,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
int main()
{
    enum week day;
    day = Tuesday;
    printf("%d",day);
    return 0;
}
