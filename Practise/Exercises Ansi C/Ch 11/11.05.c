#include <stdio.h>
#include <conio.h>
void scan(char *);
char *arrange(char *,char);
void print(char *);
void hold(void);
void main()
{
    char a[20],c,*p=a;
    scan(p);
    printf("Enter element to delete : ");
    scanf(" %c",&c);
    p = arrange(p,c);
    print(p);
    hold();
}
void scan(char *p)
{
    printf("Enter your name : ");
    scanf("%[^\n]",p);
}
char *arrange(char *p,char c)
{
    char *temp,*q=p;
    while(*p!='\0')
    {
        if(*p==c)
        {
            temp = p;
            while(*(temp)!='\0')
            {
                *(temp)=*(temp+1);
                ++temp;
            }
        }
        ++p;
    }
    return q;
}
void print(char *p)
{
     printf("%s",p);
     printf("\n");
}
void hold(void)
{
    printf("Press Enter to continue...");
    getch();
}
