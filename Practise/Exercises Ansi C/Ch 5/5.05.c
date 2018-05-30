/*Eligibility*/
#include <stdio.h>
int main()
{
    int m,p,c;
    printf("Enter marks of maths, physics and chemistry\n->");
    scanf("%d %d %d",&m,&p,&c);
    if (p,c,m>100)
        printf("Enter correct information");
    else if(m<60 || p<50 || c < 40)
        printf("Sorry, you are not eligible");
    else if (p+c+m >= 200 || m+p>=150)
        printf("Yes, you're eligible");
    else if (p+c+m < 200 && p+m<150)
        printf("Sorry, you are not eligible");
}
