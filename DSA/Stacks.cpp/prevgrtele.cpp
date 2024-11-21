
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
    // nge=pge
    int nge[n];
    nge[0]=-1;
    st.push(arr[0]);
    for(int i=1;i<n;i++){
        //pop all ele smaller than arr[i]
        // for pge just change this condition
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