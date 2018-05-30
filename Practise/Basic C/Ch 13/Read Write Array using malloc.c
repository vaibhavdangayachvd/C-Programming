//Efficiently  Reading 2D Array
//Header Files
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//UD Functions
int get_size(void);//Get Row,Col Size
int *alloc(int *,int,int);//Allocating Memory
void read(int *,int,int);//Reading Array
void write(int *,int,int);//Writing Array
void hold(void);//Holding Screen
//Main function start
int main()
{
    //Declaring Variables
    int *p;//Pointer variable
    int rsize,csize;//Normal variable
    //Reading Row Size
    printf("Enter row size of array: ");
    rsize=get_size();//Function calling
    //Reading column size
    printf("Enter column size of array : ");
    csize=get_size();//Function calling
    printf("\n");
    p = alloc(p,rsize,csize);//Allocating memory and Returning Pointer
    read(p,rsize,csize);//Reading Array
    write(p,rsize,csize);//Writing Array
    free(p);//Freeing Memory
    hold();//Holding Screen
    return(0);//Return without errors
}
int get_size(void)
{
    int size;
    scanf("%d",&size);
    return(size);
}
int *alloc(int *p,int rsize,int csize)
{
    if((p = (int *)calloc(csize,rsize*sizeof(int)))==NULL)
    {
        printf("No space available\n");
        exit(1);
    }
    return p;
}
void read(int *p,int rsize,int csize)
{
    int i,j;
    for(i=0;i<rsize;++i)
    {
        printf("Enter elements row %d : ",i+1);
        for(j=0;j<csize;++j)
        {
            scanf("%d",(p+csize*i+j));
        }
    }
    return;
}
void write(int *p,int rsize,int csize)
{
    int i,j;
    printf("Entered elements :-\n");
     for(i=0;i<rsize;++i)
    {
        for(j=0;j<csize;++j)
        {
            printf("%d ",*(p+csize*i+j));
        }
        printf("\n");
    }
    printf("\n");
    return;
}
void hold(void)
{
    printf("Press Enter to continue...");
    getch();
}
