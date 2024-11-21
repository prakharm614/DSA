#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int arr[]={0,-1,-2,3,4,-5,6,4,7,-8};
    int k=3;//window size
    vector<int>ans;
    queue<int>helper;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]<0) helper.push(i);

    }
    //  for(int i=0;i<n-k+1;i++){
    //     if(helper.front()>=i && helper.front()<=i+k){
    //         ans.push_back(arr[helper.front()]);

    //     }
    //     else ans.push_back(0);

    //     if(helper.front()<i) helper.pop();

    // }
      for (int i = 0; i < n - k + 1; i++) {
        if (!helper.empty() && helper.front() < i) {
            helper.pop(); // Remove indices that are out of current window
        }
        if (!helper.empty() && helper.front() < i + k) {
            ans.push_back(arr[helper.front()]);
        } else {
            ans.push_back(0);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }




}