#include<iostream>
#include<vector>

using namespace std;
vector<int>dp;

// fibonacci recursive + Top down
int fib(int n){
if(n==0 or n==1 ) return n;
// dp check to identify if the problem was already solved earlier
else if(dp[n]!= -1) return dp[n];
//storing ans
else return dp[n]=fib(n-1)+fib(n-2);
}

// fibonacci Bottom up
int fibbu(int n){
    dp.clear();
    dp.resize(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
   // cout<<fib(7);
   int n;
   cin>>n;
//    dp.clear();
//    dp.resize(n+1,-1); // -1 means that subproblem is not yet computed  
   cout<<fibbu(n)<<"\n";
   return 0;
}
/*
m1 normal fibonacci recursive
m2 fibonaci top down
m3 fibonacci botom up
m4 fibonacci space optimized
 */