//Team Wise List Containing Name and Average of Player
#include <stdio.h>
#include <conio.h>
#include <string.h>
//Creating Structure
struct cricket
{
    char pname[20];
    char tname[20];
    int avg;
};
void scan(struct cricket[]); //Scan Structure Data
void sort(struct cricket[]); //Sort Structure Data Name Wise (A-Z)
void print(struct cricket[]); //Print Structure Data
void hold(void); //Hold Screen
void main()
{
	struct cricket player[5]; //Structure variable player
    scan(player); //Function call
    sort(player); //Function call
    print(player); //Function call
    hold(); //Function call
}
void scan(struct cricket player[])
{
    int i;
    for(i=0;i<5;++i)
    {
        printf("Enter Name of player %d : ",i+1);
        scanf("%[^\n]",player[i].pname);
        printf("Enter Team of player %d : ",i+1);
        scanf(" %s",player[i].tname);
        printf("Enter Average of player %d : ",i+1);
        scanf("%d",&player[i].avg);
        printf("\n");
    }
    return;
}
void sort(struct cricket player[])
{
    struct cricket temp;
    int i,j;
    //Bubble Sort
	for(i=0;i<4;++i)
    {
        for(j=0;j<4-i;++j)
        {
            if(strcmp(player[j].tname,player[j+1].tname)>0)
            {
                temp=player[j];
                player[j]=player[j+1];
                player[j+1]=temp;
            }
        }
    }
    return;
}
void print(struct cricket player[])
{
    int i;
    printf("%s :-\n",player[0].tname);
    for(i=0;i<5;++i)
    {
        printf("%s %s %d\n",player[i].pname,player[i].tname,player[i].avg);
        if(strcmp(player[i].tname,player[i+1].tname)!=0&&i!=4)
        {
            printf("\n");
            printf("%s :-\n",player[i+1].tname);
        }
    }
    return;
}
void hold(void)
{
    printf("Press Enter to continue...");
    getch();
}
