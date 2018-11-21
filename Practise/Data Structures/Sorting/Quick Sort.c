#include<stdio.h>
#include<conio.h>
#define MAX 100
void quick_sort(int arr[],int start,int end);
int get_piv(int arr[],int low,int up);
int main()
{
    int arr[MAX],n=0;
    do
    {
        printf("Enter Size : ");
        scanf("%d",&n);
    }
    while(n<=0);
    printf("Enter array Elements : ");
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    printf("Sorted Array : ");
    for(int i=0;i<n;++i)
        printf("%d ",arr[i]);
    printf("\n\n\tPress Enter to exit...");
    getch();
    return 0;
}
void quick_sort(int arr[],int start,int end)
{
    int piv_loc;
    if(start>=end)
        return;
    piv_loc=get_piv(arr,start,end);
    quick_sort(arr,start,piv_loc-1);
    quick_sort(arr,piv_loc+1,end);
}
int get_piv(int arr[],int low,int up)
{
    int i=low+1;
    int j=up;
    int temp;
    while(i<=j)
    {
        while(arr[i]<arr[low] && i<up)
            ++i;
        while(arr[j]>arr[low])
            --j;
        if(i>=j)
            break;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
