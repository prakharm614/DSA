/*to determine prime numbers*/
#include <stdio.h>
int main ()
{
    int p,div1,div2,div3,div4;

    printf("Enter the number p=");
    scanf("%d",&p);
    div1=p%2;
    div2=p%3;
    div3=p%5;
    div4=p%7;
    
    if (p==1 || p==0)
    {
        printf("The number is neither prime nor composite.");
    }
    else if (div1==0 && p!=2)
    {
        printf("The entered number is not a prime number.");
    }
     else if (div2==0 && p!=3)
     {
        printf("The number is  not a prime number. ");
     }
     else if (div3==0 && p!=5)
     {
        printf("The number is not a prime number.");
     }
     else if ( div4==0 && p!=7)
     {
        printf("The number is not a prime number");
     }
     else
      {
        printf("The entered number is prime number");
     }
     return 0;
}