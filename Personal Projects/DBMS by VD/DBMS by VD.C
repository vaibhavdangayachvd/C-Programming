/**
    Purpose: Manage database of students of a class efficiently
    through linked list.
    #created 11/03/18

    @author Vaibhav As VD
    @version 2.0 (01/04/18)
    @version 3.0 (02/05/18)
	         3.1 (02/05/18 - 4.23AM)

    Change log :-
    v2 - added database file for storing data
       - minor changes
       - better user side documentation
    v3
       -password protection
       -star password format
       -add or remove password
	v3.1   
	   -password saved in secure location
	   -delete typed character
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct details
{
    int roll;
    char name[20];
    struct details *next;
};
typedef struct details node;
void load(node *,FILE *);
void create(node *);
void print(node *);
node *rem(node *);
node *insert(node *);
node *search(node *);
node *del(node*);
node *ser(node*,int);
void append(node *head,FILE *);
void ser_stu(node*);
void end(node*);
void pass(FILE *);
void set_pw(FILE *);
void rem_pw(FILE *);
int main()
{
    int a;
    node *head;
    FILE *f1;
    system("cls");
	head = (node*)malloc(sizeof(node));
    head->next=NULL;
    f1 = fopen("database","r");
    if(f1==NULL)
    {
        f1=fopen("database","w");
        printf("Database not Found!!\nCreating database..........\n\nCreate Successful !!!\n\n\t\t\t     Press Enter to continue.....");
        fclose(f1);
        getch();
    }
    else
    {
        fclose(f1);
        load(head,f1);
    }
    f1 = fopen("C:\\WINDOWS\\password","r");
    if(f1!=NULL)
    {
        fclose(f1);
        pass(f1);
    }
    start:
    system("cls");
    printf("Welcome to DBMS by VD :-\n\n\n");
    printf("Choose option :-\n\n");
    printf("1 - Create List\n2 - Print List\n3 - Remove List\n4 - Add student\n5 - Delete Student\n6 - Search Student\n7 - Create Password\n8 - Remove Password\n9 - Exit\n->");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        create(head);
        append(head,f1);
	    break;
    case 2:
	    system("cls");
	    print(head);
	    break;
    case 3:
	    head=rem(head);
	    append(head,f1);
	    break;
    case 4:
	    head = insert(head);
	    append(head,f1);
	    break;
    case 5:
	    head = del(head);
	    append(head,f1);
	    break;
    case 6:
	    ser_stu(head);
	    break;
    case 7:
	    set_pw(f1);
	    break;
    case 8:
        rem_pw(f1);
        break;
    case 9:
        end(head);
        break;
    default:
	    printf("You have entered wrong input !!! Try Again !!\n");
	    printf("Press Enter to try again...");
	    getch();
	    goto start;
    }
    goto start;
    return 0;
}
void create(node *head)
{
    system("cls");
    static int i=1;
    if(head->next!=NULL&&i==1)
    {
	    printf("List already present !!!\n\nPress Enter to go back...");
	    getch();
	    return;
    }
    jump:
    system("cls");
    printf("Last Entered Roll Number : %d\n\n",i-1);
    printf("Enter Roll No of Student(-999 to end) : ");
    scanf(" %d",&head->roll);
    if(head->roll==-999)
    {
	    head->next=NULL;
        printf("Data stored !!!\n\nPress Enter to go back...");
	    i=1;
	    getch();
	    return;
    }
    else if(head->roll!=i)
    {
       printf("Enter correct roll number!!! Press Enter to try again...");
       getch();
       goto jump;
    }
    printf("Enter name of student : ");
    scanf(" %s",head->name);
    head->next=(node*)malloc(sizeof(node));
    ++i;
    create(head->next);
}
void print(node *head)
{
    if(head->next!=NULL)
    {
	    printf("%s - %d\n",head->name,head->roll);
	    print(head->next);
    }
    else
    {
	    printf("\nPress Enter to go back...");
	    getch();
	    return;
    }
}
node *rem(node *head)
{
    int i;
    char a[8];
    jump:
    system("cls");
    printf("Are you sure you want to remove complete table? 0 - NO , 1 - Yes\n->");
    scanf(" %d",&i);
    if(i==1)
    {
	    printf("Type CONFIRM : ");
	    scanf(" %s",a);
	    i = strcmp(a,"CONFIRM");
	    if(i==0)
	    {
	        free(head);
	        head = (node*)malloc(sizeof(node));
	        printf("Data Deleted !! \n\nPress Enter to go back...");
	        head->next=NULL;
	        getch();
	        return head;
	    }
	    else
	    {
	        printf("Wrong Captch !! Press Enter to try again !!\n");
	        getch();
	        goto jump;
	    }
    }
    else
    {
	    printf("Press Enter to go back...");
	    getch();
	    return head;
    }
}
node *insert(node *head)
{

    node *p1,*p2;
    int r;
    char n[20];
    system("cls");
    printf("Enter -999 to exit without adding else enter anything to continue.\n->");
    scanf("%d",&r);
    if(r==-999)
    {
	    return head;
    }
    p2 = search(head);
    jump:
    system("cls");
    printf("Last Entered Roll Number : %d\n\n",p2->roll);
    printf("Enter roll number of new student : ");
    scanf(" %d",&r);
    printf("Enter name of new student : ");
    scanf(" %s",n);
    if(p2->roll!=r-1)
    {
	    printf("Wrong Input !! Press Enter to try again");
	    getch();
	    goto jump;
    }
    p1=(node*)malloc(sizeof(node));
    p1->roll=r;
    strcpy(p1->name,n);
    p1->next=p2->next;
    p2->next=p1;
    printf("Data Inserted !!!\nPress Enter to go back....");
    getch();
    return head;
}
node *search(node *head)
{
    if(head->next->next==NULL)
	    return(head);
    else
    {
        head = search(head->next);
	    return head;
    }
}
node *del(node*head)
{
    int key;
    node *p1,*p2;
    system("cls");
    printf("Enter -999 to exit without adding else enter anything to continue.\n->");
    scanf("%d",&key);
    if(key==-999)
    {
	    return head;
    }
    p2 = search(head);
    jump:
    system("cls");
    printf("Last Entered Roll Number : %d\n\n",p2->roll);
    printf("Enter the roll number you want to delete : ");
    scanf("%d",&key);
    p2 = search(head);
    if(p2->roll<key)
    {
	    printf("Wrong Input!! Press Enter to Try Again !!");
	    getch();
	    goto jump;
    }
    if(head->roll==key)
    {
        p2=head->next;
	    free(head);
	    head=p2;
	    while(p2->next!=NULL)
	    {
            (p2->roll)--;
	        p2=p2->next;
	    }
    }
    else
    {
	    p2 = ser(head,key);
	    p1=p2->next->next;
	    free(p2->next);
	    p2->next=p1;
        while(p1->next!=NULL)
	    {
            (p1->roll)--;
	        p1=p1->next;
	    }
    }
    printf("Data Deleted !!!\nPress Enter to go back....");
    getch();
    return head;
}
node *ser(node*head,int key)
{
    if(head->next->roll==key)
	    return head;
    else
    {
	    head = ser(head->next,key);
	    return head;
    }
}
void ser_stu(node*head)
{
    int key;
    node *p;
    p = head;
    system("cls");
    printf("Enter -999 to exit without searching else enter anything to continue.\n->");
    scanf(" %d",&key);
    if(key==-999)
    {
        return;
    }
    jump:
    head = p;
    system("cls");
    printf("Enter the roll number you want to search : ");
    scanf(" %d",&key);
    while(head->next!=NULL)
    {
	    if(head->roll==key)
        {
	        printf("%s - %d\n\n",head->name,head->roll);
	        break;
	    }
	    head = head->next;
    }
    if(head->next==NULL)
    {
	    printf("Data not found !!!\n\nPress Enter to try again...");
	    getch();
	    goto jump;
    }
    printf("Press Enter to go back...");
    getch();
    return;
}
void end(node *head)
{
    int i;
    system("cls");
    printf("Are you sure you want to exit? 0 - NO , 1 - Yes\n->");
    scanf(" %d",&i);
    if(i==1)
	{
	    free(head);
	    exit(0);
	}
    else
        return;
}
void append(node *head,FILE *f1)
{
        if(head->next==NULL)
        {
            f1=fopen("database","w");
            fclose(f1);
        }
        else
        {
            f1=fopen("database","w");
            while(head->next!=NULL)
            {
                fprintf(f1,"%d %s\n",head->roll,head->name);
                head=head->next;
            }
            fclose(f1);
        }
}
void load(node *head,FILE *f1)
{
    node p1;
    f1=fopen("database","r");
    while(head)
    {
        fscanf(f1,"%d %s",&p1.roll,&p1.name);
        if(feof(f1))
        {
            head->next=NULL;
            printf("Data Found!!\nLoading data..........\n\nLoad Successful !!!\n\n\t\t\t     Press Enter to continue.....");
            getch();
            return;
        }
        head->roll=p1.roll;
        strcpy(head->name,p1.name);
        head->next=(node*)malloc(sizeof(node));
        head=head->next;
    }
}
void pass(FILE *f1)
{
    char pass[20],c,check[20];
    int i=0,j;
    system("cls");
    f1=fopen("C:\\WINDOWS\\password","r");
    c=getc(f1);
    if(feof(f1))
        return;
    rewind(f1);
    while((c=getc(f1))!=EOF)
    {
        pass[i]=c;
        ++i;
    }
    pass[i]='\0';
    printf("Enter password\n->");
    i=-1;
    while(1)
    {
        c=getch();
        if(c==13)
            break;
        else if(c==8)
        {
            system("cls");
            printf("Enter password\n->");
            for(j=0;j<i;++j)
            {
                putchar('*');
            }
            if(i==-1)
                continue;
            else
                i--;
            continue;
        }
        i=i+1;
        check[i]=c;
        system("cls");
        printf("Enter password\n->");
        for(j=0;j<i;++j)
        {
            putchar('*');
        }
        putchar(c);
    }
    check[i+1]='\0';
    if((strcmp(pass,check))==0)
    {
        printf("\nAccess Granted !!!!!\n\n\t\t\t     Press Enter to continue.....");
        getch();
    }
    else
    {
        printf("\nWrong Password !!! Access Denied !!!!\n\n\t\t\t     Press Enter to exit.....");
        getch();
        exit(1);
    }
}
void rem_pw(FILE *f1)
{
    char c,pass[20],check[20];
    int i=0,j;
    system("cls");
    f1=fopen("C:\\WINDOWS\\password","r");
    c=getc(f1);
    if(feof(f1))
    {
        fclose(f1);
        printf("No Password Set !!!\n\n\t\t\t     Press Enter to continue.....");
        getch();
        return;
    }
    fclose(f1);
    f1=fopen("C:\\WINDOWS\\password","r");
    while((c=getc(f1))!=EOF)
    {
        pass[i]=c;
        ++i;
    }
    fclose(f1);
    pass[i]='\0';
    printf("Enter old password\n->");
    i=-1;
    while(1)
    {
        c=getch();
        if(c==13)
            break;
        else if(c==8)
        {
            system("cls");
            printf("Enter old password\n->");
            for(j=0;j<i;++j)
            {
                putchar('*');
            }
            if(i==-1)
                continue;
            else
                i--;
            continue;
        }
        i=i+1;
        check[i]=c;
        system("cls");
        printf("Enter old password\n->");
        for(j=0;j<i;++j)
        {
            putchar('*');
        }
        putchar(c);
    }
    check[i+1]='\0';
    if((strcmp(pass,check))==0)
    {
        f1=fopen("C:\\WINDOWS\\password","w");
        fclose(f1);
        printf("\nPassword Removed !!!!!\n\n\t\t\t     Press Enter to continue.....");
        getch();
    }
    else
    {
        printf("\nWrong Password !!!!\n\n\t\t\t     Press Enter to continue.....");
        getch();
        return;
    }
}
void set_pw(FILE *f1)
{
    char c,i=0,pass[20],check[20],j;
    system("cls");
    f1=fopen("C:\\WINDOWS\\password","r");
    if(f1==NULL)
    {
        printf("Enter new password\n->");
        i=-1;
        while(1)
        {
            c=getch();
            if(c==13)
                break;
            else if(c==8)
            {
                system("cls");
                printf("Enter new password\n->");
                for(j=0;j<i;++j)
                {
                    putchar('*');
                }
                if(i==-1)
                    continue;
                else
                    i--;
                continue;
            }
            i=i+1;
            pass[i]=c;
            system("cls");
            printf("Enter new password\n->");
            for(j=0;j<i;++j)
            {
                putchar('*');
            }
            putchar(c);
        }
        pass[i+1]='\0';
        system("cls");
        printf("Re-Enter password\n->");
        i=-1;
        while(1)
        {
            c=getch();
            if(c==13)
                break;
            else if(c==8)
            {
                system("cls");
                printf("Re-Enter password\n->");
                for(j=0;j<i;++j)
                {
                    putchar('*');
                }
                if(i==-1)
                    continue;
                else
                    i--;
                continue;
            }
            i=i+1;
            check[i]=c;
            system("cls");
            printf("Re-Enter password\n->");
            for(j=0;j<i;++j)
            {
                putchar('*');
            }
            putchar(c);
        }
        check[i+1]='\0';
        i=0;
        if((strcmp(pass,check))==0)
        {
            f1=fopen("C:\\WINDOWS\\password","w");
            while(pass[i]!='\0')
            {
                putc(pass[i],f1);
                ++i;
            }
            fclose(f1);
            printf("\nPassword Successfully Set !!!\n\n\t\t\t     Press Enter to continue.....");
            getch();
            return;
        }
        else
        {
            printf("\nPasswords do not match !!!! \n\n\t\t\t     Press Enter to exit.....");
            getch();
            return;
        }
    }
    else
    {
        c=getc(f1);
        if(feof(f1))
        {
            printf("Enter new password\n->");
            i=-1;
            while(1)
            {
                c=getch();
                if(c==13)
                    break;
                else if(c==8)
                {
                    system("cls");
                    printf("Enter new password\n->");
                    for(j=0;j<i;++j)
                    {
                        putchar('*');
                    }
                    if(i==-1)
                        continue;
                    else
                        i--;
                    continue;
                }
                i=i+1;
                pass[i]=c;
                system("cls");
                printf("Enter new password\n->");
                for(j=0;j<i;++j)
                {
                    putchar('*');
                }
                putchar(c);
            }
            pass[i+1]='\0';
            system("cls");
            printf("Re-Enter password\n->");
            i=-1;
            while(1)
            {
                c=getch();
                if(c==13)
                    break;
                else if(c==8)
                {
                    system("cls");
                    printf("Re-Enter password\n->");
                    for(j=0;j<i;++j)
                    {
                        putchar('*');
                    }
                    if(i==-1)
                        continue;
                    else
                        i--;
                    continue;
                }
                i=i+1;
                check[i]=c;
                system("cls");
                printf("Re-Enter password\n->");
                for(j=0;j<i;++j)
                {
                    putchar('*');
                }
                putchar(c);
            }
            check[i+1]='\0';
            i=0;
            if((strcmp(pass,check))==0)
            {
                f1=fopen("C:\\WINDOWS\\password","w");
                while(pass[i]!='\0')
                {
                    putc(pass[i],f1);
                    ++i;
                }
                fclose(f1);
                printf("\nPassword Successfully Set !!!\n\n\t\t\t     Press Enter to continue.....");
                getch();
                return;
            }
            else
            {
                printf("\nPasswords no not match !!!! \n\n\t\t\t     Press Enter to exit.....");
                getch();
                return;
            }
        }
        else
        {
            printf("Password Already Set !!!\n\n\t\t\t     Press Enter to exit..... ");
            getch();
            return;
        }
    }
}
