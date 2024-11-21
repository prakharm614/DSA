//CSES proberm set
// minimizing coins

#include<bits/stdc++.h>
# define ll long long;
using namespace std;
int helper(int n,vector<int>&v,vector<int>&dp){
    if(n==0) return 0;
    
    if(dp[n]!=-2) return dp[n];
    int res=INT_MAX;
    for(int i=0;i<v.size();i++){
        //if amt to be passed becomes negative skip that coin
        if(n-v[i]<0) continue;
        res=min(res,helper(n-v[i],v,dp));
    }
    //if no change then store INT_MAX as checkmark
    if(res==INT_MAX) return dp[n]=INT_MAX;
    return dp[n]=1+res;



}
int main(){
    vector<int>dp;
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    dp.resize(1000005,-2);
    int ans=helper(x,v,dp);
    if(ans==INT_MAX) cout<<-1;
    else cout<<ans;
    

}
