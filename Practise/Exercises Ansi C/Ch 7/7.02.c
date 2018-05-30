#include <stdio.h>
#include <conio.h>
#define DAY 5
#define CITY 5
void main()
{
    int i,j,temp[DAY][CITY],max,min,t,minday=1,mincity=1,maxday=1,maxcity=1;
    printf("Enter the value of temperature day-wise\n->");
    //Scanning Temperature
    for(i=0;i<DAY;++i)
    {
        for(j=0;j<CITY;++j)
        {
            scanf("%d",&temp[i][j]);
        }
    }
    //Computing Maximum and Minimum
    for(i=0;i<DAY;++i)
    {
        for(j=0;j<CITY;++j)
        {
            if(i==0&&j==0)
            {
                min=temp[i][j];
                max=temp[i][j];
                continue;
            }
            t=temp[i][j];
            if(t<min)
            {
                min = t;
                minday = i+1;
                mincity = j+1;
            }
            else if(t>max)
            {
                max=t;
                maxday=i+1;
                maxcity=j+1;
            }
        }
    }
    //printing Output
    printf("\n\tTemperature Table\n\n");
    printf("    City->\n\n");
    printf("Day   ");
    for(j=1;j<=CITY;++j)
    {
        printf("%3d ",j);
    }
    printf("\n");
    printf("\\/ \n");
    printf("--------------------------------------------------------\n");
    for(i=0;i<DAY;++i)
    {
        printf("%2d |  ",i+1);
        for(j=0;j<CITY;++j)
        {
            printf("%3d ",temp[i][j]);
        }
        printf("\n");
    }
    printf("--------------------------------------------------------\n\n");
    printf("Minimum Day,City = Day %d , City %d \n",minday,mincity);
    printf("Maximum Day,City = Day %d , City %d\n\n",maxday,maxcity);
    printf("Press Enter to continue...");
    getch();
}
