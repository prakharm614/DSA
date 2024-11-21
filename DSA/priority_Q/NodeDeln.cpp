#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Maxheap{
    vector<int>hp;
    public:
    void push(int ele){
        //O(logn)
        hp.push_back(ele);
        upheapify(hp.size()-1);
    }
    int peek(){
        //O(1)
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
   void downheapify(int idx){
        while(idx<hp.size()){
            int pi=(idx-1)/2;
            int lc=2*idx+1;
            int rc=2*idx+2;
            int maxele=idx;
            if(lc>=hp.size()) break; //idx->leaf
            if(hp[lc]>hp[maxele]) maxele=lc; //
            if(rc<hp.size() and hp[rc]>hp[maxele]) maxele=rc;
            if(maxele!=idx){
                swap(hp[idx],hp[maxele]);
                idx=maxele;   // for next iteration

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
    void DeleteHP(){
        //O(logn)
       if(empty()) return;
       else{
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();
        downheapify(hp[0]);
       }

    }
     void DeleteLP(){


    }
    void Deleteany(){
        //in case of maxheap replace the node at idx by infinite and call upheafify
        //now call delete HP() normally
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
        hp.DeleteHP();
        cout<<endl;
        hp.display(); 
       
        cout<<endl;
        hp.DeleteHP();
        hp.display();

    return 0;
}