/*Convert Days into months*/
#include <stdio.h>
int main()
{
    int day,month;
    printf("Enter Days :-\n->");
    scanf("%d",&day);
    month=day/30;
    day %= 30;
    printf("%d Months %d Days",month,day);
}
