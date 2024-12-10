#include<stdio.h>
void reverse(int array[],int si,int ei)
{
    for(int i=si,j=ei;i<j;i++,j--)
    {   int temp=array[i];
         array[i]=array[j];
         array[j]=temp;
     }
     return;
}
int main()
{   int array[9]={1,2,3,4,5,6,7,8,9};
    int si,ei;
    printf("enter the starting and ending index : ");
    scanf("%d  %d",&si,&ei);
    reverse (array,si,ei);
    for(int i=0;i<9;i++)
    {
        printf(" %d ",array[i]);
    }
    return 0;
}