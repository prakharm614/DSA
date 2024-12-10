#include<stdio.h>
int main()
{
    {
    int n;
    printf("enter the number of row : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
   {
     {
        for(int j=1;j<=n+1-i;j++)   //this is inverted triangle see the CONCEPT
                                      //here used is i+j=n+1 formula
        printf("* ");
    }
    printf("\n");
    }
    return 0;
}
   
}
// we have NOT used third variable in this case.
/*otherwise a third variable can be intrduced such that value of n is stored
  so that we can retain the value of n . this is helpful in number triangle*/