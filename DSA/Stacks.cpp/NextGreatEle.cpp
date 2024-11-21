
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
// using stack : pop, ans, push wala concept

// sc=o(n), tc=o(n)

    int arr[]={3,1,2,5,4,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    stack <int> st;
    int nge[n];
    nge[n-1]=-1;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        //pop all ele smaller than arr[i]
        while(st.size()>0 && st.top()<=arr[i]){
            
            st.pop();
        }
        // matrk the answer in nge array
         if(st.size()==0) nge[i]=-1;
          else  nge[i]=st.top();

             // push the greater ele to stack
        st.push(arr[i]);
    }
     for(int i=0;i<n;i++)
         cout<<arr[i]<<" ";
         cout<<endl<<endl;
    for(int i=0;i<n;i++)
         cout<<nge[i]<<" ";
    
}