#include <stdio.h>

int main()
{
    int i,o,n;
    float p[2][2]={{0.8,0.2},{0.1,0.9}},x0=0,x1=0,a,b;
    printf("Coke : 1 \nPepsi: 2 \nEnter your choice: ");
    scanf("%d",&o);
    if(o==1){
        x0 = 1.0;
        x1 = 0.0;
    }
    else{
        x0=0.0;
        x1=1.0;
    }
    a=x0;
    b=x1;


    printf("Enter the value of n: ");
    scanf("%d",&n);

    for(i = 1; i <= n;i++){

        x0 = (a * p[0][0]) + (b * p[1][0]);
        x1 = (a * p[0][1]) + (b * p[1][1]);
        a=x0;
        b=x1;


        if(x0 >= x1){
            printf("\n Day %d => Coke ( coke:%.2f pepsi:%.2f )",i,x0,x1);
        }
        else{
            printf("\n Day %d => Pepsi ( coke:%.2f pepsi:%.2f )",i,x0,x1);
        }

    }

    return 0;
}
