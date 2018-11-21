#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define PAT_PRICE 30
#define CHOW_PRICE 30
#define HOTDOG_PRICE 40
#define COST_PRICE 11000
struct menu
{
    int pat;
    int chow;
    int hotdog;
    int bill_amt;
};
void print_menu(void);
struct menu reset_order(struct menu person);
void print_order(struct menu person);
void outcome(int sales);
void append_order(struct menu person,int ord_num);
int main()
{
    struct menu person;
    FILE *fp=fopen("C:\\Users\\vaibh\\Desktop\\Sales.txt","w");
    fputs("Order Summary :-\n",fp);
    fclose(fp);
    int sales=0,ord_num=0;
    char order;
    printf("\t\t\t   Order Manager by VD\n\n");
    while(1)
    {
        print_menu();
        //initilize order with 0
        person=reset_order(person);
        //reset input
        order=0;
        //While Enter is not pressed
        while(order!=13)
        {
            order=getch();
            if(order=='x' || order=='X')
                break;
            switch(order)
            {
            case '1':
                person.pat++;
                person.bill_amt+=PAT_PRICE;
                printf("Paties Added !!(%d) ",person.pat);
                break;
            case '2':
                person.hotdog++;
                person.bill_amt+=HOTDOG_PRICE;
                printf("Hotdog Added !!(%d)",person.hotdog);
                break;
            case '3':
                person.chow++;
                person.bill_amt+=CHOW_PRICE;
                printf("Chowmein Paties Added !!(%d)",person.chow);
                break;
            case 8:
                person=reset_order(person);
                printf("Cancelled !!!\n\n");
                break;
            case 13:
                break;
            default:
                 printf("Wrong Input !! ");
            }
        }
        if(order=='x' || order=='X')
                break;
        sales+=person.bill_amt;//Set Total Sales
        printf("\n\n\tOrder Number - %d\n",++ord_num);
        print_order(person);
        printf("Total Sales : %d\n\n",sales);
        append_order(person,ord_num);//Append to file
    }
    printf("\nTotal Sales %d\n",sales);
    fclose(fp);
    outcome(sales);
    printf("\n\n\tPress Enter to exit...");
    getch();
    return 0;
}
void print_menu(void)
{
    printf("1 - Cheese Paties, ");
    printf("2 - Hotdog, ");
    printf("3 - Chowmein Paties ");
    printf("(Enter - Next order, ");
    printf("Backspace - Reset Order, ");
    printf("X - End)\n");
}
struct menu reset_order(struct menu person)
{
    person.pat=0;
    person.chow=0;
    person.hotdog=0;
    person.bill_amt=0;
    return person;
}
void print_order(struct menu person)
{
    if(person.pat)
        printf("Cheese - %d\n",person.pat);
    if(person.hotdog)
        printf("Hotdog - %d\n",person.hotdog);
    if(person.chow)
        printf("Chowmein - %d\n\n",person.chow);
    printf("\tBill Amount : %d\n\n",person.bill_amt);
}
void outcome(int sales)
{
    FILE *fp;
    fp=fopen("C:\\Users\\vaibh\\Desktop\\Sales.txt","a");
    fprintf(fp,"\nTotal Sales : %d\n",sales);
    if(sales < COST_PRICE)
    {
        printf("You Are in loss of %d\n",COST_PRICE-sales);
        fprintf(fp,"You Are in loss of %d\n",COST_PRICE-sales);
    }
    else if(sales > COST_PRICE)
    {
        printf("You are in profit of %d\n",sales-COST_PRICE);
        fprintf(fp,"You are in profit of %d\n",sales-COST_PRICE);
    }
    else
    {
        printf("No Profit No Loss\n");
        fputs("No Profit No Loss\n",fp);
    }
    fclose(fp);
}
void append_order(struct menu person,int ord_num)
{
    FILE *fp;
    fp=fopen("C:\\Users\\vaibh\\Desktop\\Sales.txt","a");
    fprintf(fp,"\n\tOrder Number - %d\n",ord_num);
    fprintf(fp,"Cheese - %d\n",person.pat);
    fprintf(fp,"Hotdog - %d\n",person.hotdog);
    fprintf(fp,"Chowmein - %d\n",person.chow);
    fprintf(fp,"\tBill Amount : %d\n",person.bill_amt);
    fclose(fp);
}
