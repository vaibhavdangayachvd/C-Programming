#include <stdio.h>
#include <conio.h>
void main()
{
    char answer[8]="Vaibhav",entry[100];
    int i,n;
    printf("What is your name?\n");
    for(i=1;i<=3;++i)
    {
        printf("Try %d : Input Answer : ",i);
        scanf("%s",entry);
        n = strcmp(answer,entry);
        if(n==0)
        {
            printf("Correct Answer");
            break;
        }
        else
        {
            printf("Wrong Answer\n");
            continue;
        }
    }
}
