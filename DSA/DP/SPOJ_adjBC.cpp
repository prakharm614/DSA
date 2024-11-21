#include<bits/stdc++.h>
using namespace std;

    
    int dp[105][105][2];

 int helper(int n, int k, int last){
    if(n==0) return 0;
    if(n==1){
        if(k==0) return 1;
        else return 0;
    }
    if(dp[n][k][last]!=-1) return dp[n][k][last];
    else {
        if(last==1) return dp[n][k][last]=helper(n-1,k,0)+helper(n-1,k-1,1);
        else if(last==0) return dp[n][k][last]=helper(n-1,k,0)+helper(n-1,k,1);

    }


 }
  
int main(){
    int t;
    cin>>t;
    while(t--){
        int num,n,k;
        cin>>num>>n>>k;
        memset(dp,-1,sizeof dp);
        int ans=helper(n,k,0)+helper(n,k,1);
        cout<<num<<" "<<ans<<endl;

    }
}