#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;
vector<int> dp(1000005,-1);
int helper(int n){
    if(n==0) return 1;
     int res=0;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=6;i++){
        if(n-i<0) break;
        res=res%mod+helper(n-i)%mod ;
    }
    return dp[n]=res%mod;
}
int bottomup(int n){
    dp[0]=1;
    for(int k=0;k<=n;k++){
        ll res=0;
        for(int i=1;i<=6;i++){
        if(n-i<0) break;
        res=res%mod+helper(n-i)%mod ;
    }

    return dp[k]=res%mod;
    }
       return dp[n];
}
int main(){
    int n;
    cin>>n;
    //cout<<helper(n)<<endl;
    cout<<bottomup(n)<<endl;
    return 0;

}
