//need other to be add
//contain data output code
#include <stdio.h>


int main()
{
    float I[50],T[50],C[50],G[50],Y[50];
    int year=2023,i,n;


    printf("Enter National Income for %d:",year);
    scanf("%f",&Y[0]);
    printf("Enter Government Expenditure for year %d:",year);
    scanf("%f",&G[0]);
    printf("Enter Number of Years to simulate:");
    scanf("%d",&n);
    printf("\n\t\t       National Economy Simulation\n\t\t\t          Using\n\t\t          Distributed Lag Model\n");
    printf("\n   Income [2021]: %.2f\t\t\t\t     Expenditure [2021]: %.2f\n",Y[0],G[0]);
        printf("\n   SN\tYear\tInvestment\tTax\tExpenditure\tConsumption\tIncome\n");
    printf("---------------------------------------------------------------------------------\n");

    for(i=1;i<=n;i++)
    {
        I[i]=2+0.1*Y[i-1];
        T[i]=0.2*Y[i-1];
        G[i]=0.15*G[i-1]+G[i-1];
        C[i]=45.45+2.27*(I[i]+G[i]);
        Y[i]=C[i]+I[i]+G[i];
        printf("   %d\t%d\t%.2f\t\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n",i,year+i,I[i],T[i],G[i],C[i],Y[i]);
    }
    printf("---------------------------------------------------------------------------------\n");
}
