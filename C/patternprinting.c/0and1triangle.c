#include<stdio.h>
int main()
{
    int n,a;
    printf("Enter the number of lines : ");
    scanf("%d",&n);

    for (int i=1;i<=n;i++)
      {
        for(int j=1;j<=n+1-i;j++)
        {  a=i+j;
            if (a%2==0)
            {printf("1 ");}
            else 
            {printf("0 ");}
        }
        printf("\n");
      }
    return 0;
}