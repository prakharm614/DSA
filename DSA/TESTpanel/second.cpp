#include<iostream>
using namespace std;
int main()
{
  //int arr[]={1,2,3,4,5,6,7,8,9};
  int arr[7];
  for(int i=0;i<7;i++)
  {
    cin>>arr[i];
    cout<<" ";
  }
  cout<<endl<<endl<<endl;
  int max=arr[0];
  int smax=arr[0];
  for(int i=0;i<7;i++){
    if(arr[i]>max)
    {
        smax=max;
        max=arr[i];
       
    }
    
  } 
  cout<<smax;
}