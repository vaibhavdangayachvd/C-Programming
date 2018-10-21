#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    int i,common[13],rare[11],epic[8],leg[5],limit,total,test=1;
    char x;
    //Reading Common Card Values
    start:
    system("@cls||clear");
    limit=1,total=0;
    printf("Enter the levels of your common card\t\t\t\tTry %d\n\tEnter 0 to end this card type\n\n",test);
    for(i=0;i<8&&limit<=8;++i)
    {
        printf("Enter level of %d Common card : ",i+1);
        scanf("%d",&common[i]);
        if(common[i]>13)
        {
            printf("Error : Enter value between 1-13\n");
            --i;
            continue;
        }
        else if(common[i]==0)
        {
            break;
        }
        total+=common[i];
        limit++;
        if(limit>8)
        {
            goto end;
        }
    }
    //Reading Rare Card Values
    printf("\nEnter the levels of your rare card\n\tEnter 0 to end this card type\n\n");
    for(i=0;i<8&&limit<=8;++i)
    {
        printf("Enter level of %d Rare card : ",i+1);
        scanf("%d",&rare[i]);
        if(rare[i]>11)
        {
            printf("Error : Enter value between 1-11\n");
            --i;
            continue;
        }
        else if(rare[i]==0)
        {
            break;
        }
        else if(rare[i]>7)
        {
            rare[i]=9+rare[i]-7;
        }
        else if (rare[i]<7)
        {
            rare[i]=9-(7-rare[i]);
        }
        total+=rare[i];
        limit++;
        if(limit>8)
        {
            goto end;
        }
    }
    //Reading Epic Card Values
    printf("\nEnter the levels of your epic card\n\tEnter 0 to end this card type\n\n");
    for(i=0;i<8&&limit<=8;++i)
    {
        printf("Enter level of %d Epic card : ",i+1);
        scanf("%d",&epic[i]);
        if(epic[i]>8)
        {
            printf("Error : Enter value between 1-8\n");
            --i;
            continue;
        }
        else if(epic[i]==0)
        {
            break;
        }
        else if(epic[i]>4)
        {
            epic[i]=9+epic[i]-4;
        }
        else if (epic[i]<4)
        {
            epic[i]=9-(4-epic[i]);
        }
        total+=epic[i];
        limit++;
        if(limit>8)
        {
            goto end;
        }
    }
    //Reading Legendary Card Values
    printf("\nEnter the levels of your Legendary card\n\tEnter 0 to end this card type\n\n");
    for(i=0;i<5&&limit<=8;++i)
    {
        printf("Enter level of %d Legendary card : ",i+1);
        scanf("%d",&leg[i]);
        if(leg[i]>5)
        {
            printf("Error : Enter value between 1-5\n");
            --i;
            continue;
        }
        else if(leg[i]==0)
        {
             break;
        }
        if(leg[i]>1)
        {
            leg[i]=9+leg[i]-1;
        }
        total+=leg[i];
        limit++;
        if(limit>8)
        {
            goto end;
        }
    }
    //Printing Total
    end:
    printf("\n\tYour Total = %d/8 = %.2f\n\n",total,(float)total/8);
    ++test;
    printf("Press Enter to continue...");
    getch();
    goto start;
}
