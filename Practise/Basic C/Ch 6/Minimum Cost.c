/*Minimum Cost*/
#include <stdio.h>
int main()
{
    float p,cost,p1,cost1;
    for(p=0;p<=10;p+=0.1)
    {
        cost=40-(8*p)+(p*p);
        if(!p)
        {
            cost1=cost;
            continue;
        }
        if(cost>=cost1)
            break;
        cost1=cost;
        p1=p;
    }
    //p=(p+p1)/2.0;
    //cost = 40-8*p+p*p;
    printf("\nMINIMUM COST = %.2f AT p = %.1f\n",cost1,p1);
}

