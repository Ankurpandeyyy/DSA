#include<stdio.h>
#include<math.h>
int main()
{
    int p,r,t,n,x;
    float si,ci,ci1;
    printf("ENTER THE PRINCIPAL RATE AND TIME\n");
    scanf("%d\n%d\n%d",&p,&r,&t);
    si = p*r*t/100;
    printf("the value will be :- %f",si);
    printf("\nenter the value of n\n");
    scanf("%d",&n);
    ci1 = (1+r/n);
    x  = n*t;
    ci =p * pow(ci1,x);
    printf("\ncompound intrest will be :- %f ",ci);

    return 0;
}