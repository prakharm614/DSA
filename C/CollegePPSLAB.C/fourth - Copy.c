/*WAP that swaps values of two variables using a third variable*/
#include <stdio.h>
int main()
{
    int p,q,temp;
    printf("Enter the value of p:-");
    scanf("%d",&p);
    printf("Enter the value of q:-");
    scanf("%d",&q);
    temp=p;
    p=q;
    q=temp;
    printf("The value after swapping is:-\n");
    printf("p=%d\n",p);
    printf("q=%d\n",q);

    return 0;

}
