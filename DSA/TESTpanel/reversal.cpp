#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &a, int p, int q)
{
    int i = p;
    int j = q;
    while (i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }

    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }
 }
int main()
{
    int n;

    vector<int> v;
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(9);
    v.push_back(8);
    int s = v.size();
    cout << "enter the number by which rotation is to be done : ";
     cin >> n;

{
    if (n == s)
    {
     { for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " "<<endl;
        }}
        

        
    }
    
    
    
    else if (n > s)
    {
        n=n%s;
        { 
        reverse(v, 0, (s-n-1));
        reverse(v,(s-n),(s-1));
        reverse(v,0,(s-1));}


        
       
    }
    else
    {
         reverse(v, 0, (s-n-1));
        reverse(v,(s-n),(s-1));
        reverse(v,0,(s-1));
        return 1;
    }
  }  
//    for (int i = 0; i < v.size(); i++)
//     {
//        cout << v[i] << " ";
//      }
   
    return 0;
}