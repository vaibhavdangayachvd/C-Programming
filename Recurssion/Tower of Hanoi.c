#include<stdio.h>
#include<conio.h>
void tow(int,char,char,char);
void main()
{
    int ndisk;
    char source='A',temp='B',dest='C';
    printf("Enter number of disk\n");
    scanf("%d",&ndisk);
    printf("Process:-\n");
    tow(ndisk,source,temp,dest);
    getch();
}
void tow(int ndisk,char source,char temp,char dest)
{
    if(ndisk==1)
    {
        printf("Move disk %d from %c to %c\n",ndisk,source,dest);
        return;
    }
    tow(ndisk-1,source,dest,temp);
    printf("Move disk %d from %c to %c\n",ndisk,source,dest);
    tow(ndisk-1,temp,source,dest);
}
