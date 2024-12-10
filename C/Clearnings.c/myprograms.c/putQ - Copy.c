#include<stdio.h>
int fun(int n){
    if( n<=0){
        return 0;
    }
    return n + fun(n-1);
}
int main()
{
    int res = fun(10);
    printf("%d\n",res);
    return 0;
}