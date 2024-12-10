/* WAP that finds whether a given number is even or odd.*/
#include <stdio.h>
int main ()
{
    int a;
    printf("enter the desired number:-");
    scanf("%d",&a);
     
     if (a%2==0)
     {
        printf("the given number is even");

     }
     else{printf(" the given number is odd");
     }
     return 0;
}