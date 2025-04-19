#include<stdio.h>
int main()
{
    int x,a,b,c,num=0, temp;
    printf("Enter the number for checking ....\n");
    scanf("%d",&x);
    temp = x;
    a = x % 10;
    x = x/ 10;
    b = x % 10;
    c = x/10;
    num = a*100 + b*10 + c*1;
    if(num == temp)
       printf("\n %d is a palindrome number",temp);
    else
       printf("\n %d is not a palindrome number",temp);
 return 0;

}