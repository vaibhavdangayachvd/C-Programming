//Zero Cross
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void check(char [][3]);
void print(char[][3]);
void main()
{
    int row,col,count=0;
    char game[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    printf("\t\t\t    Zero Cross\n\n");
    printf("Game Start !! Player 1 = X(cross), Player 2 = 0(Zero)\n\n");
    while(count < 9)
    {
        print(game);
        if(count%2==0)
        {
            jump1:
            printf("Enter your choice player 1(row,col) : ");
            scanf("%d %d",&row,&col);
            if(game[row-1][col-1]!= '-'||row>3||col>3)
            {
                printf("Enter correct input !! Try Again\n");
                goto jump1;
            }
        }
        else
        {
            jump2:
            printf("Enter your choice player 2(row,col) : ");
            scanf("%d %d",&row,&col);
            if(game[row-1][col-1]!= '-'||row>3||col>3)
            {
                printf("Enter correct input !! Try Again\n");
                goto jump2;
            }
        }
        if(count%2==0)
        {
            game[row-1][col-1]='X';
        }
        else
        {
            game[row-1][col-1]='O';
        }
        check(game);
        ++count;
        system("cls");
        printf("Tic Tack Toe\n\n");
        if(count==9)
        {
            system("cls");
            printf("Game Draw !!!\n\n");
            print(game);
        }
    }
    printf("Press Enter to exit...");
    getch();
}
void print(char game[][3])
{
    int i,j;
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
                printf("%c     |     ",game[i][j]);
        }
        printf("\n\n\n\n\n");
    }
    return;
}
void check(char game[][3])
{
    int win=0;
    char c;
    if(game[0][0]==game[0][1]&&game[0][1]==game[0][2]&&game[0][0]!='-')
        win=1,c = game[0][0];
    else if(game[1][0]==game[1][1]&&game[1][1]==game[1][2]&&game[1][0]!='-')
        win=1,c = game[1][0];
    else if(game[2][0]==game[2][1]&&game[2][1]==game[2][2]&&game[2][0]!='-')
        win=1,c = c=game[2][0];
    else if(game[0][0]==game[1][0]&&game[1][0]==game[2][0]&&game[0][0]!='-')
        win=1,c = game[0][0];
    else if(game[0][1]==game[1][1]&&game[1][1]==game[2][1]&&game[0][1]!='-')
        win=1,c = game[0][1];
    else if(game[0][2]==game[1][2]&&game[1][2]==game[2][2]&&game[0][2]!='-')
        win=1,c = game[0][2];
    else if(game[0][0]==game[1][1]&&game[1][1]==game[2][2]&&game[0][0]!='-')
        win=1,c = game[0][0];
    else if(game[0][2]==game[1][1]&&game[1][1]==game[2][0]&&game[0][2]!='-')
        win=1,c = game[0][2];
    if(win==0)
        return;
    system("cls");
    if(c == 'X')
        printf("Player 1 is Winner\n\n");
    else
        printf("Player 2 is Winner\n\n");\
    print(game);
    printf("\t\t\t   Press Enter to exit...");
    getch();
    exit(0);
}
