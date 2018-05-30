/*Multiple*/
#include <stdio.h>
int main()
{
    int m,n;
    printf("Enter 2 Integers(Smaller,Greater\n->");
    scanf("%d %d",&m,&n);
    if ( n % m == 0 )
        printf("%d is multiple of %d",m,n);
    else
        printf("%d is not multiple of %d",m,n);
}
