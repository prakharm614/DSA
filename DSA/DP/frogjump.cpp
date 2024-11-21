#include<vector>
#include<iostream>
#include<limits.h>
using namespace std;
int k;
vector<int>h;
vector<int>dp;
int f(int i){
    if(i==h.size()-1) return 0;
    else if(i>=h.size() ) return INT_MAX;
    // if already there
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    //else store
    for(int j=1;j<=k;j++){
        if(i+j>=h.size()) break;
        ans=min(ans,abs(h[i]-h[i+j])+f(i+j));
    }
    return dp[i]=ans;

}
int main(){
    int n,k;
    cin>>n>>k;
    h.resize(n);
    dp.resize(n,-1);
    for(int i=0;i<n;i++) cin>>h[i];
    cout<<f(0)<<"\n";
    return 0;
}