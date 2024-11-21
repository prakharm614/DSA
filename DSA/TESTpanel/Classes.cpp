#include<iostream>
using namespace std;
int main(){
    class cricketer{
        private:
        string name;
        int age;
        int ntm;
        int arn;
        public:
        void setAge(int age){
            this->age=age;
        }void setntm(int ntm){
            this->ntm=ntm;
        }
        void setarn(int arn){
            this->arn=arn;
        }
        void setName(string name){
            this->name=name;
        }
         int getAge(){
            return age;
        }int getntm(){
               return ntm;
        }
        int getarn(){
            return arn;
        }
        string getName(){
            return name;
        }
        
    };

   





    cricketer arr[20];
    

     for(int i=0;i<2;i++){
       string name;
        int age;
        int ntm;
        int arn;
        cin>>name;
        arr[i].setName(name);
        cin>>age;
        arr[i].setAge(age);
        cin>>ntm;
        arr[i].setntm(ntm);
        cin>>arn;
        arr[i].setarn(arn);
    }
    for(int i=0;i<2;i++){
        cout<<arr[i].getName()<<endl;
        cout<<arr[i].getAge()<<endl;
        cout<<arr[i].getntm()<<endl;
        cout<<arr[i].getarn()<<endl;
    }

}