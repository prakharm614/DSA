#include<iostream>
#include<queue>
using namespace std;
int main(){
    vector<int>v={0,};
    int arr[]={0,};
    //by default max heap
    priority_queue<int>hp;
    //for min heap
    priority_queue<int,vector<int>,greater<int>>hp;
    //vector ka use karke priority queue
    //we need to pass region in vector from where to where our vector should be arranged
    priority_queue<int,vector<int>,greater<int>>minhpvector(v.begin(),v.end());
    //using array
    priority_queue<int>maxhparray(arr,arr+n);



    
        hp.push(2);
        hp.push(34);
        hp.push(-2);
        hp.push(23);
        hp.push(9);
        hp.push(8);
        hp.push(0);
        hp.push(6);
        cout<<hp.top()<<" ";
        cout<<minhpvector.top()<<endl;
        cout<<maxhparray.top()<<endl;
        return 0;

}
