// we will make number triangle of odd numbers so that concept is well aplied
#include<stdio.h>
int main ()
{
    int n;
    printf("enter the number of row : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
   {
    int a=1;             // so that value of a becomes 1 after each loop
     
        for(int j=1;j<=i;j++)     //if we do here j<=n then we will get solid pattern.
       {                          // if we do here j<=n+1-i we will get inverted triangle.
         printf("%d ",a);
          a = a + 2;
        }
    
    printf("\n");
    }
    return 0;
}