#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int table[26]={0},i,temp;
    char word[50];
    printf("Enter Word : ");
    scanf(" %[^\n]",word);
    for(i=0;i<strlen(word);++i)
    {
        if(word[i]==' ')
            continue;
        temp=word[i]%26;
        if(table[temp])
        {
            printf("Repeted word is %c",word[i]);
            break;
        }
        else
            table[temp]=1;
    }
    if(i==strlen(word))
        printf("No Repeted Letter !!!");
    return 0;
}
