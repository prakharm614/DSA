#include<iostream>
using namespace std;
void pip (int x){
    if(x==0) return;
    cout<<x<<endl;
    pip(x-1);
    cout<<x<<endl;
    pip(x-1);
    cout<<x<<endl;

}
int main(){
    int x=3;
    pip(x);
    
    

}