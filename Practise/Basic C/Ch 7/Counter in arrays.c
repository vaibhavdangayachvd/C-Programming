#include <stdio.h>
#include <conio.h>
void main()
{
    int i,j,car;
    char city;
    int freq[5][5]={{0},{0},{0},{0},{0}};
    printf("For each person , enter the city code\n");
    printf("followed by the car code.\nEnter the letter X to end\n");
    //Input values
    for(i=1;;++i)
    {
        scanf("%c",&city);
        if(city=='X')
            break;
        scanf("%d",&car);
        switch(city)
        {
        case 'M':
            ++freq[1][car];
            break;
        case 'D':
            ++freq[2][car];
            break;
        case 'C':
            ++freq[3][car];
            break;
        case 'B':
            ++freq[4][car];
            break;
        }
    }
    printf("\n\tPopularity Table\n\n");
    printf("---------------------------------------------\n");
    printf("City       Ambassdor  Fiat   Dolphin  Maruti\n");
    printf("---------------------------------------------\n");
    for(i=1;i<=4;++i)
    {
        switch(i)
        {
        case 1:
            printf("Madras   ");
            break;
        case 2:
            printf("Delhi    ");
            break;
        case 3:
            printf("Calcutta ");
            break;
        case 4:
            printf("Bombay   ");
            break;
        }
        for(j=1;j<=4;++j)
        {
            printf("%8d",freq[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------------------\n");
}
