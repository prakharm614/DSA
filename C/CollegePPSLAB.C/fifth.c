/* WAP that checks whether the two numbers entered by the user 
are equal or not.*/
#include <stdio.h>
int main ()
{
    int a,b;
    printf("enter the value of a=");
    scanf("%d",&a);
    printf("enter the vaue of b=");
    scanf("%d",&b);
    if (a==b)
    {
        printf("both the numbers are equal!!");
    }
    else{
        printf("the numbers are not equal");
    }
    return 0;
}