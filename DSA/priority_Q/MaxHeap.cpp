#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Maxheap{
    vector<int>hp;
    public:
    void push(int ele){
        hp.push_back(ele);
        upheapify(hp.size()-1);
    }
    int peek(){
        if(empty()) return INT_MIN;
        return hp[0];
    }
    void upheapify(int ci){
        while(ci>0){
            int pi=(ci-1)/2;
            if(hp[pi]<hp[ci]){
                swap(hp[pi],hp[ci]);
                ci=pi;
            }
            else break;
        }

    }
    bool empty(){
            return hp.size()==0;
    }
    void display(){
        for(int i=0;i<hp.size();i++){
            cout<<hp[i]<<" ";
        }
    }

};
int main(){
        Maxheap hp;
        hp.push(2);
        hp.push(34);
        hp.push(-2);
        hp.push(23);
        hp.push(9);
        hp.push(8);
        hp.push(0);
        hp.push(6);
        hp.display();


    return 0;
}