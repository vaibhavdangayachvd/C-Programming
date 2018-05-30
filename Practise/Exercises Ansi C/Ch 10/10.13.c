#include <stdio.h>
#include <conio.h>
struct details
{
    char name[20];
    char address[20];
    char grade;
    int charge;
    int rooms;
};
void scan(struct details[]);
void sort(struct details[]);
void grade(struct details[],char);
void charges(struct details[],int);
void main()
{
    struct details hotel[5];
    int i;
    char c;
    scan(hotel);
    printf("Enter grade : ");
    scanf(" %c",&c);
    sort(hotel);
    grade(hotel,c);
    printf("Enter Charge : ");
    scanf("%d",&i);
    charges(hotel,i);
    printf("Press Enter to exit....");
    getch();
}
void scan(struct details temp[])
{
    int i;
    for(i=0;i<5;++i)
    {
    printf("Enter Name of Hotel %d : ",i+1);
    scanf(" %[^\n]",temp[i].name);
    printf("Enter Address of Hotel %d : ",i+1);
    scanf(" %[^\n]",temp[i].address);
    printf("Enter Grade of Hotel %d : ",i+1);
    scanf(" %c",&temp[i].grade);
    printf("Enter Charge of Hotel %d : ",i+1);
    scanf("%d",&temp[i].charge);
    printf("Enter Rooms of Hotel %d : ",i+1);
    scanf("%d",&temp[i].rooms);
    printf("\n");
    }
    return;
}
void sort(struct details hotel[])
{
    struct details temp;
    int i,j;
    for(i=0;i<4;++i)
    {
        for(j=0;j<4-i;++j)
        {
            if(hotel[j].charge>hotel[j+1].charge)
            {
                temp = hotel[j];
                hotel[j]=hotel[j+1];
                hotel[j+1]=temp;
            }
        }
    }
    return;
}
void grade(struct details hotel[],char c)
{
    int i;
    for(i=0;i<5;++i)
    {
        if(hotel[i].grade==c)
        {
            printf("%s %d\n",hotel[i].name,hotel[i].charge);
        }
    }
    return;
}
void charges(struct details hotel[],int x)
{
    int i;
    for(i=0;i<5;++i)
    {
        if(hotel[i].charge<x)
        {
            printf("%s %d\n",hotel[i].name,hotel[i].charge);
        }
    }
    printf("\n");
    return;
}
