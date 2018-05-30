//StrStr without Function
#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
    char input[20],search[20];
    int i,j,length_input,length_search,flag=0;
    printf("Enter string : ");
    gets(input);
    printf("Enter key to find : ");
    gets(search);
    length_input=strlen(input);
    length_search=strlen(search);
    for(i=0;i<=(length_input-length_search);++i)
    {
        if(search[0]==input[i])
        {
           for(j=1;j<length_search;++j)
           {
               if(search[j]!= input[i+j])
               {
                   flag = 0;
                   break;
               }
               flag = 1;
           }
           if(flag==1)
           {
               printf("\nKey present in the string\n\n");
               break;
           }
           else
           {
               continue;
           }
        }
    }
    if(flag==0)
    {
        printf("\nKey not found\n\n");
    }
    printf("\t\t\t   Press Enter to exit...");
    getch();
}
