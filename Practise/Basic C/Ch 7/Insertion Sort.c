//Insertion sort
#include<stdio.h>
#include<conio.h>
void sort(int[],int);
int main()
{
    int i,a[100],size;
    printf("Enter size : ");
    scanf("%d",&size);
    printf("Enter array elements to sort\n->");
    for(i=0;i<size;++i)
        scanf("%d",&a[i]);
    sort(a,size);
    printf("Sorted Elements : ");
    for(i=0;i<size;++i)
        printf("%d ",a[i]);
    return 0;
}
void sort(int a[],int size)
{
    int i,j,k,temp;
    for(i=1;i<size;++i)
    {
        temp=a[i];
        if(a[i]>a[i-1])
            continue;
        for(j=0;j<i;++j)
        {
            if(a[i]<a[j])
            {
                for(k=size-1;k>=j;--k)
                    a[k+1]=a[k];
                a[j]=temp;
                for(k=i;k<size;++k)
                    a[k]=a[k+1];
                break;
            }
        }
    }
}
