/*WAP to find the greatest of three numbers.*/
#include <stdio.h>
int main()
{
    int a,b,c;
    printf("enter the value of a:-");
    scanf("%d",&a);
    printf("enter the value of b:-");
    scanf("%d",&b);
    printf("enter the value of c:-");
    scanf("%d",&c);
    if (a>b && a>c)
    {
        printf("a is the largest among the three.");
    }
    else if (b>c && b>a)
    {
        printf("b is greatest among the three.");
    }
    else 
    {
        printf("c is greatest among the three.");
    }
    return 0;
}



