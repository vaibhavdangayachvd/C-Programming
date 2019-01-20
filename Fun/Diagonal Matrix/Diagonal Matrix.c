#include<stdio.h>
#include<conio.h>
int main()
{
    int size;
    //read size
    printf("Enter Size : ");
    scanf("%d",&size);
    //Create a square matrix of given size
    int arr[size][size];
    //Upper Triangle
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size-i;++j)
        {
            //If first row
            if(i==0)
            {
                arr[0][0]=1;
                int temp=1;
                for(int k=1;k<size;++k)
                {
                    arr[i][k]=arr[i][k-1]+temp;
                    temp++;
                }
                break;
            }
            else
                arr[i][j]=arr[i-1][j+1]+1;
        }
    }
    //Lower Triangle
    for(int i=size-1;i>0;--i)
    {
        for(int j=size-1;j>0;--j)
        {
            //If last row
            if(i==size-1)
            {
                arr[size-1][size-1]=size*size;
                int temp=1;
                for(int k=size-2;k>0;--k)
                {
                    arr[i][k]=arr[i][k+1]-temp;
                    temp++;
                }
                break;
            }
            else
                arr[i][j]=arr[i+1][j-1]-1;
        }
    }
    //Display Array
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j)
            printf("%3d ",arr[i][j]);
        printf("\n");
    }
}
