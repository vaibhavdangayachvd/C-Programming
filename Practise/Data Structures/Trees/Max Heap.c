#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 9999
void insert(int[],int,int *);
void move_up(int[],int);
void display(int[],int);
void del(int[],int *);
void move_bottom(int[],int,int);
int main()
{
    int heap[100],hsize=0,num;
    char option;
    heap[0]=MAX;
    while(1)
    {
        system("cls");
        printf("Choose Option :-\n1 - Insert\n2 - Display\n3 - Delete Root\n->");
        option = getch();
        system("cls");
        switch(option)
        {
        case '1':
            printf("Enter num to insert : ");
            scanf("%d",&num);
            insert(heap,num,&hsize);
            printf("Data Inserted !!!");
            getch();
            break;
        case '2':
            display(heap,hsize);
            getch();
            break;
        case '3':
            if(hsize==0)
                break;
            del(heap,&hsize);
            break;
        case 8:
            return 0;
        }
    }
}
void insert(int arr[],int num,int *hsize)
{
    arr[++*hsize]=num;
    move_up(arr,*hsize);
}
void move_up(int arr[],int i)
{
    int k,par;
    k = arr[i];
    par=i/2;
    while(arr[par]<k)
    {
        arr[i]=arr[par];
        i = par;
        par=i/2;
    }
    arr[i]=k;
}
void display(int heap[],int hsize)
{
    int i;
    for(i=1;i<=hsize;++i)
    {
        printf("%d ",heap[i]);
    }
}
void del(int arr[],int *hsize)
{
    int temp;
    temp=arr[1];
    arr[1]=arr[*hsize];
    (*hsize)--;
    move_bottom(arr,*hsize,1);
    printf("%d",temp);
}
void move_bottom(int arr[],int h_size,int i)
{
    int left=i*2;
    int right=left+1;
    int num=arr[i];
    while(right<=h_size)
    {
        if(arr[left] <=num && arr[right] <= num)
        {
            arr[i]=num;
            return;
        }
        else if(arr[left]>arr[right])
        {
            arr[i]=arr[left];
            i=left;
        }
        else
        {
            arr[i]=arr[right];
            i=right;
        }
        left=i*2;
        right=left+1;
    }
    if(left==h_size&&arr[left]>num)
    {
        arr[i]=arr[left];
        i=left;
    }
    arr[i]=num;
}
