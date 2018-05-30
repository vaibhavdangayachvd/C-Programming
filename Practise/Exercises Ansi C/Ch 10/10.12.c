#include <stdio.h>
#include <conio.h>
#include <string.h>
struct sensus
{
    char name[10];
    int population;
};
struct sensus scan(struct sensus);
void sort(struct sensus[],int);
void main()
{
    int i;
    struct sensus city[5];
    for(i=0;i<5;++i)
    {
        city[i]=scan(city[i]);
        printf("\n");
    }
    printf("Enter 0 to sort by name , 1 to sort by population : ");
    scanf("%d",&i);
    sort(city,i);
}
struct sensus scan(struct sensus city)
{
    static int i=1;
    printf("Enter City %d Name : ",i);
    scanf("%s",city.name);
    printf("Enter City %d Population : ",i);
    scanf("%d",&city.population);
    ++i;
    return(city);
};
void sort(struct sensus city[],int l)
{
    int i,j,n,tempi;
    char tempc[20];
    for(i=0;i<4;++i)
    {
        for(j=0;j<4-i;++j)
        {
            if(l==0)
            {
            n = strcmp(city[j].name,city[j+1].name);
            if(n>0)
            {
                strcpy(tempc,city[j].name);
                strcpy(city[j].name,city[j+1].name);
                strcpy(city[j+1].name,tempc);
            }
            }
            else
            {
            if(city[j].population>city[j+1].population)
            {
                tempi=city[j].population;
                city[j].population=city[j+1].population;
                city[j+1].population=tempi;
            }
            }
        }
    }
    for(i=0;i<5;++i)
    {
        printf("%s - %d\n",city[i].name,city[i].population);
    }
}

