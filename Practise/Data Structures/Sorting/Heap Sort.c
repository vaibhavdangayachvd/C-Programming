#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
#define SENTINAL 9999
void heap_sort(int arr[],int size);
int get_max(int arr[],int *size);
void restore_down(int arr[],int size,int pos);
int main()
{
    int arr[MAX],n=0;
    system("cls");
    do
    {
        printf("Enter Size : ");
        scanf("%d",&n);
    }
    while(n<=0);
    arr[0]=SENTINAL;
    printf("Enter elements : ");
    for(int i=1;i<=n;++i)
        scanf("%d",&arr[i]);
    heap_sort(arr,n);
    printf("Sorted List : ");
    for(int i=1;i<=n;++i)
        printf("%d ",arr[i]);
    printf("\n\n\tPress Enter to exit...");
    getch();
    return 0;
}
void heap_sort(int arr[],int size)
{
    int max;
    for(int i=size/2;i>=1;--i)
        restore_down(arr,size,i);
    while(size>=1)
    {
        max=get_max(arr,&size);
        arr[size+1]=max;
    }
}
int get_max(int arr[],int *size)
{
    int max=arr[1];
    arr[1]=arr[(*size)--];
    restore_down(arr,*size,1);
    return max;
}
void restore_down(int arr[],int size,int pos)
{
    int left,right;
    int temp=arr[pos];
    left=pos*2;
    right=left+1;
    while(right<=size)
    {
        if(arr[left]<temp && arr[right]<temp)
        {
            arr[pos]=temp;
            return;
        }
        if(arr[left]>arr[right])
        {
            arr[pos]=arr[left];
            pos=left;
        }
        else
        {
            arr[pos]=arr[right];
            pos=right;
        }
        left=pos*2;
        right=left+1;
    }
    if(left==size && arr[left]>temp)
    {
        arr[pos]=arr[left];
        pos=left;
    }
    arr[pos]=temp;
}
