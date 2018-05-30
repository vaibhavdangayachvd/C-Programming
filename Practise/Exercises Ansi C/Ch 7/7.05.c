#include <stdio.h>
#include <conio.h>
#define ROLL 5
#define SUB 3
void main()
{

	//Declaration
	int i,j; //Counter
    int marks[ROLL][SUB]={{0},{0},{0}},total_marks[ROLL]={0},highest_subject[SUB],highest_subject_roll[SUB]; //Arrays
    int highest_total,highest_total_roll; //Highest
    printf("Enter marks of each students subject wise\n->");

	//Reading Marks
    for(i=0;i<ROLL;++i)
    {
        for(j=0;j<SUB;++j)
        {
            scanf("%d",&marks[i][j]);
        }
    }

	//Total Marks
    for(i=0;i<ROLL;++i)
    {
        for(j=0;j<SUB;++j)
        {
            total_marks[i]+=marks[i][j];
        }
    }

	//Highest Total and Its Roll Number
    for(i=0;i<ROLL;++i)
    {
        if(i==0)
        {
            highest_total=total_marks[i];
            highest_total_roll=i+1;
            continue;
        }
        if(total_marks[i]>highest_total)
        {
            highest_total=total_marks[i];
            highest_total_roll=i+1;
        }
    }

	//Maximum per subject marks and its roll numbers
    for(j=0;j<SUB;++j)
    {
        for(i=0;i<ROLL;++i)
        {
            if(i==0)
            {
                highest_subject[j]=marks[i][j];
                highest_subject_roll[j]=i+1;
                continue;
            }
            if(marks[i][j]>highest_subject[j])
            {
                highest_subject[j] = marks[i][j];
                highest_subject_roll[j]=i+1;
            }
        }
    }

	//Printing begin
    //Table
    printf("\n\tAnnual Result\n");
    printf("--------------------------------------------------------------\n");
    printf("Roll No  ");
    for(j=1;j<=SUB;++j)
    {
        printf("Subject %d  ",j);
    }
    printf("\n");
    printf("--------------------------------------------------------------\n");
    for(i=0;i<ROLL;++i)
    {
        printf("Roll %d     ",i+1);
        for(j=0;j<SUB;++j)
        {
            printf("%3d         ",marks[i][j]);
        }
        printf("\n");
    }
    printf("--------------------------------------------------------------\n");
    printf("\n");

	//Printing Total Marks of each roll number
    for(i=0;i<ROLL;++i)
    {
        printf("Total marks of Roll %d = %d\n",i+1,total_marks[i]);
    }

	//Highest total marks
    printf("\nRoll %d scored the highest total marks i.e %d\n\n",highest_total_roll,highest_total);

	//Highest marks of each subject
    for(j=0;j<SUB;++j)
    {
        printf("Hightest marks of Subject %d is %d by Roll NO %d\n\n",j+1,highest_subject[j],highest_subject_roll[j]);
    }

	printf("Press Enter to continue...");
    getch();
}
