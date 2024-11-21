#include<iostream>
#include<vector>
using namespace std;
void change(vector<int> &p){
   p[0]=5;
}
int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(7);
    change(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
 
}