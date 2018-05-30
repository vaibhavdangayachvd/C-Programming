#include <stdio.h>
#include <conio.h>
void main()
{
    int i,cand[6]={0},vote,winner,count;
    printf("Enter the votes of all candidates\n\tenter 0 to calculate\n\n->");
    //Calcultiong votes
    for(count=0;;++count)
    {
        scanf("%d",&vote);
        if(vote==0)
            break;
        switch(vote)
        {
        case 1:
            ++cand[1];
            break;
        case 2:
            ++cand[2];
            break;
        case 3:
            ++cand[3];
            break;
        case 4:
            ++cand[4];
            break;
        case 5:
            ++cand[5];
            break;
        default:
            ++cand[0];
            break;
        }
    }
    //Calculating winner
    for(i=1;i<=5;++i)
    {
        if(i==1)
        {
            winner=i;
            continue;
        }
        if(cand[i]>cand[winner])
            winner = i;
    }
    printf("\n");
    for(i=1;i<=5;++i)
    {
        printf("Candidate %d - %d Votes\n",i,cand[i]);
    }
    printf("\nSpoilt Ballots - %d\n",cand[0]);
    printf("Total votes casted - %d\n\n",count);
    printf("Winner = Candidate %d\n\n",winner);
    printf("Press Enter to continue...");
    getch();
}
