#include<iostream>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;

    }
};
void display(TreeNode* root){
    //base case
    if(root==NULL) return;
    //kaam
    cout<<root->val<<" ";
    //recursive call
    display(root->left);
    display(root->right);
}

// with queue

void queuetrav(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(q.size()>0){
        TreeNode* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL)  q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }

}
int sum(TreeNode* root){
    if(root==NULL) return 0;
    int Sum= root->val + sum(root->left)+sum(root->right);
    return Sum;
}
int main(){
    TreeNode*a=new TreeNode(10);
    TreeNode*b=new TreeNode(20);
    TreeNode*c=new TreeNode(30);
    TreeNode*d=new TreeNode(40);
    TreeNode*e=new TreeNode(50);
    TreeNode*f=new TreeNode(60);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    display(a);
    cout<<endl<<endl;
    cout<<sum(a);
    cout<<endl;
    queuetrav(a);
}