// #include<iostream>
// using namespace std;
//  class Node{
//     public:
//         int val;
//         Node* next;
//         Node(int val){
//             this->val=val;
//             this->next=NULL;
//         }
//     };
//     class LinkedList{
//         public:
//         Node *head;
//         Node* tail;
//         int size;
//         LinkedList(){
//             head=tail=NULL;
//             size=0;
//         }
//         void InsertAtBeg(int x)
//         {
//             Node *temp= new Node(x);
//             if(size==0) head=tail=temp;
//             else{
//                 temp->next=head;
//                 head=temp;

//             }size++;
            

//         }
//         void display(){Node* temp = head;
//         while (temp != NULL) {
//             cout << temp->val << " ";
//             temp = temp->next;
//         }
//         cout<<endl;
//         }
//         void InsertAtEnd(int x){
//                 Node*temp=new Node(x);{
//                     if(size==0) head=tail=temp;
//                     else{
//                         tail->next=temp;
//                         tail=temp;

//                     }size++;

//                 }
//         }
//         void insertAtPos(int pos,int val){
//             Node*temp= new Node(val);
//             Node* var=head;
//             for(int i=1;i<pos-1;i++){
//                 var=var->next;
//             }
//             temp->next=var->next;
            
//             var->next=temp;
//             size++;
//         }
//         int delBeg(){
//             if (head=tail=NULL) 
//             {
//                cout<<"List already empty"; 
//             }
//             else{
//                 head=head->next;
//                 cout<<"Deleted\n";
//                 size--;
//             }
            
//         }
//          int delEnd(){
//             Node* temp=head;
//             if (head=tail=NULL) 
//             {
//                cout<<"List already empty"; 
//             }
//             else{
//                 while(temp->next != NULL){
//                     temp=temp->next;
                    
//                 }
//                 temp->next=NULL;
//                 cout<<"Deleted\n";
//                 size--;
//             }
            
//         }
//          void delAtPos(int pos){
//             Node* var=head;
//             for(int i=1;i<pos-1;i++){
//                 var=var->next;
//             }
//             var->next=var->next->next;
//             cout<<"DEleted\n";
//             size--;
//         }

//     };
// int main(){
//     LinkedList ll;
//     ll.InsertAtBeg(2023);
//     ll.display();
//     ll.InsertAtBeg(2022);
//     ll.display();
//     ll.InsertAtEnd(2025);
//     ll.display();
//     ll.InsertAtEnd(2026);
//     ll.display();
//     ll.insertAtPos(3,2024);
//     ll.display();
//     ll.delBeg();
//     ll.display();
//     ll.delEnd();
//     ll.display();
//     ll.delAtPos(2);
//     ll.display();

    

   
// }
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    void InsertAtBeg(int x) {
        Node* temp = new Node(x);
        if (size == 0)
            head = tail = temp;
        else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void InsertAtEnd(int x) {
        Node* temp = new Node(x);
        if (size == 0)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtPos(int pos, int val) {
        if (pos < 0 || pos > size) // Updated condition to check if pos > size
            return; // Invalid position
        if (pos == 0) { // Updated to handle insertion at the beginning separately
            InsertAtBeg(val);
            return;
        }
        if (pos == size) { // Updated to handle insertion at the end separately
            InsertAtEnd(val);
            return;
        }
        Node* temp = new Node(val);
        Node* var = head;
        for (int i = 1; i < pos - 1; i++) { // Corrected loop condition
            var = var->next;
        }
        temp->next = var->next;
        var->next = temp;
        size++;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void delBeg() {
        if (size == 0) {
            cout << "List already empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void delEnd() {
        if (size == 0) {
            cout << "List already empty" << endl;
            return;
        }
        if (size == 1) { // Corrected to handle deletion when there's only one element
            delete head;
            head = tail = NULL;
            size--;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
        size--;
    }

    void delAtPos(int pos) {
        if (pos < 0 || pos >= size) // Updated condition to check if pos >= size
            return; // Invalid position
        if (pos == 0) { // Updated to handle deletion at the beginning separately
            delBeg();
            return;
        }
        if (pos == size - 1) { // Updated to handle deletion at the end separately
            delEnd();
            return;
        }
        Node* var = head;
        for (int i = 1; i < pos; i++) {
            var = var->next;
        }
        Node* temp = var->next;
        var->next = temp->next;
        delete temp;
        size--;
    }
};

int main() {
    LinkedList ll;
    ll.InsertAtBeg(2023);
    ll.display();
    ll.InsertAtBeg(2022);
    ll.display();
    ll.InsertAtEnd(2025);
    ll.display();
    ll.InsertAtEnd(2026);
    ll.display();
    ll.insertAtPos(3, 2024);
    ll.display();
    ll.delBeg();
    ll.display();
    ll.delEnd();
    ll.display();
    ll.delAtPos(2);
    ll.display();

    return 0;
}
