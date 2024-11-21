#include<bits/stdc++.h>

//CSES problem set
//n to zero conversion



using namespace std;

vector<int>getdigits(int n){
    vector<int>v;
    while(n>0){
        int r=n%10;
        if(r!=0)
        v.push_back(r);
        n/=10;
    }
    return v;
}
//recursive
int solve(int n){
    if(n==0 ) return 0;
    else if(n<=9) return 1;
    vector<int>temp=getdigits(n);
    int res=INT_MAX;
    for(int i=0;i<temp.size();i++){
        res=min(res,solve(n-temp[i]));
    }
    return 1+res;
}
//dp top down way
vector<int>dp;
int topdowndp(int n){
    if(n==0 ) return 0;
    else if(n<=9) return 1;
    vector<int>temp=getdigits(n);
    int res=INT_MAX;
    if(dp[n]!=-1) return dp[n];
    for(int i=0;i<temp.size();i++){
        res=min(res,topdowndp(n-temp[i]));
    }
    return dp[n]=1+res;
}

//dp bottom up
int bottomup(int n){
    dp[0]=0;
    for(int i=1;i<=9;i++) dp[i]=1;
    for(int i=10;i<=n;i++){
        //i->state
        //calculate dp[n]
        vector<int>temp=getdigits(i);
        int res=INT_MAX;
        for(int j=0;j<temp.size();j++){
            res=min(res,dp[i-temp[j]]);
        }
        dp[i]=1+res;
    }
   return dp[n];

}


int main(){
    int n;
    cin>>n;
    //cout<<solve(n)<<endl;
    dp.clear();
    dp.resize(1000005,-1);
    //cout<<topdowndp(n);
    cout<<bottomup(n);
}