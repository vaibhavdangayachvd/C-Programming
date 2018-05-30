#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int get_size(void);
int *alloc(int*,int);
void scan(int*,int);
void print(int*,int);
int *ralloc(int*,int,int);
void add(int*,int,int);
void hold(void);
int main()
{
    int *p,osize,nsize;
    printf("Enter size : ");
    osize = get_size();
    p = alloc(p,osize);
    scan(p,osize);
    printf("\nEntered elements :-\n");
    print(p,osize);
    printf("Enter new size : ");
    nsize = get_size();
    if(nsize<osize)
    {
        p = ralloc(p,osize,nsize);
        print(p,nsize);
        hold();
        exit(0);
    }
    p = ralloc(p,osize,nsize);
    printf("Enter new elements to add : ");
    add(p,osize,nsize);
    printf("\nEntered elements(including new):-\n");
    print(p,nsize);
    free(p);
    hold();
    return(0);
}
int get_size(void)
{
    int size;
    scanf("%d",&size);
    return size;
}
int *alloc(int *p,int size)
{
    if((p = (int *)malloc(size*sizeof(int)))==NULL)
    {
        printf("Not enough space\n");
        exit(1);
    }
    printf("Buffer of total size %d byte, %d byte each created !\n\n",_msize(p),sizeof(int));
    return p;
}
void scan(int*p,int size)
{
    int i;
    printf("Enter elements : ");
    for(i=0;i<size;++i)
    {
        scanf("%d",(p+i));
    }
    return;
}
void print(int*p,int size)
{
    int i;
    for(i=0;i<size;++i)
    {
        printf("%d ",*(p+i));
    }
    printf("\n\n");
    return;
}
int *ralloc(int*p,int osize,int nsize)
{
    if((p=(int*)realloc(p,nsize*sizeof(int)))==NULL)
    {
        printf("Not enough space\n");
        exit(1);
    }
    if(nsize>osize)
        printf("Buffer of size %d , %d byte each created and old elements copied !\n\n",_msize(p),sizeof(int));
    else
        printf("Buffer of size %d , %d byte each created and extra elements deleted !\n\n",_msize(p),sizeof(int));
    return p;
}
void add(int*p,int osize,int nsize)
{
    int i;
    for(i=1;i<=nsize-osize;++i)
    {
        scanf("%d",(p+osize-1+i));
    }
    return;
}
void hold(void)
{
    printf("Press Enter to continue...");
    getch();
}
