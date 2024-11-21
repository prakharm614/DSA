
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
// using stack : pop, ans, push wala concept

    int arr[]={100,80,60,81,70,60,75,85};
    int n=sizeof(arr)/sizeof(arr[0]);
    stack <int> st;//in stack store pge ka idx
    //nge array is = our answer it is not real nge
    int nge[n];
    nge[0]=-1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0 && arr[st.top()]<=arr[i]){
            
            st.pop();
        }
         if(st.size()==0) nge[i]=-1;
          else  nge[i]=st.top();

             // push the greater ele to stack
        st.push(i);
    }
     for(int i=0;i<n;i++)
         cout<<arr[i]<<" ";
         cout<<endl<<endl;
         // do this for getting pg ka idx
    // for(int i=0;i<n;i++)
    //      cout<<nge[i]<<" ";

    //for our actual ans
     for(int i=0;i<n;i++)
         cout<<abs(nge[i]-i)<<" ";
}