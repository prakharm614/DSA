#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n==m) cout<<"YEs"<<endl;
        else if (n<m) cout<<"NO"<<endl;
        else{
            if((n-m)%2==0) cout<<"YEs"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}