#include<stdio.h>
#include<conio.h>
#define MAX 100
void merge_pass(int arr[],int n);
void merge_sort(int arr[],int n,int size,int temp[]);
void merge(int arr[],int u1,int d1,int u2,int d2,int temp[]);
void copy_temp(int arr[],int temp[],int n);
int main()
{
    int i,arr[MAX],n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter array elements to sort : ");
    for(i=0;i<n;++i)
        scanf("%d",&arr[i]);
    merge_pass(arr,n);
    printf("Sorted Array : ");
    for(i=0;i<n;++i)
        printf("%d ",arr[i]);
    printf("\n\n\tPress Enter to exit...");
    getch();
    return 0;
}
void merge_pass(int arr[],int n)
{
    int size=1;
    int temp[MAX];
    while(size<n)
    {
        merge_sort(arr,n,size,temp);
        size*=2;
        merge_sort(temp,n,size,arr);
        size*=2;
    }
}
void merge_sort(int arr[],int n,int size,int temp[])
{
    int i,u1,d1,u2,d2;
    u1=0;
    while(u1+size<n)
    {
        d1=u1+size-1;
        u2=d1+1;
        d2=u2+size-1;
        if(d2>=n)
            d2=n-1;
        merge(arr,u1,d1,u2,d2,temp);
        u1=d2+1;
    }
    for(i=u1;i<n;++i)
        temp[i]=arr[i];
}
void merge(int arr[],int u1,int d1,int u2,int d2,int temp[])
{
    int i=u1;
    int j=u2;
    int k=u1;
    while(i<=d1 && j<=d2)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=d1)
        temp[k++]=arr[i++];
    while(j<=d2)
        temp[k++]=arr[j++];
}
