/*Mixed Data Type*/
#include <stdio.h>
int main()
{
    int count;
    char code;
    float ratio;
    char name[15];
    scanf("%d %c %f %s",&count,&code,&ratio,name);
    printf("%d %c %3.2f %s",count,code,ratio,name);
}
