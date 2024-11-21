#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#define big INT_MAX
using namespace std;
// recursive approach
int soln(int n ){
    if(n==1) return 0;
    else if(n==2 or n==3) return 1;
    else return 1+ min({(soln(n-1)),(n%2==0)?soln(n/2):big,(n%3==0)?soln(n/3):big});
}
// top down
vector<int>dp;
int topdown(int n ){
    if(n==1) return 0;
    else if(n==2 or n==3) return 1;
    if(dp[n]!=-1) return dp[n];
    else return 
    dp[n]=1+ min({(soln(n-1)),(n%2==0)?soln(n/2):big,(n%3==0)?soln(n/3):big});
}
//bottom up
int bottomup(int n){
    dp.clear();
    dp.resize(1005,-1);
    dp[1]=0;
    dp[2]=dp[3]=1;
    for(int i=4;i<=n;i++){
        
        dp[i] = 1 + min({dp[i-1], (i%2 == 0) ? dp[i/2] : big, (i%3 == 0) ? dp[i/3] : big});


    }
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    cout << soln(n) << "\n";
    
    dp.clear();
    dp.resize(n + 1, -1);
    cout << topdown(n) << "\n";
    
    cout << bottomup(n) << "\n";
    
    return 0;
}